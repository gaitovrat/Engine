#include "App.hpp"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Resource/ResourceManager.hpp"
#include "Resource/Model/Sphere.hpp"
#include "Resource/Model/SuziSmooth.hpp"
#include "Resource/Model/SuziFlat.hpp"
#include "Resource/Model/Tree.hpp"
#include "Resource/Model/Gift.hpp"
#include "KeyboardEvent/KeyboardEvent.hpp"
#include "KeyboardEvent/EKey.hpp"
#include "Configuration.hpp"

App::App(const int width, const int height, const char *title) :
    m_window(width, height, title)
{
    m_window.EnableVSync();

    RegisterDefaultKeyEvents();
	m_scenes.emplace_back();

    auto& scene = m_scenes.back();

    for (int i = 0; i < 100; i++)
    {
	    constexpr auto distance = 3.f;
	    DrawableObject* object(nullptr);

        switch (i % 5)
        {
        case 0:
            object = new Sphere();
            break;
        case 1:
            object = new SuziSmooth();
            break;
        case 2:
            object = new SuziFlat();
            break;
        case 3:
            object = new Tree();
            break;
        default:
            object = new Gift();
            break;
        }

		object->SetShader(ResourceManager::GetInstance().GetShader("lights"));
        object->GetTransformation().AddTranslate(glm::vec3(i % 10 * distance, 0,
                                                           static_cast<float>(static_cast<int>(i / 10.f)) * distance));

        scene.AddObject(*object);
        delete object;
    }
    scene.GetLight().SetPosition(glm::vec3(0, 6, -2));
}

void App::Run()
{ 
    // Set correct light position
    m_scenes[Configuration::level].UpdateObjects();

    while (m_window.ShoudlClose() == false)
    {
        m_renderer.Clear();

        for (auto& object : m_scenes[Configuration::level].GetObjects())
        {
            m_renderer.Draw(object);
        }

        m_window.PollEvents();
        m_window.SwapBuffers();
    }
}

void App::RegisterDefaultKeyEvents()
{
	for (const std::vector listeners = {
		     KeyboardEventListener(m_window, EKey::KEY_S, []() {
			     Camera::GetInstance().MoveBackward(Configuration::playerSpeed);
			     std::cout << "move backward clicked\n";
		     }),
		     KeyboardEventListener(m_window, EKey::KEY_W, []() {
			     Camera::GetInstance().MoveForward(Configuration::playerSpeed);
			     std::cout << "move backward clicked\n";
		     }),
		     KeyboardEventListener(m_window, EKey::KEY_A, []() {
			     Camera::GetInstance().MoveLeft(Configuration::playerSpeed);
			     std::cout << "move backward clicked\n";
		     }),
		     KeyboardEventListener(m_window, EKey::KEY_D, []() {
			     Camera::GetInstance().MoveRight(Configuration::playerSpeed);
			     std::cout << "move backward clicked\n";
		     }),
		     KeyboardEventListener(m_window, EKey::KEY_S, []() {
			     Camera::GetInstance().MoveBackward(Configuration::playerSpeed);
			     std::cout << "move backward clicked\n";
		     }),
		     KeyboardEventListener(m_window, EKey::KEY_ESCAPE, [this]() {
			     m_window.Close();
		     })
	     }; const auto& listener : listeners)
    {
        KeyboardEvent::GetInstance().AddListener(listener);
    }
}
