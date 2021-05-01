#include <Lebakas.h>
#include "Lebakas/Time.h"
#include "Entity.h"
#include "CircleEntityGenerator.h"
#include "StatsEntity.h"

class Sandbox : public Lebakas::Application
{
public:
	Sandbox()
		: Application()
	{
		unsigned int entities = 1000;
		mBounds = sf::Rect<float>(0.0f, 0.0f, mRenderer.GetWindowWidth(), mRenderer.GetWindowHeight());
		for (unsigned int i = 0; i < entities; ++i)
		{
			mEntities.emplace_back(CircleEntityGenerator::generateInBounds(mBounds));
		}

		for (auto it = mEntities.begin(); it != mEntities.end(); it++)
		{
			mRenderer.AddDrawable(&((*it)->mShape));
		}
		mRenderer.AddDrawable(&(mStats.Stats));
	}

	~Sandbox()
	{
	}

	virtual void Update(double deltaTime)
	{
		//LEBAKAS_INFO(deltaTime);
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
		for (auto entity : mEntities)
		{
			entity->update(deltaTime);
		}
		mStats.update(deltaTime);
	}

	sf::Rect<float> mBounds;
	std::vector<MovingCircleEntity*> mEntities;
	StatsEntity mStats;
};

Lebakas::Application* Lebakas::CreateApplication()
{
	return new Sandbox();
}