/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Level2.cpp
Project: CS230
Author: Kevin Wright
Creation date: 2/10/2021
-----------------------------------------------------------------*/
#include "../Engine/Engine.h"   //GetGameStateManager
#include "Screens.h"
#include "Mode2.h"

Mode2::Mode2()
	: ship(ship),
	levelReload(CS230::InputKey::Keyboard::R), levelNext(CS230::InputKey::Keyboard::Enter) {}

void Mode2::Load() {
	ship.Load();
}

void Mode2::Update(double dt) {
	ship.Update(dt);

	if (levelNext.IsKeyReleased() == true) {
		Engine::GetGameStateManager().Shutdown();
	}

	if (levelReload.IsKeyReleased() == true) {
		Engine::GetGameStateManager().ReloadState();
	}

}

void Mode2::Unload() {
}

void Mode2::Draw() {
	Engine::GetWindow().Clear(0x000000FF);

	ship.Draw();
}