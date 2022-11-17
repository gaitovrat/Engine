#pragma once

#include <vector>

#include "Window.hpp"
#include "Scene.hpp"
#include "Render/Renderer.hpp"

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
