#pragma once

class Timer
{
	float mTime;
	float mProgress = 0.f;

public:
	Timer(float time)
	{
		mTime = time;
	}

	void Reset()
	{
		mProgress = 0.f;
	}

	bool Update(float dt)
	{
		mProgress += dt;

		if (mProgress < mTime)
			return false;
		
		mProgress = 0.0f;
		
		return true;
	}
};

