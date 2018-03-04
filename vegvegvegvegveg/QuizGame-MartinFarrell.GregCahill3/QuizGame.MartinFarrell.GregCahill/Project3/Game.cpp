#include "Game.h"//murt 
#include <SFML\Graphics.hpp>
#include <iostream>

GameState Game::m_gamestate{ GameState::Quiz1 };

Game::Game() :
	m_window{ sf::VideoMode{ 800, 600, 32 }, "Mini-Motivators" }
{
	setupAssets(); // load font 
	if (sf::Joystick::isConnected(0))
	{
		std::cout << "connected";
	}
}


Game::~Game()
{
}


void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}
/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
}

/// <summary>
/// Update the game world
/// switch to which ever class is dealing wiht curretn game state
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	if (sf::Joystick::isButtonPressed(0, 0))
	{
		std::cout << "pressed";
	}

	switch (m_gamestate)
	{
	case GameState::Intro:
		m_introScreen.update(t_deltaTime);
		break;
	case GameState::Splash:
		m_splash.update(t_deltaTime);
		break;
	case GameState::MainMenu:
		m_mainMenuScreen.update(t_deltaTime, m_window);
		break;
	case GameState::Quiz1:
		m_quiz.update(t_deltaTime);
		break;
	case GameState::Quiz2:
		break;
	case GameState::Credits:
		//update
		break;
	default:
		break;
	}

}

/// <summary>
/// draw the game
/// switch to which ever class is dealing with current game state
/// </summary>
void Game::render()
{
	switch (m_gamestate)
	{
	case GameState::Intro:
		m_introScreen.render(m_window);
		break;
	case GameState::Splash:
		m_splash.render(m_window);
		break;
	case GameState::MainMenu:
		m_mainMenuScreen.render(m_window);
		break;
	case GameState::Quiz1:
		m_quiz.render(m_window);
		break;
	case GameState::Quiz2:
		//draw
		break;
	case GameState::Credits:
		//draw
		break;
	default:
		break;
	}

}

/// <summary>
/// load the font for use in other classes
/// get other classes to setup their assets
/// </summary>
void Game::setupAssets()
{
	if (!m_ArialBlackfont.loadFromFile("ASSETS\\DIGITALDREAMSKEWNARROW.ttf"))
	{
		std::cout << "problem loading font" << std::endl;
	}
	m_splash.setup(m_ArialBlackfont);
	m_introScreen.setup(m_ArialBlackfont);
	m_quiz.setup(m_ArialBlackfont);
	m_mainMenuScreen.setup(m_ArialBlackfont);
}