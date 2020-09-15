#include <iostream>

char position[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
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
int a;
int b;
bool win = false;
void check1() {
    if (position[i] == 'X' && position[i + j] == 'X' && position[i + j + j] == 'X') {
        win = true;
    }
}
void check2() {
    if (position[a] == 'O' && position[a + b] == 'O' && position[a + b + b] == 'O') {
        win = true;
    }
}
int main() {
    int p1;
    int p2;

    std::cout << "\t******* Welcome to Tic Tac Toe! *******\n\n";
    bool player1_turn = true;
    do {
        table();
        int X[10] = {};

        if (player1_turn == true) {
            std::cout << "Player 1, write a number between 1 or 9: ";
            std::cin >> p1;
            int choice1 = p1 - 1;

            if (position[choice1] == 'X' || position[choice1] == 'O') {//checks if the spot is already taken
                std::cout << "Already taken" << std::endl;;
            }
            else {
                position[choice1] = 'X';
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
                    check1();
                    if (i == 0) {
                        j = 4;
                        check1();
                    }
                }
                if (i <= 2) {
                    j = 3;
                    check1();
                    if (i == 2) {
                        j = 2;
                        check1();
                    }
                }
            }
        }
        if (player1_turn == false) {
            std::cout << "Player 2, write a number between 1 or 9: ";
            std::cin >> p2;
            int choice2 = p2 - 1;

            if (position[choice2] == 'X' || position[choice2] == 'O') {//checks if the spot is already taken
                std::cout << "Already taken" << std::endl;;
            }
            else {
                position[choice2] = 'O';
            }
            for (a = 0; a <= 6; a++) {
                if (a % 3 == 0) {
                    b = 1;
                    check2();
                    if (a == 0) {
                        b = 4;
                        check2();
                    }
                }
                if (a <= 2) {
                    b = 3;
                    check2();
                    if (a == 2) {
                        b = 2;
                        check2();
                    }
                }
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
    if (player1_turn == false) {
        std::cout << "Player 1 wins!";
    }
    else {
        std::cout << "Player 2 wins!";
    }
}

