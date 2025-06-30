#pragma once

#include <vector>

struct GameState {
    /// @brief 2D 3x3 game board; [1,2] on the board corresponds with [1,2] in the vector.
    std::vector<std::vector<int>> gameBoard{4, std::vector<int> (4)};

    /// @brief 1: X's turn; 0: O's turn.
    int currentPlayer = 1; 
    /// @brief true: Game is in progress; false: Game has not started or is already done.
    bool inProgress = false;
    /// @brief Game's winner at the moment. 'N': NULL - Undecided winner.
    char winner = 'N';
    int moveCount = 0;
};

namespace gameManager {

    /// @brief Start function
    void Start();

    /// @brief Loop function
    void Loop();

    /// @brief Game entity
    class game {

        public:

            /// @brief Make a move on [x,y] as the current player (X or O)
            /// @param x Move's row (1-3)
            /// @param y Move's column (1-3)
            /// @return 0: valid, proceeded move; 1: invalid, unattempted move.
            int playMove(const int& x, const int& y);

            /// @brief Print the board to CLI.
            void renderBoard();

            /// @brief Reset the game to a clean, new board.
            void resetBoard();

        private:
            /// @brief Game state - struct type that contains variables that define the game state
            GameState state;

            /// @brief 
            void calculateGameState();
    };
};