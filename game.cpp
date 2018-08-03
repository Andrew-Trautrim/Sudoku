
#include "game.h"

// initiates grid values to 0 incase of lingering digits
void Game::init_grid()
{
    for(int y = 0; y < SIZE; ++y)
        for(int x = 0; x < SIZE; ++x)
            grid[y][x] = 0;
    
    return;
}

// Loads example Sudoku game.
// Supposedly the world's hardest Sudoku puzzle
// published by Finnish mathematician Arto Inkala
void Game::load_game()
{
    grid[0][0] = 8;
    
    grid[1][2] = 3;
    grid[1][3] = 6;
    
    grid[2][1] = 7;
    grid[2][4] = 9;
    grid[2][6] = 2;
    
    grid[3][1] = 5;
    grid[3][5] = 7;
    
    grid[4][4] = 4;
    grid[4][5] = 5;
    grid[4][6] = 7;
    
    grid[5][3] = 1;
    grid[5][7] = 3;
    
    grid[6][2] = 1;
    grid[6][7] = 6;
    grid[6][8] = 8;
    
    grid[7][2] = 8;
    grid[7][3] = 5;
    grid[7][7] = 1;
    
    grid[8][1] = 9;
    grid[8][6] = 4;
    
    return;
}

// prints text based Sudoku grid
void Game::print_grid()
{
    cout << " ------- ------- -------" << endl;
    for(int y = 0; y < SIZE; ++y)
    {
        cout << "| ";
        for(int x = 0; x < SIZE; ++x)
        {
            if(grid[y][x] == 0)
                cout << "  ";
            else
                cout << grid[y][x] << ' ';
            
            if((x+1) % 3 == 0)
                cout << "| ";
        }
        cout << endl;
        if((y+1) % 3 == 0)
            cout << " ------- ------- -------" << endl;
    }
    
    return;
}

// recursive solve function
bool Game::solve()
{
    int row, column;
    
    if(!find_unused_location(row, column))
        return true;
    
    // test values 1 - 9
    for(int i = 1; i <= 9; ++i)
    {
        if(check(row, column, i))
        {
            // assigns temporary value
            grid[row][column] = i;
            
            // recursively checks if possible solution from current point
            if(solve())
                return true;
            
            // resets value if no solution found
            grid[row][column] = 0;
        }
    }
    
    return false;
}

// check number for validity
bool Game::check(int row, int column, int test)
{
    // check row for repeated instances
    for(int i = 0; i < SIZE; ++i)
        if(grid[row][i] == test)
            return false;
    
    // check column for repeated instances
    for(int i = 0; i < SIZE; ++i)
        if(grid[i][column] == test)
            return false;
    
    // check box for repeated instances
    for(int i = (row - (row%3)), n = i+3; i < n; ++i)
        for(int j = (column - (column%3)), m = j+3; j < m; ++j)
            if(grid[i][j] == test)
                return false;
        
    return true;
}

// finds the first unused location, returns false otherwise
bool Game::find_unused_location(int& row, int& column)
{
    for (row = 0; row < SIZE; ++row)
        for(column = 0; column < SIZE; ++column)
            if(grid[row][column] == 0)
                return true;
    
    return false;
}