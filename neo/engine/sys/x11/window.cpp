#include "window.hpp"


bool scream::ScreamWindow::Create(const std::string & title, const uint32_t width, const uint32_t height, const bool) {
	XInitThreads();

	// Create the display and window.
	m_display = XOpenDisplay(NULL);
	m_windowRoot = DefaultRootWindow(m_display);

	GLint glDisplayAttributes[] = { GLX_RGBA, GLX_DEPTH_SIZE, 24, GLX_DOUBLEBUFFER, None };
	m_visualInfo = glXChooseVisual(m_display, 0, glDisplayAttributes);
	m_colorMap = XCreateColormap(m_display, m_windowRoot, m_visualInfo->visual, AllocNone);
	m_setWindowAttributes.colormap = m_colorMap;

	m_setWindowAttributes.event_mask = ExposureMask | KeyPressMask | KeyReleaseMask | ButtonPressMask | ButtonReleaseMask | PointerMotionMask | FocusChangeMask;

	// Now create the window we want.
	m_window = XCreateWindow(
		m_display, 
		m_windowRoot, 
		30, 
		30, 
		width, 
		height, 
		0, 
		m_visualInfo->depth, 
		InputOutput, 
		m_visualInfo->visual, 
		CWColormap | CWEventMask, 
		&m_setWindowAttributes
	);

	Atom wmDelete = XInternAtom(m_display, "WM_DELETE_WINDOW", true);
	XSetWMProtocols(m_display, m_window, &wmDelete, 1);

	XMapWindow(m_display, m_window);
	XStoreName(m_display, m_window, title.c_str());

	return true;
}

bool scream::ScreamWindow::Destroy() {
	XDestroyWindow(m_display, m_window);
	XCloseDisplay(m_display);
	return true;
}


scream::ButtonState scream::ScreamWindow::GetMouse(uint32_t) {
	scream::ButtonState s;

	return s;
}

int32_t scream::ScreamWindow::GetMouseX() {
	return 0;
}

int32_t scream::ScreamWindow::GetMouseY() {
	return 0;
}

scream::ButtonState scream::ScreamWindow::GetKey(scream::KeyCode) {
	scream::ButtonState s;

	return s;
}

