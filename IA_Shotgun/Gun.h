#pragma once

#include <iostream>

class Gun
{
private:
    int mAmmo;
    int mCapacity;

    float mReloadTime;
    float mReloadProgress = 0.f;

    float mShootTime;
    float mShootProgress = 0.f;

    float mUnloadTime;
    float mUnloadProgress = 0.f;

    bool mIsReloading = false;
    bool mIsShooting = false;
    bool mIsUnloading = false;

public:
    Gun(int capacity, float reloadTime = 2.0f, float shootTime = 0.5f, float unloadTime = 0.75f);

    void Update(float deltaTime);

    bool Shoot();

    bool Reload();

    bool Unload();
};
