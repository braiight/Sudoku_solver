#include "sudoku.hpp"


bool checkPlacementSquare(Board& board, int col, int row)
{
    std::vector<char> toCheck;
    col = (col / 3) * 3;
    row = (row / 3) * 3;
    for (int i = col; i < col + 3; i++)
    {
        for (int j = row; j < row + 3; j++)
        {
            toCheck.push_back(board[i][j]);
        }
    }
    return (validRow(toCheck));
}


bool isValidPlacement(Board& board, int i, int j)
    {
        if (!validRow(board[i]))
            return (false);
        if (!validColumn(board, j))
            return (false);

        return (checkPlacementSquare(board, i, j));
    }


    bool    fillEmptyCell(Board& board)
    {

        if (boardIsFull(board) && isValidSudoku(board))
            return (true);

        char num = '1';
        for (size_t i = 0; i < board.size(); i++)
        {
            for (size_t j = 0; j < board[i].size(); j++)
            {
                if (!isdigit(board[i][j]))
                {
                    while (num <= '9')
                    {
                        board[i][j] = num;
                        if (isValidPlacement(board, i, j))
                        {
                            // printBoard(board);
                            if (fillEmptyCell(board))
                                return (true);
                        }
                        num++;
                    }
                    board[i][j] = '.';
                    return (false);
                }
            }
        }
        return (false);
    }







    int main(int argc, char **argv)
    {
        Board board;


        std::cout << "SUDOKU SOLVER!!\n\n";

        if (argc != 2)
        {
            std::cout << "Error! Must pass one and only one input file as parameter!\n";
            return (1);
        }
        board = parseFile(argv[1]);
        std::cout << "Current Board:\n";
        printBoard(board);

        if (fillEmptyCell(board))
        {
            std::cout << "Success! Here is the solved board:\n";
            printBoard(board);
        }
        else
        {
            std::cout << "This board is unsolvable!\n";
        }
        return (0);

    }