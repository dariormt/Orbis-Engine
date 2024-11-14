//
// Created by Dario on 14/11/2024.
//

#pragma once

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cerrno>

/**
 * \brief Reads the contents of a file and returns it as a string.
 *
 * This function opens a file, reads its contents, and returns the contents as a string.
 *
 * \param filename The path to the file to be read.
 * \return std::string The contents of the file.
 */
std::string get_file_contents(const char* filename);

/**
 * \brief Class representing a shader program in OpenGL.
 *
 * This class encapsulates the creation, activation, and deletion of a shader program.
 */
class Shader
{
public:
    /// ID of the shader program
    GLuint ID;

    /**
     * \brief Constructor that creates a shader program from vertex and fragment shader files.
     *
     * This constructor reads the vertex and fragment shader source code from files, compiles them,
     * links them into a shader program, and assigns the program ID to the ID member.
     *
     * \param vertexFile The path to the vertex shader file.
     * \param fragmentFile The path to the fragment shader file.
     */
    Shader(const char* vertexFile, const char* fragmentFile);

    /**
     * \brief Activates the shader program.
     *
     * This method activates the shader program, making it the current program used by OpenGL.
     */
    void Activate();

    /**
     * \brief Deletes the shader program.
     *
     * This method deletes the shader program, freeing the associated GPU memory.
     */
    void Delete();
};