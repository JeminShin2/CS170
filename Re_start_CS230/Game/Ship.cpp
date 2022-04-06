/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Ship.cpp
Project: CS230
Author: Kevin Wright
Creation date: 2/11/2021
-----------------------------------------------------------------*/
#include "../Engine/Engine.h"	//Engine::GetWindow
#include "Ship.h"

Ship::Ship(math::vec2 pos) : initPosition(pos), velocity({ 0,0 }), moveLeftKey(CS230::InputKey::Keyboard::A), moveRightKey(CS230::InputKey::Keyboard::D),
moveUpKey(CS230::InputKey::Keyboard::W), moveDownKey(CS230::InputKey::Keyboard::S)
{}

void Ship::Load() {
	sprite.Load("assets/Ship.png");
	position = initPosition;
	velocity = { 0,0 };
}

void Ship::Update(double dt) {
	if (moveUpKey.IsKeyDown() == true) {
		velocity.y += accel * dt;
	}
	if (moveDownKey.IsKeyDown() == true) {
		velocity.y -= accel * dt;
	}
	if (moveRightKey.IsKeyDown() == true) {
		velocity.x += accel * dt;
	}
	if (moveLeftKey.IsKeyDown() == true) {
		velocity.x -= accel * dt;
	}

	velocity -= (velocity * Ship::drag * dt);

	Engine::GetLogger().LogDebug("Velocity = " + std::to_string(velocity.x) + "," + std::to_string(velocity.y));

	position += velocity * dt;

	TestForWrap();
}

void Ship::TestForWrap() {
	if (position.y > Engine::GetWindow().GetSize().y + sprite.GetTextureSize().y / 2.0) {
		position.y = 0 - sprite.GetTextureSize().y / 2.0;
	}
	else if (position.y < 0 - sprite.GetTextureSize().y / 2.0) {
		position.y = Engine::GetWindow().GetSize().y + sprite.GetTextureSize().y / 2.0;
	}
	if (position.x > Engine::GetWindow().GetSize().x + sprite.GetTextureSize().x / 2.0) {
		position.x = 0 - sprite.GetTextureSize().x / 2.0;
	}
	else if (position.x < 0 - sprite.GetTextureSize().x / 2.0) {
		position.x = Engine::GetWindow().GetSize().x + sprite.GetTextureSize().x / 2.0;
	}
}

void Ship::Draw() {
	sprite.Draw(position);
}