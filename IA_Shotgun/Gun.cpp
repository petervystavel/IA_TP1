#include "Gun.h"

#include <string>

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
    if (mIsReloading)
    {
        mReloadProgress += deltaTime;
        if (mReloadProgress >= mReloadTime)
        {
            mAmmo = mCapacity;
            mReloadProgress = 0.0f;
            mIsReloading = false;

            Print("Ready to shoot, Ammo: " + std::to_string(mAmmo));
        }
    }
    else if (mIsShooting)
    {
        mShootProgress += deltaTime;
        if (mShootProgress >= mShootTime)
        {
            mShootProgress = 0.0f;
            mIsShooting = false;

            if (mAmmo == 0) 
            {
                Print("Empty !");
            }
            else 
            {
                Print("Ready to shoot, Ammo: " + std::to_string(mAmmo));
            }
        }
    }
}

bool Gun::Shoot()
{
    if (mIsReloading)
        return false;

    if (mIsShooting)
        return false;

    if (mAmmo == 0) 
        return false;

    Print("Bang!");

    mIsShooting = true;
    mAmmo--;

    return true;
}

bool Gun::Reload()
{
    if (mIsShooting)
        return false;

    if (mIsReloading)
        return false;

    if (mAmmo == mCapacity)
        return false;

    Print("Reloading...");

    mIsReloading = true;

    return true;
}