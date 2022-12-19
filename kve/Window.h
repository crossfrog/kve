#pragma once

#include <string>

#ifdef KVE_GL
#include <SDL2/SDL.h>
#endif

#include <glm/glm.hpp>

namespace kve {
	struct WindowProperties {
		int width = 640, height = 480;
		std::string title = "KVE Window";
		bool resizeable = false;
	};

	class Window {
#ifdef KVE_GL
	private:
		SDL_Window* sdlWindow;
		SDL_GLContext sdlGlContext;
#endif

	private:
		WindowProperties properties;
		void Resize(int width, int height);

	public:
		int GetWidth();
		int GetHeight();

		glm::mat4 GetOrthoTransform();

		bool Start(WindowProperties properties);
		void End();
		bool Update();
		void Render();
	};
}