#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <ctype.h>

void operationCalculator(double& firstNumber , double secondNumber , char operatorSign) {

   switch (operatorSign) {

      case '+': firstNumber += secondNumber; break;
      case '-': firstNumber -= secondNumber; break;
      case '*': firstNumber *= secondNumber; break;
      case '/': firstNumber /= secondNumber; break;
      default: throw std::invalid_argument("invalid input");

   }

}

bool isNumber(std::string individualValue) {

   for(int i = 0 ; i < individualValue.size() ; i++) {

      if(!(isdigit(individualValue[i]))) {
         return false;
      }

   }
        
   return true; 
}

int main() {

   try {

      std::cout << "Enter the desired sequence: " << std::endl;

      std::string inputValues, individualValue;
      std::getline(std::cin , inputValues);
      std::istringstream input(inputValues);
      std::vector<double> numberVector;

      while(input >> individualValue) {

         if(isNumber(individualValue)) {

            numberVector.push_back(std::stoi(individualValue));

         } else {

            for (int i = 1; i < numberVector.size(); i++) {
               operationCalculator(numberVector.at(0) , numberVector.at(i) , individualValue[0]);
               numberVector.resize(1);
            }

         }
      }

      std::cout << numberVector.at(0);

   } catch (std::invalid_argument &excpt) {
      std::cout << "Invalid input" << std::endl;
   }
   
   return 0;
}

