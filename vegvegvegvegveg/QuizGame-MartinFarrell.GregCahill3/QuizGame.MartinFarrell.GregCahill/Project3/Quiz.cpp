#include"Quiz.h"

Quiz::Quiz()
{
	//quiz one questions
	m_QuizOne[0].setString("One");
	m_QuizOne[1].setString("Two");
	m_QuizOne[2].setString("Three");
	m_QuizOne[3].setString("Nineteen");

	//quiz two questions
	m_QuizTwo[0].setString("Gold");
	m_QuizTwo[1].setString("Platinum");
	m_QuizTwo[2].setString("Bronze");
	m_QuizTwo[3].setString("Silver");

	for (int i = 0; i < 4; i++)//initialise buttons
	{
		m_buttons[i].setSize(sf::Vector2f(200, 50));
		m_buttons[i].setFillColor(sf::Color::Blue);
		m_buttons[i].setOutlineThickness(5);
		m_buttons[i].setOutlineColor(sf::Color::Red);
		m_buttons[i].setPosition(100, 100 + i * 75);
	}

	for (int i = 0; i < 4; i++)//intialise texts
	{
		m_QuizOne[i].setCharacterSize(24);
		m_QuizOne[i].setFont(m_font);
		m_QuizOne[i].setPosition(m_buttons[i].getPosition().x + 15, m_buttons[i].getPosition().y + 10);
		m_QuizOne[i].setFillColor(sf::Color::White);

		m_QuizTwo[i].setCharacterSize(24);
		m_QuizTwo[i].setPosition(m_buttons[i].getPosition().x + 15, m_buttons[i].getPosition().y + 10);
		m_QuizTwo[i].setFont(m_font);
		m_QuizTwo[i].setFillColor(sf::Color::White);
	}
	//initialise confirm button
	m_confirmButton.setSize(sf::Vector2f(200, 50));
	m_confirmButton.setFillColor(sf::Color::Blue);
	m_confirmButton.setOutlineThickness(5);
	m_confirmButton.setOutlineColor(sf::Color::Red);
	m_confirmButton.setPosition(500, 300);

	//initialise confirm text
	m_confirmText.setString("CONFIRM");
	m_confirmText.setCharacterSize(24);
	m_confirmText.setPosition(530, 310);
	m_confirmText.setFillColor(sf::Color::White);

	for (int i = 0; i < 2; i++)//initialise questions
	{
		m_questions[i].setCharacterSize(24);
		m_questions[i].setPosition(400, 210);
		m_questions[i].setFillColor(sf::Color::White);
	}

	m_questions[0].setString("How many goals on\n a football pitch?");
	m_questions[1].setString("What metals are used\n in olympic metals?");

	m_scoreText.setCharacterSize(20);
	m_scoreText.setPosition(500, 10);
	m_scoreText.setFillColor(sf::Color::White);
}

Quiz::~Quiz()
{
}

void Quiz::update(sf::Time t_deltaTime)
{
	if (!true)//change to bool from game.h
	{
		m_questions[0].setString("Where is the Arsenal\nFC home stadium?");
		m_questions[1].setString("Which of these are\nactual golf scores?");

		m_QuizOne[0].setString("Dublin");
		m_QuizOne[1].setString("London");
		m_QuizOne[2].setString("Manchester");
		m_QuizOne[3].setString("Louth");

		//quiz two questions
		m_QuizTwo[0].setString("Bogey");
		m_QuizTwo[1].setString("Falcon");
		m_QuizTwo[2].setString("Eagle");
		m_QuizTwo[3].setString("Strike");
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (buttonPressed == false)
		{
			m_buttons[count].setOutlineColor(sf::Color::Red);
			count++;
			buttonPressed = true;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (buttonPressed == false)
		{
			m_buttons[count].setOutlineColor(sf::Color::Red);
			count--;
			buttonPressed = true;
		}
	}
	else
	{
		buttonPressed = false;
	}

	if (!questionOne)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		{
			if (returnPressed == false)
			{
				if (selected[count] == true)
				{
					selected[count] = false;
				}
				else
				{
					selected[count] = true;
				}
				returnPressed = true;
			}
		}
		else
		{
			returnPressed = false;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (selected[i] == true)
		{
			m_buttons[i].setOutlineColor(sf::Color::Yellow);
		}
		else
		{
			m_buttons[i].setOutlineColor(sf::Color::Red);
		}
	}
	
	


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_confirmButton.setOutlineColor(sf::Color::Yellow);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_confirmButton.setOutlineColor(sf::Color::Red);
	}

	m_buttons[count].setOutlineColor(sf::Color::Yellow);

	if (questionOne == true && m_confirmButton.getOutlineColor() == sf::Color::Yellow && sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		questionOne = false;
		if (count == 1)
		{
			score = 1;
		}
	}
	m_scoreText.setString("Score: " + std::to_string(score));
	
}

void Quiz::render(sf::RenderWindow &t_window)
{
	t_window.clear();
	t_window.draw(m_scoreText);
	for (int i = 0; i < 4; i++)
	{
		t_window.draw(m_buttons[i]);
		if (questionOne)
		{
			t_window.draw(m_QuizOne[i]);
		}
		else
		{
			t_window.draw(m_QuizTwo[i]);
		}
	}

	t_window.draw(m_confirmButton);
	t_window.draw(m_confirmText);
	if (questionOne)
	{
		t_window.draw(m_questions[0]);
	}
	else
	{
		t_window.draw(m_questions[1]);
	}

	t_window.display();
}

void Quiz::setup(sf::Font & t_font)
{
	for (int i = 0; i < 4; i++)
	{
		m_QuizOne[i].setFont(t_font);
		m_QuizTwo[i].setFont(t_font);
	}
	m_confirmText.setFont(t_font);
	m_questions[0].setFont(t_font);
	m_questions[1].setFont(t_font);
	m_scoreText.setFont(t_font);
}
