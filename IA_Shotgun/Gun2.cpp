#include "Gun2.h"

#include <iostream>

inline void Print(const std::string& message)
{
    system("cls");
    std::cout << message << std::endl;
}

Gun2::Gun2(int capacity, float reloadTime, float shootTime)
{
    mAmmo = capacity;
    mCapacity = capacity;
    mReloadTime = reloadTime;
    mShootTime = shootTime;

    Print("Ready to shoot, Ammo: " + std::to_string(mAmmo));
}

void Gun2::Update(float deltaTime)
{
    if (mState == State::Reloading)
    {
        mReloadProgress += deltaTime;
        if (mReloadProgress >= mReloadTime)
        {
            mAmmo = mCapacity;
            mReloadProgress = 0.0f;

            Print("Ready to shoot, Ammo: " + std::to_string(mAmmo));
            TransitionTo(State::Full);
        }
    }
    else if (mState == State::Shooting)
    {
        mShootProgress += deltaTime;
        if (mShootProgress >= mShootTime)
        {
            mShootProgress = 0.0f;
            if (mAmmo > 0)
            {
                Print("Ready to shoot, Ammo: " + std::to_string(mAmmo));
                TransitionTo(State::Loaded);
            }
            else
            {
                Print("Empty!");
                TransitionTo(State::Empty);
            }
        }
    }
}

bool Gun2::TransitionTo(State newState)
{
    if (mTransitions[(int)mState][(int)newState])
    {
        mState = newState;
        return true;
    }

    return false;
}

bool Gun2::Shoot()
{
    if (TransitionTo(State::Shooting) == false)
        return false;

    Print("Bang!");

    mAmmo--;

    return true;
}

bool Gun2::Reload()
{
    if (TransitionTo(State::Reloading) == false)
        return false;

    Print("Reloading...");

    return true;
}
