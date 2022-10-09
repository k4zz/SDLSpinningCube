#include <SDL.h>

#include "CApp.h"

int main([[maybe_unused]]int argc,[[maybe_unused]] char *argv[])
{
    CApp app;

    return app.onExecute();
}