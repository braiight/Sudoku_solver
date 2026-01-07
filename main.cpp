#include "sudoku.hpp"



 


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
                        if (isValidSudoku(board))
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