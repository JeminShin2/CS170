/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Ball.cpp
Project: CS230
Author: Kevin Wright
Creation date: 2/14/2021
-----------------------------------------------------------------*/
#include "Mode1.h"	//Level1::gravity
#include "Ball.h"

Ball::Ball(math::vec2 startPos) : initPosition(startPos), velocity({ 0,0 }) {}

void Ball::Load() {
	sprite.Load("assets/Ball.png", { 43, 0 });
	position = initPosition;
	velocity = { 0, 0 };
}

void Ball::Update(double dt) {
	velocity.y -= Mode1::gravity * dt;
	position += velocity * dt;

	if (position.y < Mode1::floor) {
		position.y = Mode1::floor;
		velocity.y = Ball::bounceVelocity;
	}
}

void Ball::Draw() {
	sprite.Draw(position);
}