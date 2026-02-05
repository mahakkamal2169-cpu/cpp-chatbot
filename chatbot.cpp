
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>
using namespace std;

// Chatbot function
void chatbot() {
    cout << "\n Chatbot: Hello! I'm your game assistant.\n";
    cout << "You can ask about rules, players, score, or how to play.\n";
    cout << "Type 'exit' to go back to the game.\n";

    string input;
    cin.ignore(); // clear leftover input

    while (true) {
        cout << "\nYou: ";
        getline(cin, input);

        // Convert to lowercase for easy comparison
        string question = input;
        transform(question.begin(), question.end(), question.begin(), ::tolower);

        if (question == "exit") {
            cout << "Chatbot: Okay! Back to the game.\n";
            break;
        }
        else if (question.find("rule") != string::npos) {
            cout << "Chatbot: Rules are simple:\n";
            cout << "1. Guess the number between 1 and 100.\n";
            cout << "2. You have 6 chances.\n";
            cout << "3. Each wrong guess reduces 5 points.\n";
        }
        else if (question.find("player") != string::npos) {
            cout << "Chatbot: Only one player can play at a time.\n";
        }
        else if (question.find("score") != string::npos) {
            cout << "Chatbot: You start with 100 points. Every wrong guess -5 points.\n";
        }
        else if (question.find("how") != string::npos && question.find("play") != string::npos) {
            cout << "Chatbot: Enter a number and see if it's correct. Try to guess in fewer moves!\n";
        }
        else if (question.find("win") != string::npos) {
            cout << "Chatbot: You win when you guess the correct number before using all moves.\n";
        }
        else {
            cout << "Chatbot: Sorry, I didn’t understand that. Try asking about rules or how to play.\n";
        }
    }
}

// Main game
int main() {
    srand(time(0));
    int playAgain = 1;

    cout << "==============================\n";
    cout << "       FIND ME GAME       \n";
    cout << "==============================\n";

    while (playAgain == 1) {
        int target = rand() % 100 + 1;
        int moves = 0;
        int score = 100;
        bool won = false;

        cout << "\nType 'chat' anytime to talk to the chatbot!\n";

        while (moves < 6 && !won && score > 0) {
            cout << "\nEnter your guess (1-100): ";
            string userInput;
            cin >> userInput;

            // Open chatbot
            if (userInput == "chat") {
                chatbot();
                continue;
            }

            int guess;
            try {
                guess = stoi(userInput);
            } catch (...) {
                cout << "Invalid input! Please enter a number or 'chat'.\n";
                continue;
            }

            if (guess < 1 || guess > 100) {
                cout << "Please enter a number between 1 and 100.\n";
                continue;
            }

            moves++;

            if (guess == target) {
                cout << "\n Correct! You found the number " << target << "!\n";
                cout << "You took " << moves << " moves.\n";
                cout << "Final Score: " << score << "/100\n";
                won = true;
            } 
            else if (guess < target) {
                cout << "Too low! Try a higher number.\n";
                score -= 5;
            } 
            else {
                cout << "Too high! Try a lower number.\n";
                score -= 5;
            }
        }

        if (!won) {
            cout << "\nGame Over! The number was " << target << ".\n";
        }

        cout << "\nDo you want to play again? (1 = Yes, 0 = No): ";
        cin >> playAgain;
    }

    cout << "\nThanks for playing! Goodbye \n";
    return 0;
}
