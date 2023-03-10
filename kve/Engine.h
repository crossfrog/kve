#pragma once
#include "Window.h"
#include "Renderer.h"

namespace kve {
	class Engine {
	private:
		void End();
		bool Update();
		void Render();

	public:
		Window window;
		Renderer renderer;

		virtual WindowProperties GetWindowProperties() { return WindowProperties(); }
		virtual RendererProperties GetRendererProperties() { return RendererProperties(); }

		bool Start();

		virtual bool GameStart() { return true; }
		virtual void GameEnd() {}
		virtual bool GameUpdate(float delta) { return true; }
		virtual void GameRender() {}
	};
}