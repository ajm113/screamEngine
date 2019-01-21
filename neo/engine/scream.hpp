#ifndef SCREAM_HPP
#define SCREAM_HPP

#include <X11/X.h>		// Used to create our window context.
#include <X11/Xlib.h>
#include <chrono>		// Track the FPS/time of our game engine.
#include <thread>		// Spawning the slave thread for our game.
#include <atomic>		// Handle thread control of our game engine.
#include <condition_variable>	
#include <functional>
#include <map>			// Used for key mapping/tracking.
#include <string>

// Uncomment me when OpenGL is involved.
// typedef int(glSwapInterval_t) (Display *dpy, GLXDrawable drawable, int interval);
// static glSwapInterval_t *glSwapIntervalEXT;


namespace scream {

	const std::string DefaultAppName = "Untitled ScreamEngine Game";
	const uint32_t DefaultScreenWidth = 640;
	const uint32_t DefaultScreenHeight = 480;

	const uint32_t DefaultPixelHeight = 8;
	const uint32_t DefaultPixelWidth = 8;

	const bool DefaultFullscreen = false;

	const std::string DefaultGameDir = "base";
	const std::string DefaultModDir = "mods";

	class ScreamEngine {
		public:
		ScreamEngine(
			std::string appName = DefaultAppName,
			uint32_t screenWidth = DefaultScreenWidth,
			uint32_t screenHeight = DefaultScreenHeight,
			uint32_t pixelWidth = DefaultPixelWidth,
			uint32_t pixelHeight = DefaultPixelHeight,
			bool fullscreen = DefaultFullscreen,
			const std::string & gameDir = DefaultGameDir,
			const std::string & modDir = DefaultModDir
		);

		~ScreamEngine();
		
		bool Initalize();
		bool Start();

		// Virtual API functions.

		// Called on startup after ScreamEngine::Initalize is ran.
		virtual bool OnCreate();

		// Called on startup after ScreamEngine::~ScreamEngine is ran.
		virtual bool OnClear();

		// Called on every frame BEFORE renderer is called.
		virtual bool OnUpdate();

		// Called on every frame WHEN renderer is called.
		virtual bool OnDraw();


		// Hardware Interface states.

		// Determin if the Window is focused or not.
		bool IsFocused();
		bool IsFullscreen();
		bool IsVSync();

		int32_t GetMouseX();
		int32_t GetMouseY();

		// Engine Specific.

		uint32_t ScreenWidth();
		uint32_t ScreenHeight();
		uint32_t PixelHeight();
		uint32_t PixelWidth();
		std::string GameDir();
		std::string ModDir();
		std::string AppName();

		float GetDelta();

		bool SetVSync(bool enable = true);

		private:
		
		// Engine specific variables.
		uint32_t m_screenWidth;
		uint32_t m_screenHeight;

		uint32_t m_pixelWidth;
		uint32_t m_pixelHeight;
		
		bool m_fullscreen;
		bool m_vSync;

		std::string m_gameDir;
		std::string m_modDir;

		std::string m_appName;

		float m_delta;
		uint32_t m_frameCount;

		// Hardware specific variables.

		bool m_vsync;
		bool m_focused;
		int32_t m_mouseX;
		int32_t m_mouseY;

		static std::atomic<bool> m_atomActive;

		// Window specific variables

		Display* m_display;
		Window m_window;
		Window m_windowRoot;
		XSetWindowAttributes m_setWindowAttribs;
	};

	class SEX {
		friend class scream::ScreamEngine;
		protected:
		static ScreamEngine* se;
	};

	// Create a global instance for any secondary threads or logic needed outside of the scope of our class.
	std::atomic<bool> ScreamEngine::m_atomActive{ false };
	scream::ScreamEngine* scream::SEX::se = nullptr;
}

#endif
