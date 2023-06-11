#include "beginGame.hpp"

void BeginGame::Init(){
    this->camera= new Camera(1000,1000);
    this->stage=Stages::beginGame;
    this->floor.Init(this->camera);

    this->turtle.setDeltaTime(this->deltaTime);
    this->turtle.setKeys(this->keys);
    this->turtle.setCamera(this->camera);
    this->turtle.Init();
};
void BeginGame::Update(){
    this->handlerCollision.resertState();
    this->handlerCollision.loopState();
    
    this->turtle.Update();
};
void BeginGame::Render(){

    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0f, 0.003f, 0.03f,1.0f);
    this->floor.Render();
    this->turtle.Render();
};

void BeginGame::setDeltaTime(double *deltaTime){
    this->deltaTime=deltaTime;
}
void BeginGame::setMouse(Mouse *mouse){
    this->mouse=mouse;
};
void BeginGame::setKeys(std::unordered_map<int,ButtonKey>*Keys){
    this->keys=Keys;
};
void BeginGame::setMouseKeys(std::unordered_map<int,ButtonKey>*mouseKeys){
    this->mouseKeys=mouseKeys;
};

Stages BeginGame::getStage(){
    return this->stage ;
}
