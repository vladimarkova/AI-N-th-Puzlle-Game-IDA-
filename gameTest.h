#pragma once
#include <iostream>
#include "Board.h"
#include "IDAStar.h"
using namespace std;

void gameTest()
{
    char response = '1';
    Board board;
    while(response != '0')
    {
            board.read();
            int size = board.getSize();
            while (board.unsolvable())
            {
                cout << "This board does not have a solution. Please try with another board." << endl;
                board.read();
                size = board.getSize();
            }
            board.print(); 

            cout << "Enter position of zero in result:" << endl;
            int posOfZero;
            cin >> posOfZero;

            IDAStar game;
            game.setStart(board);
            game.setGoal(posOfZero, size);
            vector<string> result = game.play();
            if (result.size() > 0 && result[0] == "UNSOLVABLE")
            {
                cout << "This board is unsolvable!" << endl;
            }
            else
            {
                cout << result.size() << endl;
                for (int i = 0; i < result.size(); i++)
                {
                    cout << result[i] << endl;
                }
            }

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
