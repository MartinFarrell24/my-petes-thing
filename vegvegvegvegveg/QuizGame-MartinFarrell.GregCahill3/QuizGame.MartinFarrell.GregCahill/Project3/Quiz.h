#pragma once
#include"SFML\Graphics.hpp"
//@Author Martin Farrell & Greg Cahill
class Quiz//class used for quiz
{
public:
	Quiz();//constructor
	~Quiz();//destructor
	void update(sf::Time t_deltaTime);//update everything
	void render(sf::RenderWindow &t_window);//draw everything
	void setup(sf::Font &t_font);//load fonts

private:
	sf::Font m_font;//used to store font
	sf::Text m_QuizOne[4];//texts for question one buttons
	sf::Text m_QuizTwo[4];//texts for question 2 buttons
	
	sf::RectangleShape m_buttons[4];//buttons
	sf::RectangleShape m_confirmButton;
	sf::Text m_confirmText;
	sf::Text m_questions[2];
	sf::Text m_scoreText;

	int count = 0;//used to track buttons
	bool buttonPressed = false;
	bool questionOne = false;
	int score = 0;
	bool returnPressed = false;
	bool selected[4];
};
