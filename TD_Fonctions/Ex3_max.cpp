#include <iostream>
#include <cstdlib>

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}

int main()
{
    std::cout << "Le max entre 42 et 66 : " << max(42,66) << " et le min : " << min(42,66) << std::endl;
}