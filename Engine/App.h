#pragma once

#include <vector>

#include "Window.h"
#include "Scene.h"
#include "Render/Renderer.h"

class App final
{
public:
	App(int width, int height, const char* title);

	void Run();
private:
	void RegisterDefaultKeyEvents();

	Window m_window;
	std::vector<Scene> m_scenes;
	Renderer m_renderer;
};