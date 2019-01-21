#include "lest.hpp" // Our testing framework.
#include "../neo/engine/scream.hpp"


using namespace std;

const lest::test specification[] = {
	CASE("Initalize scream engine with defaults.")
	{
		scream::ScreamEngine* s = new scream::ScreamEngine();

		EXPECT(s != nullptr);

		// If we know our constructor didn't flop test the defaults.
		EXPECT(s->GetScreenWidth() == scream::DefaultScreenWidth);
		EXPECT(s->GetScreenHeight() == scream::DefaultScreenHeight);
		
		EXPECT(s->GetPixelWidth() == scream::DefaultPixelWidth);
		EXPECT(s->GetPixelHeight() == scream::DefaultPixelHeight);

		EXPECT(s->IsFullscreen() == scream::DefaultFullscreen);

		// Once done delete the pointer,
		delete s;
		s = nullptr;
	}
};

int main(int argc, char* argv[]) {
	return lest::run(specification, argc, argv);
}
