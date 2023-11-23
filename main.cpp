#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include <termios.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>






//this is the main function
int main() {
        srand(static_cast<unsigned>(time(nullptr)));

        SnakeGame game;
        game.Name();
        game.Run();

        return 0;
    }
