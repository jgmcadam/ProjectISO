#include "Input.h"

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
};

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
}
