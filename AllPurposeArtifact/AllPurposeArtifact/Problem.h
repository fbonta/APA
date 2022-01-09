#ifndef APA_PROBLEM_H
#define APA_PROBLEM_H

#include <vector>

namespace APA
{
	template <typename State, typename Action>
	class Problem
	{
	public:
		Problem(const State& initialState, const State& goalState)
		{
			this->initialState = initialState;
			this->goalState = goalState;
		}
		State initialState;
		State goalState;
		virtual std::vector<Action> Actions(const State& state) const = 0;
		virtual State Result(const State& state, const Action& action) const = 0;
		virtual bool IsGoal(const State& state) const = 0;
		virtual double StepCost(const State& state, const Action& action) const = 0;
		virtual Action NullAction() const = 0;
		virtual ~Problem() = default;

		Problem(Problem const&) = delete;
		Problem& operator =(Problem const&) = delete;
		Problem(Problem&&) = delete;
		Problem& operator=(Problem&&) = delete;
	};
}

#endif

