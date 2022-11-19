#include "App.hpp"

#include <GLFW/glfw3.h>
#include <iostream>

#include "Resource/ResourceManager.hpp"
#include "Resource/Model/Sphere.hpp"
#include "Resource/Model/SuziFlat.hpp"
#include "KeyboardEvent/KeyboardEvent.hpp"
#include "KeyboardEvent/EKey.hpp"
#include "Configuration.hpp"
#include "Light/PointLight.hpp"
#include "Camera.hpp"

App::App(const int width, const int height, const char *title) :
    m_window(width, height, title)
{
    m_window.EnableVSync();

    RegisterDefaultKeyEvents();
	m_scenes.emplace_back();

    auto& scene = m_scenes.back();

    auto light = new PointLight;
    light->SetPosition(glm::vec3(0, 3, 0));
    scene.AddLight(light);

	light = new PointLight;
	light->SetPosition(glm::vec3(-3, 0, 0));
	scene.AddLight(light);

	const auto object = new SuziFlat;
	scene.AddObject(object);
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
