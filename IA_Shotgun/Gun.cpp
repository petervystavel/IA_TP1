#include "Gun.h"

#include <string>

inline void Print(const std::string& message)
{
    system("cls");
    std::cout << message << std::endl;
}

Gun::Gun(int capacity, float reloadTime, float shootTime, float unloadTime)
{
    mAmmo = capacity;
    mCapacity = capacity;
    mReloadTime = reloadTime;
    mShootTime = shootTime;
	mUnloadTime = unloadTime;

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
            mIsReloading = false;

            Print("Ready to shoot, Ammo: " + std::to_string(mAmmo));
        }
    }
    else if (mIsShooting)
    {
        mShootProgress += deltaTime;
        if (mShootProgress >= mShootTime)
        {
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
    else if (mIsUnloading)
    {
        mUnloadProgress += deltaTime;
        if (mUnloadProgress >= mUnloadTime)
        {
            mIsUnloading = false;
			mAmmo = 0;

            Print("Empty !");
        }
    }
}

bool Gun::Shoot()
{
    if (mIsShooting)
        return false;

    if (mIsReloading)
        return false;

    if (mIsUnloading)
        return false;

    if (mAmmo == 0) 
        return false;

    Print("Bang!");

    mIsShooting = true;
    mAmmo--;
    mShootProgress = 0.0f;

    return true;
}

bool Gun::Reload()
{
    if (mIsShooting)
        return false;

    if (mIsReloading)
        return false;

    if (mIsUnloading)
        return false;

    if (mAmmo == mCapacity)
        return false;

    Print("Reloading...");

    mIsReloading = true;
    mReloadProgress = 0.0f;

    return true;
}

bool Gun::Unload()
{
    if (mIsShooting)
        return false;

    if (mIsReloading)
        return false;

    if(mIsUnloading)
		return false;

	if (mAmmo == 0)
		return false;

    Print("Unloading...");

    mIsUnloading = true;
    mUnloadProgress = 0.0f;

    return true;
}