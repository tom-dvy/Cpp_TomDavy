#define NOMINMAX
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <ctime>
#include <limits>
#include "Windows.h"
#include <conio.h>

// Get Input
bool isKeyPressed()
{
    if (_kbhit())
    {
        while (_kbhit()) // Flush input buffer
        {
            _getch();
        }
        return true; // Key Was Hit
    }
    return false; // No keys were pressed
}

int main()
{
    srand(time(NULL));

    float winInterval = 1.0f; // Intervalle de tolérance initial (en secondes)
    bool gagne = true;

    while (gagne)
    {
        // Variables
        float timeToFind = (float)(rand() % (10 + 1));

        // Règles du jeu
        std::cout << "----------------------------------" << std::endl;
        std::cout << "Bienvenue dans le ChronoSpacer !" << std::endl;
        std::cout << "Comptez jusqu'a " << timeToFind << " secondes..." << std::endl;
        std::cout << "Le decompte commence quand vous aurez appuyer sur une touche !" << std::endl;

        // Attente d'une entrée utilisateur
        system("pause");
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Vide le buffer
        std::cout << "C'est parti !" << std::endl;

        // Démarrage du chrono
        float startTime = (float)clock() / (float)CLOCKS_PER_SEC;
        float elapsedTime = 0.0f;
        bool touchePressee = false;

        // Boucle while
        while (true)
        {
            float currentTime = (float)clock() / (float)CLOCKS_PER_SEC;
            elapsedTime = currentTime - startTime;

            if (isKeyPressed())
            {
                touchePressee = true;
                break; // Sort de la boucle si une touche est pressée
            }
            if (elapsedTime > timeToFind + 10.0f)
            {
                // Plus de 10 secondes après le temps à estimer, partie perdue
                touchePressee = false;
                break;
            }
            Sleep(10);
        }

        // Fin du chrono
        std::cout << "Temps passe : " << elapsedTime << std::endl;
        if (!touchePressee)
        {
            std::cout << "Vous avez attendu trop longtemps !" << std::endl;
            gagne = false;
        }
        else if (elapsedTime >= timeToFind - winInterval && elapsedTime <= timeToFind + winInterval)
        {
            std::cout << "Bravo, vous avez gagne !" << std::endl;
            winInterval *= 0.2f; // Réduit l'intervalle de tolérance de 80%
            std::cout << "Nouvel intervalle de tolerance : " << winInterval << " secondes." << std::endl;
        }
        else
        {
            std::cout << "Dommage, vous avez perdu !" << std::endl;
            gagne = false;
        }
    }

    return 0;
}