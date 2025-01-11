#pragma once

#include <string>

class Gun
{
public:
    enum class State
    {
        Full,
        Loaded,
        Empty,
        Shooting,
        Reloading,

        Count
    };

    static constexpr int STATE_COUNT = static_cast<int>(State::Count);

private:
    int mAmmo;
    int mCapacity;

    State mState = State::Full;

    float mReloadTime;
    float mReloadProgress = 0.f;

    float mShootTime;
    float mShootProgress = 0.f;

    int mTransitions[STATE_COUNT][STATE_COUNT] =
	{
		// Full, Loaded, Empty, Shooting, Reloading
		{  1,     0,      0,     1,        0 }, // Full
		{  0,     0,      0,     1,        1 }, // Loaded
		{  0,     0,      0,     0,        1 }, // Empty
		{  0,     1,      1,     0,        0 }, // Shooting
		{  1,     0,      0,     0,        0 }  // Reloading
	};

public:
    Gun(int capacity, float reloadTime = 2.0f, float shootTime = 0.5f);

    void Update(float deltaTime);

    bool TransitionTo(State newState);

    bool Shoot();

    bool Reload();
};