#include "Input.h"

#define _NOCHAR -1

Input* Input::m_instance = nullptr;

Input::Input()
{
	m_instance = this;
}

Input::~Input()
{
	m_instance = nullptr;
}

void Input::SetKeyDown(sf::Keyboard::Key keyCode)
{
	if (m_keyStates[keyCode] == false)
	{
		m_keyPressedStates[keyCode] = true;
	}

	m_keyStates[keyCode] = true;
}

void Input::SetKeyUp(sf::Keyboard::Key keyCode)
{
	if (m_keyStates[keyCode] == true)
	{
		m_keyReleasedStates[keyCode] = true;
	}

	m_keyStates[keyCode] = false;
}

void Input::SetCharEntered(sf::Uint32 character)
{
	if (character < 128)
	{
		m_characterBuffer = static_cast<char>(character);
	}
}

bool Input::GetKeyUp(sf::Keyboard::Key keyCode)
{
	return m_instance->m_keyReleasedStates[keyCode];
}

bool Input::GetKeyDown(sf::Keyboard::Key keyCode)
{
	return m_instance->m_keyPressedStates[keyCode];
}

bool Input::GetKey(sf::Keyboard::Key keyCode)
{
	return  m_instance->m_keyStates[keyCode];
}

bool Input::TryGetTypedASCIICharacter(char* character)
{
	if (m_instance->m_characterBuffer == _NOCHAR)
	{
		return false;
	}

	(*character) = m_instance->m_characterBuffer;
	return true;
}


void Input::EndInputFrame()
{
	for (int i = 0; i < sf::Keyboard::KeyCount; i++)
	{
		m_keyReleasedStates[i] = false;
	}

	for (int i = 0; i < sf::Keyboard::KeyCount; i++)
	{
		m_keyPressedStates[i] = false;
	}

	m_characterBuffer = _NOCHAR;
}
