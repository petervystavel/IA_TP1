#pragma once

#include "Gun.h"
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
	float mTime;
	float mProgress = 0.f;

public:
	ActionShooting(float shootTime)
	{
		mTime = shootTime;
	}

	void Start(Gun* pGun) override
	{
		pGun->mAmmo--;

		Print("Bang!");
	}

	void Update(Gun* pGun, float dt) override
	{
		mProgress += dt;
		if (mProgress < mTime)
			return;

		mProgress = 0.0f;
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
	float mTime;
	float mProgress = 0.f;

public:
	ActionReloading(float reloadTime)
	{
		mTime = reloadTime;
	}

	void Start(Gun* pGun) override
	{
		Print("Reloading...");
	}

	void Update(Gun* pGun, float dt) override
	{
		mProgress += dt;
		if (mProgress < mTime)
			return;

		pGun->mAmmo = pGun->mCapacity;
		mProgress = 0.0f;

		pGun->TransitionTo(Gun::State::Full);
	}
};

class ActionUnloading : public Action
{
	float mTime;
	float mProgress = 0.f;

public:
	ActionUnloading(float time)
	{
		mTime = time;
	}

	void Start(Gun* pGun) override
	{
		Print("Unloading...");
	}

	void Update(Gun* pGun, float dt) override
	{
		mProgress += dt;
		if (mProgress < mTime)
			return;

		mProgress = 0.0f;

		pGun->mAmmo = 0;

		pGun->TransitionTo(Gun::State::Empty);
	}
};
