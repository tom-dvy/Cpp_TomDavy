#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

struct AIData
{
    bool useAI = false;
    int aiGoodAnswer = 0;
    int aiBadAnswer = 0;
    int aiLevel = 5;
    int aiMin = 1;
    int aiMax = 100;
};

int CompareAndDisplay(int playerInput, int numberToFind)
{
    if (playerInput < numberToFind)
    {
        std::cout << "C'est plus !" << std::endl;
        std::cout << "----------------------------------" << std::endl;
        return 1;
    }
    else if (playerInput > numberToFind)
    {
        std::cout << "C'est moins !" << std::endl;
        std::cout << "----------------------------------" << std::endl;
        return -1;
    }
    else
    {
        std::cout << "----------------------------------" << std::endl;
        std::cout << "Bravo, vous avez trouver le nombre !" << std::endl;
        return 0;
    }
}

int AIChoose(int aiMin, int aiMax, int aiLevel)
{
    if (aiLevel == 10)
        return (aiMin + aiMax) / 2;
    else
    {
        float ratio = aiLevel / 10.0f;
        int plage = (aiMax - aiMin + 1);
        int range = std::max(1, static_cast<int>(plage * ratio));
        int minChoice = aiMin;
        int maxChoice = std::min(aiMax, aiMin + range - 1);
        if (maxChoice < minChoice)
            return aiMin;

        return minChoice + rand() % (maxChoice - minChoice + 1);
    }
}

int AIResult(int result, int playerInput, int &aiMin, int &aiMax)
{
    if (result == -1)
    {
        aiMax = playerInput - 1;
    }
    else if (result == 1)
    {
        aiMin = playerInput + 1;
    }
    return 0;
}

int main()
{
    srand(time(NULL));

    // Variables pour l'IA
    AIData ai;

    // Variables
    int playerMaxInput = 100;
    int playerInput;
    int coups = 0;
    float moyenne = 0.0f;

    // Règles du jeu
    std::cout << "----------------------------------" << std::endl;
    std::cout << "Bienvenue dans le Plus ou Moins !" << std::endl;
    std::cout << "Vous allez devoir deviner un nombre aleatoire !" << std::endl;

    std::cout << "----------------------------------" << std::endl;
    std::cout << "Voulez-vous utiliser l'IA (Y/N) : " << std::endl;
    char aiChoice;
    std::cin >> aiChoice;
    ai.useAI = (aiChoice == 'y' || aiChoice == 'Y');

    // Choix du niveau de l'IA
            std::cout << "Choisissez le niveau de l'IA (1-10) : ";
            std::cin >> ai.aiLevel;
            if (ai.aiLevel < 1)
                ai.aiLevel = 1;
            if (ai.aiLevel > 10)
                ai.aiLevel = 10;
    
    for (int i = 0; i < 100; i++)
    {

        //std::cout << "Choisissez le nombre maximum que vous pouvez entrer : ";
        //std::cin >> playerMaxInput;
        ai.aiMax = playerMaxInput;

        int coupsPartie = 0;
        ai.aiMin = 1;
        ai.aiMax = playerMaxInput;

        int numberToFind = (rand() % (playerMaxInput + 1));

        if (ai.useAI)
        {

            // Lancement du jeu avec l'IA
            std::cout << "L'IA va essayer de deviner le nombre !" << std::endl;
            std::cout << "----------------------------------" << std::endl;
            int result = -1;
            do
            {
                playerInput = AIChoose(ai.aiMin, ai.aiMax, ai.aiLevel);
                std::cout << "L'IA choisit : " << playerInput << std::endl;
                result = CompareAndDisplay(playerInput, numberToFind);
                AIResult(result, playerInput, ai.aiMin, ai.aiMax);
                coupsPartie++;
                if (result == 0)
                {
                    ai.aiGoodAnswer++;
                }
                else
                {
                    ai.aiBadAnswer++;
                }
            } while (result != 0);
            // std::cout << "L'IA a trouve le nombre en " << coups << " coups !" << std::endl;
            coups += coupsPartie;
        }
        else
        {
            do
            {
                std::cout << "Choisissez un nombre entre 0 et " << playerMaxInput << " : ";
                std::cin >> playerInput;
                coups++;
            } while (CompareAndDisplay(playerInput, numberToFind) != 0);

            std::cout << "Vous avez trouve le nombre en " << coups << " coups !" << std::endl;
        }
        if (ai.useAI && ai.aiGoodAnswer > 0)
        {
        moyenne = static_cast<float>(coups) / ai.aiGoodAnswer;
        std::cout << "L'IA a trouver en moyenne " << moyenne << " essais !" << std::endl;
        std::cout << "L'IA a eu " << ai.aiGoodAnswer << " bonnes reponses et " << ai.aiBadAnswer << " mauvaises reponses." << std::endl;
        }
    }

    return 0;
}