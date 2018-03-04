#ifndef GAME
#define GAME
#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "Splash.h"
#include "Intro.h"
#include "Quiz.h"
#include"mainmenu.h"

class Game
{
public:
	Game();
	~Game();

	void run();
	static GameState m_gamestate;
private:

	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();

	Intro m_introScreen;
	Splash m_splash;
	Quiz m_quiz;
	MainMenu m_mainMenuScreen;
	void setupAssets();

	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont;

};

#endif // !GAME










