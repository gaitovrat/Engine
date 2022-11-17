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

    for (int i = 0; i < 4; ++i)
    {
        m_scenes.emplace_back();
    }

    // Level 1
    Sphere spheres[4];
    float distance = 1.5f;
    spheres[0].GetTransformation().AddTranslate(glm::vec3(-distance, 0.f, 0.f));
    spheres[1].GetTransformation().AddTranslate(glm::vec3(0.f, -distance, 0.f));
    spheres[2].GetTransformation().AddTranslate(glm::vec3(0.f, distance, 0.f));
    spheres[3].GetTransformation().AddTranslate(glm::vec3(distance, 0.f, 0.f));
    
    for (int i = 0; i < 4; i++)
    {
        m_scenes[0].AddObject(spheres[i]);
    }

    // Level 2.1
    Sphere sphere1;
    sphere1.SetShader(ResourceManager::GetInstance().GetShader("2.1"));
    m_scenes[1].AddObject(sphere1);
    m_scenes[1].GetLight().SetPosition(glm::vec3(0, 0, 6));

    // Level 2.2
    Sphere sphere2;
    sphere2.SetShader(ResourceManager::GetInstance().GetShader("2.2"));
    m_scenes[2].AddObject(sphere2);
    m_scenes[2].GetLight().SetPosition(glm::vec3(0, 0, 6));

    // Level 3
    distance = 3.f;
    for (int i = 0; i < 100; i++)
    {
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
        case 4:
            object = new Gift();
            break;
        }

        switch (i % 3)
        {
        case 0:
            object->SetShader(ResourceManager::GetInstance().GetShader("3.1"));
            break;
        case 1:
            object->SetShader(ResourceManager::GetInstance().GetShader("3.2"));
            break;
        case 2:
            object->SetShader(ResourceManager::GetInstance().GetShader("3.3"));
            break;
        }

        object->GetTransformation().AddTranslate(glm::vec3((i % 10) * distance, 0, float(int(i / 10.f)) * distance));

        m_scenes[3].AddObject(*object);
        delete object;
    }
    m_scenes[3].GetLight().SetPosition(glm::vec3(0, 6, -2));
}

void App::Run()
{ 
    // Set correct light position
    m_scenes[Configuration::Level].UpdateObjects();

    while (m_window.ShoudlClose() == false)
    {
        m_renderer.Clear();

        for (auto& object : m_scenes[Configuration::Level].GetObjects())
        {
            m_renderer.Draw(object);
        }

        m_window.PollEvents();
        m_window.SwapBuffers();
    }
}

void App::RegisterDefaultKeyEvents()
{
    std::vector<KeyboardEventListener> listeners = {
        KeyboardEventListener(m_window, EKey::KEY_S, []() {
            Camera::GetInstance().MoveBackward(Configuration::PlayerSpeed);
            std::cout << "move backward clicked\n";
        }),
        KeyboardEventListener(m_window, EKey::KEY_W, []() {
            Camera::GetInstance().MoveForward(Configuration::PlayerSpeed);
            std::cout << "move backward clicked\n";
        }),
        KeyboardEventListener(m_window, EKey::KEY_A, []() {
            Camera::GetInstance().MoveLeft(Configuration::PlayerSpeed);
            std::cout << "move backward clicked\n";
        }),
        KeyboardEventListener(m_window, EKey::KEY_D, []() {
            Camera::GetInstance().MoveRight(Configuration::PlayerSpeed);
            std::cout << "move backward clicked\n";
        }),
        KeyboardEventListener(m_window, EKey::KEY_S, []() {
            Camera::GetInstance().MoveBackward(Configuration::PlayerSpeed);
            std::cout << "move backward clicked\n";
        }),
        KeyboardEventListener(m_window, EKey::KEY_ESCAPE, [this]() {
			m_window.Close();
        }),
        KeyboardEventListener(m_window, EKey::KEY_1, [this]() {
            if (m_scenes.size() > 0)
            {
                Configuration::Level = 0;
                m_scenes[0].UpdateObjects();
            }
        }),
        KeyboardEventListener(m_window, EKey::KEY_2, [this]() {
            if (m_scenes.size() > 1)
            {
                Configuration::Level = 1;
                m_scenes[1].UpdateObjects();
            }
        }),
        KeyboardEventListener(m_window, EKey::KEY_3, [this]() {
            if (m_scenes.size() > 2)
            {
                Configuration::Level = 2;
                m_scenes[2].UpdateObjects();
            }
        }),
        KeyboardEventListener(m_window, EKey::KEY_4, [this]() {
            if (m_scenes.size() > 3)
            {
                Configuration::Level = 3;
                m_scenes[3].UpdateObjects();
            }
        })
    };

    for (const auto& listener : listeners)
    {
        KeyboardEvent::GetInstance().AddListener(listener);
    }
}
