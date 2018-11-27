#include <iostream>
#include <SFML\Graphics.hpp>

#include "HumanPlayer.h"

#define SQUARE_SIZE 40 	// Length of each square of the maze

// Constructor - takes in file name of the sprite texture and the maze that the player will be placed in
// Right now it assumes the player will only be
HumanPlayer::HumanPlayer(const sf::Texture& imagePath, MazeConstructor Maze) {
    mSprite(imagePath);
	currentMaze = Maze;
	// Default movement speed
	moveSpeed = 1.0;
	// Sets the current square the player is in
	x = currentMaze.xStart;
	y = currentMaze.yStart;
	currentSquare = currentMaze.maze[x][y];
	isMoving = false;
	// Set the starting position of the player
	mSprite.setPosition(15.0f, 15.0f);
	// Sets the size of the sprite
	mSprite.setTextureRect(sf::IntRect(15, 15, 20, 20));
}

HumanPlayer::~HumanPlayer() {
    // TODO Auto-generated destructor stub
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(mSprite, states);
}

// Accessor
float getMoveSpeed() const {
	return moveSpeed;
}

// Mutator
void changeMoveSpeed(const float newMoveSpeed) {
	moveSpeed = newMoveSpeed;
}

/* MOVEMENT
 * The Player object moves from square to square
 * Animation speed is dictated by MOVE_SPEED
 */

void HumanPlayer::moveUp() {
	//if (currentSquare.upWall && !isMoving) {
		currentSquare = currentMaze.maze[x][y-1];
		y--;
		float newYPos = mSprite.getPosition().y - SQUARE_SIZE;
		// Move to the square above
		isMoving = true;
		while (mSprite.getPosition().y >= newYPos) {
			mSprite.move(0, -MOVE_SPEED);
		}
		isMoving = false;
//	}
}

void HumanPlayer::moveDown() {
//	if (currentSquare.downWall && !isMoving) {
		currentSquare = currentMaze.maze[x][y+1];
		y++;
		float newYPos = mSprite.getPosition().y + SQUARE_SIZE;
		// Move to the square below
		isMoving = true;
		while (mSprite.getPosition().y <= newYPos) {
			mSprite.move(0, MOVE_SPEED);
		}
		isMoving = false;
//	}
}

void HumanPlayer::moveLeft() {
	//if (currentSquare.leftWall && !isMoving) {
		currentSquare = currentMaze.maze[x-1][y];
		x--;
		float newXPos = mSprite.getPosition().x - SQUARE_SIZE;
		// Move to the square to the left
		while (mSprite.getPosition().x >= newXPos) {
			mSprite.move(-MOVE_SPEED, 0);
		}
		isMoving = true;
//	}
}

void HumanPlayer::moveRight() {
//	if (currentSquare.rightWall && !isMoving) {
		currentSquare = currentMaze.maze[x+1][y];
		x++;
		float newXPos = mSprite.getPosition().x + SQUARE_SIZE;
		// Move to the square to the right
		while (mSprite.getPosition().x <= newXPos) {
			mSprite.move(MOVE_SPEED, 0);
		}
		isMoving = true;
//	}
}


