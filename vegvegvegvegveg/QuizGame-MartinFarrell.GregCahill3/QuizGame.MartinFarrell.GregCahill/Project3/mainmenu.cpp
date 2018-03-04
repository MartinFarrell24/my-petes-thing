#include"MainMenu.h"
#include "Game.h"
#include "GameState.h"

MainMenu::MainMenu()
{
}

MainMenu::~MainMenu()
{
}

void MainMenu::update(sf::Time t_deltaTime, sf::Window &t_window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		mousey.setTexture(mouseyClickedTexture);
	}
	else
	{
		mousey.setTexture(mouseyTexture);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		mousey.setPosition(mousey.getPosition().x, mousey.getPosition().y - 2);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		mousey.setPosition(mousey.getPosition().x, mousey.getPosition().y + 2);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		mousey.setPosition(mousey.getPosition().x - 2, mousey.getPosition().y);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		mousey.setPosition(mousey.getPosition().x + 2, mousey.getPosition().y);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))//if mouse left click
	{
		sf::Vector2f mouseLocation;//store mouse location in the windoww
		mouseLocation = mousey.getPosition();//gets the mouse position from window
		for (int i = 0; i < 4; i++)
		{
			if (mouseLocation.x > m_buttonSprites[i].getPosition().x &&
				mouseLocation.x <  m_buttonSprites[i].getPosition().x + m_buttonSprites[0].getGlobalBounds().width)//if mouse is inside button x parameters
			{
				if (mouseLocation.y > m_buttonSprites[i].getPosition().y &&
					mouseLocation.y <  m_buttonSprites[i].getPosition().y + m_buttonSprites[0].getGlobalBounds().height)//if top button
				{
					if (i = 0)
					{
						Game::m_gamestate = GameState::Quiz1;
					}
					else if (i = 1)
					{
						Game::m_gamestate = GameState::Quiz2;
					}
				}
			}
			else if (mouseLocation.x > 630 && mouseLocation.y >130)
			{
				t_window.close();
			}
		}
	}
}

void MainMenu::render(sf::RenderWindow & t_window)
{
	t_window.clear(sf::Color::Black);
	t_window.draw(backgroundSquare);
	for (int i = 0; i < 2; i++)
	{
		//draw buttons and text
		t_window.draw(m_buttonSprites[i]);
	}
	t_window.draw(mousey);
	t_window.display();
}

void MainMenu::setup(sf::Font & t_font)
{
	m_font = t_font;
	m_message.setFillColor(sf::Color::Green);
	m_message.setPosition(sf::Vector2f{ 50.0f,50.0f });
	m_message.setCharacterSize(24u);
	m_message.setString("Main Menu");
	m_message.setFont(m_font);


	//variables used to set buttons

	int textDropOffset = 10;
	if (!m_buttonTexture[0].loadFromFile("ASSETS/QuizOne.png"))//load image and check for error
	{
		std::cout << "error with button file";//error message
	}
	if (!m_buttonTexture[1].loadFromFile("ASSETS/QuizTwo.png"))//load image and check for error
	{
		std::cout << "error with button file";//error message
	}


	for (int i = 0; i < 2; i++)//loops number of times = noOFButtons
	{
		//set up sprite/buttons

		m_buttonSprites[i].setTexture(m_buttonTexture[i]);//sets texture for button to loaded image
														  //m_buttonSprites[i].setPosition(m_leftOffset, m_verticalSpacing * i + m_topOffset);//setsposition of button
		sf::Vector2u textureSize = m_buttonTexture[i].getSize();//gets size for scale
		m_buttonSprites[i].setScale(.75, .75);//sets scale
		m_buttonSprites[i].setPosition(100 + 200 * i, 160);

	}

	if (!m_background.loadFromFile("ASSETS/Menu_Background.png"))//load image and check for error
	{
		std::cout << "error with button file";//error message
	}
	backgroundSquare.setPosition(0, 0);
	backgroundSquare.setSize(sf::Vector2f(800, 600));
	backgroundSquare.setTexture(&m_background);

	if (!mouseyTexture.loadFromFile("ASSETS/mouse.png"))//load image and check for error
	{
		std::cout << "error with button file";//error message
	}
	if (!mouseyClickedTexture.loadFromFile("ASSETS/mouseClicked.png"))//load image and check for error
	{
		std::cout << "error with button file";//error message
	}
	mousey.setTexture(mouseyTexture);
	mousey.setPosition(100, 100);
}
