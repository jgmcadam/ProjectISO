#pragma once

#include <SFML/Graphics.hpp>

class Input final
{

public: 
	
	Input();
	~Input();

	void SetKeyDown(sf::Keyboard::Key keyCode);
	void SetKeyUp(sf::Keyboard::Key keyCode);
	void SetCharEntered(sf::Uint32 character);

	void EndInputFrame();

	static bool GetKeyUp(sf::Keyboard::Key keyCode);
	static bool GetKeyDown(sf::Keyboard::Key keyCode);
	static bool GetKey(sf::Keyboard::Key keyCode);
	static bool TryGetTypedASCIICharacter(char* character);

private:

	static Input* m_instance;

	bool m_keyStates[sf::Keyboard::KeyCount];
	bool m_keyReleasedStates[sf::Keyboard::KeyCount];
	bool m_keyPressedStates[sf::Keyboard::KeyCount];

	char m_characterBuffer;

};