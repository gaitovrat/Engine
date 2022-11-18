#include "Camera.hpp"

#include <glm/gtc/matrix_transform.hpp>
#include "Configuration.hpp"

#include <iostream>

Camera::Camera() : m_eye(0.0f, 0.0f, 3.0f), m_target(0.0f, 0.0f, -1.0f), m_up(0.0f, 1.0f, 0.0f), m_lastX(), m_lastY(), m_pitch(), m_yaw()
{
}

Camera& Camera::GetInstance()
{
	static Camera camera;

	return camera;
}

glm::mat4 Camera::ToMatrix() const
{
	return glm::lookAt(m_eye, m_eye + m_target, m_up);
}

void Camera::MoveLeft(const float speed)
{
	m_eye -= glm::normalize(glm::cross(m_target, m_up)) * speed;

	NotifyAll(EObserverEvent::VIEW_MATRIX_CHANGED);
}

void Camera::MoveForward(const float speed)
{
	m_eye += speed * m_target;

    NotifyAll(EObserverEvent::VIEW_MATRIX_CHANGED);
}

void Camera::MoveRight(const float speed)
{
	m_eye += glm::normalize(glm::cross(m_target, m_up)) * speed;

    NotifyAll(EObserverEvent::VIEW_MATRIX_CHANGED);
}

void Camera::MoveBackward(float speed)
{
	m_eye -= speed * m_target;

    NotifyAll(EObserverEvent::VIEW_MATRIX_CHANGED);
}

void Camera::NotifyAll(const EObserverEvent event)
{
	for (auto& observer : m_observers)
	{
		observer->Notify(event);
	}
}

void Camera::AddObserver(IObserver* observer)
{
    m_observers.push_back(observer);
}

void Camera::UpdateTarget(glm::vec3 eye)
{
	m_target = glm::normalize(eye);

    NotifyAll(EObserverEvent::VIEW_MATRIX_CHANGED);
}

void Camera::Rotate(const double x, const double y)
{
    std::cout << x << " " << y << std::endl;

    float xoffset = x - m_lastX;
    float yoffset = m_lastY - y;
    m_lastX = x;
    m_lastY = y;

    float sensitivity = Configuration::sensivity;
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    m_yaw += xoffset;
    m_pitch += yoffset;

    if (m_pitch > 89.0f)
        m_pitch = 89.0f;
    if (m_pitch < -89.0f)
        m_pitch = -89.0f;

    glm::vec3 direction;
    direction.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    direction.y = sin(glm::radians(m_pitch));
    direction.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    UpdateTarget(direction);
}

void Camera::UpdateViewport(int width, int height)
{
    m_width = width;
    m_height = height;

    glViewport(0, 0, width, height);
    NotifyAll(PROJECTION_MATRIX_CHANGED);
}

int Camera::GetWidth() const
{
    return m_width;
}

int Camera::GetHeight() const
{
    return m_height;
}

glm::vec3 Camera::GetEye() const
{
    return m_eye;
}
