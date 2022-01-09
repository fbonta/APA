#ifndef APA_ENVIRONMENT_H
#define APA_ENVIRONMENT_H

namespace APA
{
	template <typename Action, typename Percept>
	class Environment
	{
	public:
		Environment() = default;
		virtual Percept GetPercept() const = 0;
		virtual void ExecuteAction(const Action& action) = 0;
		virtual ~Environment() = default;

		Environment(Environment const&) = delete;
		Environment& operator =(Environment const&) = delete;
		Environment(Environment&&) = delete;
		Environment& operator=(Environment&&) = delete;
	};
}

#endif
