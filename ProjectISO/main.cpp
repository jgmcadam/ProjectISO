#include <SFML/Graphics.hpp>
#include "Input.h"

#include <iostream>

int main()
{
	// Create All the core systems 
	Input* inputSystem = new Input();

	// TODO: Create a window utilising the graphics settings system to load previous settings 
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			// TODO: Develop the core systems to handle these events - https://www.sfml-dev.org/tutorials/2.5/window-events.php#the-textentered-event
			switch (event.type)
			{
			case  sf::Event::Closed:
				window.close();
				break;
			case sf::Event::LostFocus:
				break;
			case sf::Event::GainedFocus:
				break;
			case sf::Event::KeyPressed:
				inputSystem->SetKeyDown(event.key.code);
				break;
			case sf::Event::KeyReleased:
				inputSystem->SetKeyUp(event.key.code);
				break;
			case sf::Event::MouseEntered:
				break;
			case sf::Event::MouseLeft:
				break;
			case sf::Event::MouseMoved:
				break;
			case sf::Event::MouseButtonPressed:
				inputSystem->SetMouseButtonDown(event.mouseButton.button);
				break;
			case sf::Event::MouseButtonReleased:
				inputSystem->SetMouseButtonUp(event.mouseButton.button);
				break;
			case sf::Event::MouseWheelScrolled:
				break;
			case sf::Event::TextEntered:
				inputSystem->SetCharEntered(event.text.unicode);
				break;
			case sf::Event::Resized:
				break;
			default:
				break;
				// Note: Do nothing this event is not handled
			}
		}

		if (Input::GetMouseButtonDown(sf::Mouse::Button::Right))
		{
			std::cout << "Right" << std::endl;
		}

		if (Input::GetMouseButtonDown(sf::Mouse::Button::Left))
		{
			std::cout << "Left" << std::endl;
		}

		inputSystem->EndInputFrame();

		window.clear();
		window.display();
	}

	return 0;
}


