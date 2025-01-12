#include "Gun.h"
#include "Actions.h"

Gun::Gun(int capacity, float reloadTime, float shootTime, float unloadTime)
{
    mAmmo = capacity;
    mCapacity = capacity;

	mActions[(int)State::Full] = new ActionFull();
	mActions[(int)State::Shooting] = new ActionShooting(shootTime);
    mActions[(int)State::Loaded] = new ActionLoaded();
	mActions[(int)State::Empty] = new ActionEmpty();
	mActions[(int)State::Reloading] = new ActionReloading(reloadTime);
	mActions[(int)State::Unloading] = new ActionUnloading(unloadTime);
	
	for (int i = 0; i < STATE_COUNT; ++i)
	{
		for (int j = 0; j < STATE_COUNT; ++j)
		{
			mTransitions[i][j] = false;
		}
	}
	
	SetTransition(State::Full, State::Full, true);
	SetTransition(State::Full, State::Shooting, true);
	SetTransition(State::Full, State::Unloading, true);

	SetTransition(State::Shooting, State::Loaded, true);
	SetTransition(State::Shooting, State::Empty, true);

	SetTransition(State::Loaded, State::Shooting, true);
	SetTransition(State::Loaded, State::Reloading, true);
	SetTransition(State::Loaded, State::Unloading, true);

	SetTransition(State::Empty, State::Reloading, true);

	SetTransition(State::Reloading, State::Full, true);

	SetTransition(State::Unloading, State::Empty, true);

	//Init
	SetState(State::Full);
}

void Gun::Update(float deltaTime)
{
	mActions[(int)mState]->Update(this, deltaTime);
}

bool Gun::SetState(State newState)
{
    if (mTransitions[(int)mState][(int)newState])
    {
		mActions[(int)newState]->Start(this);
        mState = newState;

        return true;
    }

    return false;
}
