#pragma once

#include <SFML/Graphics.hpp>

class Input final
{

public: 
	
	Input();
	~Input();

	void SetKeyDown(sf::Keyboard::Key keyCode);
	void SetKeyUp(sf::Keyboard::Key keyCode);
	void SetMouseButtonDown(sf::Mouse::Button mouseButton);
	void SetMouseButtonUp(sf::Mouse::Button mouseButton);
	void SetCharEntered(sf::Uint32 character);

	void EndInputFrame();

	static bool GetKeyUp(sf::Keyboard::Key keyCode);
	static bool GetKeyDown(sf::Keyboard::Key keyCode);
	static bool GetKey(sf::Keyboard::Key keyCode);
	static bool GetMouseButtonUp(sf::Mouse::Button mouseButton);
	static bool GetMouseButtonDown(sf::Mouse::Button mouseButton);
	static bool GetMouseButton(sf::Mouse::Button mouseButton);
	static bool TryGetTypedASCIICharacter(char* character);

private:

	static Input* m_instance;

	bool m_keyStates[sf::Keyboard::KeyCount];
	bool m_keyReleasedStates[sf::Keyboard::KeyCount];
	bool m_keyPressedStates[sf::Keyboard::KeyCount];

	bool m_mouseStates[sf::Mouse::Button::ButtonCount];
	bool m_mouseReleasedStates[sf::Mouse::Button::ButtonCount];
	bool m_mousePressedStates[sf::Mouse::Button::ButtonCount];

	char m_characterBuffer;

};