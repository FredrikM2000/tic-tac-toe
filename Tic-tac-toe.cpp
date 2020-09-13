#include <iostream>

char position[10] = "123456789";
   void table() {
        std::cout << "  |  " << position[0] << "  ";
        std::cout << "|  " << position[1] << "  ";
        std::cout << "|  " << position[2] << "  |\n";
        std::cout << "  |  " << position[3] << "  ";
        std::cout << "|  " << position[4] << "  ";
        std::cout << "|  " << position[5] << "  |\n";
        std::cout << "  |  " << position[6] << "  ";
        std::cout << "|  " << position[7] << "  ";
        std::cout << "|  " << position[8] << "  |\n";
        std::endl(std::cout);
    }
int main() {
    int p1;
    bool win = false;

    std::cout << "\t******* Welcome to Tic Tac Toe! *******\n\n";

    do {
        table();
        int X[10] = {};

        std::cout << "Write a number between 1 or 9: ";
        std::cin >> p1;
        int choice = p1 - 1;

        if (position[choice] == 'X' || position[choice] == 'O') {
            std::cout << "Already taken" << std::endl;;
        } else {
            position[choice] = 'X';
        }
        for (int i = 0; i <= 7; i++) {
            for (int j = 1; j <= 4; j++) {
                if (position[i] == 'X' && position[i + j] == 'X' && position[i + j + j] == 'X') {
                    win = true;
                }
            }    
        }
    } while (win != true);
    table();
    std::cout << "Player 1 wins!";
}

