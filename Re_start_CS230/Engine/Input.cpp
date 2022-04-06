#include "Input.h"
#include <doodle/input.hpp>
#include "Engine.h"


CS230::InputKey::InputKey(Keyboard button) : button(button) 
{

}


bool CS230::InputKey::IsKeyDown()const
{

	return Engine::GetInput().IsKeyDown(button);
}

bool CS230::InputKey::IsKeyReleased()const
{
	return Engine::GetInput().IsKeyReleased(button);
}

CS230::Input::Input()
{
	keyDown.resize(static_cast<int>(InputKey::Keyboard::Count));
	wasKeyDown.resize(static_cast<int>(InputKey::Keyboard::Count));
}

void CS230::Input::Update()
{
	wasKeyDown = keyDown;
}


bool CS230::Input::IsKeyDown(InputKey::Keyboard key) const
{
	return keyDown[static_cast<int>(key)];

	
}

bool CS230::Input::IsKeyReleased(InputKey::Keyboard key) const
{
	if (keyDown[static_cast<int>(key)] == false&& wasKeyDown[static_cast<int>(key)] == true)
	{
		return true;
	}
	return false;
}

void CS230::Input::SetKeyDown(InputKey::Keyboard key, bool value)
{
	keyDown[static_cast<int>(key)] = value;
}
