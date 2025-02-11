#include "Gun.h"

#include <iostream>

inline void Print(const std::string& message)
{
    system("cls");
    std::cout << message << std::endl;
}

Gun::Gun(int capacity, float reloadTime, float shootTime)
{
    mAmmo = capacity;
    mCapacity = capacity;
    mReloadTime = reloadTime;
    mShootTime = shootTime;

    Print("Ready to shoot, Ammo: " + std::to_string(mAmmo));
}

void Gun::Update(float deltaTime)
{
    if (mState == State::Reloading)
    {
        mReloadProgress += deltaTime;
        if (mReloadProgress >= mReloadTime)
        {
            mAmmo = mCapacity;

            Print("Ready to shoot, Ammo: " + std::to_string(mAmmo));
            SetState(State::Full);
        }
    }
    else if (mState == State::Shooting)
    {
        mShootProgress += deltaTime;
        if (mShootProgress >= mShootTime)
        {
            if (mAmmo > 0)
            {
                Print("Ready to shoot, Ammo: " + std::to_string(mAmmo));
                SetState(State::Loaded);
            }
            else
            {
                Print("Empty!");
                SetState(State::Empty);
            }
        }
    }
}

bool Gun::SetState(State newState)
{
    if (mTransitions[(int)mState][(int)newState])
    {
        mState = newState;
        return true;
    }

    return false;
}

bool Gun::Shoot()
{
    if (SetState(State::Shooting) == false)
        return false;

    Print("Bang!");

    mAmmo--;
    mShootProgress = 0.0f;

    return true;
}

bool Gun::Reload()
{
    if (SetState(State::Reloading) == false)
        return false;

    Print("Reloading...");

    mReloadProgress = 0.0f;

    return true;
}
