#ifndef APA_QUEUE_H
#define APA_QUEUE_H

#include <list>
#include <memory>

#include "Node.h"

namespace APA
{
	template <typename State, typename Action>
	class Queue
	{
	private:
		std::list<std::shared_ptr<Node<State, Action>>> data;
	public:
		void Push(const std::shared_ptr<Node<State, Action>>& node)
		{
			data.push_back(node);
		}
		std::shared_ptr<Node<State, Action>> Pop()
		{
			std::shared_ptr<Node<State, Action>> node = data.front();
			data.pop_front();
			return node;
		}
		bool IsEmpty() const
		{
			return data.empty();
		}
		std::shared_ptr<Node<State, Action>> ContainsState(const State& state)
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

