#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <vector>


class GameManager {
public:
    GameManager();
    ~GameManager();
    bool init();
    void run();
    void clean();

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool isRunning;

    void handleEvents();
    void update();
    void render();
};
