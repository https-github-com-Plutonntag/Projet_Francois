#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

using namespace std;

int main() {
    // Seed the random number generator
    srand(time(0));

    int sequenceLength; // Length of the sequence
    int correctGuesses = 0; // Counter for correct guesses

    // Ask the player to choose the length of the sequence
    cout << "Choose the length of the sequence:\n"
        "1. Sequence of 5\n"
        "2. Sequence of 10\n"
        "3. Sequence of 25\n"
        "Enter your choice: ";
    int choice;
    cin >> choice;

    // Determine the length of the sequence based on the player's choice
    switch (choice) {
    case 1:
        sequenceLength = 5;
        break;
    case 2:
        sequenceLength = 10;
        break;
    case 3:
        sequenceLength = 25;
        break;
    default:
        cout << "Invalid choice! Exiting program." << endl;
        return 1;
    }

    // Array to store the sequence of random numbers
    int sequence[sequenceLength];

    // Generate the sequence of random numbers and store them in the array
    for (int i = 0; i < sequenceLength; ++i) {
        sequence[i] = rand() % 3 + 1;
    }

    // Start the game
    while (correctGuesses < sequenceLength) {
        // Display the options and ask the player to choose
        cout << "Guess the " << correctGuesses + 1 << "th number in the sequence (1, 2, or 3): ";
        int userChoice;
        cin >> userChoice;

        // Compare user's choice with the corresponding number in the sequence
        if (userChoice == sequence[correctGuesses]) {
            cout << "Right! You guessed the correct number." << endl;
            correctGuesses++;
        }
        else {
            cout << "Wrong guess! Restarting from the beginning." << endl;
            correctGuesses = 0; // Reset the counter for correct guesses
        }
    }

    cout << "Congratulations! You guessed the correct sequence!" << endl;
}?