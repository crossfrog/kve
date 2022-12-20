#pragma once

#include <string>
#include <glm/glm.hpp>

#ifdef KVE_GL
#include <SDL2/SDL.h>
#endif

namespace kve {
	struct WindowProperties {
		int width = 640, height = 480;
		std::string title = "KVE Window";
		bool resizeable = false;

		float fps = 60.0f;
	};

	class Engine;

	class Window {
#ifdef KVE_GL
	private:
		SDL_Window* sdlWindow;
		SDL_GLContext sdlGlContext;

		unsigned int lastTicks;
		int frameTime;

		float deltaTime;
#endif

	private:
		WindowProperties properties;
		glm::mat4 frameTransform;

		void UpdateFrameTransform();

		void Resize(int width, int height);
		void GraphicsResize(int width, int height);

		bool StartGraphics();

		Engine* engine;
		friend class Engine;

	public:
		WindowProperties GetProperties();

		glm::mat4 GetFrameTransform();

		void Sleep();
		float GetDeltaTime();

		bool Start(WindowProperties properties);
		void End();
		bool Update();

		void PreRender();
		void Render();
	};
}