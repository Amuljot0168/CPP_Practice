#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

// Declaring TicTacToe class
class TicTacToe
{
    // Data Member
private:
    int board[3][3]; // Board of 3 X 3

public:
    TicTacToe(); // Default Constructor

    // Member Functions
    void DisplayBoard();                         // Display board to user
    bool makeMove(int player, int row, int col); // Make move fo the user
    bool isDraw();                               // Check for draw in game
    int whoWin();                                // return player who wins the game
    void computerMove();                         // Function for Computer make move
};

#endif