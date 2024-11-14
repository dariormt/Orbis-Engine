//
// Created by Dario on 14/11/2024.
//

#include "EBO.h"

/**
 * \brief Constructor that generates an EBO and uploads index data.
 *
 * This constructor generates an Element Buffer Object (EBO), binds it to the GL\_ELEMENT\_ARRAY\_BUFFER target,
 * and uploads the provided index data to the GPU.
 *
 * \param indices Pointer to the index data.
 * \param size Size of the index data in bytes.
 */
EBO::EBO(GLuint* indices, GLsizeiptr size)
{
    glGenBuffers(1, &ID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
}

/**
 * \brief Binds the EBO.
 *
 * This method binds the EBO to the GL\_ELEMENT\_ARRAY\_BUFFER target.
 */
void EBO::Bind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
}

/**
 * \brief Unbinds the EBO.
 *
 * This method unbinds the EBO from the GL\_ELEMENT\_ARRAY\_BUFFER target.
 */
void EBO::Unbind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

/**
 * \brief Deletes the EBO.
 *
 * This method deletes the EBO, freeing the associated GPU memory.
 */
void EBO::Delete()
{
    glDeleteBuffers(1, &ID);
}