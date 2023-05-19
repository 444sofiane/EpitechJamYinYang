/*
** EPITECH PROJECT, 2023
** EpitechJamYinYang
** File description:
** main
*/

#include "Engine.hpp"

int main(int argc, char **argv)
{
    Engine& engine = Engine::getInstance();

    engine.init();
    engine.run();
    return 0;
}