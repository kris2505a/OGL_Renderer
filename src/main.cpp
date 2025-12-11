#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "VertexBuffer.h"
#include "IndexBuffer.h"

struct Vertex {
	glm::vec3 pos;
	glm::vec4 col;
};

int main() {
	glfwInit();

	GLFWwindow* window = glfwCreateWindow(1280, 720, "Big butt", nullptr, nullptr);
	glfwMakeContextCurrent(window);

	gladLoadGL();

	glClearColor(0.03f, 0.2f, 0.8f, 1.0f);

	Vertex vertices[]{
			{{-0.5f,  0.5f,  0.5f}, {1.0f, 0.0f, 1.0f, 1.0f}},
			{{ 0.5f, -0.5f,  0.5f}, {1.0f, 1.0f, 0.0f, 1.0f}},
			{{-0.5f, -0.5f,  0.5f}, {0.0f, 1.0f, 1.0f, 1.0f}},
			{{ 0.5f,  0.5f,  0.5f}, {1.0f, 0.0f, 1.0f, 1.0f}},
			{{-0.5f,  0.5f, -0.5f}, {1.0f, 1.0f, 0.0f, 1.0f}},
			{{ 0.5f, -0.5f, -0.5f}, {1.0f, 0.0f, 1.0f, 1.0f}},
			{{-0.5f, -0.5f, -0.5f}, {0.0f, 1.0f, 1.0f, 1.0f}},
			{{ 0.5f,  0.5f, -0.5f}, {1.0f, 0.0f, 1.0f, 1.0f}}
	};

	unsigned int indices[]{
		// Front face (z = +0.5)
		0, 2, 1,
		0, 1, 3,

		// Back face (z = -0.5)
		4, 5, 6,
		4, 7, 5,

		// Left face (x = -0.5)
		4, 6, 2,
		4, 2, 0,

		// Right face (x = +0.5)
		3, 1, 5,
		3, 5, 7,

		// Top face (y = +0.5)
		4, 0, 3,
		4, 3, 7,

		// Bottom face (y = -0.5)
		1, 2, 6,
		1, 6, 5
	};

	VertexBuffer vbo(vertices, sizeof(vertices));
	vbo.bind();

	IndexBuffer ibo(indices, sizeof(indices));
	ibo.bind();
	
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)(3 * sizeof(float)));

	while (!glfwWindowShouldClose(window)) {

		glClear(GL_COLOR_BUFFER_BIT);

		glDrawElements(GL_TRIANGLES, std::size(indices), GL_UNSIGNED_INT, nullptr);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);

	glfwTerminate();
}