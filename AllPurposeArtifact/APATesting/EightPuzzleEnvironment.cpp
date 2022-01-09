#include "EightPuzzleEnvironment.h"

#include <iostream>

APA_TESTING::EightPuzzleState APA_TESTING::EightPuzzleEnvironment::GetPercept() const
{
	return state;
}

void APA_TESTING::EightPuzzleEnvironment::ExecuteAction(const EightPuzzleAction& action)
{
	state = state.ExecuteAction(action);
	if (EightPuzzleAction::EIGHT_PUZZLE_NULL_ACTION != action)
	{
		std::cout << action;
		std::cout << state;
	}
}
