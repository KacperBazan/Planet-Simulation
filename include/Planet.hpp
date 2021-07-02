#pragma once

#include <SFML/Graphics.hpp>		
#include <MyConstants.hpp>			
#include <vector>			

class Planet
{
private:
	float m_mass{ 100.0f };						// Mass of the planet.
	float m_radius{ 25.0f };					// Radius of the planet.
	sf::Vector2f m_pos{ Constants::offset };	// Vector position of the planet (X/Y Coordinates).
	sf::Vector2f m_vel{ 0.0f, 0.0f };			// Vector velocity of the planet.
	sf::Vector2f m_acc{ 0.0f, 0.0f };			// Vector acceleration of the planet.
	sf::Color m_col{ Constants::planet_color }; // Color of the planet.
	bool m_static{ false };						// Determines whether planet can move or not.

	sf::CircleShape m_planet{};			// Rendered circle of the planet.
	std::vector<sf::Vertex> m_path{};	// Vector containing lines of the planet's path.
	int m_increment{ 0 };				// Increment that works alongside path resolution.

public:
	/* Constructor. */
	Planet(float mass, sf::Vector2f pos, float radius, sf::Vector2f vel, sf::Color col);

	void draw(sf::RenderWindow& window);					  // Draw planet to screen.
	void update(float dt, std::vector<Planet>& v, int index); // Update planet's position.
	void updatePath(sf::RenderWindow& window);				  // Update line's within path.

	void setStatic(bool b) { m_static = b; } // Set whether planet is allowed to move or not.
	static float massToRadius(float mass);   // Convert mass of sphere to radius using constant density.
};

