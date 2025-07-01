#pragma once

#include <vector>

namespace GameManager {

    /// @brief Start function
    void Start();

    /// @brief Loop function
    void Loop();


    enum class Player {None, O, X};
    enum class Winner {None, O, X, Draw};

    struct GameState {
        /// @brief 2D game board; [1,2] on the board corresponds with [1,2] in the vector.
        std::vector<std::vector<Player>> gameBoard;
        /// @brief Length of square board
        int boardSize = 0;
        /// @brief Minimum number of consecutive X or O to win.
        int minimumToWin = 0;
        /// @brief 1: X's turn; 0: O's turn.
        Player currentPlayer;
        /// @brief Game's winner at the moment.
        Winner winner;
        int moveCount;
    };

    /// @brief Game entity
    class Game {

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

            /// @brief 
            void setGameRules();

        private:
            /// @brief Calculate game state and change variables
            void calculateGameState();
    };

    /// @brief Game state - struct type that contains variables that define the game state
    extern GameState state;
    extern Game game;
};