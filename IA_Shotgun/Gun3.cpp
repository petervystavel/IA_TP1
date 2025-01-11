#include "Gun3.h"
#include "Actions.h"

Gun3::Gun3(int capacity, float reloadTime, float shootTime)
{
    mAmmo = capacity;
    mCapacity = capacity;

	mActions[(int)State::Full] = new ActionFull();
    mActions[(int)State::Loaded] = new ActionLoaded();
	mActions[(int)State::Shooting] = new ActionShoot(shootTime);
	mActions[(int)State::Empty] = new ActionEmpty();
	mActions[(int)State::Reloading] = new ActionReload(reloadTime);

	TransitionTo(State::Full);
}

void Gun3::Update(float deltaTime)
{
	mActions[(int)mState]->Update(this, deltaTime);
}

bool Gun3::TransitionTo(State newState)
{
    if (mTransitions[(int)mState][(int)newState])
    {
		mActions[(int)newState]->Start(this);
        mState = newState;

        return true;
    }

    return false;
}

bool Gun3::Shoot()
{
    if (TransitionTo(State::Shooting) == false)
        return false;

    mAmmo--;

    return true;
}

bool Gun3::Reload()
{
    if (TransitionTo(State::Reloading) == false)
        return false;

    return true;
}
