#include "scream.hpp"

int main() {
	scream::ScreamEngine* engine = new scream::ScreamEngine();

	if(engine == nullptr) {
		return 1;
	}

	if(!engine->Initalize()) {
		return 1;
	}

	uint32_t rcode = engine->Start() ? 0 : 1;

	delete engine;
	engine = nullptr;

	return rcode;
}
