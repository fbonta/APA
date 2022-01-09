#ifndef APA_TESTING_EIGHT_PUZZLE_STATE_H
#define APA_TESTING_EIGHT_PUZZLE_STATE_H

#include <array>
#include <vector>
#include <iostream>

#include "EightPuzzleAction.h"

namespace APA_TESTING
{
	class EightPuzzleState
	{
	private:
		std::array<int, 9> board = std::array<int, 9>();
		size_t freePosition;
	public:
		EightPuzzleState();
		~EightPuzzleState() = default;
		explicit EightPuzzleState(const bool& isGoal);
		explicit EightPuzzleState(const std::array<int, 9>& board);
		std::vector<EightPuzzleAction> Actions() const;
		EightPuzzleState ExecuteAction(const EightPuzzleAction& action) const;
		bool operator==(const EightPuzzleState& state) const;
		EightPuzzleState(EightPuzzleState const& state);
		EightPuzzleState(EightPuzzleState&& state) noexcept;
		EightPuzzleState& operator=(const EightPuzzleState& state);
		EightPuzzleState& operator=(EightPuzzleState&& state) noexcept;
		friend bool operator<(const EightPuzzleState& leftState, const EightPuzzleState& rightState);
		friend std::ostream& operator<<(std::ostream& os, const EightPuzzleState& state);
		
	};
}


#endif

