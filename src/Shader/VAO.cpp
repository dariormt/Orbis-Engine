//
// Created by Dario on 14/11/2024.
//

#include "VAO.h"

/**
 * \brief Constructor that generates a VAO.
 *
 * This constructor generates a Vertex Array Object (VAO) and assigns it an ID.
 */
VAO::VAO()
{
    glGenVertexArrays(1, &ID);
}

/**
 * \brief Links a VBO to the VAO.
 *
 * This method links a Vertex Buffer Object (VBO) to the VAO using the specified layout.
 *
 * \param VBO The VBO to link.
 * \param layout The layout location to link the VBO to.
 */
void VAO::LinkVBO(VBO VBO, GLuint layout)
{
    VBO.Bind();
    glVertexAttribPointer(layout, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
    glEnableVertexAttribArray(layout);
    VBO.Unbind();
}

/**
 * \brief Binds the VAO.
 *
 * This method binds the VAO, making it the current VAO.
 */
void VAO::Bind()
{
    glBindVertexArray(ID);
}

/**
 * \brief Unbinds the VAO.
 *
 * This method unbinds the VAO, making no VAO the current VAO.
 */
void VAO::Unbind()
{
    glBindVertexArray(0);
}

/**
 * \brief Deletes the VAO.
 *
 * This method deletes the VAO, freeing the associated GPU memory.
 */
void VAO::Delete()
{
    glDeleteVertexArrays(1, &ID);
}