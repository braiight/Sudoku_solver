#ifndef SUDOKU_HPP
# define SUDOKU_HPP


#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>

typedef std::vector<std::vector<char> > Board;


Board   parseFile(std::string fileName);
void    printBoard(Board &board);
bool    validRow(std::vector<char> &originalRow);
bool    validColumn(Board& board, int colIndex);
bool    checkSquare(Board& board, int col, int row);
bool    checkAllSquares(Board& board);
bool    isValidSudoku(Board& board);
bool    boardIsFull(Board &board);

#endif