#pragma once
#include <GL/glew.h>
#include "../event/events.hpp"

enum class Stages{
    beginGame,
    one,
};

class Stage{
    public:
        virtual void Init(){};
        virtual void Update(){};
        virtual void Render(){};
        virtual Stages getStage(){return Stages::beginGame;};
        virtual void setDeltaTime(double *deltaTime){};
        virtual void setMouse(Mouse *mouse){};
        virtual void setKeys(std::unordered_map<int,ButtonKey>*Keys){};
        virtual void setMouseKeys(std::unordered_map<int,ButtonKey>*mouseKeys){};
};
