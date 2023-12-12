#include "ArithmeticApp.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>
#include <string>
using namespace std;

Choice menuChoice;
bool correct;
int result;
string resultSummary;
list<tuple<int, Choice, int, int, bool, int>> history;

void generateQuestion() {
    int num1 = rand() % 9 + 1;
    int num2 = rand() % 9 + 1 ;
    int answer;

    switch (menuChoice) {
        case ADDITION:
            answer = num1 + num2;
            break;

        case SUBTRACTION:
            if (num1 < num2) {
                std::swap(operand1, operand2);
            }
            answer = num1 - num2;
            break;

        case MULTIPLICATION:
            answer = num1 * num2;
            break;

        case DIVISION:
            if (num2 == 0) {
                std::cout << "Error: Division by zero is not allowed." << std::endl;
                return;
            }
            answer = operand1 / operand2;
            break;

        default:
            break;
    }

    int userResult;
    int tries = 0;
    while (true) {
        tries++;
        std::cout << "Question: " << operand1 << " " << getOperationString(menuChoice) << " " << operand2 << " = ";
        std::cin >> userResult;

        if (userResult == answer) {
            correct = true;
            break;
        } else {
            correct = false;
            std::cout << "Incorrect! }
            void displayResultsSummary() {
                int totalAttempts = 0;
                int correctAnswers = 0;
                int incorrectAnswers = 0;

                for (const auto &item : history) {
                    bool correct = std::get<4>(item);
                    int tries = std::get<5>(item);

                    totalAttempts += tries;

                    if (correct) {
                        correctAnswers++;
                    } else {
                        incorrectAnswers++;
                    }
                }

                std::cout << "Total attempts: " << totalAttempts << ". ";
                std::cout << "Correct answers: " << correctAnswers << ". ";
                std::cout << "Incorrect answers: " << incorrectAnswers << ". ";
                std::cout << std::endl;
            }

            void displayHistory() {
                for (const auto &item : history) {
                    int question = std::get<0>(item);
                    Choice choice = std::get<1>(item);
                    int operand1 = std::get<2>(item);
                    int operand2 = std::get<3>(item);
                    bool correct = std::get<4>(item);
                    int tries = std::get<5>(item);

                    std::cout << "Question: " << question << " " << getOperationString(choice) << " " << operand1 << " and " << operand2 << ". ";
                    std::cout << "Attempts: " << tries << ". ";
                    std::cout << "Correct: " << (correct ? "Yes" : "No") << ". ";
                    std::cout << std::endl;
                }
            }

            void startApp() {
                while (true) {
                    displayMenu();
                    int choice;
                    std::cin >> choice;
                    if (choice == EXIT) {
                        break;
                    }
                    menuChoice = static_cast<Choice>(choice - 1);
                    if (menuChoice == EXIT) {
                        break;
                    }
                    generateQuestion();
                    history.push_back(std::make_tuple(result, menuChoice, operand1, operand2, correct, tries));
                    displayResultsSummary();
                }
            }