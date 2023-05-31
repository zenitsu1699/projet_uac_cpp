/*
** PROJECT, 2023
** BY Gérard TOUDOGUIN
** File description:
** main
*/

#include "./window/Window.hpp"

int main(void)
{
    Window window("NEWSLETTER");

    window.gameLoop();

    return (EXIT_SUCCESS);
}