#ifndef APA_BREADTH_FIRST_SEARCH_H
#define APA_BREADTH_FIRST_SEARCH_H

#include <vector>
#include <memory>
#include <set>

#include "Problem.h"
#include "Node.h"
#include "Queue.h"

namespace APA
{
	template <typename State, typename Action>
	std::vector<Action> BreadthFirstSearch(const std::shared_ptr<Problem<State, Action>>& problem, bool& isFailure)
	{
		isFailure = false;
		std::shared_ptr<Node<State, Action>> node = std::make_shared<Node<State, Action>>(problem);
		Queue<State, Action> frontier;
		frontier.Push(node);
		std::set<State> explored;
		explored.insert(node->state);

		if (problem->IsGoal(node->state))
		{
			return Solution<State, Action>(node);
		}

		while(!frontier.IsEmpty())
		{
			node = frontier.Pop();
			for (const Action& action : problem->Actions(node->state))
			{
				std::shared_ptr<Node<State, Action>> child = ChildNode<State, Action>(problem, node, action);
				if (0 == explored.count(child->state))
				{
					if (problem->IsGoal(child->state))
					{
						return Solution<State, Action>(child);
					}
					frontier.Push(child);
					explored.insert(child->state);
				}
			}
		}

		isFailure = true;
		return std::vector<Action>();
	}
}

#endif

