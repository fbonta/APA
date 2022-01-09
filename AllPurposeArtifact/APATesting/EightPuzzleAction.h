#ifndef APA_TESTING_EIGHT_PUZZLE_ACTION_H
#define APA_TESTING_EIGHT_PUZZLE_ACTION_H

#include <iostream>

namespace APA_TESTING
{
	enum class EightPuzzleAction
	{
		EIGHT_PUZZLE_NULL_ACTION,
		EIGHT_PUZZLE_UP,
		EIGHT_PUZZLE_RIGHT,
		EIGHT_PUZZLE_DOWN,
		EIGHT_PUZZLE_LEFT
	};

	std::ostream& operator<<(std::ostream& os, const EightPuzzleAction& action);
}

#endif