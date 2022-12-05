#pragma once

#include <glm/glm.hpp>
#include <vector>
#include <memory>

#include "Resource/Shader.hpp"
#include "Observer/ISubject.hpp"
#include "Observer/IObserver.hpp"
#include "Observer/EObserverEvent.hpp"

class Camera final : public ISubject
{
public:
	Camera();

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

	_NODISCARD glm::mat4 Projection();

	_NODISCARD int Width() const;

	_NODISCARD int Height() const;

	_NODISCARD glm::vec3 Eye() const;

	_NODISCARD glm::vec3 Target() const;

	_NODISCARD double ClickedX();

	_NODISCARD double ClickedY();

	void SetClickedX(double x);

	void SetClickedY(double y);

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

	double m_clickedX;
	double m_clickedY;
};
