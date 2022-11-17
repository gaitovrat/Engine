#pragma once

#include <glm/glm.hpp>
#include <vector>

#include "Resource/Shader.h"
#include "Observer/ISubject.h"
#include "Observer/IObserver.h"
#include "Observer/EObserverEvent.h"

class Camera final : public ISubject
{
private:
	Camera();

public:
	static Camera& GetInstance();

	glm::mat4 ToMatrix() const;

	void MoveLeft(float speed);

	void MoveForward(float speed);

	void MoveRight(float speed);

	void MoveBackward(float speed);

	void NotifyAll(EObserverEvent event) override;

	void AddObserver(IObserver* observer) override;

	void Rotate(double x, double y);

	void UpdateViewport(int width, int height);

	int GetWidth() const;

	int GetHeight() const;

	glm::vec3 GetEye() const;

private:
	void UpdateTarget(glm::vec3 target);

	glm::vec3 m_eye;
	glm::vec3 m_target;
	glm::vec3 m_up;

	std::vector<IObserver*> m_observers;

	double m_lastX;
	double m_lastY;
	double m_yaw;
	double m_pitch;

	int m_width;
	int m_height;
};
