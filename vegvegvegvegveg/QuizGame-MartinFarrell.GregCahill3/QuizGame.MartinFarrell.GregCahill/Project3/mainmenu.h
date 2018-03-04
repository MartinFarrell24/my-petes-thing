#pragma once
#include <SFML/Graphics.hpp>

class MainMenu
{
public:
	MainMenu();
	~MainMenu();
	void update(sf::Time t_deltaTime, sf::Window &t_window);
	void render(sf::RenderWindow &t_window);
	void setup(sf::Font &t_font);
private:
	sf::Font m_font;
	sf::Text m_message;
	sf::RectangleShape menuButtons[4];
	/// Number of buttons on our menu
	static const int m_optionCount = 5;
	/// green button background
	sf::Texture m_buttonTexture[4];
	/// array of sprites used to display buttons
	sf::Sprite m_buttonSprites[m_optionCount];

	sf::Texture m_background;
	sf::RectangleShape backgroundSquare;

	sf::Sprite mousey;
	sf::Texture mouseyTexture;
	sf::Texture mouseyClickedTexture;
};

