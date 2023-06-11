#pragma once
#include "../../../shader.hpp"
#include "../../../camera/camera.hpp"
#include "../../../textures/textures.hpp"

class DrawBodyOfTurtle{
    private:
        unsigned int VBO, VAO;
        unsigned int texture;
        glm::vec3 *translate;
        float angle;
        Camera *camera;
        Shader *shader;
        glm::vec3 *position;
    public:
        glm::mat4 model;
        
        DrawBodyOfTurtle();
        void Update();
        void Render();
        
        void setVetices();
        void setPosition(glm::vec3 * position);
        void setCamera(Camera *camera);
        
        void move(glm::vec3 translate);
        void rotate(double angle);
};
