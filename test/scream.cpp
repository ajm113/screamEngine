#include "lest.hpp" // Our testing framework.

#include "../neo/engine/scream.hpp"
#include "../neo/engine/logger.hpp"

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
	},

	CASE("Testing logger.")
	{
		scream::Logger* l = new scream::Logger();

		EXPECT(l != nullptr);	

		l->Debug("Debug Message");
		l->Message("Message Message");
		l->Warning("Warning message");
		l->Error("Error message");

		delete l;
		l = nullptr;
	}
};

int main(int argc, char* argv[]) {
	return lest::run(specification, argc, argv);
}
