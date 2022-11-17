#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <functional>

#include "KeyboardEvent/EKey.h"

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

private:
    
	GLFWwindow* m_window;
};
