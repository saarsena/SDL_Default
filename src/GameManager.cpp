#include "GameManager.h"
#include <iostream>

GameManager::GameManager()
    : window(nullptr), renderer(nullptr), isRunning(false) {}

GameManager::~GameManager() { clean(); }

bool GameManager::init() {
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    return false;
  if (!IMG_Init(IMG_INIT_PNG))
    return false;
  if (TTF_Init() == -1)
    return false;
  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    return false;

  window = SDL_CreateWindow("SDL2 Game", SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED, 800, 600, 0);
  if (!window)
    return false;

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (!renderer)
    return false;

//  SDL_Surface *tempSurface = IMG_Load("assets/classic_roguelike_white.png");
//  SDL_Texture *tileTexture =
//      SDL_CreateTextureFromSurface(renderer, tempSurface);
//  SDL_FreeSurface(tempSurface);



  isRunning = true;
  return true;
}

void GameManager::run() {
  while (isRunning) {
    handleEvents();
    update();
    render();
    SDL_Delay(16);
  }
}

void GameManager::handleEvents() {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT)
      isRunning = false;
  }
}

void GameManager::update() {}

void GameManager::render() {
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);
}

void GameManager::clean() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  Mix_Quit();
  TTF_Quit();
  IMG_Quit();
  SDL_Quit();
}
