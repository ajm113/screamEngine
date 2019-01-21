#include "lest.hpp" // Our testing framework.
#include "../neo/engine/scream.hpp"


using namespace std;

const lest::test specification[] = {
	CASE("Initalize scream engine with defaults.")
	{
		scream::ScreamEngine* s = new scream::ScreamEngine();

		EXPECT(s != nullptr);
		EXPECT(s->GetScreenWidth() == scream::DefaultScreenWidth);
	}
};

int main(int argc, char* argv[]) {
	return lest::run(specification, argc, argv);
}
