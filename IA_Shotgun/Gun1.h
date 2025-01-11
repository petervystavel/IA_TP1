#pragma once

#include <iostream>

class Gun1
{
private:
    int mAmmo;
    int mCapacity;

    float mReloadTime;
    float mReloadProgress = 0.f;

    float mShootTime;
    float mShootProgress = 0.f;

    bool mIsReloading = false;
    bool mIsShooting = false;

public:
    Gun1(int capacity, float reloadTime = 2.0f, float shootTime = 0.5f);

    void Update(float deltaTime);

    bool Shoot();

    bool Reload();
};
