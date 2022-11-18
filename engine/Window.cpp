#include "Window.hpp"

#include "Exception/GLFWException.hpp"
#include "Exception/GLException.hpp"
#include "KeyboardEvent/KeyboardEvent.hpp"
#include "Camera.hpp"

Window::Window(const int width, const int height, const char* title)
{
    if (glfwInit() == false)
    {
        throw GLFWException("Unable to init glfw");
    }

#ifdef __APPLE__
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#endif

    m_window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (m_window == nullptr)
    {
        throw GLFWException("Unable to create window");
    }
    
    glfwMakeContextCurrent(m_window);
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        throw GLException("Unable to initialize glew");
    }

    Camera::GetInstance().UpdateViewport(GetWidth(), GetHeight());

    glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, const double l_x, const double l_y) {
            Camera::GetInstance().Rotate(l_x, l_y);
    });
    glfwSetWindowSizeCallback(m_window, [](GLFWwindow* window, const int l_width, const int l_height) {
        Camera::GetInstance().UpdateViewport(l_width, l_height);
    });
}

Window::~Window()
{
    if (m_window != nullptr)
    {
        glfwDestroyWindow(m_window);
    }
    glfwTerminate();
}

void Window::EnableVSync() const
{
    glfwSwapInterval(1);
}

void Window::DisableVSync() const
{
    glfwSwapInterval(0);
}

bool Window::ShoudlClose() const
{
    return glfwWindowShouldClose(m_window);
}

void Window::PollEvents() const
{
    glfwPollEvents();

    KeyboardEvent::GetInstance().Dispath();
}

void Window::SwapBuffers() const
{
    glfwSwapBuffers(m_window);
}

int Window::GetWidth() const
{
    int width;
    glfwGetFramebufferSize(m_window, &width, nullptr);

    return width;
}

int Window::GetHeight() const
{
    int height;
    glfwGetFramebufferSize(m_window, nullptr, &height);

    return height;
}

bool Window::IsPressed(EKey key)
{
    return glfwGetKey(m_window, key) == GLFW_PRESS;
}

void Window::Close()
{
    glfwSetWindowShouldClose(m_window, true);
}
