#include <SDL2/SDL.h>
#include "game.h"
#include "graphics.h"
#include "input.h"
#include<bits/stdc++.h>

Game::Game() {
	SDL_Init(SDL_INIT_EVERYTHING);
	this -> gameLoop();
};

Game::~Game() {};

namespace {
	const int FPS = 50;
	const int MAX_FRAME_TIME = 5000 / FPS;
};

void Game::gameLoop() {
	Graphics graphics;
	SDL_Event event;
	Input input;

	int LAST_UPDATE_TIME = SDL_GetTicks();

	std::cout << "Initializing";

	while(true) {
		input.beginNewFrame();
		if(SDL_PollEvent(&event)) {
			if(event.type == SDL_KEYDOWN) {
				if(event.key.repeat == 0) {
					input.keyDownEvent(event);	
				}
			} else if (event.type == SDL_KEYUP) {
				input.keyUpEvent(event);
			} else if(event.type == SDL_QUIT) {
				return;
			}
		}
	
		if(input.wasKeyPressed(SDL_SCANCODE_ESCAPE) == true) {
			return;
		}

		int CURRENT_TIME_MS = SDL_GetTicks();
		int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;

		this -> update(std::min(ELAPSED_TIME_MS, MAX_FRAME_TIME));

		LAST_UPDATE_TIME = CURRENT_TIME_MS;
	}
}

void Game::draw(Graphics &graphics) {}

void Game::update(float elapsedTime) {}
