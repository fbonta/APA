#include "EnvironmentTesting.h"

#include <cassert>

void APA_TESTING::EnvironmentTesting()
{
	EnvironmentTest environmentTest;
	assert(environmentTest.GetPercept() == 0.0);
	environmentTest.ExecuteAction(1.0);
	assert(environmentTest.GetPercept() == 1.0);
	environmentTest.ExecuteAction(0.0);
	assert(environmentTest.GetPercept() == 0.0);
	environmentTest.ExecuteAction(5.0);
	assert(environmentTest.GetPercept() == 5.0);
	environmentTest.ExecuteAction(2.0);
	assert(environmentTest.GetPercept() == 2.0);
}
