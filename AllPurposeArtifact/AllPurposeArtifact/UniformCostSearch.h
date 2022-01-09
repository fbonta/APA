#ifndef APA_UNIFORM_COST_SEARCH_H
#define APA_UNIFORM_COST_SEARCH_H

#include <vector>
#include <memory>
#include <set>

#include "Problem.h"
#include "Node.h"
#include "PriorityQueue.h"

namespace APA
{
	template <typename State, typename Action>
	std::vector<Action> UniformCostSearch(const std::shared_ptr<Problem<State, Action>>& problem, bool& isFailure)
	{
		isFailure = false;
		std::shared_ptr<Node<State, Action>> node = std::make_shared<Node<State, Action>>(problem);
		PriorityQueue<State, Action> frontier;
		frontier.Push(node, node->pathCost);
		std::set<State> explored;

		while(!frontier.IsEmpty())
		{
			node = frontier.Pop();
			if (problem->IsGoal(node->state))
			{
				return Solution<State, Action>(node);
			}
			explored.insert(node->state);
			for (const Action& action : problem->Actions(node->state))
			{
				std::shared_ptr<Node<State, Action>> child = ChildNode<State, Action>(problem, node, action);
				std::shared_ptr<Node<State, Action>> frontierNode = frontier.ContainsState(child->state);
				if ((0 == explored.count(child->state)) && (nullptr == frontierNode))
				{
					frontier.Push(child, child->pathCost);
				}
				else if (nullptr != frontierNode)
				{
					if (frontierNode->pathCost > child->pathCost)
					{
						frontierNode->pathCost = child->pathCost;
					}
				}

			}
		}

		isFailure = true;
		return std::vector<Action>();
	}
}

#endif
