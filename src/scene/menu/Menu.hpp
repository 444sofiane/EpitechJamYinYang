/*
** EPITECH PROJECT, 2023
** EpitechJamYinYang
** File description:
** Menu
*/

#ifndef MENU_HPP_
    #define MENU_HPP_

#include "IScene.hpp"
#include "Widget.hpp"
#include "SceneManager.hpp"

class MenuScene : public IScene{
    public:
        Menu();
        ~Menu();
        void handleEvent(sf::Event& event, sf::RenderWindow& window) override;
        void update(float dt) override;
        void render(sf::RenderTarget& target) override;
        void restart() override;
        void stop() override;
    protected:
        std::unordered_map<std::string, std::shared_ptr<ui::Widget>> m_uiElements;
        sf::RectangleShape m_background;
        sf::Music* m_music = nullptr;
    private:
};

#endif /* !MENU_HPP_ */
