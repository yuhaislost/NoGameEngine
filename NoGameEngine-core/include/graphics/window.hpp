#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>

namespace NoGameEngine{
    namespace Graphics
    {
        #define MAX_KEYS    1024
        #define MAX_BUTTONS 32

        static void windowResizeCallback(GLFWwindow *t_Window, int t_Width, int t_Height);
        static void key_callback(GLFWwindow* t_Window, int t_Key, int t_Scancode, int t_Action, int t_Mods);
        static void mouse_button_callback(GLFWwindow *t_Window, int t_Button, int t_Action, int t_Mods);
        static void cursor_position_callback(GLFWwindow* t_Window, double t_Xpos, double t_Ypos);

        class Window
        {
            public:

                Window(const char *t_Title, int t_Width, int t_Height);
                ~Window();

                bool closed() const;
                void update();
                void clear() const;
                void updateScreenSize();

                inline int getWidth() const { return m_Width; };
                inline int getHeight() const { return m_Height; };
                void getMousePosition(double &t_X, double &t_Y) const;

                bool isKeyPressed(unsigned int t_Key) const;
                bool isButtonPressed(unsigned int t_Button) const;

            private:

                bool init();
                friend void windowResizeCallback(GLFWwindow *t_Window, int t_Width, int t_Height);
                friend void key_callback(GLFWwindow* t_Window, int t_Key, int t_Scancode, int t_Action, int t_Mods);
                friend void mouse_button_callback(GLFWwindow *t_Window, int t_Button, int t_Action, int t_Mods);
                friend void cursor_position_callback(GLFWwindow* t_Window, double t_Xpos, double t_Ypos);

            private:

                const char *m_Title;
                int m_Width;
                int m_Height;
                GLFWwindow *m_Window;

                std::vector<bool> m_Keys;
                std::vector<bool> m_MouseButtons;
                double m_MouseX, m_MouseY;
        };
    }
}