/* Member functions for the 'Planet' class. */

#include "Planet.hpp"
#include <cassert>
#include <iostream>
#include <cmath>

/* Constructor. */
Planet::Planet(float mass, sf::Vector2f pos, float radius, sf::Vector2f vel, sf::Color col)
	:m_mass{ mass }, m_pos{ pos }, m_radius{ radius }, m_vel{ vel }, m_col{ col }
{
	assert(mass > 0 && radius > 0 && "Invalid Planet Given.");

	m_planet.setRadius(m_radius);
	m_planet.setOrigin({ m_radius, m_radius });
	m_planet.setFillColor(m_col);
	m_planet.setPosition(m_pos);

	/* First point of path needs to be the starting point of the planet. */
	m_path.push_back(sf::Vertex(m_pos, m_col));
}

void Planet::update(float dt, std::vector<Planet>& v, int index)
{
	/* No movement variables need updating if planet is static. */
	if (m_static)
		return;

	m_acc = { 0.0f, 0.0f }; // Need to recalculate m_acc every frame.

	/* Add the gravitational acc's from each OTHER planet. */
	for (size_t i = 0; i < v.size(); ++i)
	{
		/* We don't want to calculate the gravity of the same planet. */
		if (i == index)
			continue;

		float delta_x{ v[i].m_pos.x - v[index].m_pos.x };
		float delta_y{ v[index].m_pos.y - v[i].m_pos.y };
		float acc_g{ Constants::G * v[i].m_mass / (delta_x * delta_x + delta_y * delta_y) };
		float ang{ atan2(delta_y,delta_x) };

		m_acc += { acc_g* cos(ang), -acc_g * sin(ang) };
	}

	m_vel += m_acc * dt;
	m_pos += m_vel * dt;

	m_planet.setPosition(m_pos);
}

void Planet::updatePath(sf::RenderWindow& window)
{
	/* If the planet can't move, draw no path. */
	if (m_static)
		return;

	/* Size check is done before rendering to prevent flickering. */
	if (m_path.size() >= Constants::max_path_length)
		m_path.erase(m_path.begin(), m_path.begin() + 1);

	/* Fade each line segment using its position in the 'm_path'. */
	for (std::size_t i = 0; i < m_path.size(); ++i)
		m_path[i].color = m_col * sf::Color(255, 255, 255, (int)(255.0f * ((float)(i) / (float)(m_path.size()))));

	/* Define array as start of vector and draw path. */
	sf::Vertex* lineArr = &m_path[0];
	window.draw(lineArr, m_path.size(), sf::Lines);

	/* Only allow an update to the path every 'path_resolution' ticks. */
	if (m_increment++ < Constants::path_resolution)
		return;

	m_increment = 0; // Reset increment to allow next segment to be drawn.
	m_path.push_back(sf::Vertex(m_pos, m_col));
	m_path.push_back(sf::Vertex(m_pos, m_col));
}

/* Draw the planet to the screen. */
void Planet::draw(sf::RenderWindow& window)
{
	window.draw(m_planet);
}

/* Using a pre-defined density, we convert from a spherical mass to a radius. */
float Planet::massToRadius(float mass)
{
	return pow((3.0f * mass) / (4.0f * Constants::pi * Constants::ro), (1.0f / 3.0f));
}