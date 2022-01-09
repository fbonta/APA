#ifndef APA_STACK_H
#define APA_STACK_H

#include <vector>
#include <memory>

#include "Node.h"

namespace APA
{
	template <typename State, typename Action>
	class Stack
	{
	private:
		std::vector<std::shared_ptr<Node<State, Action>>> data;
	public:
		void Push(const std::shared_ptr<Node<State, Action>>& node)
		{
			data.push_back(node);
		}
		std::shared_ptr<Node<State, Action>> Pop()
		{
			std::shared_ptr<Node<State, Action>> node = data.back();
			data.pop_back();
			return node;
		}
		bool IsEmpty() const
		{
			return data.empty();
		}
		std::shared_ptr<Node<State, Action>> ContainsState(const State& state) const
		{
			for (const std::shared_ptr<Node<State, Action>>& node : data)
			{
				if (node->state == state)
				{
					return node;
				}
			}
			return nullptr;
		}
	};
}

#endif
