#include"Splash.h"
#include "Game.h"
#include "GameState.h"

Splash::Splash()
{
}


Splash::~Splash()
{
}


void Splash::update(sf::Time t_deltaTime)
{
	timer--;
	stringPos.x -= 1;
	if (timer == 30 || timer == 0 && lightsOn)
	{
		lightsOn = false;
	}
	else if (timer == 30 || timer == 0 && !lightsOn)
	{
		lightsOn = true;
	}
	if (timer <= 0)
	{
		m_message.setPosition(stringPos);
		timer = 60;
	}


	if (m_message.getPosition().x <= -600)
	{
		m_message.setPosition(550, 350);
		stringPos = m_message.getPosition();
	}
	/*if (sf::Joystick)
	{
		Game::m_gamestate = GameState::MainMenu;
	} */
}

void Splash::render(sf::RenderWindow & t_window)
{
	t_window.clear();
	t_window.draw(m_message);
	if (lightsOn)
	{
		t_window.draw(m_pressA);
	}

	t_window.draw(m_sprite);
	t_window.display();
}

void Splash::setup(sf::Font & t_font)//k
{
	m_font = t_font;
	m_message.setFillColor(sf::Color::Green);

	m_message.setPosition(sf::Vector2f{ 550.0f,350.0f });
	m_message.setCharacterSize(48u);
	m_message.setString("        A pete Like\n        Production");
	m_message.setFont(m_font);
	stringPos = m_message.getPosition();

	m_pressA.setFillColor(sf::Color::Green);
	m_pressA.setPosition(sf::Vector2f{ 20.0f,150.0f });
	m_pressA.setCharacterSize(40u);
	m_pressA.setString("Press A      to continue");
	m_pressA.setFont(m_font);
	if (!m_texture.loadFromFile("ASSETS//ScoreBoard_image.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading sprite" << std::endl;
	}
	m_sprite.setPosition(0, 0);
	m_sprite.setSize(sf::Vector2f(800, 600));
	m_sprite.setTexture(&m_texture);
}