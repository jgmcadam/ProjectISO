#include "Input.h"

#define _NOCHAR -1

Input* Input::m_instance = nullptr;

Input::Input()
{
	LogUtils::LogToDebug("Input System Created.");
	LogUtils::LogToDebug("Input System Created.");
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

void Input::SetMouseButtonDown(sf::Mouse::Button mouseButton)
{
	if (m_mouseStates[mouseButton] == false)
	{
		m_mousePressedStates[mouseButton] = true;
	}

	m_mouseStates[mouseButton] = true;
}

void Input::SetMouseButtonUp(sf::Mouse::Button mouseButton)
{
	if (m_mouseStates[mouseButton] == true)
	{
		m_mousePressedStates[mouseButton] = false;
	}

	m_mouseStates[mouseButton] = false;
}

void Input::SetCharEntered(sf::Uint32 character)
{
	if (character < 128)
	{
		m_characterBuffer = static_cast<char>(character);
	}
}

void Input::SetMousePosition(int x, int y)
{
	m_mousePosition.x = x;
	m_mousePosition.y = y;
}

void Input::SetVerticalScrollWheelDelta(float mouseWheelDelta)
{
	m_mouseVerticalScrollWheelDelta = mouseWheelDelta;
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
	return m_instance->m_keyStates[keyCode];
}

bool Input::GetMouseButtonUp(sf::Mouse::Button mouseButton)
{
	return m_instance->m_mouseReleasedStates[mouseButton];
}

bool Input::GetMouseButtonDown(sf::Mouse::Button mouseButton)
{
	return m_instance->m_mousePressedStates[mouseButton];
}

bool Input::GetMouseButton(sf::Mouse::Button mouseButton)
{
	return m_instance->m_mouseStates[mouseButton];
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

sf::Vector2i Input::GetMousePosition()
{
	return m_instance->m_mousePosition;
}

float Input::GetVerticalScrollWheelDelta()
{
	return m_instance->m_mouseVerticalScrollWheelDelta;
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

	for (int i = 0; i < sf::Mouse::Button::ButtonCount; i++)
	{
		m_mouseReleasedStates[i] = false;
	}

	for (int i = 0; i < sf::Mouse::Button::ButtonCount; i++)
	{
		m_mousePressedStates[i] = false;
	}

	m_characterBuffer = _NOCHAR;

	m_mouseVerticalScrollWheelDelta = 0.0f;
}
