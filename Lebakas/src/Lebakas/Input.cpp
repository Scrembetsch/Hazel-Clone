#include "Input.h"

namespace Device
{
	void Input::Init()
	{
		for (int i = 0; i < NUM_KEYS; i++)
		{
			mKeyDown[i] = false;
			mKeyPressed[i] = false;
			mKeyReleased[i] = false;
		}
	}

	void Input::KeyPressed(int key)
	{
		++key;
		mKeyPressed[key] = true;
		mKeyDown[key] = true;
		mKeyReleased[key] = false;
	}

	void Input::KeyReleased(int key)
	{
		key++;
		mKeyPressed[key] = false;
		mKeyDown[key] = false;
		mKeyReleased[key] = true;
	}

	void Input::Update()
	{
		for (int i = 0; i < NUM_KEYS; i++)
		{
			mKeyReleased[i] = false;
			mKeyPressed[i] = false;
		}
	}

	bool Input::IsKeyDown(int key)
	{
		return mKeyDown[++key];
	}

	bool Input::WasKeyReleased(int key)
	{
		return mKeyReleased[++key];
	}

	bool Input::WasKeyPressed(int key)
	{
		return mKeyPressed[++key];
	}
}