#include <iostream>

char tic[10] = "123456789";
   void table() {
        std::cout << "  |  " << tic[0] << "  ";
        std::cout << "|  " << tic[1] << "  ";
        std::cout << "|  " << tic[2] << "  |\n";
        std::cout << "  |  " << tic[3] << "  ";
        std::cout << "|  " << tic[4] << "  ";
        std::cout << "|  " << tic[5] << "  |\n";
        std::cout << "  |  " << tic[6] << "  ";
        std::cout << "|  " << tic[7] << "  ";
        std::cout << "|  " << tic[8] << "  |\n";
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
        tic[choice] = 'X';

        
        
        /*for i 0 - 2, if i + 3 + 3 exist in X-array win = true
        for 0,3,6 if i + 1 + 1 exist = win
        for tic[0] if i + 4 + 4 exist = win
        for tic[2] if i + 2 + 2 exist = win

        *REMEMBER IF SPOT ALREADY TAKEN NOT VALID*

        */
    } while (win != true);
    table();
}

