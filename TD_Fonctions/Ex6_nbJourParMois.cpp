#include <iostream>
#include <cstdlib>

bool IsBissextile(int annee)
{
    if ((annee % 4 == 0 && annee % 100 != 0) || (annee % 400 == 0))
        return true;
    else
        return false;
}

int NombreDeJour(int mois, int annee)
{
    switch (mois)
    {
    case 1: // Janvier
    case 3: // Mars
    case 5: // Mai
    case 7: // Juillet
    case 8: // Aout
    case 10: // Octobre
    case 12: // Decembre
        return 31;
    case 4: // Avril
    case 6: // Juin
    case 9: // Septembre
    case 11: // Novembre
        return 30;
    case 2: // Fevrier
        if (IsBissextile(annee))
            return 29;
        else
            return 28;
    default:
        return -1; // Mois invalide
    }
}

int main()
{
    int annee = 2020;
    int mois = 2;
    
    std::cout << "Nombre de jours en " << mois << " en " << annee << " : " << NombreDeJour(mois, annee) << std::endl;
}