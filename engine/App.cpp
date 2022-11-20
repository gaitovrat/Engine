#include "App.hpp"

#include <GLFW/glfw3.h>
#include <iostream>

#include "Resource/ResourceManager.hpp"
#include "KeyboardEvent/KeyboardEvent.hpp"
#include "KeyboardEvent/EKey.hpp"
#include "Configuration.hpp"
#include "Camera.hpp"

App::App(const int width, const int height, const char *title) :
    m_window(width, height, title)
{
    m_window.EnableVSync();

    RegisterDefaultKeyEvents();
	m_scenes.emplace_back();

    auto& scene = m_scenes.back();
	auto& object = ResourceManager::GetInstance().GetDrawableObject("box.obj", "texture", "box.jpg");

	scene.AddObject(&object);
}

void App::Run()
{ 
    // Set correct light position
    m_scenes[Configuration::level].UpdateObjects();

    while (m_window.ShoudlClose() == false)
    {
        m_renderer.Clear();
        for (const auto& object : m_scenes[Configuration::level].GetObjects())
        {
            m_renderer.Draw(*object);
        }
		m_renderer.Draw(m_scenes[Configuration::level].GetSkyBox());

        m_window.PollEvents();
        m_window.SwapBuffers();
    }
}

void App::RegisterDefaultKeyEvents()
{
	for (const std::vector listeners = {
		     KeyboardEventListener(m_window, KEY_S, []() {
			     Camera::GetInstance().MoveBackward(Configuration::playerSpeed);
			     std::cout << "move backward clicked\n";
		     }),
		     KeyboardEventListener(m_window, KEY_W, []() {
			     Camera::GetInstance().MoveForward(Configuration::playerSpeed);
			     std::cout << "move backward clicked\n";
		     }),
		     KeyboardEventListener(m_window, KEY_A, []() {
			     Camera::GetInstance().MoveLeft(Configuration::playerSpeed);
			     std::cout << "move backward clicked\n";
		     }),
		     KeyboardEventListener(m_window, KEY_D, []() {
			     Camera::GetInstance().MoveRight(Configuration::playerSpeed);
			     std::cout << "move backward clicked\n";
		     }),
		     KeyboardEventListener(m_window, KEY_S, []() {
			     Camera::GetInstance().MoveBackward(Configuration::playerSpeed);
			     std::cout << "move backward clicked\n";
		     }),
		     KeyboardEventListener(m_window, KEY_ESCAPE, [this]() {
			     m_window.Close();
		     })
	     }; const auto& listener : listeners)
    {
        KeyboardEvent::GetInstance().AddListener(listener);
    }
}
