#pragma once

#include <string>

class Action;

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

    bool mTransitions[STATE_COUNT][STATE_COUNT];
	Action* mActions[STATE_COUNT];

private:
	void SetTransition(State from, State to, bool value) { mTransitions[(int)from][(int)to] = value; }

public:
    Gun(int capacity, float reloadTime = 2.0f, float shootTime = 0.5f);

    void Update(float deltaTime);

    bool TransitionTo(State newState);

    friend class ActionFull;
	friend class ActionLoaded;
	friend class ActionShoot;
	friend class ActionEmpty;
	friend class ActionReload;
};
