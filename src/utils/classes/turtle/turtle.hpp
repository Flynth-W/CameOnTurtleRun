#pragma once
#include "../Draw/turtle/turtle.hpp"
#include "../collision.hpp"
#include "../../../event/events.hpp"
#include "../camera/camera.hpp"

class Turtle:public Iobjet_colicion{
    private:
        std::unordered_map<int,ButtonKey>*keys;
        Camera *camera;
        double *deltaTime;
        double radius;
        DrawTurtle drawTurtle;
    private:
        void events();
        void view();
    public:
        void Init();
        void Update();
        void Render();
        
        void setKeys(std::unordered_map<int,ButtonKey>*keys) ;
        void setDeltaTime(double *deltaTime);
        void setCamera(Camera *camera);
        
        void colision(Iobjet_colicion *a) override;
        double getRadio() override;
        glm::vec3 getPosition() override;

};
