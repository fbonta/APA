#include "EightPuzzleAction.h"

std::ostream& APA_TESTING::operator<<(std::ostream& os, const EightPuzzleAction& action)
{
	switch (action)
	{
	case EightPuzzleAction::EIGHT_PUZZLE_UP:
		os << "UP\n";
		break;
	case EightPuzzleAction::EIGHT_PUZZLE_RIGHT:
		os << "RIGHT\n";
		break;
	case EightPuzzleAction::EIGHT_PUZZLE_DOWN:
		os << "DOWN\n";
		break;
	case EightPuzzleAction::EIGHT_PUZZLE_LEFT:
		os << "LEFT\n";
		break;
	case EightPuzzleAction::EIGHT_PUZZLE_NULL_ACTION:
		os << "NULL_ACTION\n";
	}

	return os;
}
