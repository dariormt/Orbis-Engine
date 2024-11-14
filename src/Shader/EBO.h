//
// Created by Dario on 14/11/2024.
//
#pragma once
#include <glad/glad.h>

/**
 * \brief Class representing an Element Buffer Object (EBO) in OpenGL.
 *
 * This class encapsulates the creation, binding, unbinding, and deletion of an EBO.
 */
class EBO
{
public:
    /// ID of the EBO
    GLuint ID{};

    /**
     * \brief Constructor that generates an EBO and uploads index data.
     *
     * This constructor generates an Element Buffer Object (EBO), binds it to the GL\_ELEMENT\_ARRAY\_BUFFER target,
     * and uploads the provided index data to the GPU.
     *
     * \param indices Pointer to the index data.
     * \param size Size of the index data in bytes.
     */
    EBO(GLuint* indices, GLsizeiptr size);

    /**
     * \brief Binds the EBO.
     *
     * This method binds the EBO to the GL\_ELEMENT\_ARRAY\_BUFFER target.
     */
    void Bind();

    /**
     * \brief Unbinds the EBO.
     *
     * This method unbinds the EBO from the GL\_ELEMENT\_ARRAY\_BUFFER target.
     */
    void Unbind();

    /**
     * \brief Deletes the EBO.
     *
     * This method deletes the EBO, freeing the associated GPU memory.
     */
    void Delete();
};