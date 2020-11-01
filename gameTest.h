#include <iostream>
#include "IDAStar.h"
// #include "Board.h"
using namespace std;

void gameTest()
{
    char response = '1';
    Board board;
    while(response != '0')
    {
            int size = board.read();
            while (board.unsolvable())
            {
                cout << "This board does not have a solution. Please try with another board." << endl;
                size = board.read();
            }
            board.print(); 

            cout << "Enter position of zero in result:" << endl;
            int posOfZero;
            cin >> posOfZero;

            Board test;
            test.makeGoal(posOfZero, size);
            test.print();
            cout << std::boolalpha << test.solvable() << endl; 
            cout << test.countInversions() << "GAME TEST: " << endl;

            IDAStar game;
            game.setStart(board);
            game.setGoal(posOfZero, size);
            cout << game.play() << endl;

            cout << "Enter 0 to stop the game or 1 to continue." << endl;
            cin >> response;
            if (response == '0')
            {
                cout << "Game finished!" << endl;
            }
            else
            {
                cout << "New try started." << endl;
            }
    }
}
