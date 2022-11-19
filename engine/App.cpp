#include "App.hpp"

#include <GLFW/glfw3.h>
#include <iostream>

#include "Resource/ResourceManager.hpp"
#include "Resource/Model/Sphere.hpp"
#include "Resource/Model/SuziFlat.hpp"
#include "KeyboardEvent/KeyboardEvent.hpp"
#include "KeyboardEvent/EKey.hpp"
#include "Configuration.hpp"
#include "Light/DirectionalLight.hpp"
#include "Light/PointLight.hpp"
#include "Light/SpotLight.hpp"
#include "Light/AbstractLight.hpp"
#include "Camera.hpp"

App::App(const int width, const int height, const char *title) :
    m_window(width, height, title)
{
    m_window.EnableVSync();

    RegisterDefaultKeyEvents();
	m_scenes.emplace_back();

    auto& scene = m_scenes.back();

    AbstractLight* light = new DirectionalLight;
    light->SetPosition(glm::vec3(-3, 0, 0));
    scene.AddLight(light);

	auto object = new SuziFlat;
	scene.AddObject(object);

	object = new SuziFlat;
	object->GetTransformation().AddTranslate(glm::vec3(5.f, .0f, .0f));
	scene.AddObject(object);

	light = new PointLight;
	light->SetPosition(glm::vec3(5.f, 3.f, 0.f));
	scene.AddLight(light);

	light = new SpotLight;
	scene.AddLight(light);
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
