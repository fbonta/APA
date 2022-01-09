#ifndef APA_TESTING_EIGHT_PUZZLE_PROBLEM_H
#define APA_TESTING_EIGHT_PUZZLE_PROBLEM_H

#include "../AllPurposeArtifact/Problem.h"
#include "EightPuzzleState.h"
#include "EightPuzzleAction.h"


namespace APA_TESTING
{
	class EightPuzzleProblem final : public APA::Problem<EightPuzzleState, EightPuzzleAction>
	{
	public:
		EightPuzzleProblem(const EightPuzzleState& initialEightPuzzleState, const EightPuzzleState& goalEightPuzzleState)
			: Problem<EightPuzzleState, EightPuzzleAction>(initialEightPuzzleState, goalEightPuzzleState) {}
		~EightPuzzleProblem() override = default;
		std::vector<EightPuzzleAction> Actions(const EightPuzzleState& state) const override;
		EightPuzzleState Result(const EightPuzzleState& state, const EightPuzzleAction& action) const override;
		bool IsGoal(const EightPuzzleState& state) const override;
		double StepCost(const EightPuzzleState& state, const EightPuzzleAction& action) const override;
		EightPuzzleAction NullAction() const override;

		EightPuzzleProblem(EightPuzzleProblem const&) = delete;
		EightPuzzleProblem& operator =(EightPuzzleProblem const&) = delete;
		EightPuzzleProblem(EightPuzzleProblem&&) = delete;
		EightPuzzleProblem& operator=(EightPuzzleProblem&&) = delete;
	};
}

#endif