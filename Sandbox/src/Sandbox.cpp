#include <Lebakas.h>
#include "Lebakas/Time.h"

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

	virtual void Update(double deltaTime)
	{
		LEBAKAS_INFO(deltaTime);
		sf::Vector2f newPos = mCircle.getPosition();
		if(Device::Input::IsKeyDown(Device::Input::Key::A))
		{
			newPos.x -= deltaTime * mMoveSpeed;
		}
		if (Device::Input::IsKeyDown(Device::Input::Key::D))
		{
			newPos.x += deltaTime * mMoveSpeed;
		}
		if (Device::Input::IsKeyDown(Device::Input::Key::W))
		{
			newPos.y -= deltaTime * mMoveSpeed;
		}
		if (Device::Input::IsKeyDown(Device::Input::Key::S))
		{
			newPos.y += deltaTime * mMoveSpeed;
		}

		if (Device::Input::WasKeyPressed(Device::Input::Key::Up))
		{
			Time::SetFixedFps(Time::GetFixedFps() + 5);
		}
		else if (Device::Input::WasKeyPressed(Device::Input::Key::Down))
		{
			if (Time::GetFixedFps() >= 6)
			{
				Time::SetFixedFps(Time::GetFixedFps() - 5);
			}
		}

		newPos.x = std::clamp(newPos.x, 0.0f, mRenderer.GetWindowWidth() - mCircle.getRadius() * 2);
		newPos.y = std::clamp(newPos.y, 0.0f, mRenderer.GetWindowHeight() - mCircle.getRadius() * 2);
		mCircle.setPosition(newPos);
	}

	sf::CircleShape mCircle;
	double mMoveSpeed;
};

Lebakas::Application* Lebakas::CreateApplication()
{
	return new Sandbox();
}