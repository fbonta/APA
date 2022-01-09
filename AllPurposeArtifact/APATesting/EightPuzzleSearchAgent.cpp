#include "EightPuzzleSearchAgent.h"

#include "../AllPurposeArtifact/BreadthFirstSearch.h"
#include "../AllPurposeArtifact/DepthFirstSearch.h"
#include "../AllPurposeArtifact/IterativeDeepeningSearch.h"
#include "../AllPurposeArtifact/UniformCostSearch.h"
#include "EightPuzzleProblem.h"


void APA_TESTING::EightPuzzleSearchAgent::UpdateState(const EightPuzzleState& percept)
{
	initialState = percept;
}

APA_TESTING::EightPuzzleState APA_TESTING::EightPuzzleSearchAgent::FormulateGoal(const EightPuzzleState&) const
{
	return EightPuzzleState(true);
}

std::shared_ptr<APA::Problem<APA_TESTING::EightPuzzleState, APA_TESTING::EightPuzzleAction>> APA_TESTING::
EightPuzzleSearchAgent::FormulateProblem(const EightPuzzleState& initialEightPuzzleState, const EightPuzzleState& goalEightPuzzleState) const
{
	return std::make_shared<EightPuzzleProblem>(initialEightPuzzleState, goalEightPuzzleState);
}

std::vector<APA_TESTING::EightPuzzleAction> APA_TESTING::EightPuzzleSearchAgent::Search(
	std::shared_ptr<APA::Problem<EightPuzzleState, EightPuzzleAction>>& eightPuzzleProblem, bool& isFailure) const
{
	if (search == "bfs")
	{
		return APA::BreadthFirstSearch<EightPuzzleState, EightPuzzleAction>(eightPuzzleProblem, isFailure);
	}
	if(search == "dfs")
	{
		return APA::DepthFirstSearch<EightPuzzleState, EightPuzzleAction>(eightPuzzleProblem, isFailure);
	}
	if (search == "ids")
	{
		return APA::IterativeDeepeningSearch<EightPuzzleState, EightPuzzleAction>(eightPuzzleProblem, isFailure);
	}

	return APA::UniformCostSearch<EightPuzzleState, EightPuzzleAction>(eightPuzzleProblem, isFailure);
}
