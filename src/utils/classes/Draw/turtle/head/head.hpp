#pragma once
#include "../../../shader.hpp"
#include "../../../camera/camera.hpp"
#include "../../../textures/textures.hpp"

class DrawHeadOfTurtle{
    private:
        unsigned int VBO, VAO;
        unsigned int texture;
        glm::vec3 *translate;
        float angle;
        Camera *camera;
        Shader *shader;
        glm::vec3 initPosition;
        glm::vec3 addPosition;
        bool reverse;
    public:
        glm::mat4 *model;
        glm::mat4 *modelBody;
        
        DrawHeadOfTurtle();
        void Update();
        void Render();
        
        void setVetices();
        void setPosition(glm::vec3 initPosition);
        void setCamera(Camera *camera);
        void setModel(glm::mat4 *modelBody);
        void setPositionAdd(glm::vec3 addPosition);
        
        void move(glm::vec3 translate);
        void rotate(double angle);
};
