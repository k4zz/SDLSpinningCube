#include <iostream>
#include "CApp.h"

#include "ErrorCodes.h"


CApp::CApp()
{
    mRunning = true;
}

int CApp::onExecute()
{
    if (!onInit())
        return ErrorCode::OnInitFailed;

    SDL_Event event{};

    size_t a, b, delta;

    while (mRunning)
    {
        while (SDL_PollEvent(&event))
        {
            onEvent(&event);
        }


        a = SDL_GetTicks();
        delta = a - b;

        if(delta > 1000/ 60)
        {
            b = a;
            onLoop();
            onRender();
        }
    }

    onCleanup();

    return ErrorCode::NoError;
}

bool CApp::onInit()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cerr << SDL_GetError();
        return false;
    }

    SDL_CreateWindowAndRenderer(640, 480, SDL_WINDOW_SHOWN, &mWindow, &mRenderer);
    if (!mWindow)
    {
        return false;
    }

    int width, height;
    SDL_GetWindowSize(mWindow, &width, &height);

    mLogic = new Logic(width, height);

    return true;
}

void CApp::onEvent([[maybe_unused]] SDL_Event *_event)
{
    if (_event->type == SDL_QUIT)
        mRunning = false;
}

void CApp::onLoop()
{
    mLogic->pitch   += 0.01f;
    mLogic->yaw     += 0.02f;
    mLogic->roll    += 0.03f;

    auto cubeSize = 20.f;
    pointA = mLogic->projectToScreen({-cubeSize, -cubeSize, -cubeSize});
    pointB = mLogic->projectToScreen({cubeSize, -cubeSize, -cubeSize});
    pointC = mLogic->projectToScreen({cubeSize, cubeSize, -cubeSize});
    pointD = mLogic->projectToScreen({-cubeSize, cubeSize, -cubeSize});
    pointE = mLogic->projectToScreen({-cubeSize, -cubeSize, cubeSize});
    pointF = mLogic->projectToScreen({cubeSize, -cubeSize, cubeSize});
    pointG = mLogic->projectToScreen({cubeSize, cubeSize, cubeSize});
    pointH = mLogic->projectToScreen({-cubeSize, cubeSize, cubeSize});


}

void CApp::onRender()
{
    SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(mRenderer);
    SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLine(mRenderer, pointA.x, pointA.y, pointB.x, pointB.y);
    SDL_RenderDrawLine(mRenderer, pointB.x, pointB.y, pointC.x, pointC.y);
    SDL_RenderDrawLine(mRenderer, pointC.x, pointC.y, pointD.x, pointD.y);
    SDL_RenderDrawLine(mRenderer, pointD.x, pointD.y, pointA.x, pointA.y);
    SDL_RenderDrawLine(mRenderer, pointE.x, pointE.y, pointF.x, pointF.y);
    SDL_RenderDrawLine(mRenderer, pointF.x, pointF.y, pointG.x, pointG.y);
    SDL_RenderDrawLine(mRenderer, pointG.x, pointG.y, pointH.x, pointH.y);
    SDL_RenderDrawLine(mRenderer, pointH.x, pointH.y, pointE.x, pointE.y);
    SDL_RenderDrawLine(mRenderer, pointA.x, pointA.y, pointE.x, pointE.y);
    SDL_RenderDrawLine(mRenderer, pointB.x, pointB.y, pointF.x, pointF.y);
    SDL_RenderDrawLine(mRenderer, pointC.x, pointC.y, pointG.x, pointG.y);
    SDL_RenderDrawLine(mRenderer, pointD.x, pointD.y, pointH.x, pointH.y);
    SDL_RenderPresent(mRenderer);
}

void CApp::onCleanup()
{
    delete mLogic;
    SDL_DestroyWindow(mWindow);
    SDL_Quit();
}

