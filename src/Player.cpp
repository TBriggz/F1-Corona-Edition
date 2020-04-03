#include "Player.h"
#include "Game.h"

Player::Player():m_currentRow(0), m_currentFrame(0), m_currentAnimationState(PLAYER_IDLE_RIGHT)
{
	TheTextureManager::Instance()->load("../Assets/sprites/megaman-idle.png",
		"player-idle", TheGame::Instance()->getRenderer());

	TheTextureManager::Instance()->load("../Assets/sprites/megaman-run.png",
		"player-run", TheGame::Instance()->getRenderer());

	setWidth(81);
	setHeight(58);

	setPosition(glm::vec2(400.0f, 300.0f));
	setVelocity(glm::vec2(0.0f, 0.0f));
	setAcceleration(glm::vec2(0.0f, 0.0f));
	setIsColliding(false);
	setType(PLAYER);
}

Player::~Player()
= default;

void Player::draw()
{
	const int xComponent = getPosition().x;
	const int yComponent = getPosition().y;


	switch(m_currentAnimationState)
	{
	case PLAYER_IDLE_RIGHT:
		TheTextureManager::Instance()->drawFrame("player-idle", xComponent, yComponent,
			getWidth(), getHeight(), m_currentRow, m_currentFrame,
			4, 1, 0.12,
			TheGame::Instance()->getRenderer(), 0, 255, true);
		break;
	case PLAYER_IDLE_LEFT:
		TheTextureManager::Instance()->drawFrame("player-idle", xComponent, yComponent,
			getWidth(), getHeight(), m_currentRow, m_currentFrame,
			4, 1, 0.12,
			TheGame::Instance()->getRenderer(), 0, 255, true, SDL_FLIP_HORIZONTAL);
		break;
	case PLAYER_RUN_RIGHT:
		TheTextureManager::Instance()->drawFrame("player-run", xComponent, yComponent,
			getWidth(), getHeight(), m_currentRow, m_currentFrame,
			4, 1, 0.25,
			TheGame::Instance()->getRenderer(), 0, 255, true);
		break;
	case PLAYER_RUN_LEFT:
		TheTextureManager::Instance()->drawFrame("player-run", xComponent, yComponent,
			getWidth(), getHeight(), m_currentRow, m_currentFrame,
			4, 1, 0.25,
			TheGame::Instance()->getRenderer(), 0, 255, true, SDL_FLIP_HORIZONTAL);
		break;
	}
	
	
	
}

void Player::update()
{
}

void Player::clean()
{
}

void Player::setAnimationState(const PlayerAnimationState new_state)
{
	m_currentAnimationState = new_state;
}
