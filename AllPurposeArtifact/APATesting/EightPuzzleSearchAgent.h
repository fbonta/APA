#ifndef APA_TESTING_EIGHT_PUZZLE_SEARCH_AGENT_H
#define APA_TESTING_EIGHT_PUZZLE_SEARCH_AGENT_H

#include <string>

#include "../AllPurposeArtifact/SearchAgent.h"
#include "EightPuzzleState.h"
#include "EightPuzzleAction.h"

namespace APA_TESTING
{
	class EightPuzzleSearchAgent final : public APA::SearchAgent<EightPuzzleState, EightPuzzleAction, EightPuzzleState>
	{
		std::string search;
	public:
		EightPuzzleSearchAgent()
		{
			search = "bfs";
		}
		explicit EightPuzzleSearchAgent(const std::string& search)
		{
			this->search = search;
		}
		void UpdateState(const EightPuzzleState& percept) override;
		EightPuzzleState FormulateGoal(const EightPuzzleState& initialState) const override;
		std::shared_ptr<APA::Problem<EightPuzzleState, EightPuzzleAction>> FormulateProblem(
			const EightPuzzleState& initialEightPuzzleState, const EightPuzzleState& goalEightPuzzleState) const override;
		std::vector<EightPuzzleAction> Search(
			std::shared_ptr<APA::Problem<EightPuzzleState, EightPuzzleAction>>& eightPuzzleProblem,
			bool& isFailure) const override;
	};
}

#endif
