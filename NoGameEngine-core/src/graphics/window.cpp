#include "graphics/window.hpp"

namespace NoGameEngine{
    namespace Graphics
    {

        Window::Window(const char *t_Title, int t_Width, int t_Height) : m_Title(t_Title), m_Width(t_Width), m_Height(t_Height)
        {
            if (!init())
                glfwTerminate();
            
            m_Keys = std::vector<bool>(MAX_KEYS, false);
            m_MouseButtons = std::vector<bool>(MAX_BUTTONS, false);
        }
        
        Window::~Window()
        {
            glfwTerminate();
        }

        bool Window::init()
        {
            if (!glfwInit())
            {
                std::cout << "Failed to initialize GLFW" << std::endl;
                return false;
            }
            glfwDefaultWindowHints();
            glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);
            m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);

            if (!m_Window)
            {
                std::cout << "Failed to create window" << std::endl;
                return false;
            }
            glfwMakeContextCurrent(m_Window);
            glfwSetWindowSizeCallback(m_Window, windowResizeCallback);
            glfwSetKeyCallback(m_Window, key_callback);
            glfwSetMouseButtonCallback(m_Window, mouse_button_callback);
            glfwSetCursorPosCallback(m_Window, cursor_position_callback);
            glfwSwapInterval(0.0f);

            glfwSetWindowUserPointer(m_Window, this);

            if (glewInit() != GLEW_OK)
            {
                std::cout << "Failed to initalize GLEW" << std::endl;
                return false;
            }
            std::cout << "OpenGL Version " << glGetString(GL_VERSION) << std::endl;
            return true;
        }

        bool Window::closed() const
        {
            return glfwWindowShouldClose(m_Window) == 1;
        }

        void Window::update()
        {
            GLenum error = glGetError();
            if (error != GL_NO_ERROR)
                std::cout << "OpenGL Error" << error << std::endl;
            glfwPollEvents();
            glfwSwapBuffers(m_Window);
        }

        void Window::getMousePosition(double &t_X, double &t_Y) const
        {
            t_X = m_MouseX;
            t_Y = m_MouseY;
        }   

        void Window::clear() const
        {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }

        void Window::updateScreenSize()
        {
            glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
        }

        bool Window::isKeyPressed(unsigned int t_Key) const
        {
            if (t_Key >= MAX_KEYS)
                return false;
            return m_Keys[t_Key];
        }
        
        bool Window::isButtonPressed(unsigned int t_Button) const
        {
            if(t_Button >= MAX_BUTTONS)
                return false;
            return m_MouseButtons[t_Button];
        }

        static void windowResizeCallback(GLFWwindow *t_Window, int t_Width, int t_Height)
        {
            glViewport(0,0, t_Width, t_Height);
            Window *wBuffer = static_cast<Window *>(glfwGetWindowUserPointer(t_Window));
            wBuffer->updateScreenSize();
        }

        static void key_callback(GLFWwindow* t_Window, int t_Key, int t_Scancode, int t_Action, int t_Mods)
        {
            Window *wBuffer = static_cast<Window *>(glfwGetWindowUserPointer(t_Window));
            if (t_Action != GLFW_RELEASE)
                wBuffer->m_Keys[t_Key] = true;
            else
                wBuffer->m_Keys[t_Key] = false;
        }

        static void mouse_button_callback(GLFWwindow *t_Window, int t_Button, int t_Action, int t_Mods)
        {
            Window *wBuffer = static_cast<Window *>(glfwGetWindowUserPointer(t_Window));
            if (t_Action != GLFW_RELEASE)
                wBuffer->m_MouseButtons[t_Button] = true;
            else
                wBuffer->m_MouseButtons[t_Button] = false;
        }

        static void cursor_position_callback(GLFWwindow* t_Window, double t_Xpos, double t_Ypos)
        {
            Window *wBuffer = static_cast<Window *>(glfwGetWindowUserPointer(t_Window));
            wBuffer->m_MouseX = t_Xpos;
            wBuffer->m_MouseY = t_Ypos;
        }
    }
}