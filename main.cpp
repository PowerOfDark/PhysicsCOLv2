#include <SFML/Graphics.hpp>
#include "Physics/Entity/Circle.h"
#include "Physics/Collisions/Collisions.h"
#include <cstdlib>
#include <ctime>
#include "Math/Math.h"
#include "Physics/Move/Move.h"
#include "Physics/Gravity/Gravity.h"
#include <cmath>
#include <vector>
#include <chrono>
#include <thread>

#ifdef _MSC_VER
#include <Windows.h>
#endif


inline int min(int a, int b)
{
	if (a <= b) return a;
	return b;
}


int main()
{
	sf::RenderWindow window(sf::VideoMode(1300, 700, 32), "test");
	std::vector<Circle> circles;

	srand(time(nullptr));

	for (int i = 0; i < 200; i++)
	{
		sf::CircleShape circletmp;
		circletmp.setRadius(float(rand() % 1) + 2.4);
		//circletmp.setRadius(3);
		circletmp.setPosition(rand() % (window.getSize().x - 100) + 50, rand() % (window.getSize().y - 100) + 50);
		int fillcolor = min(circletmp.getRadius() * circletmp.getRadius() * 10, 255);
		circletmp.setFillColor(sf::Color(sf::Uint8(rand() % 254), sf::Uint8(rand() % 254), sf::Uint8(rand() % 254)));
		//circletmp.setFillColor(sf::Color(sf::Uint8 (fillcolor/2),sf::Uint8 (fillcolor),sf::Uint8 (fillcolor)));

		circles.emplace_back(circletmp);
		//circles[circles.size()-1].vx = float((rand()%20)+10)/100.f;
		//circles[circles.size()-1].vy = float((rand()%20)+10)/100.f;
		circles[circles.size() - 1].circleMass = (circles[circles.size() - 1].circleShape.getRadius()) / 10;
		//circles[circles.size()-1].circleMass =rand()%10+1;
	}

	while (window.isOpen())
	{
		sf::Event event{};
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		for (auto& circle : circles)
		{
			Collision::DetectWallCollision(circle, window);
		}
		for (int i = 0; i < circles.size(); i++)
		{
			for (int j = i + 1; j < circles.size(); j++)
			{
				if (Collision::DetectCollision(circles[i], circles[j]))
				{
					Collision::Collide(circles[i], circles[j]);
				}
			}
		}
		for (int i = 0; i < circles.size(); i++)
		{
			for (int j = i + 1; j < circles.size(); j++)
			{
				Gravity::Attract(circles[i], circles[j]);
			}
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2f mousepos;
			mousepos.x = float(sf::Mouse::getPosition().x);
			mousepos.y = float(sf::Mouse::getPosition().y);
			for (auto& circle : circles)
			{
				Gravity::Reject(mousepos, circle);
			}
		}
		std::this_thread::sleep_for(std::chrono::microseconds(1));
		//window.clear(sf::Color(10, 150, 250));
		window.clear(sf::Color::Black);
		for (auto& circle : circles)
		{
			Move::update(circle);
			window.draw(circle.circleShape);
		}
		window.display();
	}
	return 0;
}

#ifdef _MSC_VER

int CALLBACK WinMain(
	_In_ HINSTANCE hInstance,
	     _In_ HINSTANCE hPrevInstance,
	     _In_ LPSTR lpCmdLine,
	     _In_ int nCmdShow
)
{
	return main();
}

#endif
