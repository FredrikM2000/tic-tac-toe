#include <iostream>


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
void check1(int i, int j, char z) {
    if (position[i] == z && position[i + j] == z && position[i + j + j] == z) {
        win = true;
    }
}
void check2(char z) {
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
void test(char brick) {
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
            //available_position[choice].remove
            valid_input = true;
        }
    } while (valid_input == false);
}



//************************REMEMBER TO COMMENT TO EXPLAIN ALL THIS SHIT*****************
/*things you could do:
-color the X an O red
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

        if (selection == 1) {
            valid_selection = true;
            bool player1_turn = true;
            bool draw = false;
            do {
                int X[10] = {};

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
            } while (win != true && draw != true);

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
        else if (selection == 2) {
            valid_selection = true;
            
            

            //std::cout << available_position[0];

            int r = 0;
            do {
                test('X');
                check2('X');
                //available spots = positions


                //for (int q = 0;q <= 9;q++) {
                //    if (position[q] == 'X' || position[q] == 'O') {
                //    }
                //    else {
                //        available_position.erase(available_position.begin() + q);
                //        std::cout << available_position[q];
                //    }
                //}

                /*available spot.random = 'O'*/


                int placement;// = random
                //while nothing is placed
                //if already placement already taken nothing happens, if not place

                if (position[placement] == 'X' || position[placement] == 'O') {//checks if the spot is already taken
                }
                else {
                    position[placement] = 'O';
                    a++;//counter to see if its a draw
                    //available_position[choice].remove
                }






                position[r] = 'O';

                check2('O');



                r++;
            } while (win != true);

            table();

            std::cout << "You win!";





            
            } else {
                 std::cout << "Invalid option, try again";
                 valid_selection = false;
            }
            
    }while (valid_selection == false);
    
}


