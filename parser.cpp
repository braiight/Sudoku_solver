#include "sudoku.hpp"

    Board parseFile(std::string fileName)
    {
        std::ifstream inputFile(fileName);
        std::string line;
        Board board;
        int lineCount = 0;
        while (std::getline(inputFile, line) && lineCount < 9)
        {

            std::vector<char> row;
            for (size_t i = 0; i < line.length(); i++)
            {
                if (isdigit(line[i]) || line[i] == '.')
                {
                    row.push_back(line[i]);
                }
                else
                {
                    std::cout << "Error! Invalid input, only numbers and periods are allowed!\n";
                    exit(EXIT_FAILURE);
                }
            }
            if (row.size() != 9)
            {
                std::cout << "Error! Rows can only have 9 characters!";
                exit(EXIT_FAILURE);
            }
            board.push_back(row);
            lineCount++;
        }
        if (board.size() != 9)
        {
            std::cout << "Error! Board must have 9 rows";
            exit(EXIT_FAILURE);
        }
        return (board);
    }