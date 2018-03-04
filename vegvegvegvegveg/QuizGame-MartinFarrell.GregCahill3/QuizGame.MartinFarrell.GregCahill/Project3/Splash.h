#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Splash
{
public:
	Splash();
	~Splash();
	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow &t_window);
	void setup(sf::Font &t_font);
private:
	sf::Font m_font;
	sf::Text m_message;
	sf::Text m_pressA;
	sf::Texture m_texture;
	sf::RectangleShape m_sprite;
	bool lightsOn = true;
	sf::Vector2f stringPos;
	int timer = 60;
};
