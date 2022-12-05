#include "App.hpp"

#include <GLFW/glfw3.h>
#include <iostream>

#include "Resource/ResourceManager.hpp"
#include "KeyboardEvent/KeyboardEvent.hpp"
#include "KeyboardEvent/EKey.hpp"
#include "Configuration.hpp"
#include "Light/SpotLight.hpp"
#include "Light/DirectionalLight.hpp"
#include "Light/PointLight.hpp"
#include "Camera.hpp"
#include "Resource/Model/Sphere.hpp"
#include "Resource/Model/Gift.hpp"
#include "Resource/Model/SuziSmooth.hpp"
#include "Resource/Model/SuziFlat.hpp"
#include "Resource/Model/Tree.hpp"

App::App(const int width, const int height, const char *title) :
    m_window(width, height, title)
{
    m_window.EnableVSync();
    RegisterDefaultKeyEvents();


	m_scenes.emplace_back();
	for (int i = 0; i < 4; i++) {
		m_scenes.emplace_back(false);
	}

	// Level 0
	auto* scene = &m_scenes[0];
	scene->AddObject(DrawableObject());

	// Level 1
	scene = &m_scenes[1];
	scene->AddObject(Gift());

	// Level 2
	scene = &m_scenes[2];

	float distance = 2.f;
	for (int i = 0; i < 4; i++)
	{
		scene->AddObject(Sphere(ResourceManager::GetInstance().GetShader("phonguv")));
	}

	scene->GetObjects()[0].GetTransformation().AddTranslate(glm::vec3(distance, 0, 0));
	scene->GetObjects()[1].GetTransformation().AddTranslate(glm::vec3(-distance, 0, 0));
	scene->GetObjects()[2].GetTransformation().AddTranslate(glm::vec3(0, distance, 0));
	scene->GetObjects()[3].GetTransformation().AddTranslate(glm::vec3(0, -distance, 0));

	// Level 3
	scene = &m_scenes[3];

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
			object->SetShader(ResourceManager::GetInstance().GetShader("constant"));
			break;
		case 1:
			object->SetShader(ResourceManager::GetInstance().GetShader("phonguv"));
			break;
		case 2:
			object->SetShader(ResourceManager::GetInstance().GetShader("lights"));
			break;
		}

		object->GetTransformation().AddTranslate(glm::vec3((i % 10) * distance, 0, float(int(i / 10.f)) * distance));

		scene->AddObject(*object);
		delete object;
	}
	scene->AddLight(std::make_shared<SpotLight>());
	auto light = std::make_shared<DirectionalLight>();
	light->SetPosition(glm::vec3(0, 5, 0));
	scene->AddLight(light);
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
			 KeyboardEventListener(m_window, KEY_1, [=]() {
				 Configuration::Level = 0;
				 m_scenes[Configuration::Level].UpdateObjects();
			 }),
			 KeyboardEventListener(m_window, KEY_2, [=]() {
				 Configuration::Level = 1;
				 m_scenes[Configuration::Level].UpdateObjects();
			 }),
			 KeyboardEventListener(m_window, KEY_3, [=]() {
				 Configuration::Level = 2;
				 m_scenes[Configuration::Level].UpdateObjects();
			 }),
			 KeyboardEventListener(m_window, KEY_4, [=]() {
				 Configuration::Level = 3;
				 m_scenes[Configuration::Level].UpdateObjects();
			 }),
		     KeyboardEventListener(m_window, KEY_ESCAPE, [this]() {
			     m_window.Close();
		     })
	     }; const auto& listener : listeners)
    {
        KeyboardEvent::GetInstance().AddListener(listener);
    }
}
