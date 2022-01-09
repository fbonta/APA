#ifndef APA_ITERATIVE_DEEPENING_SEARCH_H
#define APA_ITERATIVE_DEEPENING_SEARCH_H

#include <vector>
#include <memory>

#include "Problem.h"
#include "Node.h"

namespace APA
{
	template <typename State, typename Action>
	std::vector<Action> RecursiveDepthLimitedSearch
	(
		const std::shared_ptr<Node<State, Action>>& node,
		const std::shared_ptr<Problem<State, Action>>& problem, 
		const int64_t& limit,
		bool& isFailure,
		bool& isCutoff,
		std::set<State> explored)
	{
		if (problem->IsGoal(node->state))
		{
			return Solution<State, Action>(node);
		}
		if (0 == limit)
		{
			isCutoff = true;
			return std::vector<Action>();
		}
		bool cutoffOccurred = false;
		for (const Action& action : problem->Actions(node->state))
		{
			std::shared_ptr<Node<State, Action>> child = ChildNode(problem, node, action);
			if (0 == explored.count(child->state))
			{
				bool cutoff = false;
				bool failure = false;
				explored.insert(child->state);
				std::vector<Action> result = RecursiveDepthLimitedSearch(child, problem, limit - 1, failure, cutoff, explored);
				explored.erase(child->state);
				if (cutoff)
				{
					cutoffOccurred = true;
				}
				else if (!failure)
				{
					return result;
				}
			}
		}
		if (cutoffOccurred)
		{
			isCutoff = true;
			return std::vector<Action>();
		}
		isFailure = true;
		return std::vector<Action>();
	}

	template <typename State, typename Action>
	std::vector<Action> DepthLimitedSearch(const std::shared_ptr<Problem<State, Action>>& problem, const int64_t& limit, bool& isFailure, bool& isCutoff)
	{
		return RecursiveDepthLimitedSearch(std::make_shared<Node<State, Action>>(problem), problem, limit, isFailure, isCutoff, std::set<State>());
	}

	template <typename State, typename Action>
	std::vector<Action> IterativeDeepeningSearch(const std::shared_ptr<Problem<State, Action>>& problem, bool& isFailure)
	{
		for (int64_t depth = 30; depth < INT64_MAX ; ++depth)
		{
			bool isCutoff = false;
			std::vector<Action> result = DepthLimitedSearch(problem, depth, isFailure, isCutoff);
			if (!isCutoff)
			{
				return result;
			}
		}
		isFailure = true;
		return std::vector<Action>();
	}

}

#endif
