#include "EightPuzzleState.h"

APA_TESTING::EightPuzzleState::EightPuzzleState()
{
	board[0] = 8;
	board[1] = 6;
	board[2] = 7;
	board[3] = 2;
	board[4] = 5;
	board[5] = 4;
	board[6] = 3;
	board[7] = 0;
	board[8] = 1;
	freePosition = 7;
}

APA_TESTING::EightPuzzleState::EightPuzzleState(const bool& isGoal)
{
	if (isGoal)
	{
		board[0] = 1;
		board[1] = 2;
		board[2] = 3;
		board[3] = 4;
		board[4] = 5;
		board[5] = 6;
		board[6] = 7;
		board[7] = 8;
		board[8] = 0;
		freePosition = 8;
	}
	else
	{
		board[0] = 8;
		board[1] = 6;
		board[2] = 7;
		board[3] = 2;
		board[4] = 5;
		board[5] = 4;
		board[6] = 3;
		board[7] = 0;
		board[8] = 1;
		freePosition = 7;
	}
}

APA_TESTING::EightPuzzleState::EightPuzzleState(const std::array<int, 9>& board)
{
	this->freePosition = 0;
	for (size_t i = 0 ; i < board.size() ; ++i)
	{
		this->board[i] = board[i];
		if (0 == board[i])
		{
			this->freePosition = i;
		}
	}
}

std::vector<APA_TESTING::EightPuzzleAction> APA_TESTING::EightPuzzleState::Actions() const
{
	const size_t row = freePosition / 3;
	const size_t column = freePosition % 3;
	std::vector<EightPuzzleAction> actions;

	if (row > 0)
	{
		actions.push_back(EightPuzzleAction::EIGHT_PUZZLE_UP);
	}
	if (row < 2)
	{
		actions.push_back(EightPuzzleAction::EIGHT_PUZZLE_DOWN);
	}
	if (column > 0)
	{
		actions.push_back(EightPuzzleAction::EIGHT_PUZZLE_LEFT);
	}
	if (column < 2)
	{
		actions.push_back(EightPuzzleAction::EIGHT_PUZZLE_RIGHT);
	}

	return actions;

}

APA_TESTING::EightPuzzleState APA_TESTING::EightPuzzleState::ExecuteAction(const EightPuzzleAction& action) const
{
	EightPuzzleState state(board);
	switch (action)
	{
	case EightPuzzleAction::EIGHT_PUZZLE_UP:
		state.board[freePosition] = state.board[freePosition - 3];
		state.board[freePosition - 3] = 0;
		state.freePosition = state.freePosition - 3;
		break;
	case EightPuzzleAction::EIGHT_PUZZLE_DOWN:
		state.board[freePosition] = state.board[freePosition + 3];
		state.board[freePosition + 3] = 0;
		state.freePosition = state.freePosition + 3;
		break;
	case EightPuzzleAction::EIGHT_PUZZLE_LEFT:
		state.board[freePosition] = state.board[freePosition - 1];
		state.board[freePosition - 1] = 0;
		state.freePosition = state.freePosition - 1;
		break;
	case EightPuzzleAction::EIGHT_PUZZLE_RIGHT:
		state.board[freePosition] = state.board[freePosition + 1];
		state.board[freePosition + 1] = 0;
		state.freePosition = state.freePosition + 1;
		break;
	case EightPuzzleAction::EIGHT_PUZZLE_NULL_ACTION:
		break;
	}

	return state;
}

APA_TESTING::EightPuzzleState& APA_TESTING::EightPuzzleState::operator=(const EightPuzzleState& state)
{
	for (size_t i = 0 ; i < board.size() ; ++i)
	{
		board[i] = state.board[i];
	}
	freePosition = state.freePosition;
	return *this;
}

APA_TESTING::EightPuzzleState& APA_TESTING::EightPuzzleState::operator=(EightPuzzleState&& state) noexcept
{
	for (size_t i = 0 ; i < board.size() ; ++i)
	{
		board[i] = state.board[i];
	}
	freePosition = state.freePosition;
	return *this;
}

bool APA_TESTING::EightPuzzleState::operator==(const EightPuzzleState& state) const
{
	for (size_t i = 0 ; i < state.board.size() ; ++i)
	{
		if (board[i] != state.board[i])
		{
			return false;
		}
	}
	return true;
}

APA_TESTING::EightPuzzleState::EightPuzzleState(EightPuzzleState const& state)
{
	for (size_t i = 0; i < board.size(); ++i)
	{
		board[i] = state.board[i];
	}
	freePosition = state.freePosition;
}

APA_TESTING::EightPuzzleState::EightPuzzleState(EightPuzzleState&& state) noexcept
{
	for (size_t i = 0; i < board.size(); ++i)
	{
		board[i] = state.board[i];
	}
	freePosition = state.freePosition;
}

bool APA_TESTING::operator<(const EightPuzzleState& leftState, const EightPuzzleState& rightState)
{
	for (size_t i = 0 ; i < leftState.board.size() ; ++i)
	{
		if (leftState.board[i] < rightState.board[i])
		{
			return true;
		}
		if (leftState.board[i] > rightState.board[i])
		{
			return false;
		}
	}

	return false;
}

std::ostream& APA_TESTING::operator<<(std::ostream& os, const EightPuzzleState& state)
{
	for (size_t i  = 0 ; i < state.board.size() ; ++i)
	{
		os << state.board[i] << " ";
		if (2 == i % 3)
		{
			os << "\n";
		}
	}
	return os;
}
