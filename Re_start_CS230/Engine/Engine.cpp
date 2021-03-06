/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Engine.cpp
Purpose: This is the service provider for our games engine services
Project: CS230
Author: Kevin Wright
Creation date: 2/10/2021
-----------------------------------------------------------------*/
#include "Engine.h"

Engine::Engine() : frameCount(0), dt(0), lastTick(std::chrono::system_clock::now()),
#ifdef _DEBUG				
logger(CS230::Logger::Severity::Debug, true, lastTick)
#else 						
logger(CS230::Logger::Severity::Event, false, lastTick)
#endif
{}

Engine::~Engine() {}

void Engine::Init(std::string windowName) {
	logger.LogEvent("Engine Init");
	window.Init(windowName);
	fpsCalcTime = lastTick;
}

void Engine::Shutdown() {
	logger.LogEvent("Engine Shutdown");
}

void Engine::Update() {
	std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
	 dt = std::chrono::duration<double>(now - lastTick).count();

	if (dt >= 1 / Engine::Target_FPS) {
		logger.LogVerbose("Engine Update");
		lastTick = now;

		if (++frameCount >= Engine::FPS_IntervalFrameCount) {
			double actualTime = std::chrono::duration<double>((now - fpsCalcTime)).count();
			logger.LogEvent("FPS:  " + std::to_string(frameCount / actualTime));
			frameCount = 0;
			fpsCalcTime = now;
		}
		gameStateManager.Update(dt);
		input.Update();
		window.Update();
	}
}

bool Engine::HasGameEnded() {
	return gameStateManager.HasGameEnded();
}
