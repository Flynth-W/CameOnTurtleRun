#pragma once 
#include "../shader.hpp"
#include "../camera/camera.hpp"
#include "../textures/textures.hpp"

class Floor{
    private:
        unsigned int planeVBO,planeVAO;
        glm::mat4 lightSpaceMatrix;
        unsigned int woodTexture ;
        Shader *shader;
        Camera *camera;
    public:
        void Init(Camera *camera_);
        void Render();
};
