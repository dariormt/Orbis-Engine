//
// Created by Dario on 14/11/2024.
//

#include "shaderClass.h"

#include <cstring>

// Missing Vertex Shader source code
const char* missingVertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

// Missing Fragment Shader source code
const char* missingFragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.5f, 0.0f, 0.5f, 1.0f);\n"
"}\n\0";

/**
 * \brief Reads the contents of a file and returns it as a string.
 *
 * This function opens a file, reads its contents, and returns the contents as a string.
 *
 * \param filename The path to the file to be read.
 * \return std::string The contents of the file.
 * \throws std::runtime_error If the file cannot be opened.
 */
std::string get_file_contents(const char* filename)
{
    std::ifstream in(filename, std::ios::binary);
    if (!in)
    {
        std::cout << std::string("Failed to open file ") + filename + ": " + strerror(errno) + "\n";
        return {};
    }
    std::string contents((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
    return contents;
}

/**
 * \brief Constructor that creates a shader program from vertex and fragment shader files.
 *
 * This constructor reads the vertex and fragment shader source code from files, compiles them,
 * links them into a shader program, and assigns the program ID to the ID member.
 *
 * \param vertexFile The path to the vertex shader file.
 * \param fragmentFile The path to the fragment shader file.
 */
Shader::Shader(const char *vertexFile, const char *fragmentFile)
{
    std::string vertexCode = get_file_contents(vertexFile);
    if(vertexCode.empty())
    {
        std::cout << "Failed to read vertex shader file " << vertexFile << " falling back to missing shader\n";
        vertexCode = missingVertexShaderSource;
    }

    std::string fragmentCode = get_file_contents(fragmentFile);
    if(fragmentCode.empty())
    {
        std::cout << "Failed to read fragment shader file " << fragmentFile << " falling back to missing shader\n";
        fragmentCode = missingFragmentShaderSource;
    }

    const char* vertexSource = vertexCode.c_str();
    const char* fragmentSource = fragmentCode.c_str();

    // Create and compile the vertex shader
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexSource, nullptr);
    glCompileShader(vertexShader);

    // Create and compile the fragment shader
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSource, nullptr);
    glCompileShader(fragmentShader);

    // Link shaders to create a shader program
    ID = glCreateProgram();
    glAttachShader(ID, vertexShader);
    glAttachShader(ID, fragmentShader);
    glLinkProgram(ID);

    // Delete the shader objects once linked
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

/**
 * \brief Activates the shader program.
 *
 * This method activates the shader program, making it the current program used by OpenGL.
 */
void Shader::Activate()
{
    glUseProgram(ID);
}

/**
 * \brief Deletes the shader program.
 *
 * This method deletes the shader program, freeing the associated GPU memory.
 */
void Shader::Delete()
{
    glDeleteProgram(ID);
}