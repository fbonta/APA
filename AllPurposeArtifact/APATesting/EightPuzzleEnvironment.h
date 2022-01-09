#ifndef APA_TESTING_EIGHT_PUZZLE_ENVIRONMENT_H
#define APA_TESTING_EIGHT_PUZZLE_ENVIRONMENT_H

#include "../AllPurposeArtifact/Environment.h"
#include "EightPuzzleAction.h"
#include "EightPuzzleState.h"

namespace APA_TESTING
{
	class EightPuzzleEnvironment final : public APA::Environment<EightPuzzleAction, EightPuzzleState>
	{
	private:
		EightPuzzleState state;
	public:
		EightPuzzleState GetPercept() const override;
		void ExecuteAction(const EightPuzzleAction& action) override;
	};
}

#endif