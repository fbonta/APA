#include "AgentTesting.h"

#include <cassert>

void APA_TESTING::AgentTesting()
{
	AgentTest agentTest;

	assert(agentTest.GetAction(2.0) == 3.0);
	assert(agentTest.GetAction(1.0) == 2.0);
	assert(agentTest.GetAction(3.0) == 4.0);
	assert(agentTest.GetAction(4.0) == 5.0);
	assert(agentTest.GetAction(-1.0) == 0.0);
	assert(agentTest.GetAction(5.0) == 6.0);
}