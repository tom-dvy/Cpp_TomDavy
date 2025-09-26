#include <iostream>
#include <cstdlib>

int distance(int a, int b)
{
    if (a > b)
        return a - b;
    else
        return b - a;
}

int main()
{
    std::cout << "distance(25, 42): " << distance(25, 42) << std::endl;

    std::cout << "distance(42, 25): " << distance(42, 25) << std::endl;
}