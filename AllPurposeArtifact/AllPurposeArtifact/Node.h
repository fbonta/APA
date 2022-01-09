#ifndef APA_NODE_H
#define APA_NODE_H

#include <memory>

#include "Problem.h"

namespace APA
{
	template <typename State, typename Action>
	class Node
	{
	public:
		State state;
		std::shared_ptr<Node<State, Action>> parent;
		Action action;
		double pathCost;
		explicit Node(const std::shared_ptr<Problem<State, Action>>& problem) : state(problem->initialState),
			parent(nullptr), action(problem->NullAction()), pathCost(0.0)
		{
		}
		Node(const State& state, const std::shared_ptr<Node<State, Action>>& parent, const Action& action, double pathCost)
		{
			this->state = state;
			this->parent = parent;
			this->action = action;
			this->pathCost = pathCost;
		}
	};

	template <typename State, typename Action>
	std::shared_ptr<Node<State, Action>> ChildNode
	(
		const std::shared_ptr<Problem<State, Action>>& problem, 
		const std::shared_ptr<Node<State, Action>>& parent, 
		const Action& action
	)
	{
		return std::make_shared<Node<State, Action>>
		(
			problem->Result(parent->state, action),
			parent,
			action,
			parent->pathCost + problem->StepCost(parent->state, action));
	}


	template <typename State, typename Action>
	std::vector<Action> Solution(const std::shared_ptr<Node<State, Action>>& node)
	{
		std::vector<Action> solution;
		std::shared_ptr<Node<State, Action>> currentNode = node;

		while(nullptr != currentNode)
		{
			solution.push_back(currentNode->action);
			currentNode = currentNode->parent;
		}

		if (1 < solution.size())
		{
			solution.pop_back();
		}
		return solution;
	}

}

#endif

