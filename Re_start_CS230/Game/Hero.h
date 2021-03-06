/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Hero.h
Project: CS230
Author: Kevin Wright
Creation date: 2/11/2021
-----------------------------------------------------------------*/
#pragma once
#include "..\Engine\Sprite.h"
#include "..\Engine\Input.h"
#include "..\Engine\Vec2.h"
#include"..\Engine\Camera.h"

namespace CS230 {
	class Camera;
}


class Hero {
public:
	Hero(math::vec2 startPos, const CS230::Camera& camera);
	void Load();
	void Update(double dt);
	void Draw();

private:
	CS230::Camera camera;
	CS230::Sprite sprite;
	math::vec2 startPos;
	math::vec2 position;
	math::vec2 velocity;
	bool isJumping;
	bool isRising;

	static constexpr double jumpVelocity = 950;
	static constexpr double xAccel = 600;
	static constexpr double xDrag = 900;
	static constexpr double maxXVelocity = 900;

	CS230::InputKey jumpKey;
	CS230::InputKey moveLeftKey;
	CS230::InputKey moveRightKey;
};