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
}

scream::ScreamEngine::~ScreamEngine() {
	OnClear();
}

bool scream::ScreamEngine::Initalize() {
	return true;
}

bool scream::ScreamEngine::Start() {
	return true;
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


bool scream::ScreamEngine::SetVSync(bool enable) {
	return true;
}

std::atomic<bool> scream::ScreamEngine::m_atomActive { false };
scream::ScreamEngine* scream::SEX::se = nullptr;


