#include <iostream>

#include "App.h"

int main(const int argc, const char** argv) {
    try {
        App app(640, 480, "Engine");
        app.Run();
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
