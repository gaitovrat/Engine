#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <functional>

#include "KeyboardEvent/EKey.hpp"

class Window final
{
public:
	Window(int width, int height, const char* title);

	~Window();

	void EnableVSync() const;

	void DisableVSync() const;

	bool ShoudlClose() const;

	void PollEvents() const;

	void SwapBuffers() const;

	int GetWidth() const;

	int GetHeight() const;

	bool IsPressed(EKey key);

	void Close();

	std::function<void()> LeftClick() const;

	std::function<void()> RightClick() const;

	void SetLeftClick(std::function<void()> leftClick);

	void SetRightClick(std::function<void()> rightClick);

private:
	std::function<void()> m_leftClick;
	std::function<void()> m_rightClick;
	GLFWwindow* m_window;
};
