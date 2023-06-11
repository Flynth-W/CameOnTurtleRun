#pragma once
#include "../../shader.hpp"
#include "../../camera/camera.hpp"
#include "./body/body.hpp"
#include "./limb/limb.hpp"
#include "./head/head.hpp"

class DrawTurtle{   
    private:
        Camera *camera;
        DrawBodyOfTurtle body;
        DrawLimbOfTurtle limbTopRight;
        DrawLimbOfTurtle limbTopLeft;
        DrawLimbOfTurtle limbButtomRight;
        DrawLimbOfTurtle limbButtomLeft;
        DrawHeadOfTurtle head;
    public:
        void Init(glm::vec3 *position);
        void Update();
        void Render();
        
        void setCamera(Camera *camera);
        glm::mat4 getModel();

        void move(float translate);
        void rotate(double angle);
        void headRotate(double angle);
};
