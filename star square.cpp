#include <iostream>

int main()
{
    int width, length;

    std::cout << "Enter the width of the square: ";
    std::cin >> width;

    std::cout << "Enter the length of the square: ";
    std::cin >> length;

    for (int i = 0; i < length; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            if (i == 0 || i == length - 1 || j == 0 || j == width - 1)
                std::cout << "* ";
            else
                std::cout << "  ";
        }
        std::cout << std::endl;
    }

    return 0;
}