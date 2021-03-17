#include <Lebakas.h>

class Sandbox : public Lebakas::Application
{
public:
	Sandbox()
	{
	}

	~Sandbox()
	{
	}
};

Lebakas::Application* Lebakas::CreateApplication()
{
	return new Sandbox();
}