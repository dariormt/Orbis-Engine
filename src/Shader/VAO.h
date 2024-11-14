//
// Created by Dario on 14/11/2024.
//

#pragma once

#include <glad/glad.h>
#include "VBO.h"

/**
 * \brief Class representing a Vertex Array Object (VAO) in OpenGL.
 *
 * This class encapsulates the creation, binding, unbinding, and deletion of a VAO.
 * It also provides a method to link a VBO to the VAO.
 */
class VAO
{
public:
    /// ID of the VAO
    GLuint ID{};

    /**
     * \brief Constructor that generates a VAO.
     *
     * This constructor generates a Vertex Array Object (VAO) and assigns it an ID.
     */
    VAO();

    /**
     * \brief Links a VBO to the VAO.
     *
     * This method links a Vertex Buffer Object (VBO) to the VAO using the specified layout.
     *
     * \param VBO The VBO to link.
     * \param layout The layout location to link the VBO to.
     */
    void LinkVBO(VBO VBO, GLuint layout);

    /**
     * \brief Binds the VAO.
     *
     * This method binds the VAO, making it the current VAO.
     */
    void Bind();

    /**
     * \brief Unbinds the VAO.
     *
     * This method unbinds the VAO, making no VAO the current VAO.
     */
    void Unbind();

    /**
     * \brief Deletes the VAO.
     *
     * This method deletes the VAO, freeing the associated GPU memory.
     */
    void Delete();
};