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

	void AddObserver(const std::shared_ptr<IObserver>& observer) override;

	void Rotate(double x, double y);

	void UpdateViewport(int width, int height);

	[[nodiscard]] int Width() const;

	[[nodiscard]] int Height() const;

	[[nodiscard]] glm::vec3 Eye() const;
	[[nodiscard]] glm::vec3 Target() const;

private:
	void UpdateTarget(glm::vec3 target);

	glm::vec3 m_eye;
	glm::vec3 m_target;
	glm::vec3 m_up;

	std::vector<std::shared_ptr<IObserver>> m_observers;

	double m_lastX;
	double m_lastY;
	double m_yaw;
	double m_pitch;

	int m_width;
	int m_height;
};
