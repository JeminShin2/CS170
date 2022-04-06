/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Level1.h
Project: CS230
Author: Kevin Wright
Creation date: 2/10/2021
-----------------------------------------------------------------*/
#pragma once
#include "..\Engine\GameState.h"
#include "..\Engine\Input.h"
#include "..\Engine\Texture.h"
#include "Hero.h"
#include"Ball.h"

class Mode1 : public CS230::GameState {
public:
	static constexpr double floor = 126.0f;
	static constexpr double gravity = 1875;

	Mode1();
	void Load() override;
	void Update(double dt) override;
	void Unload() override;
	void Draw() override;

	std::string GetName() override { return "Mode1"; }
private:
	Hero hero;
	Ball ball;
	CS230::Texture background;
	CS230::InputKey levelReload;
	CS230::InputKey levelNext;
};

