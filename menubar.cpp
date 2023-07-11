#include <iostream>

int main()
{
    char number;
    bool running = true;

    while (running)
    {
        std::cout << "-------------------------" << std::endl;
        std::cout << "|        Menu           |" << std::endl;
        std::cout << "|-----------------------|" << std::endl;
        std::cout << "|  1. Sort Numbers      |" << std::endl;
        std::cout << "|  2. Check Even        |" << std::endl;
        std::cout << "|  3. Check Odd         |" << std::endl;
        std::cout << "|  4. Check 5's         |" << std::endl;
        std::cout << "|  5. Divide Check      |" << std::endl;
        std::cout << "|  6. Max Number        |" << std::endl;
        std::cout << "|  7. Factorial         |" << std::endl;
        std::cout << "|  8. Swap Numbers      |" << std::endl;
        std::cout << "|  9. Even Numbers      |" << std::endl;
        std::cout << "| 10. Average           |" << std::endl;
        std::cout << "| 11. Average and Grade |" << std::endl;
        std::cout << "| 12. Even or Odd       |" << std::endl;
        std::cout << "|  0. Exit              |" << std::endl;
        std::cout << "-------------------------" << std::endl;

        std::cout << "Enter your choice: ";
        std::cin >> number;

        switch (number)
        {
            case '1':
            {
                int num1, num2, num3;
                std::cout << "(you can only enter 3 numbers)Enter number1: ";
                std::cin >> num1 >> num2>> num3;

                if (num1 < num2)
                    std::swap(num1, num2);
                if (num1 < num3)
                    std::swap(num1, num3);
                if (num2 < num3)
                    std::swap(num2, num3);

                std::cout << "Sorted numbers: " << num1 << ", " << num2 << ", " << num3 << std::endl;
                break;
            }
            case '2':
            {
                int number;
                std::cout << "Enter a number: ";
                std::cin >> number;

                if (number % 2 == 0)
                    std::cout << "The number is even." << std::endl;
                else
                    std::cout << "The number is odd." << std::endl;

                break;
            }
            case '3':
            {
                int number;
                std::cout << "Enter a number: ";
                std::cin >> number;

                if (number % 2 != 0)
                    std::cout << "The number is odd." << std::endl;
                else
                    std::cout << "The number is even." << std::endl;

                break;
            }
            case '4':
            {
                int num;
                std::cout << "Enter a number: ";
                std::cin >> num;

                bool found = false;
                while (num > 0)
                {
                    if (num % 10 == 5)
                    {
                        found = true;
                        break;
                    }
                    num /= 10;
                }

                if (found)
                    std::cout << "The number contains 5." << std::endl;
                else
                    std::cout << "The number does not contain 5." << std::endl;

                break;
            }
            case '5':
            {
                int num1, num2;
                std::cout << "Enter two numbers: ";
                std::cin >> num1 >> num2;

                if (num1 % num2 == 0)
                    std::cout << num1 << " is divisible by " << num2 << std::endl;
                else
                    std::cout << num1 << " is not divisible by " << num2 << std::endl;

                break;
            }
            case '6':
            {
                int num1, num2;
                std::cout << "Enter two numbers: ";
                std::cin >> num1 >> num2;

                int max = (num1 > num2) ? num1 : num2;
                std::cout << "The maximum number is: " << max << std::endl;

                break;
            }
            case '7':
            {
                int num;
                std::cout << "Enter a number: ";
                std::cin >> num;

                int factorial = 1;
                for (int i = 2; i <= num; i++)
                    factorial *= i;

                std::cout << "The factorial of " << num << " is: " << factorial << std::endl;

                break;
            }
            case '8':
            {
                int num1, num2;
                std::cout << "Enter two numbers: ";
                std::cin >> num1 >> num2;

                std::swap(num1, num2);
                std::cout << "Swapped numbers: " << num1 << ", " << num2 << std::endl;

                break;
            }
            case '9':
            {
                int num1, num2;
                std::cout << "Enter two numbers: ";
                std::cin >> num1 >> num2;

                if (num1 > num2)
                    std::swap(num1, num2);

                for (int i = num1; i <= num2; i++)
                {
                    if (i % 2 == 0)
                        std::cout << i << " ";
                }

                std::cout << std::endl;

                break;
            }
            case '10':
			{
				double num1, num2, num3;
				std::cout << "Enter three numbers: ";
				std::cin >> num1 >> num2 >> num3;
				double average = (num1 + num2 + num3) / 3.0;
				std::cout << "The average of the numbers is: " << average << std::endl;

				break;
			}
			case '11':
			{
				double num1, num2, num3;
				std::cout << "Enter three numbers: ";
				std::cin >> num1 >> num2 >> num3;

				double average = (num1 + num2 + num3) / 3.0;

				char grade;
				if (average >= 90)
					grade = 'A';
				else if (average >= 80)
					grade = 'B';					
				else if (average >= 70)
					grade = 'C';
				else if (average >= 60)
					grade = 'D';
				else
					grade = 'F';

				std::cout << "Average: " << average << ", Grade: " << grade << std::endl;

				break;
				}
				case '12':
				{
					int number;
					std::cout << "Enter a number: ";
					std::cin >> number;

					if (number == 0)
						std::cout << "The number is zero." << std::endl;
					else if (number % 2 == 0)
						std::cout << "The number is even." << std::endl;
					else
						std::cout << "The number is odd." << std::endl;

					break;
				}
				case '0':
					running = false; // Exit the program
					break;
				default:
					std::cout << "** Invalid Menu Choice **" << std::endl;
					break;