#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <memory>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "../shader.h"
#include "../vertex.h"

namespace blank
{
	class Game
	{
	private:
		GLFWwindow* window;
		int width;
		int height;
		const char* title;

		std::unique_ptr<Shader> shader;

		double lastTime = 0.0;
		double nowTime = 0.0;
		double deltaTime = 0.0;

	public:
		Game(int width, int height, const char* title);

		int Init();
		void Run();
		void Update();
		void Render();
	};

	void processInput(GLFWwindow* window);
	void framebuffer_size_callback(GLFWwindow*, int width, int height);

} // namespace blank
#endif
