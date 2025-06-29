add_library(gameManager STATIC gameManager/gameManager.cpp)
add_library(inputHandler STATIC inputHandler/inputHandler.cpp)
add_library(GameStateEvaluator STATIC GameStateEvaluator/GameStateEvaluator.cpp)
add_library(renderer STATIC renderer/renderer.cpp)

# Establish dependencies
target_link_libraries(gameManager PRIVATE inputHandler)
target_link_libraries(gameManager PRIVATE renderer)
target_link_libraries(gameManager PRIVATE GameStateEvaluator)