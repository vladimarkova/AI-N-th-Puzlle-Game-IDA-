#include <iostream>
#include "IDAStar.h"
// #include "Board.h"
using namespace std;

void gameTest()
{
    Board board, test;
    int size = board.read();
    board.print();

    cout << "Enter position of zero in result:" << endl;
    int posOfZero;
    cin >> posOfZero;

    test.makeGoal(posOfZero, size);
    test.print();
    // IDAStar game;
    // game.setStart(board);
    // game.setGoal(posOfZero, size);

}