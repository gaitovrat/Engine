#include "App.hpp"

#include <GLFW/glfw3.h>
#include <iostream>

#include "Resource/ResourceManager.hpp"
#include "KeyboardEvent/KeyboardEvent.hpp"
#include "KeyboardEvent/EKey.hpp"
#include "Configuration.hpp"
#include "Light/SpotLight.hpp"
#include "Camera.hpp"
#include "Resource/Model/Sphere.hpp"
#include "Resource/Model/Gift.hpp"

App::App(const int width, const int height, const char *title) :
    m_window(width, height, title)
{
    m_window.EnableVSync();
    RegisterDefaultKeyEvents();

	for (int i = 0; i < 2; i++)
	{
		m_scenes.emplace_back(false);
	}

	auto* scene = &m_scenes[0];

	scene->AddObject(Gift());

	scene = &m_scenes[1];

	float distance = 2.f;
	for (int i = 0; i < 4; i++)
	{
		scene->AddObject(Sphere(ResourceManager::GetInstance().GetShader("phonguv")));
	}

	scene->GetObjects()[0].GetTransformation().AddTranslate(glm::vec3(distance, 0, 0));
	scene->GetObjects()[1].GetTransformation().AddTranslate(glm::vec3(-distance, 0, 0));
	scene->GetObjects()[2].GetTransformation().AddTranslate(glm::vec3(0, distance, 0));
	scene->GetObjects()[3].GetTransformation().AddTranslate(glm::vec3(0, -distance, 0));

	m_scenes.emplace_back();

	scene = &m_scenes[2];
	scene->AddObject(DrawableObject());
}

void App::Run()
{ 
    m_scenes[Configuration::Level].UpdateObjects();

    while (m_window.ShoudlClose() == false)
    {
        m_renderer.Clear();
		auto sky = m_scenes[Configuration::Level].GetSky();
		if (sky.has_value())
		{
			m_renderer.Draw(sky.value());
		}
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
	for (const std::vector listeners = {
		     KeyboardEventListener(m_window, KEY_S, []() {
			     Camera::GetInstance().MoveBackward(Configuration::PlayerSpeed);
		     }),
		     KeyboardEventListener(m_window, KEY_W, []() {
			     Camera::GetInstance().MoveForward(Configuration::PlayerSpeed);
		     }),
		     KeyboardEventListener(m_window, KEY_A, []() {
			     Camera::GetInstance().MoveLeft(Configuration::PlayerSpeed);
		     }),
		     KeyboardEventListener(m_window, KEY_D, []() {
			     Camera::GetInstance().MoveRight(Configuration::PlayerSpeed);
		     }),
		     KeyboardEventListener(m_window, KEY_S, []() {
			     Camera::GetInstance().MoveBackward(Configuration::PlayerSpeed);
			 }),
			 KeyboardEventListener(m_window, KEY_1, []() {
				 Configuration::Level = 0;
			 }),
			 KeyboardEventListener(m_window, KEY_2, []() {
				 Configuration::Level = 1;
			 }),
			 KeyboardEventListener(m_window, KEY_3, []() {
				 Configuration::Level = 2;
			 }),
		     KeyboardEventListener(m_window, KEY_ESCAPE, [this]() {
			     m_window.Close();
		     })
	     }; const auto& listener : listeners)
    {
        KeyboardEvent::GetInstance().AddListener(listener);
    }
}
