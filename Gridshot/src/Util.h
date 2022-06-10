#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Util
{
private:
	const int WIDTH, HEIGHT;

	// load/setup font and styles:
	sf::Font tFont;

	// text settings
	const size_t fontSize = 18;
	const sf::Color fontColor = sf::Color::Red;

public:
	Util();

	/* font and text settings: */
	sf::Font LoadFont();    
	void SetupText(sf::Text& tStartText, const std::string& name);

	/* Helper Get functions: */
	sf::Font GetFont() const;
	size_t GetFontSize() const;
	sf::Color GetFontColour() const;

	int GetScreenWidth() const;
	int GetScreenHeight() const;
};

inline Util::Util() : WIDTH(800), HEIGHT(600), tFont(LoadFont())
{
	std::cout << "Util constructor called" << std::endl;
}

/* font and text settings: */
inline sf::Font Util::LoadFont() 
{
	sf::Font f;
	if (!f.loadFromFile("./assets/fonts/FiraCode-Regular.ttf"))
	{
		std::cout << "ERROR: Can't find font, wrong path!";
	}
	return f;
}

inline void Util::SetupText(sf::Text& tStartText, const std::string& name)
{
	tStartText.setFont(tFont);
	tStartText.setFillColor(fontColor);
	tStartText.setCharacterSize(fontSize);
	tStartText.setString(name);

	// make origin point center of text, then center it to window
	tStartText.setOrigin(
		tStartText.getGlobalBounds().width/2, 
		tStartText.getGlobalBounds().height/2
	);
	tStartText.setPosition(static_cast<float>(WIDTH)/2, static_cast<float>(HEIGHT)/2);
}

/* Get methods: */
inline sf::Font Util::GetFont()			const { return tFont; }
inline size_t Util::GetFontSize()		const { return fontSize; }
inline sf::Color Util::GetFontColour()	const { return fontColor; }
inline int Util::GetScreenWidth()		const { return WIDTH; }
inline int Util::GetScreenHeight()		const { return HEIGHT; }