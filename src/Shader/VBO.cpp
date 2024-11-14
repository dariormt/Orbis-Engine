//
// Created by Dario on 14/11/2024.
//

#include "VBO.h"

/**
 * \brief Constructor that generates a VBO and uploads vertex data.
 *
 * This constructor generates a Vertex Buffer Object (VBO), binds it to the GL\_ARRAY\_BUFFER target,
 * and uploads the provided vertex data to the GPU.
 *
 * \param vertices Pointer to the vertex data.
 * \param size Size of the vertex data in bytes.
 */
VBO::VBO(GLfloat* vertices, GLsizeiptr size)
{
    glGenBuffers(1, &ID);
    glBindBuffer(GL_ARRAY_BUFFER, ID);
    glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

/**
 * \brief Binds the VBO.
 *
 * This method binds the VBO to the GL\_ARRAY\_BUFFER target.
 */
void VBO::Bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, ID);
}

/**
 * \brief Unbinds the VBO.
 *
 * This method unbinds the VBO from the GL\_ARRAY\_BUFFER target.
 */
void VBO::Unbind()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

/**
 * \brief Deletes the VBO.
 *
 * This method deletes the VBO, freeing the associated GPU memory.
 */
void VBO::Delete()
{
    glDeleteBuffers(1, &ID);
}