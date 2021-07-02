#pragma once
#include <SFML/Graphics.hpp>

namespace Constants
{
	/* Screen Variables */
	const int screen_height{ 1000 };
	const int screen_width{ 1200 };
	const sf::Vector2f offset{ (float)screen_width / 2.0f, (float)screen_height / 2.0f };

	/* Physics Variables */
	const float pi{ 3.14159265f };
	const float G{ 5.0f };			// Universal gravitational constant. 
	const float dt{ 0.005f };		// Incremental time step for the simulation.
	const float ro{ 0.1f };			// Density of planets.

	/* Cosmetic Variables */
	const sf::Color space_color{ sf::Color(31,31,31) };
	const sf::Color planet_color{ sf::Color(71,237,155) };

	/* Path Variables */
	const int path_resolution{ 100 };	// Lower is more detailed. <100 is visually negligible.
	const int max_path_length{ 150 };	// Determines how long each path is before fading out.
}