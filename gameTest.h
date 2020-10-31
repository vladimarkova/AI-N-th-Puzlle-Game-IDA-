#include <iostream>
// #include "IDAStar.h"
#include "Board.h"
using namespace std;

void gameTest()
{
    Board board, test;
    int size = board.read();
    /*while (!board.solvable())
    {
        cout << "This board does not have a solution. Please try with another board." << endl;
        size = board.read();
    }*/
    board.print();

    cout << "Enter position of zero in result:" << endl;
    int posOfZero;
    cin >> posOfZero;

    test.makeGoal(posOfZero, size);
    test.print();
    // cout << test.evenInversions() << endl;
    // IDAStar game;
    // game.setStart(board);
    // game.setGoal(posOfZero, size);

}