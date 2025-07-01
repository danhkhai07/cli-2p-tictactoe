#include "gameManager.h"

#include <iostream>
#include <vector>
#include <thread> // sleep_for, sleep_until
#include <chrono> // ms, ns, ...

namespace GameManager {
    GameState state;
    Game game;

    void Start(){
        std::cout << "CLI Two-Player Tic Tac Toe - Written by danhkhai07\n";
        std::cout << "- Github repository: https://github.com/danhkhai07/cli-2p-tictactoe\n";
        GameManager::Loop();
    }

    void Loop(){

        game.renderBoard();
    }

    //Define class Game
    int Game::playMove(const int& x, const int& y){
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

                switch (state.gameBoard[i-1][j-1]){
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

    void Game::calculateGameState(){

    }

    void Game::setGameRules(){
        int boardSize, minimumToWin;
        std::cout << "Note: This act will erase the board and reset the game.\n";
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
};