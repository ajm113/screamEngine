#include "scream.hpp"

scream::ScreamEngine::ScreamEngine() {
	ScreamEngine(
		scream::DefaultAppName,
		scream::DefaultScreenWidth, 
		scream::DefaultScreenHeight, 
		scream::DefaultPixelWidth, 
		scream::DefaultPixelHeight,
		scream::DefaultFullscreen,
		scream::DefaultGameDir,
		scream::DefaultModDir
	);

}
scream::ScreamEngine::ScreamEngine(
	std::string appName, 
	uint32_t screenWidth, 
	uint32_t screenHeight, 
	uint32_t pixelWidth, 
	uint32_t pixelHeight, 
	bool fullscreen
) {
	ScreamEngine(
		appName,
		screenWidth, 
		screenHeight, 
		pixelWidth, 
		pixelHeight,
		fullscreen,
		scream::DefaultGameDir,
		scream::DefaultModDir
	);
}

scream::ScreamEngine::ScreamEngine(
	std::string appName,
	uint32_t screenWidth, 
	uint32_t screenHeight, 
	uint32_t pixelWidth, 
	uint32_t pixelHeight,
	bool fullscreen,
	const std::string & gameDir
) {
	ScreamEngine(
		appName,
		screenWidth, 
		screenHeight, 
		pixelWidth, 
		pixelHeight,
		fullscreen,
		gameDir,
		scream::DefaultModDir
	);
}

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
const bool scream::ScreamEngine::IsFocused() {
	return m_focused;
}

const bool scream::ScreamEngine::IsFullscreen() {
	return m_fullscreen;
}

const bool scream::ScreamEngine::IsVSync() {
	return m_vsync;
}

const int32_t scream::ScreamEngine::GetMouseX() {
	return m_mouseX;
}

const int32_t scream::ScreamEngine::GetMouseY() {
	return m_mouseY;
}


// Engine Specific.

const uint32_t scream::ScreamEngine::ScreenWidth() {
	return m_screenWidth;
}

const uint32_t scream::ScreamEngine::ScreenHeight() {
	return m_screenHeight;
}

const uint32_t scream::ScreamEngine::PixelHeight() {
	return m_pixelHeight;
}

const uint32_t scream::ScreamEngine::PixelWidth() {
	return m_pixelWidth;
}

const std::string scream::ScreamEngine::GameDir() {
	return m_gameDir;
}

const std::string scream::ScreamEngine::ModDir() {
	return m_modDir;
}

const std::string scream::ScreamEngine::AppName() {
	return m_appName;
}


const float scream::ScreamEngine::GetDelta() {
	return m_delta;
}


const bool scream::ScreamEngine::SetVSync(bool enable) {
	return true;
}


int main() {

	scream::ScreamEngine* engine = new scream::ScreamEngine();

	if(!engine->Initalize()) {
		return 1;
	}


	return engine->Start() ? 0 : 1;
}
