/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Level1.cpp
Project: CS230
Author: Kevin Wright
Creation date: 2/10/2021
-----------------------------------------------------------------*/
#include "../Engine/Engine.h"	//GetGameStateManager
#include "Screens.h"
#include "Mode1.h"

Mode1::Mode1() : hero({ Engine::GetWindow().GetSize().x / 2.0, Mode1::floor }),
ball({ 600, Mode1::floor }),
levelReload(CS230::InputKey::Keyboard::R), levelNext(CS230::InputKey::Keyboard::Enter) {}

void Mode1::Load() {
	hero.Load();
	ball.Load();

	background.Load("assets/Background.png");
}
void Mode1::Update(double dt) {
	hero.Update(dt);
	ball.Update(dt);

	if (levelNext.IsKeyReleased() == true) {
		Engine::GetGameStateManager().SetNextState(static_cast<int>(Screens::Mode2));
	}

	if (levelReload.IsKeyReleased() == true) {
		Engine::GetGameStateManager().ReloadState();
	}

}
void Mode1::Unload() {
}

void Mode1::Draw() {
	background.Draw({ 0, 0 });
	hero.Draw();
	ball.Draw();
}