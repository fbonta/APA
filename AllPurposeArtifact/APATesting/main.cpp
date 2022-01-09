#include "AgentTesting.h"
#include "EnvironmentTesting.h"
#include "EightPuzzleTesting.h"

void RunTests()
{
	APA_TESTING::AgentTesting();
	APA_TESTING::EnvironmentTesting();
	APA_TESTING::EightPuzzleTesting();
}

int main()
{
	RunTests();
	return 0;
}