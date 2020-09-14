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

int i;
int j;
bool win = false;
void bruh() {
    if (position[i] == 'X' && position[i + j] == 'X' && position[i + j + j] == 'X') {
        win = true;
    }
}
int main() {
    int p1;

    std::cout << "\t******* Welcome to Tic Tac Toe! *******\n\n";
    bool player1_turn = true;
    do {
        table();
        int X[10] = {};

        if (player1_turn == true) {
            std::cout << "Write a number between 1 or 9: ";
            std::cin >> p1;
            int choice = p1 - 1;

            if (position[choice] == 'X' || position[choice] == 'O') {//checks if the spot is already taken
                std::cout << "Already taken" << std::endl;;
            }
            else {
                position[choice] = 'X';
            }

            /*int h;
            int v;
            int d;


            switch (choice) {
                case (0):
                    h = 1;
                    v = 2;
                    d = 4;
                    break;
                default:
                    ;
            }

            int j;
            int angle[4] = { h, v, d };
            for (int i = 0; i <= 2; i++) {
                j = angle[i];
                std::cout << angle[0];
                if (position[choice + j] == 'X' && position[choice + j + j] == 'X') {
                    win = true;
                    std::cout << i;
                }
            }*/
            for (i = 0; i <= 6; i++) {
                if (i % 3 == 0) {
                    j = 1;
                    bruh();
                    if (i == 0) {
                        j = 4;
                        bruh();
                    }
                }
                if (i <= 2) {
                    j = 3;
                    bruh();
                    if (i == 2) {
                        j = 2;
                        bruh();
                    }
                }
            }

            if (player1_turn = false) {

            }
        
           
        }
        switch (player1_turn) {
        case true:
            player1_turn = false;
            break;
        case false:
            player1_turn = true;
        }
    }while (win != true);
    table();
    std::cout << "Player 1 wins!";
}

