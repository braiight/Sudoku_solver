#include "sudoku.hpp"

   void    printBoard(Board &board)
    {
        std::cout << "Printing Board:\n";
        for (size_t i = 0; i < board.size(); i++)
        {
            for (size_t j = 0; j < board[i].size(); j++)
            {
                std::cout << board[i][j] << ' ';
            }
            std::cout << "\n";
        }
    }

    bool validRow(std::vector<char> &originalRow)
    {
        std::vector<char> row = originalRow;
        std::sort(row.begin(), row.end());
        for (int i = 1; i < 9; i++)
        {
            if (isdigit(row[i]))
            {
                if (row[i] == row[i - 1])
                {
/*                     std::cout << "This row is false: \n";
                    printVec(row); */
                    return (false);
                }
            }
        }
/*         std::cout << "This passed the check:\n";
        printVec(row); */
        return (true);
    }

    bool validColumn(Board& board, int colIndex)
    {
        std::vector<char> column;
        for (size_t i = 0; i < 9; i++)
        {
            column.push_back(board[i][colIndex]);
        }
        return (validRow(column));
    }
    bool checkSquare(Board& board, int col, int row)
    {
        std::vector<char> toCheck;
        for (int i = col; i < col + 3; i++)
        {
            for (int j = row; j < row + 3; j++)
            {
                toCheck.push_back(board[i][j]);
            }
        }
        return (validRow(toCheck));
    }
    bool checkAllSquares(Board& board)
    {
        if (!checkSquare(board, 0, 0))
            return (false);
        if (!checkSquare(board, 0, 3))
            return (false);
        if (!checkSquare(board, 0, 6))
            return (false);
        if (!checkSquare(board, 3, 0))
            return (false);
        if (!checkSquare(board, 3, 3))
            return (false);
        if (!checkSquare(board, 3, 6))
            return (false);
        if (!checkSquare(board, 6, 0))
            return (false);
        if (!checkSquare(board, 6, 3))
            return (false);
        if (!checkSquare(board, 6, 6))
            return (false);
        return (true);
    }

    bool isValidSudoku(Board& board)
    {
        //check all rows
        for (size_t i = 0; i < 9; i++)
        {
            if (!validRow(board[i]))
                return (false);
            if (!validColumn(board, i))
                return (false);
        }
/*         std::cout << "Passed row and column check\n"; */
        return (checkAllSquares(board));
    }


    bool    boardIsFull(Board &board)
    {
        for (size_t i = 0; i < board.size(); i++)
        {
            for (size_t j = 0; j < board[i].size(); j++)
            {
                if (!isdigit(board[i][j]))
                    return (false);
            }
        }
        return (true);
    }