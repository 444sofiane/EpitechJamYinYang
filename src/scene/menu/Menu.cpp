/*
** EPITECH PROJECT, 2023
** EpitechJamYinYang
** File description:
** Menu
*/

#include "Menu.hpp"

Menu::Menu()
{
    m_background.setSize(sf::Vector2f(WINDOW_SIZE));
    m_backgroud.setTexture(&getResource().getTexture("menu_bg"));
}
Menu::~Menu()
{
}

void Menu::handleEvent(sf::Event &event, sf::RenderWindow &window)
{
}

void Menu::update(float dt)
{
}

void Menu::render(sf::RenderTarget &target)
{
}

void Menu::restart()
{
    
}

void Menu::stop()
{
}