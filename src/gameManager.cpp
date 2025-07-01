#include "gameManager.h"

#include <iostream>
#include <vector>

namespace GameManager {
    GameState state;
    Game game;

    void Start(){
        int boardSize, minimumToWin;
        std::cout << "Set game rules:\n";
        while (true){
            std::cout << "   boardSize = "; std::cin >> boardSize;
            if (std::cin.fail()){
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                continue;
            }   
            break;
        }
        while (true){
            std::cout << "   minimumToWin = "; std::cin >> minimumToWin;
            if (std::cin.fail()){
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                continue;
            }   
            break;
        }

        game.initiateBoard(boardSize,minimumToWin);
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

    void Game::initiateBoard(int boardSize, int minimumToWin){
        state.boardSize = boardSize;
        state.minimumToWin = minimumToWin;
        resetBoard();
    }

    void Game::calculateGameState(){

    }
};