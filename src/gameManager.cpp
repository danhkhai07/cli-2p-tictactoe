#include "gameManager.h"

#include <iostream>
#include <vector>
// #include <thread> // sleep_for, sleep_until
// #include <chrono> // ms, ns, ...
#include <string>
#include <utility>

namespace GameManager {
    Game game;

    void Start(){
        std::cout << "CLI Two-Player Tic Tac Toe - Written by danhkhai07\n";
        std::cout << "- Github repository: https://github.com/danhkhai07/cli-2p-tictactoe\n\n";
        GameManager::Loop();
    }

    void Loop(){
        int err = 0; // hold playMove() value
        game.setGameRules();
        game.renderBoard();
        std::cout << '\n';
        while (true){
            int x, y;
            std::string prompt;
            std::cout << game.currentPlayer() << "'s move:\n";
            
            while (true){
                std::cout << "- x cordinate: "; std::cin >> x;
                if (std::cin.fail()){
                    std::cout << "Invalid input.";
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    continue;
                }   
                if (x <= 0 || x > game.boardSize()){
                    std::cout << "Out of range!\n";
                    continue;
                }
                break;
            }
    
            while (true){
                std::cout << "- y cordinate: "; std::cin >> y;
                if (std::cin.fail()){
                    std::cout << "Invalid input.";
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    continue;
                }   
                if (y <= 0 || y > game.boardSize()){
                    std::cout << "Out of range!\n";
                    continue;
                }
                break;
            }

            err = game.playMove(x-1,y-1);
            if (err == 1){
                std::cout << "\n[" << x << ',' << y <<"] is an occupied square! Try another move.\n\n";
            }

            if (err == 0){
                std::cout << "==============================\n";
                game.renderBoard();
                std::cout << '\n';
                Winner result = game.calculateGameState();
                bool end_flag = true;
                switch (result){
                    case Winner::None:
                        end_flag = false;
                        break;
                    case Winner::Draw:
                        std::cout << "The game has resulted in a draw!\n";
                        break;
                    case Winner::X:
                        std::cout << "X has won!\n";
                        break;
                    case Winner::O:
                        std::cout << "O has won!\n";
                        break;
                }
                
                if (end_flag){
                    std::cout << "\n";
                    break;
                }
            }
        }
        std::cout << "Thanks for playing the game!\n";
        std::cout << "Brought to you by danhkhai07.\n";
        std::cin.get();

        return;
    }

    //Define class Game
    int Game::playMove(const int& x, const int& y){
        if (game.state.gameBoard[x][y] != Player::None) return 1;
        game.state.gameBoard[x][y] = game.state.currentPlayer;
        if (game.state.currentPlayer == Player::X) game.state.currentPlayer = Player::O;
        else game.state.currentPlayer = Player::X;
        game.state.moveCount++;
        return 0;
    }

    void Game::renderBoard(){
        for (int i = 0; i <= state.boardSize; i++){
            std::cout << "   ";
            for (int j = 0; j <= state.boardSize; j++){
                if (i == 0){
                    if (j != 0) std::cout << j << ' ';
                    else std::cout << "  ";
                    continue;
                }

                if (j == 0 && i != 0) {
                    std:: cout << i << ' ';
                    continue;
                }

                switch (state.gameBoard[j-1][i-1]){
                    case Player::None:
                        std::cout << '.';
                        break;
                    case Player::O:
                        std::cout << 'O';
                        break;
                    case Player::X:
                        std::cout << 'X';
                        break;
                }
                std::cout << ' ';
            }
            std::cout << '\n';
        }
    }

    void Game::resetBoard(){
        state.gameBoard.resize(state.boardSize, std::vector<Player> (state.boardSize));
        state.currentPlayer = Player::X;
        state.winner = Winner::None;
        state.moveCount = 0;
    }

    Winner Game::calculateGameState(){
        int maxRange = state.boardSize - state.minimumToWin;
        for (int x = 0; x < state.boardSize; x++){
            for (int y = 0; y < state.boardSize; y++){
                bool check_flag = true;
                // Horizontal check
                if (x <= maxRange){
                    // X check
                    for (int i = x; i <= x + state.minimumToWin - 1; i++){
                        if (state.gameBoard[i][y] != Player::X){
                            check_flag = false;
                            break;
                        }
                    }
                    if (check_flag) return Winner::X;
                    // O check
                    check_flag = true;
                    for (int i = x; i <= x + state.minimumToWin - 1; i++){
                        if (state.gameBoard[i][y] != Player::O){
                            check_flag = false;
                            break;
                        }
                    }
                    if (check_flag) return Winner::O;
                }

                // Vertical check
                if (y <= maxRange){
                    // X check
                    check_flag = true;
                    for (int i = y; i <= y + state.minimumToWin - 1; i++){
                        if (state.gameBoard[x][i] != Player::X){
                            check_flag = false;
                            break;
                        }
                    }
                    if (check_flag) return Winner::X;
                    // O check
                    check_flag = true;
                    for (int i = y; i <= y + state.minimumToWin - 1; i++){
                        if (state.gameBoard[x][i] != Player::O){
                            check_flag = false;
                            break;
                        }
                    }
                    if (check_flag) return Winner::O;
                }

                // Diagonal check
                if (x <= maxRange && y <= maxRange){
                    // X check
                    check_flag = true;
                    for (int i = x; i <= x + state.minimumToWin - 1; i++){
                        if (state.gameBoard[i][i] != Player::X){
                            check_flag = false;
                            break;
                        }
                    }
                    if (check_flag) return Winner::X;
                    // O check
                    check_flag = true;
                    for (int i = x; i <= x + state.minimumToWin - 1; i++){
                        if (state.gameBoard[i][i] != Player::O){
                            check_flag = false;
                            break;
                        }
                    }
                    if (check_flag) return Winner::O;
                }
            }
        }

        if (state.moveCount == state.boardSize*state.boardSize) return Winner::Draw;
        return Winner::None;
    }

    void Game::setGameRules(){
        int boardSize, minimumToWin;
        std::cout << "Set game rules:\n";
        while (true){
            std::cout << "   boardSize (integer from 1-9) = "; std::cin >> boardSize;
            if (std::cin.fail()){
                std::cout << "Invalid input.";
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                continue;
            }   
            if (boardSize <= 0 || boardSize > 9){
                std::cout << "Out of range!\n";
                continue;
            }
            break;
        }
        while (true){
            std::cout << "   minimumToWin (integer > 0 && <= boardSize) = "; std::cin >> minimumToWin;
            if (std::cin.fail()){
                std::cout << "Invalid input.";
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                continue;
            }   
            if (minimumToWin <= 0 || minimumToWin > boardSize){
                std::cout << "Out of range!\n";
                continue;
            }
            break;
        }

        state.boardSize = boardSize;
        state.minimumToWin = minimumToWin;
        resetBoard();
    }

    char Game::currentPlayer(){
        if (game.state.currentPlayer == Player::X) return 'X';
        else return 'O';
    }

    int Game::boardSize(){
        return state.boardSize;
    }
};