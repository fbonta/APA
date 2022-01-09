#include "EightPuzzleProblem.h"

std::vector<APA_TESTING::EightPuzzleAction> APA_TESTING::EightPuzzleProblem::Actions(
	const EightPuzzleState& state) const
{
	return state.Actions();
}

APA_TESTING::EightPuzzleState APA_TESTING::EightPuzzleProblem::Result(const EightPuzzleState& state, const EightPuzzleAction& action) const
{
	return state.ExecuteAction(action);
}

bool APA_TESTING::EightPuzzleProblem::IsGoal(const EightPuzzleState& state) const
{
	return state == goalState;
}

double APA_TESTING::EightPuzzleProblem::StepCost(const EightPuzzleState&, const EightPuzzleAction&) const
{
	return 1.0;
}

APA_TESTING::EightPuzzleAction APA_TESTING::EightPuzzleProblem::NullAction() const
{
	return EightPuzzleAction::EIGHT_PUZZLE_NULL_ACTION;
}
