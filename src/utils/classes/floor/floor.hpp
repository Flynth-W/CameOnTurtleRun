#pragma once 
#include "../shader.hpp"
#include "../camera/camera.hpp"
#include "../textures/textures.hpp"

class Floor{
    private:
        unsigned int VBO,VAO;
        unsigned int woodTexture ;
        Shader *shader;
        Camera *camera;
    public:
        void Init(Camera *camera_);
        void Render();
        void setBackgroundColor(glm::vec3 color);
};
