// Project is to build Countdown Math Game
//Author: Pathik Sangani
// Date: September 30th, 2024


#include <iostream>
#include "mersenne-twister.h"

using namespace std;

// global variables for keeping track of the numbers and the target
int num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0, num6 = 0;
int target = 0;

// function declarations
void removeNumber(int number);
void addNumber(int number);
void displayNumbers();
void displayTarget();
int chooseRandomNumber(int min,int max);

int main(){
    int randSeed, numBig;
    
    cout << "Enter random seed: " << endl;
    cin >> randSeed;
    seed(randSeed);


    cout << "Let's play Countdown!" << endl;
    cout << "How many big numbers would you like (0-4)? " << endl;
    cout << endl;
    cin >> numBig;

    // generate big numbers
    for (int i =0; i < numBig; i++){
        int bigNum = chooseRandomNumber(1,4) * 25;
        addNumber(bigNum);
    }

    // generate little numbers
    for (int i = 0; i < (6 - numBig); i++){
        int littleNum = chooseRandomNumber(1,10);
        addNumber(littleNum);
    }

    // generate target number
    target = chooseRandomNumber(101,999);

    // Display numbers and target
    displayNumbers();
    displayTarget();

    // game loop
    while(true){
        cout << "Enter a calculation (or 0 to quit): " << endl;
        string input;

        int firstNumber, secondNumber;
        char operation;
        
        if (cin >> firstNumber){
            if (firstNumber == 0){
                break; // Quit the game
            }
        }
        cin >> operation >> secondNumber;

        // Perform the calculation
        int result = 0;
        bool validOperation = true;

        switch(operation){
            case '+':
                result = firstNumber + secondNumber;
                break;
            case '-':
                result = firstNumber - secondNumber;
                break;
            case '*':
                result = firstNumber * secondNumber;
                break;
            case '/':
                if (secondNumber == 0 || firstNumber % secondNumber != 0) {
                    cout << "Invalid calculation (division error)!" << endl;
                    validOperation = false;
                } else {
                    result = firstNumber / secondNumber;
                }
                break;
            default:
                cout << "Invalid operation! Use +, -, *, or /." << endl;
                validOperation = false;
        }

        if (validOperation) {
            

            cout << firstNumber << " " << operation << " " << secondNumber << " = " << result << endl;
            cout << endl;

            // Remove used numbers and add the result
            removeNumber(firstNumber);
            removeNumber(secondNumber);
            addNumber(result);

            

            // Check for win condition
            if (result == target) {
                cout << "You win!" << endl;
                break;
            }

            // Check for lose condition
            int remainingNumbers = (num1 != 0) + (num2 != 0) + (num3 != 0) + (num4 != 0) + (num5 != 0) + (num6 != 0);
            if (remainingNumbers == 1 && (num1 != target && num2 != target && num3 != target && num4 != target && num5 != target && num6 != target)) {
                cout << "You lose." << endl;
                break;
            }
            // Display updated numbers and target
            displayNumbers();
            displayTarget();
        }
    }

    return 0;
} 

void removeNumber(int number){
    if (num1 == number) num1 = 0;
    else if (num2 == number) num2 = 0;
    else if (num3 == number) num3 = 0;
    else if (num4 == number) num4 = 0;
    else if (num5 == number) num5 = 0;
    else if (num6 == number) num6 = 0;
}

void addNumber(int number){
    if (num1 == 0) num1 = number;
    else if (num2 == 0) num2 = number;
    else if (num3 == 0) num3 = number;
    else if (num4 == 0) num4 = number;
    else if (num5 == 0) num5 = number;
    else if (num6 == 0) num6 = number;
}

void displayNumbers(){
    cout << "Your numbers are: ";
    if (num1 != 0) cout << num1 << " ";
    if (num2 != 0) cout << num2 << " "; 
    if (num3 != 0) cout << num3 << " "; 
    if (num4 != 0) cout << num4 << " ";
    if (num5 != 0) cout << num5 << " ";
    if (num6 != 0) cout << num6 << " ";
    cout << endl;
}

void displayTarget(){
    cout << "The target is: " << target << endl;
}

int chooseRandomNumber(int min, int max){
    return rand_u32() % (max - min + 1) + min;
}
