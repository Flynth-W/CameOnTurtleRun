#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../scenes/orchestrator.hpp"
#include "../event/events.hpp"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);


class App{
    public:
        GLFWwindow *window;
        double deltaTime=0.0;
        Orchestrator orchestrator;
    private:
        unsigned int height, width;
        const char *title = "Asteroid"; 
        std::unordered_map<int,ButtonKey>*keys;
        std::unordered_map<int,ButtonKey>*mouseKeys;
        Mouse *mouse;
    public:
        App();
        ~App();
        void Init();
        void Events();
        void Update();
        void Render();
        void setKeys(std::unordered_map<int,ButtonKey> *_keys);
        void setMouse(Mouse *_mouse);
        void setMouseKeys(std::unordered_map<int,ButtonKey> *_mousekeys);
        bool getRun();
};
