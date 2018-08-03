
/* 
 * File:   board.h
 * Author: Andrew-Trautrim
 *
 * Created on July 30, 2018, 5:54 PM
 */

#ifndef GAME_H
#define GAME_H

#include <iostream>

static const int SIZE = 9;

using namespace std;

class Game {
public:
    
    void init_grid();
    void load_game();
    void print_grid();
    
    bool solve();
    
private:
    
    int grid[SIZE][SIZE];
    
    bool check(int row, int column, int check);
    bool find_unused_location(int& row, int& column);
    
};

#endif /* GAME_H */

