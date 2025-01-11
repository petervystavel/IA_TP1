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

public:
	ActionShooting(float shootTime) : mTimer(shootTime)
	{
	}
	
	void Start(Gun* pGun) override
	{
		mTimer.Reset();

		pGun->mAmmo--;

		Print("Bang!");
	}

	void Update(Gun* pGun, float dt) override
	{
		if (mTimer.Update(dt) == false)
			return;

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

class ActionLoaded : public Action
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

class ActionReloading : public Action
{
	Timer mTimer;

public:
	ActionReloading(float reloadTime) : mTimer(reloadTime)
	{
	}

	void Start(Gun* pGun) override
	{
		Print("Reloading...");
	}

	void Update(Gun* pGun, float dt) override
	{
		if (mTimer.Update(dt) == false)
			return;

		pGun->mAmmo = pGun->mCapacity;
		
		pGun->TransitionTo(Gun::State::Full);
	}
};
