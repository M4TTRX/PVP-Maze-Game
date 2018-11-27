/*
 * ScreenController.h
 *
 *  Created on: Nov 2, 2018
 *      Author: Adrian
 */

#ifndef SCREENCONTROLLER_H_
#define SCREENCONTROLLER_H_

#include <iostream>
using namespace std;
//#include "Graphics.hpp"
#include "GameControll.h"
class ScreenController{
public:
	string highScoreFile;
	vector<sf::Keyboard::Key> player1Controls;
	vector<sf::Keyboard::Key> player2Controls;
};

class TitleScreen: public ScreenController{
public:
	TitleScreen();
	void StartUp(sf::RenderWindow& window);
	void StartGame(sf::RenderWindow& window);
	void ScreenTransfer(int transferNum, sf::RenderWindow& window);
};

class InstructionsScreen: public ScreenController{
public:
	InstructionsScreen(vector<sf::Keyboard::Key> player1Controls, vector<sf::Keyboard::Key> player2Controls);
	void Open(sf::RenderWindow& window);
	string fromKtoS(const sf::Keyboard::Key& k);
};

class SetupScreen: public ScreenController{
public:
	SetupScreen(vector<sf::Keyboard::Key> player1Controls, vector<sf::Keyboard::Key> player2Controls, string scoreFile);
	void ScreenTransfer(int transferNum, sf::RenderWindow& window);
	void SetupGame(sf::RenderWindow& window);
};
/*
//Daniel's new code
class GameScreen: public ScreenController{
public:
	void Game(sf::RenderWindow& window);
};

class PauseMenu: public ScreenController{
public:
	void PauseGame(sf::RenderWindow& window);
};*/
#endif /* SCREENCONTROLLER_H_ */
