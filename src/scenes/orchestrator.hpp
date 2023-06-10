#pragma once
#include "beginGame/beginGame.hpp"

#include "../event/events.hpp"

class Orchestrator{
    private:
        Stage *stage;
        Stages typeStage;
        double *deltaTime;
        std::unordered_map<int,ButtonKey>*keys;
        std::unordered_map<int,ButtonKey>*mouseKeys;
        Mouse *mouse;
    public:
        void Init();
        void Update();
        void Render();
        void setDeltaTime(double *deltaTime);
        void setMouse(Mouse *mouse);
        void setKeys(std::unordered_map<int,ButtonKey>*Keys);
        void setMouseKeys(std::unordered_map<int,ButtonKey>*mouseKeys);
    private:
        void changeStage();
};
