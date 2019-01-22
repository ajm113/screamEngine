#include "scream.hpp"


scream::ScreamEngine::ScreamEngine(
	std::string appName,
	uint32_t screenWidth, 
	uint32_t screenHeight, 
	uint32_t pixelWidth, 
	uint32_t pixelHeight,
	bool fullscreen,
	const std::string & gameDir,
	const std::string & modDir
) {
	m_appName = appName;

	m_screenWidth = screenWidth;
	m_screenHeight = screenHeight;
	m_pixelWidth = pixelWidth;
	m_pixelHeight = pixelHeight;
	m_fullscreen = fullscreen;
	m_gameDir = gameDir;
	m_modDir = modDir;

	m_logger = new Logger();
	m_logger->Debug("ScreamEngine starting...");
	
	m_window = new scream::ScreamWindow();
}

scream::ScreamEngine::~ScreamEngine() {
	m_logger->Message("ScreamEngine closing...");
	m_window->Destroy();
	
	delete m_window;
	m_window =nullptr;

	OnClear();

	m_logger->Debug("ScreamEngine successfully closed.");
	delete m_logger;
	m_logger = nullptr;
}

bool scream::ScreamEngine::Initalize() {
	m_logger->Message("ScreamEngine initalized!");
	return true;
}

bool scream::ScreamEngine::Start() {
	m_logger->Debug("Screamengine Start() called.");
	
	return m_window->Create(
			m_appName, 
			m_screenWidth*m_pixelWidth,
			m_screenHeight*m_pixelHeight,
			m_fullscreen
		);
}

// Called on startup after ScreamEngine::Initalize is ran.
bool scream::ScreamEngine::OnCreate() {
	return true;
}

// Called on startup after ScreamEngine::~ScreamEngine is ran.
bool scream::ScreamEngine::OnClear() {
	return true;
}

// Called on every frame BEFORE renderer is called.
bool scream::ScreamEngine::OnUpdate() {
	return true;
}

// Called on every frame WHEN renderer is called.
bool scream::ScreamEngine::OnDraw() {
	return true;
}

// Determin if the Window is focused or not.
bool scream::ScreamEngine::IsFocused() {
	return m_focused;
}

bool scream::ScreamEngine::IsFullscreen() {
	return m_fullscreen;
}

bool scream::ScreamEngine::IsVSync() {
	return m_vsync;
}

int32_t scream::ScreamEngine::GetMouseX() {
	return m_mouseX;
}

int32_t scream::ScreamEngine::GetMouseY() {
	return m_mouseY;
}


// Engine Specific.

uint32_t scream::ScreamEngine::GetScreenWidth() {
	return m_screenWidth;
}

uint32_t scream::ScreamEngine::GetScreenHeight() {
	return m_screenHeight;
}

uint32_t scream::ScreamEngine::GetPixelHeight() {
	return m_pixelHeight;
}

uint32_t scream::ScreamEngine::GetPixelWidth() {
	return m_pixelWidth;
}

std::string scream::ScreamEngine::GetGameDir() {
	return m_gameDir;
}

std::string scream::ScreamEngine::GetModDir() {
	return m_modDir;
}

std::string scream::ScreamEngine::GetAppName() {
	return m_appName;
}


float scream::ScreamEngine::GetDelta() {
	return m_delta;
}


bool scream::ScreamEngine::SetVSync(bool) {
	return true;
}

std::atomic<bool> scream::ScreamEngine::m_atomActive { false };
scream::ScreamEngine* scream::SEX::se = nullptr;


