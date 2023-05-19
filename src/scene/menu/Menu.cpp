/*
** EPITECH PROJECT, 2023
** EpitechJamYinYang
** File description:
** Menu
*/

#include "Menu.hpp"

Menu::Menu()
{
    m_uiElements["Settings"] = std::make_shared<ui::Text>();

    sf::Vector2f wSize(info::getWindowSize());

    m_background.setSize(sf::Vector2f(WINDOW_SIZE));
    m_background.setTexture(&getResource().getTexture("menu_bg"));

    ui::Text* title = ((ui::Text*)m_uiElements.at("Settings").get());
    title->setString("Settings");
    title->setFont(getResource().getFont("title_font"));
    title->setCharacterSize(100);
    title->setPosition({wSize.x * 0.5, wSize.y * 0.1});
    title->setOrigin(title->getGlobalBounds().width / 2, title->getGlobalBounds().height / 2);
}

Menu::~Menu()
{
}

void Menu::handleEvent(sf::Event &event, sf::RenderWindow &window)
{
    for (auto& [key, element] : m_uiElements) {
        element->handleEvent(event, window);
    }
}

void Menu::update(float dt)
{
}

void Menu::render(sf::RenderTarget &target)
{
    target.draw(m_background);
    for (auto& [key, element] : m_uiElements)
        element->render(target);
}

void Menu::restart()
{
    SceneManager::getInstance().setCurrentSceneIndex(0);
}

void Menu::stop()
{
    if(m_music != nullptr)
        m_music->stop();
}