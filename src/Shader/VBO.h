//
// Created by Dario on 14/11/2024.
//
#pragma once

#include <glad/glad.h>

/**
 * \brief Class representing a Vertex Buffer Object (VBO) in OpenGL.
 *
 * This class encapsulates the creation, binding, unbinding, and deletion of a VBO.
 */
class VBO
{
public:
    /// ID of the VBO
    GLuint ID{};

    /**
     * \brief Constructor that generates a VBO and uploads vertex data.
     *
     * \param vertices Pointer to the vertex data.
     * \param size Size of the vertex data in bytes.
     */
    VBO(GLfloat* vertices, GLsizeiptr size);

    /**
     * \brief Binds the VBO.
     */
    void Bind();

    /**
     * \brief Unbinds the VBO.
     */
    void Unbind();

    /**
     * \brief Deletes the VBO.
     */
    void Delete();
};