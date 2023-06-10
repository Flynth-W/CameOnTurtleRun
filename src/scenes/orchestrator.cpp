#include "orchestrator.hpp"

void Orchestrator::Init(){
    this->typeStage = Stages::beginGame;
    this->changeStage();
}

void Orchestrator::Update(){
    if(typeStage == stage->getStage() ){
        stage->Update();
        return;
    }
    typeStage = stage->getStage();
    this->changeStage();
    return;
}
void Orchestrator::changeStage(){
    switch (typeStage) {
        case Stages::beginGame:
            stage = new BeginGame();
            stage->setMouse(mouse);
            stage->setKeys(keys);
            stage->setMouseKeys(mouseKeys);
            stage->setDeltaTime(deltaTime);
            stage->Init();
        case Stages::one:

          break;
    }
}

void Orchestrator::Render(){
    stage->Render();
}

void Orchestrator::setDeltaTime(double *deltaTime){
    this->deltaTime=deltaTime;
}
void Orchestrator::setMouse(Mouse *mouse){
    this->mouse=mouse;
};
void Orchestrator::setKeys(std::unordered_map<int,ButtonKey>*Keys){
    this->keys=Keys;
};
void Orchestrator::setMouseKeys(std::unordered_map<int,ButtonKey>*mouseKeys){
    this->mouseKeys=mouseKeys;
};
