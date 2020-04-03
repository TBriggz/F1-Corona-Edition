#pragma once
#ifndef __PLAYER__
#define __PLAYER__

#include "DisplayObject.h"
#include "PlayerAnimationState.h"

class Player : public DisplayObject
{
public:
	Player();
	~Player();

	// Life Cycle Methods
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;

	// setters
	void setAnimationState(PlayerAnimationState new_state);

private:

	int m_currentRow;
	int m_currentFrame;

	PlayerAnimationState m_currentAnimationState;
};

#endif /* defined (__PLAYER__) */