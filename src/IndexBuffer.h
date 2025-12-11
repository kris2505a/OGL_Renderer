#pragma once

class IndexBuffer {
public:
	IndexBuffer(const void* data, int size);
	~IndexBuffer();

	void bind() const;
	void undbind() const;

private:
	unsigned int m_buffer;
};