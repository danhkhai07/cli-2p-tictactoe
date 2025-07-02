#include "gameManager.h"

#include <iostream>
#include <limits>

int main(){
    GameManager::Start();
    // Wait for input before closing
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cin.get();
    return 0;
}