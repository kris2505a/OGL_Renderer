#pragma once

class VertexBuffer {
public:
	VertexBuffer(const void* vertices, int size);
	~VertexBuffer();

	void bind() const;
	void unbind() const;

private:
	unsigned int m_buffer;
};