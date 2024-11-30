#pragma once

#include <iostream>
#include <string>
#include <fstream>

// namespace NoGameEngine
// {
//     namespace Utils
//     {
//         std::string read_file(const char* t_Filepath);
//     }
// }

namespace NoGameEngine
{
    namespace Utils
    {
        class FileUtils
        {
            public:
                static std::string read_file(const char* t_Filepath)
                {
                    std::ifstream file {t_Filepath, std::ios::in};

                    if (!file.is_open())
                        std::cout << "Could not open " << t_Filepath << std::endl;

                    file.seekg(0, std::ios::end);
                    unsigned long length = file.tellg();
                    
                    char* data = new char[length + 1];
                    std::fill(data, data + length + 1, 0);
                    file.seekg(std::ios::beg);
                    file.read(data, length);
                    file.close();

                    std::string result {data};
                    delete [] data;
                    return result;
                }
        };
    }
}