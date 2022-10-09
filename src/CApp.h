#pragma once

#include <memory>

#include "SDL.h"

#include "Logic.h"

class CApp
{
public:
    CApp();

    int onExecute();
    bool onInit();
    void onEvent(SDL_Event* _event);
    void onLoop();
    void onRender();
    void onCleanup();

private:
    bool mRunning{};
    SDL_Window* mWindow{};
    SDL_Renderer* mRenderer{};

    size_t maxFPS{60};

    Logic* mLogic;

    vector2<int> pointA{}, pointB{}, pointC{}, pointD{}, pointE{}, pointF{}, pointG{}, pointH{};
};
