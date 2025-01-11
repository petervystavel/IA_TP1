#include <iostream>
#include <chrono>

#include <conio.h>

#define GUN1

#ifdef GUN1
#include "gun1.h"
typedef Gun1 Gun;
#endif

#ifdef GUN2
#include "gun2.h"
typedef Gun2 Gun;
#endif

#ifdef GUN3
#include "gun3.h"
typedef Gun3 Gun;
#endif

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
        std::cout << "Invalid input\n";
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
