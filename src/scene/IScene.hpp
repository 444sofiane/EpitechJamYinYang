/*
** EPITECH PROJECT, 2023
** EpitechJamYinYang
** File description:
** IScene
*/

#ifndef ISCENE_HPP_
#define ISCENE_HPP_

#include "common.hpp"

class IScene {
    public:
        virtual ~IScene() = default;
        virtual void handleEvent(sf::Event& event, sf::RenderWindow& window) = 0;
        virtual void update(float dt) = 0;
        virtual void render(sf::RenderTarget& target) = 0;
        virtual void restart() = 0;
        virtual void stop() = 0;
    protected:
    private:
};

#endif /* !ISCENE_HPP_ */
