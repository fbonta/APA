#ifndef APA_ENVIRONMENT_TESTING_H
#define APA_ENVIRONMENT_TESTING_H


#include "../AllPurposeArtifact/Environment.h"

namespace APA_TESTING
{
	class EnvironmentTest final : public APA::Environment<double, double>
	{
	private:
		double percept;
	public:
		EnvironmentTest() : Environment<double, double>()
		{
			percept = 0.0;
		}
		double GetPercept() const override
		{
			return percept;
		}
		void ExecuteAction(const double& action) override
		{
			percept = action;
		}

		~EnvironmentTest() override = default;
		EnvironmentTest(EnvironmentTest const&) = delete;
		EnvironmentTest& operator =(EnvironmentTest const&) = delete;
		EnvironmentTest(EnvironmentTest&&) = delete;
		EnvironmentTest& operator=(EnvironmentTest&&) = delete;
	};

	void EnvironmentTesting();
}

#endif