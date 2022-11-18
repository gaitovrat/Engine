#include <iostream>

#include "App.hpp"
#include "Log/Log.hpp"

int main() {
    Log::debug("App started.");

    try {
        App app(640, 480, "Engine");
        app.Run();
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
