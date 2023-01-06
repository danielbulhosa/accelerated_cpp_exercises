#include <iostream>

int main() {
    std::cout << "Enter any two integers: " << std::endl;
    int num1 = 0, num2 = 0;
    std::cin >> num1 >> num2;

    if (num1 != num2){
        if(num1 > num2){
            std::cout << "The first number is larger than the second." << std::endl;
        }
        else{
            std::cout << "The second number is larger than the first." << std::endl;
        }
    }
    else{
        std::cout << "The numbers are equal!" << std::endl;
    }
}
