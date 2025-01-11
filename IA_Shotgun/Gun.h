#pragma once

#include <string>

class Gun
{
public:
    enum class State
    {
        Full,
        Shooting,
        Loaded,
        Empty,
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

    bool mTransitions[STATE_COUNT][STATE_COUNT];

private:
    void SetTransition(State from, State to, bool value) { mTransitions[(int)from][(int)to] = value; }

public:
    Gun(int capacity, float reloadTime = 2.0f, float shootTime = 0.5f);

    void Update(float deltaTime);

    bool TransitionTo(State newState);

    bool Shoot();

    bool Reload();
};