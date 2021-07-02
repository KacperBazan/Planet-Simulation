#include <SFML/Graphics.hpp>
#include "MyConstants.hpp"
#include "Planet.hpp"
#include <iostream>
#include <vector>

int main()
{
	std::vector<Planet> planet_list{};
	planet_list.push_back(Planet{ 1000.0f, {150.0f,500.0f}, Planet::massToRadius(1000.0f), {0.0f, 10.54092553f}, sf::Color::Red });
	planet_list.push_back(Planet{ 600.0f, {700.0f,500.0f}, Planet::massToRadius(600.0f), {0.0f, -22.36067977f}, sf::Color::Green });
	planet_list.push_back(Planet{ 600.0f, {500.0f,500.0f}, Planet::massToRadius(600.0f), {0.0f, 22.36067977f}, sf::Color::White });
	planet_list.push_back(Planet{ 50.0f, {200.0f,500.0f}, Planet::massToRadius(50.0f), {0.0f, 20.0f}, sf::Color::Magenta });
	planet_list.push_back(Planet{ 10000.0f, Constants::offset, Planet::massToRadius(10000.0f), {0.0f, -2.0f}, sf::Color::Yellow });
	planet_list[planet_list.size() - 1].setStatic(true); // Prevent "Sun" from moving. 

	/* Make the window and set the Anti-Aliasing level. */
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(Constants::screen_width, Constants::screen_height), "Planets by Kacper", sf::Style::Close, settings);

	/* Entry for main loop */
	while (window.isOpen())
	{
		/* Checks if window is ever closed */
		sf::Event window_event{};
		while (window.pollEvent(window_event))
		{
			if (window_event.type == sf::Event::Closed)
				window.close();
		}

		/* Clears screen buffer to the constant space color. */
		window.clear(Constants::space_color);

		/* Draw each planet and path to the window. */
		for (size_t i = 0; i < planet_list.size(); ++i)
		{
			planet_list[i].update(Constants::dt, planet_list, i);
			planet_list[i].draw(window);
			planet_list[i].updatePath(window);
		}

		/* Render objects to screen */
		window.display();
	}
	return 0;
}