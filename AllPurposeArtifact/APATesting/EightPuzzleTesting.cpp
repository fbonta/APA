#include "EightPuzzleTesting.h"


#include "EightPuzzleEnvironment.h"
#include "EightPuzzleSearchAgent.h"

void APA_TESTING::EightPuzzleTesting()
{
	EightPuzzleEnvironment environment;
	EightPuzzleSearchAgent agent("ids");
	EightPuzzleAction action = EightPuzzleAction::EIGHT_PUZZLE_UP;

	while (EightPuzzleAction::EIGHT_PUZZLE_NULL_ACTION != action)
	{
		action = agent.GetAction(environment.GetPercept());
		environment.ExecuteAction(action);
	}
}
