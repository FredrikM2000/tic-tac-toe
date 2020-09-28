#include <iostream>
#include <ctime>

char position[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

bool win = false;
int currentPlayer = 1;
int a = 0;
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
void check1(int i, int j, char z) {//CHANGE
    if (position[i] == z && position[i + j] == z && position[i + j + j] == z) {
        win = true;
    }
}
void check2(char z) {//CHANGE
    for (int n = 0; n <= 6;n++) {
        if (n % 3 == 0) {
            check1(n, 1, z);
        }
        if (n <= 2) {
            check1(n, 3, z);
        }
        if (n == 2) {
            check1(n, 2, z);
        }
        if (n == 0) {
            check1(n, 4, z);
        }
    }
}
void test(char brick) {//CHANGE
    bool valid_input = false;
    int player;

    table();
    do {
        std::cout << "Player " << currentPlayer << ", write a number between 1 or 9 : ";
        std::cin >> player;
        int choice = player - 1;

        if (position[choice] == 'X' || position[choice] == 'O') {//checks if the spot is already taken
            std::cout << "Already taken" << std::endl;
        }
        else {
            position[choice] = brick;
            a++;//counter to see if its a draw
            valid_input = true;
        }
    } while (valid_input == false);
}

//************************REMEMBER TO COMMENT TO EXPLAIN ALL THIS SHIT*****************
/*things you could do:
-color the X and O red
-ability to replay
-ability to choose level
*/ 
int main() {
    std::cout << "\t******* Welcome to Tic Tac Toe! *******\n";

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
                    test('X');
                    check2('X');
                }
                if (player1_turn == false) {
                    test('O');
                    check2('O');
                }

                if (a == 9) {
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
                test('X');
                check2('X');


                if (a == 9) {
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
                            a++;//counter to see if its a draw
                            placed = true;
                        }
                    } while (placed == false);

                    check2('O');
                }
                if (draw == true && win == true) {//Makes sure that if the player wins with the last placement it doesn't come out as a draw
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


