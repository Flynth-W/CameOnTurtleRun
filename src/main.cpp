#include "./app/app.hpp"
#include "./factory/app/app.hpp"
#include <iostream>
#include <chrono>
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image.h"
#include "stb/stb_image_resize.h"
#include "stb/stb_image_write.h"
using namespace std;

int main() {
    App app(factoryApp());
    
    auto lastTime = std::chrono::system_clock::now();
    while(app.getRun()){
        auto current = std::chrono::system_clock::now();
        std::chrono::duration<double> deltaTime = current - lastTime;
        app.deltaTime = deltaTime.count() ;  
        app.Events();
        app.Update();
        app.Render();

        lastTime = current;
    }

}

