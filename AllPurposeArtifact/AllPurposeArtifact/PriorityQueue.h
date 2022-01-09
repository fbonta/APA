   #ifndef APA_PRIORITY_QUEUE_H
#define APA_PRIORITY_QUEUE_H

#include <vector>
#include <memory>

#include "Node.h"

namespace APA
{
	template<typename State, typename Action>
	class PriorityQueue
	{
	private:
		std::vector<std::shared_ptr<Node<State, Action>>> data;
		std::vector<double> priorities;
		size_t SearchPosition(const double& priority)
		{
			if (data.empty())
			{
				return 0;
			}
			size_t start = 0;
			size_t end = priorities.size();
			while(start < end)
			{
				const size_t middle = (start + end) / 2;
				if (priority > priorities[middle])
				{
					start = middle + 1;
				}
				else
				{
					end = middle;
				}
			}
			return start;
		}
	public:
		void Push(const std::shared_ptr<Node<State, Action>>& node, const double& priority)
		{
			int position = static_cast<int>(SearchPosition(priority));
			data.insert(data.begin() + position, node);
			priorities.insert(priorities.begin() + position, priority);
		}
		std::shared_ptr<Node<State, Action>> Pop()
		{
			std::shared_ptr<Node<State, Action>> node = data.back();
			data.pop_back();
			priorities.pop_back();
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
