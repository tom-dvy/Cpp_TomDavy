#include <iostream>
#include <cstdlib>

bool IsBissextile(int annee)
{
    if ((annee % 4 == 0 && annee % 100 != 0) || (annee % 400 == 0))
        return true;
    else
        return false;
}

int main()
{
    int annee = 2000;
    
    do
    {
        if (IsBissextile(annee))
            std::cout << annee << " est une annee bissextile" << std::endl;
        else
            std::cout << annee << " n'est pas une annee bissextile" << std::endl;
        annee++;
    } 
    while (annee != 2022);
}