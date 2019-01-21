#include "scream.hpp"

int main() {
	scream::ScreamEngine* engine = new scream::ScreamEngine();

	if(engine == nullptr) {
		return 1;
	}

	if(!engine->Initalize()) {
		return 1;
	}

	return engine->Start() ? 0 : 1;
}
