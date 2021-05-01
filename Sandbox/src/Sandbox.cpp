#include <Lebakas.h>

class Sandbox : public Lebakas::Application
{
public:
	Sandbox()
		: Application()
		, mCircle(30)
		, mMoveSpeed(100)
	{
		mCircle.setPosition(50, 50);
		mRenderer.AddDrawable(&mCircle);
	}

	~Sandbox()
	{
	}

	virtual void Update(float deltaTime)
	{
		sf::Vector2f move(0, 0);
		if(Device::Input::IsKeyDown(Device::Input::Key::A))
		{
			move.x -= deltaTime * mMoveSpeed;
		}
		if (Device::Input::IsKeyDown(Device::Input::Key::D))
		{
			move.x += deltaTime * mMoveSpeed;
		}
		if (Device::Input::IsKeyDown(Device::Input::Key::W))
		{
			move.y -= deltaTime * mMoveSpeed;
		}
		if (Device::Input::IsKeyDown(Device::Input::Key::S))
		{
			move.y += deltaTime * mMoveSpeed;
		}

		mCircle.setPosition(mCircle.getPosition() + move);
	}

	sf::CircleShape mCircle;
	double mMoveSpeed;
};

Lebakas::Application* Lebakas::CreateApplication()
{
	return new Sandbox();
}