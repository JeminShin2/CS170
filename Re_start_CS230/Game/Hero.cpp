/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Hero.cpp
Project: CS230
Author: Kevin Wright
Creation date: 2/11/2021
-----------------------------------------------------------------*/
#include "../Engine/Engine.h"	//GetLogger
#include "Mode1.h"
#include "Hero.h"


Hero::Hero(math::vec2 startPos, const CS230::Camera& camera) : startPos(startPos), camera(&camera),
isJumping(false), isRising(false), jumpKey(CS230::InputKey::Keyboard::Up), velocity{ 0,0 },
moveLeftKey(CS230::InputKey::Keyboard::Left), moveRightKey(CS230::InputKey::Keyboard::Right) {
}

void Hero::Load() {
	sprite.Load("assets/Hero.png", { 56, 14 });
	position = startPos;
	isJumping = false;
	isRising = false;
	velocity = { 0,0 };
}

void Hero::Update(double dt) {
	double xDragDt = Hero::xDrag * dt;
	if (moveRightKey.IsKeyDown() == true) {
		if (velocity.x >= 0) {
			velocity.x += Hero::xAccel * dt;
			if (velocity.x > Hero::maxXVelocity) {
				velocity.x = Hero::maxXVelocity;
				Engine::GetLogger().LogDebug("+Max Velocity");
			}
			else {
				Engine::GetLogger().LogDebug("+Accelerating");
			}
		}
		else {
			velocity.x += xDragDt * 2;
			Engine::GetLogger().LogDebug("+Skidding");
		}
	}
	else if (moveLeftKey.IsKeyDown() == true) {
		if (velocity.x <= 0) {
			velocity.x -= Hero::xAccel * dt;
			if (velocity.x < -Hero::maxXVelocity) {
				velocity.x = -Hero::maxXVelocity;
				Engine::GetLogger().LogDebug("-Max Velocity");
			}
			else {
				Engine::GetLogger().LogDebug("-Accelerating");
			}
		}
		else {
			Engine::GetLogger().LogDebug("-Skidding");
			velocity.x -= xDragDt * 2;
		}
	}
	else {
		if (velocity.x > xDragDt) {
			Engine::GetLogger().LogDebug("-Dragging");
			velocity.x -= xDragDt;
		}
		else if (velocity.x < -xDragDt) {
			Engine::GetLogger().LogDebug("+Dragging");
			velocity.x += xDragDt;
		}
		else {
			if (velocity.x != 0) {
				Engine::GetLogger().LogDebug("Stopped");
			}
			velocity.x = 0;
		}
	}
	if (isJumping == true) {
		velocity.y -= Mode1::gravity * dt;
		if (isRising == true && jumpKey.IsKeyReleased() == true) {
			Engine::GetLogger().LogDebug("Top of jump (Early) - YPos: " + std::to_string(position.y));
			velocity.y = 0;
			isRising = false;
		}

		if (isRising == true && velocity.y <= 0) {
			Engine::GetLogger().LogDebug("Top of jump - YPos: " + std::to_string(position.y));
			isRising = false;
		}
	}
	if (jumpKey.IsKeyDown() == true && position.y == Mode1::floor) {
		velocity.y = Hero::jumpVelocity;
		isJumping = true;
		isRising = true;
		Engine::GetLogger().LogDebug("Starting Jump - YPos: " + std::to_string(position.y));
	}

	position += velocity * dt;

	if (isJumping == true && position.y < Mode1::floor) {
		velocity.y = 0;
		position.y = Mode1::floor;
		isJumping = false;
		Engine::GetLogger().LogDebug("Ending Jump - YPos: " + std::to_string(position.y));
	}
}

void Hero::Draw() {
	sprite.Draw(position);
}