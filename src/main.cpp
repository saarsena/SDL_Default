#include "GameManager.h"

int main(int argc, char* argv[]) {
    GameManager game;
    if (game.init()) {
        game.run();
    }
    game.clean();
    return 0;
}
