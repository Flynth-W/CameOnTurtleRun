#pragma once
#include "../stage.hpp"
#include "../../utils/classes/camera/camera.hpp"
#include "../../utils/classes/floor/floor.hpp"
#include "../../utils/classes/collision.hpp"
#include "../../utils/classes/turtle/turtle.hpp"

class BeginGame:public Stage{
    private:
        double *deltaTime;
        std::unordered_map<int,ButtonKey>*keys;
        std::unordered_map<int,ButtonKey>*mouseKeys;
        Mouse *mouse;
        Stages stage;
        Camera *camera;
        CollisionsHandler handlerCollision;
        Floor floor;
        Turtle turtle;
    public:
        void Init()   override;
        void Update() override;
        void Render() override;
        void setDeltaTime(double *deltaTime) override;
        void setMouse(Mouse *mouse) override;
        void setKeys(std::unordered_map<int,ButtonKey>*Keys) override;
        void setMouseKeys(std::unordered_map<int,ButtonKey>*mouseKeys) override;
        Stages getStage()override;
};
