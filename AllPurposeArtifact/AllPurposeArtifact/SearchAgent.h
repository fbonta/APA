#ifndef APA_SEARCH_AGENT_H
#define APA_SEARCH_AGENT_H

#include <vector>
#include <memory>

#include "Agent.h"
#include "Problem.h"

namespace APA
{
	template <typename State, typename Action, typename Percept>
	class SearchAgent : public Agent<Action, Percept>
	{
	public:
		SearchAgent() = default;
		std::vector<Action> sequence;
		State initialState;
		State goalState;
		std::shared_ptr<Problem<State, Action>> problem;
		virtual void UpdateState(const Percept& percept) = 0;
		virtual State FormulateGoal(const State& initialState) const = 0;
		virtual std::shared_ptr<Problem<State, Action>> FormulateProblem(const State& initialState, const State& goalState) const = 0;
		virtual std::vector<Action> Search(std::shared_ptr<Problem<State, Action>>& problem, bool& isFailure) const = 0;

		Action GetAction(const Percept& percept) override
		{
			UpdateState(percept);
			if (sequence.empty())
			{ 
				bool isFailure = false;
				goalState = FormulateGoal(initialState);
				problem = FormulateProblem(initialState, goalState);
				sequence = Search(problem, isFailure);
				if (isFailure)
				{
					return problem->NullAction();
				}
			}
			Action action = sequence.back();
			sequence.pop_back();
			return action;
		}
	};
}

#endif