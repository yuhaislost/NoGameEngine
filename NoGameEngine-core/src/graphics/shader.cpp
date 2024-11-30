#include "graphics/shader.hpp"

namespace NoGameEngine
{
    namespace Graphics
    {
        Shader::Shader(const char* t_VertexPath, const char* t_FragmentPath) : m_VertexPath(t_VertexPath), m_FragmentPath(t_FragmentPath)
        {
            m_ShaderID = load();
        }

        Shader::~Shader()
        {
            glDeleteProgram(m_ShaderID);
        }

        void Shader::setUniform1f(const GLchar* t_Name, float t_Val)
        {
            glUniform1f(getUniformLocation(t_Name), t_Val);
        }

        void Shader::setUniform2f(const GLchar* t_Name, const Math::vec2& t_Vec2)
        {
           glUniform2f(getUniformLocation(t_Name), t_Vec2.x, t_Vec2.y);
        }

        void Shader::setUniform3f(const GLchar* t_Name, const Math::vec3& t_Vec3)
        {
            glUniform3f(getUniformLocation(t_Name), t_Vec3.x, t_Vec3.y, t_Vec3.z);
        }
        void Shader::setUniform4f(const GLchar* t_Name, const Math::vec4& t_Vec4)
        {
            glUniform4f(getUniformLocation(t_Name), t_Vec4.x, t_Vec4.y, t_Vec4.z, t_Vec4.w);
        }

        void Shader::setUniform1i(const GLchar* t_Name, int t_Val)
        {
            glUniform1i(getUniformLocation(t_Name), t_Val);
        }

        void Shader::setUniformMat4(const GLchar* t_Name, const Math::mat4& t_Matrix)
        {
            glUniformMatrix4fv(getUniformLocation(t_Name), 1, GL_FALSE, t_Matrix.elements);
        }

        GLint Shader::getUniformLocation(const GLchar *t_Name)
        {
            return glGetUniformLocation(m_ShaderID, t_Name);
        }

        GLuint Shader::load()
        {
            GLuint program = glCreateProgram();
            GLuint vert = glCreateShader(GL_VERTEX_SHADER);
            GLuint frag = glCreateShader(GL_FRAGMENT_SHADER);
            std::string vertSourceString = Utils::FileUtils::read_file(m_VertexPath);
            std::string fragSourceString = Utils::FileUtils::read_file(m_FragmentPath);

            const char* vertSource = vertSourceString.c_str();
            const char* fragSource = fragSourceString.c_str();

            glShaderSource(vert, 1, &vertSource, NULL);
            glCompileShader(vert);

            GLint result;
            glGetShaderiv(vert, GL_COMPILE_STATUS, &result);

            if (result == GL_FALSE)
            {
                GLint length;
                glGetShaderiv(vert, GL_INFO_LOG_LENGTH, &length);
                std::vector<char> error(length);
                glGetShaderInfoLog(vert, length, &length, &error[0]);
                std::cout << "Vertex shader failed to compile" << std::endl << &error[0] << std::endl;
                glDeleteShader(vert);
                return 0;
            }

            glShaderSource(frag, 1, &fragSource, NULL);
            glCompileShader(frag);

            glGetShaderiv(frag, GL_COMPILE_STATUS, &result);

            if (result == GL_FALSE)
            {
                GLint length;
                glGetShaderiv(frag, GL_INFO_LOG_LENGTH, &length);
                std::vector<char> error(length);
                glGetShaderInfoLog(frag, length, &length, &error[0]);
                std::cout << "Fragment shader failed to compile" << std::endl << &error[0] << std::endl;
                glDeleteShader(frag);
                return 0;
            }

            glAttachShader(program, vert);
            glAttachShader(program, frag);

            glLinkProgram(program);
            glValidateProgram(program);
            glDeleteShader(vert);
            glDeleteShader(frag);

            return program;
        }

        void Shader::enable() const
        {
            glUseProgram(m_ShaderID);
        }

        void Shader::disable() const
        {
            glUseProgram(0);
        }
    }
}