#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void playRound(int &userScore, int &computerScore);
void showMenu();
void showStatistics(int userScore, int computerScore);

int main() {
    srand(time(0));  // Initiera slumpgenerator

    int userScore = 0, computerScore = 0;
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:  // Starta nytt spel
                userScore = 0;
                computerScore = 0;
                while (userScore < 3 && computerScore < 3) {
                    playRound(userScore, computerScore);
                    cout << "Poängställning: Du " << userScore << " - Datorn " << computerScore << endl;
                }
                if (userScore == 3) {
                    cout << "Grattis, du vann matchen!" << endl;
                } else {
                    cout << "Datorn vann matchen." << endl;
                }
                break;
            case 2:  // Visa statistik
                showStatistics(userScore, computerScore);
                break;
            case 3:  // Avsluta spelet
                cout << "Avslutar spelet..." << endl;
                break;
            default:
                cout << "Ogiltigt val, försök igen." << endl;
        }

    } while (choice != 3);

    return 0;
}

void playRound(int &userScore, int &computerScore) {
    string userChoice;
    cout << "Välj sten, sax eller påse: ";
    cin >> userChoice;

    // Generera slumpmässigt val för datorn
    int randomChoice = rand() % 3;
    string computerChoice;
    if (randomChoice == 0) computerChoice = "sten";
    else if (randomChoice == 1) computerChoice = "sax";
    else computerChoice = "påse";

    cout << "Datorn valde: " << computerChoice << endl;

    // Jämför val och uppdatera poäng
    if (userChoice == computerChoice) {
        cout << "Oavgjort!" << endl;
    } else if ((userChoice == "sten" && computerChoice == "sax") ||
               (userChoice == "sax" && computerChoice == "påse") ||
               (userChoice == "påse" && computerChoice == "sten")) {
        cout << "Du vann denna runda!" << endl;
        userScore++;
    } else {
        cout << "Datorn vann denna runda." << endl;
        computerScore++;
    }
}

void showMenu() {
    cout << "\n1. Starta nytt spel\n";
    cout << "2. Visa statistik\n";
    cout << "3. Avsluta spelet\n";
    cout << "Gör ditt val: ";
}

void showStatistics(int userScore, int computerScore) {
    cout << "Poängställning: Du " << userScore << " - Datorn " << computerScore << endl;
}
