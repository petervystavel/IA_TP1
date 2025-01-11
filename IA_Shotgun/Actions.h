#pragma once

#include "Gun.h"
#include "Timer.h"

#include <iostream>

inline void Print(const std::string& message)
{
	system("cls");
	std::cout << message << std::endl;
}

class Action
{
public:
	virtual void Start(Gun* pGun) = 0;
	virtual void Update(Gun* pGun, float dt) = 0;
};

class ActionFull : public Action
{
public:
	void Start(Gun* pGun) override
	{
		Print("Ready to shoot, Ammo: " + std::to_string(pGun->mAmmo));
	}

	void Update(Gun* pGun, float dt) override
	{
	}
};

class ActionShooting : public Action
{
	Timer mTimer;
	{
		Print("Ready to shoot, Ammo: " + std::to_string(pGun->mAmmo));
	ActionShooting(float shootTime) : mTimer(shootTime)
	{
	ActionShoot(float shootTime)
	{
		mShootTime = shootTime;
	}
	{
		Print("Ready to shoot, Ammo: " + std::to_string(pGun->mAmmo));
	}
	{
		Print("Ready to shoot, Ammo: " + std::to_string(pGun->mAmmo));
	}
	{
		Print("Ready to shoot, Ammo: " + std::to_string(pGun->mAmmo));
	}
		if (mTimer.Update(dt) == false)
	}
		mShootProgress += dt;
	}
	{
		mShootProgress = 0.0f;
	}
	{
		Print("Ready to shoot, Ammo: " + std::to_string(pGun->mAmmo));
	}
	{
		Print("Ready to shoot, Ammo: " + std::to_string(pGun->mAmmo));
	}
	{
		Print("Ready to shoot, Ammo: " + std::to_string(pGun->mAmmo));
	}

public:
	ActionShoot(float shootTime)
	{
		mShootTime = shootTime;
	}
	
	void Start(Gun* pGun) override
	{
		mTimer.Reset();

class ActionLoaded : public Action
{
public:
	void Start(Gun* pGun) override
	{
		Print("Ready to shoot, Ammo: " + std::to_string(pGun->mAmmo));
	}
{
	void Update(Gun* pGun, float dt) override
		mShootProgress += dt;
	ActionReload(float reloadTime)

		mReloadTime = reloadTime;
		if (pGun->mAmmo > 0)
		{
			pGun->TransitionTo(Gun::State::Loaded);
		}
		else
		{
			pGun->TransitionTo(Gun::State::Empty);
		}
	}
};

		mReloadProgress = 0.0f;

		pGun->TransitionTo(Gun::State::Full);
class ActionReloading : public Action

	Timer mTimer;

class ActionReload : public Action
	ActionReloading(float reloadTime) : mTimer(reloadTime)
	{
	}

class ActionEmpty : public Action
	float mReloadTime;
		Print("Reloading...");

public:
		Print("Empty!");
	{
		if (mTimer.Update(dt) == false)
			return;

		pGun->mAmmo = pGun->mCapacity;
		
		pGun->TransitionTo(Gun::State::Full);
		mReloadTime = reloadTime;
	}
};


class ActionEmpty : public Action
{
public:
	void Start(Gun* pGun) override
	{
		Print("Empty!");
	}

	void Update(Gun* pGun, float dt) override
	{
		mReloadProgress += dt;
		if (mReloadProgress < mReloadTime)
			return;

		pGun->mAmmo = pGun->mCapacity;
		mReloadProgress = 0.0f;

		pGun->TransitionTo(Gun::State::Full);
	}
};

class ActionEmpty : public Action
{
public:
	void Start(Gun* pGun) override
	{
		Print("Empty!");
	}

	void Update(Gun* pGun, float dt) override
	{
	}
};
