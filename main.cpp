
/* 
 * File:   main.cpp
 * Author: Andrew-Trautrim
 *
 * Created on July 30, 2018, 5:54 PM
 */

#include <cstdlib>

#include "game.h"

using namespace std;

/*
 * Sudoku solving program implementing a backtracking algorithm
 */

int main(int argc, char** argv) {
    Game sudoku;
    
    sudoku.init_grid();
    sudoku.load_game();
    sudoku.print_grid();
    
    if(sudoku.solve())
    { 
        cout << "Solution: " << endl;
        sudoku.print_grid();
    }
    else
    {
        cout << "No possible solutions" << endl;
    }
    
    return 0;
}

