#include <iostream>
#include <ctime>
#include <windows.h>

char position[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

bool win = false;
int currentPlayer = 1;
int counter = 0;
void table() {
        std::cout << "\n  |  " << position[0] << "  ";
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

void win_algorithm(int i, int j, char z) {
    if (position[i] == z && position[i + j] == z && position[i + j + j] == z) {
        win = true;
    }
}
void win_row(char z) {
    for (int n = 0; n <= 6;n++) {
        if (n % 3 == 0) {
            win_algorithm(n, 1, z);//checks horizontal rows for win
        }
        if (n <= 2) {
            win_algorithm(n, 3, z);//checks vertical rows for win
        }
        if (n == 2) {
            win_algorithm(n, 2, z);//checks one diagonal row for win
        }
        if (n == 0) {
            win_algorithm(n, 4, z);//checks the other diagonal row for win
        }
    }
}
void placementXO(char xo) {//Asks player to enter their placement, if it is taken, they try again until it is available, and then places the X/O 
    bool valid_input = false;
    int player;

    table();
    do {
        std::cout << "Player " << currentPlayer << ", write a number between 1 or 9 : ";
        std::cin >> player;

        int choice = player - 1;

        if (position[choice] == 'X' || position[choice] == 'O') {//checks if the spot is already taken
            std::cout << "Already taken" << std::endl;
            valid_input = false;
        }
        else {
            position[choice] = xo;//Places the X/O
            counter++;//counter to see if its a draw
            valid_input = true;
        }
    } while (valid_input == false);
}

int main() {
    std::cout << "\t******* Welcome to Tic Tac Toe! *******\n\n";

    bool valid_selection = true;
    do {
        int selection;
        std::cout << "Select option : \n";
        std::cout << "Play 1v1(1)\n";
        std::cout << "Play against AI(2)\n";
        std::cin >> selection;

        if (selection == 1) { //Play 1v1
            valid_selection = true;
            bool player1_turn = true;
            bool draw = false;
            do {
                if (player1_turn == true) {
                    placementXO('X');
                    win_row('X');
                }
                if (player1_turn == false) {
                    placementXO('O');
                    win_row('O');
                }

                if (counter == 9) {
                    draw = true;
                }

                switch (player1_turn) {
                case true:
                    player1_turn = false;
                    currentPlayer = 2;
                    break;
                case false:
                    player1_turn = true;
                    currentPlayer = 1;
                }
            } while (win == false && draw == false);

            table();
            if (draw == true) {
                std::cout << "Congratulations, you are equally bad";
            }
            else {
                if (player1_turn == false) {
                    std::cout << "Player 1 wins!";
                }
                else {
                    std::cout << "Player 2 wins!";
                }
            }
        } 


        else if (selection == 2) { //Play against AI
            valid_selection = true;
            bool draw = false;
            bool player1turn = true;

            do {
                player1turn = true;
                draw = false;
                placementXO('X');
                win_row('X');

                if (counter == 9) {
                    draw = true;
                }

                if (win != true && draw != true) {
                    player1turn = false;
                    bool placed = false;
                    do {// The AI places an O at a random available position
                        std::srand(static_cast<unsigned int>(std::time(nullptr)));
                        int placement = rand() % 8 + 1;

                        if (position[placement] == 'X' || position[placement] == 'O') {//checks if the spot is already taken
                        }
                        else {
                            position[placement] = 'O';
                            counter++;//counter to see if its a draw
                            placed = true;
                        }
                    } while (placed == false);

                    win_row('O');
                }
                if (draw == true && win == true) {//Makes sure that if the player wins with the last placement it comes out as a win, and not a draw
                    draw = false;
                }

            } while (win != true && draw != true);

            table();

            if (win == true) {
                if (player1turn == true) {
                    std::cout << "Congratulations, you won against the AI!";
                }
                else {
                    std::cout << "You lost against the AI";
                }
            }

            if (draw == true) {
                std::cout << "You drew with the AI";
            }

        } else {
                 std::cout << "Invalid option, try again";
                 valid_selection = false;
        }
            
    }while (valid_selection == false);
    
}


