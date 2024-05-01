#include <SoftwareBuilder.h>

class Sandbox : public SoftwareBuilder::Application
{
public:
	Sandbox() {

	}
	~Sandbox() {

	}
};

SoftwareBuilder::Application* SoftwareBuilder::CreateApplication()
{
	return new Sandbox();
}