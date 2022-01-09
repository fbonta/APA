#ifndef APA_AGENT_H
#define APA_AGENT_H

namespace APA
{
	template <typename Action, typename Percept>
	class Agent
	{
	public:
		Agent() = default;
		virtual Action GetAction(const Percept& percept) = 0;
		virtual ~Agent() = default;

		Agent(Agent const&) = default;
		Agent& operator =(Agent const&) = delete;
		Agent(Agent&&) = delete;
		Agent& operator=(Agent&&) = delete;
	};
}

#endif