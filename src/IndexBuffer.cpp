#include "IndexBuffer.h"
#include <glad/glad.h>

IndexBuffer::IndexBuffer(const void* data, int size) {
	glGenBuffers(1, &m_buffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_buffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

IndexBuffer::~IndexBuffer() {
	glDeleteBuffers(1, &m_buffer);
}

void IndexBuffer::bind() const {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_buffer);
}

void IndexBuffer::undbind() const {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
