#pragma once
#include"SFML\Graphics.hpp"
#include<iostream>
//@Author Martin Farrell

class Intro//class for intro screen
{
public:
	Intro();//constructor
	~Intro();//destructor
	void update(sf::Time t_deltaTime);//update everything here
	void render(sf::RenderWindow &t_window);//draw everything
	void setup(sf::Font &t_font); //load fonts etc

private:
	sf::Font m_font; //used to store font for text objects
	sf::Text m_message; //message to display on intro screen
	int count = 0;//used to count frames
	int timer = 0;//used to count seconds
	int transparency = 255;//decremented to change transparency
	sf::RectangleShape m_earth;//stores earth sprite
	sf::RectangleShape m_ball; //stores ball sprite
	sf::Texture m_texture; //earth texture
	sf::Texture m_textureTwo; //ball texture
	sf::Vector2f ballPos; //stores position of ball, used for movement
	float ballSize = 100; //used to decrease ball in size
};
