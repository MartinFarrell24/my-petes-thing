#include"Intro.h"
#include"Game.h"
#include"Gamestate.h"

Intro::Intro()//destructor
{
	if (!m_texture.loadFromFile("ASSETS\\Globe.png"))//load globe sprite
	{
		// error...
	}

	if (!m_textureTwo.loadFromFile("ASSETS\\ball.png"))//load ball sprite
	{
		// error...
	}

	m_earth.setOrigin(75, 75);//set origin to centre of sprite
	m_earth.setTexture(&m_texture);//apply texture
	m_earth.setSize(sf::Vector2f(150, 150));
	m_earth.setPosition(575, 200);

	m_ball.setOrigin(ballSize / 2, ballSize / 2);//set origin to centre of sprite
	m_ball.setTexture(&m_textureTwo);
	m_ball.setSize(sf::Vector2f(ballSize, ballSize));
	m_ball.setPosition(195, 715);
}

Intro::~Intro()//destructor
{
}

void Intro::update(sf::Time t_deltaTime)
{
	transparency--;//decrement the alpha value
	m_message.setFillColor(sf::Color(255, 0, 0, transparency));//update with new transparency

	count++;//count frames
	if (count == 60)//add a second every 60
	{
		timer++;
		count = 0;//reset frames
	}
		ballSize -= 0.5;//decrease size
		m_ball.setSize(sf::Vector2f(ballSize, ballSize));//set new size

	m_earth.rotate(1);//rotate planet 
	if (timer >= 4)//draw transition when text is done
	{
		m_ball.rotate(-1);//rotate ball
		ballPos = m_ball.getPosition();//initialise to balls current pos
		ballPos.x++;//move right one pixel
		ballPos.y -= 2;//move up 2 pixels
		m_ball.setPosition(ballPos);//set new pos
	}

	if (timer >7)//change to splash when transition is done
	{
		Game::m_gamestate = GameState::Splash;
	}
}

void Intro::render(sf::RenderWindow & t_window)//draw everything in the window
{
	t_window.clear();//clear screen
	if (timer < 4)//draw text for first 3 seconds
	{
		t_window.draw(m_message);
	}
	else//then draw everything else
	{
		t_window.draw(m_ball);
		t_window.draw(m_earth);
	}
	t_window.display();//display updates graphics
}

void Intro::setup(sf::Font & t_font)//load fonts and set up text
{
	m_message.setFont(t_font);
	m_message.setString("A Greg & Murt Production");//string
	m_message.setCharacterSize(28);
	m_message.setPosition(200, 400);
	m_message.setFillColor(sf::Color(255, 0, 0, transparency));
}



