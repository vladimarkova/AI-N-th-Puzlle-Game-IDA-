#include <iostream>
// #include "IDAStar.h"
#include "Board.h"
using namespace std;

void gameTest()
{
    Board board;
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

    // IDAStar game;
    // game.setStart(board);
    // game.setGoal(posOfZero, size);
    // game.play();

    Board test;
    test.makeGoal(posOfZero, size);
    test.print();
    cout << std::boolalpha << test.solvable() << endl; 
    cout << test.countInversions() << endl;
}
