#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <X11/X.h>
#include <X11/Xlib.h>
#include <GL/gl.h>
#include <GL/glx.h>

#include "../baseWindow.hpp"


namespace scream {

	class ScreamWindow : public BaseWindow {
		public:
		bool Create(const std::string & title, const uint32_t width, const uint32_t height, const bool fullscreen = false);
		bool Destroy();

		ButtonState GetMouse(uint32_t b);
		int32_t GetMouseX();
		int32_t GetMouseY();
		ButtonState GetKey(KeyCode c);

		private:
		Display*	m_display;
		Window		m_window;
		Window 	 	m_windowRoot;
		XVisualInfo*	m_visualInfo;
		Colormap	m_colorMap;
		XSetWindowAttributes m_setWindowAttributes;
	};
}



#endif
