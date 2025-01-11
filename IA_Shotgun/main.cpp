#include <iostream>
#include <chrono>

#include <conio.h>

#include "Gun.h"

void HandleInput(Gun& gun, bool& running)
{
    if (_kbhit() == false)
        return;

    char input = _getch();

    switch (input)
    {
    case 's':
    {
        gun.Shoot();
        break;
    }
    case 'r':
    {
        gun.Reload();
        break;
    }
    case 'q':
    {
        running = false;
        break;
    }
    default:
    {
        break;
    }
    }
}


int main()
{
    Gun myGun(10);

    bool running = true;
    float deltaTime = 0.0f;

    while (running)
    {
        auto start = std::chrono::high_resolution_clock::now();

        HandleInput(myGun, running);

        myGun.Update(deltaTime);

        auto end = std::chrono::high_resolution_clock::now();
        deltaTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000000.f;
    }

    std::cout << "Game ended.\n";

    return 0;
}
