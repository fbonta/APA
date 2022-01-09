#ifndef APA_AGENT_TESTING_H
#define APA_AGENT_TESTING_H

#include "../AllPurposeArtifact/Agent.h"

namespace APA_TESTING
{
	class AgentTest final : public APA::Agent<double, double>
	{
	public:
		AgentTest() : Agent<double, double>()
		{
			
		}
		double GetAction(const double& percept) override
		{
			return percept + 1;
		}

		~AgentTest() override = default;
		AgentTest(AgentTest const&) = delete;
		AgentTest& operator =(AgentTest const&) = delete;
		AgentTest(AgentTest&&) = delete;
		AgentTest& operator=(AgentTest&&) = delete;
	};

	void AgentTesting();
}

#endif


