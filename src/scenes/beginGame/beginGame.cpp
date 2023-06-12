#include "beginGame.hpp"

void BeginGame::Init(){
    this->camera= new Camera(1000,1000);
    this->stage=Stages::beginGame;
    this->stateGame=StateGame::RunToPoint;
    this->time=0.0;

    this->floor.Init(this->camera);
    this->floor.setBackgroundColor(glm::vec3(1.0,1.0,1.0));

    this->turtle.setDeltaTime(this->deltaTime);
    this->turtle.setKeys(this->keys);
    this->turtle.setCamera(this->camera);
    this->turtle.Init();

    this->square.setPosition(glm::vec3(0.0,0.001,35.0) );
    this->square.setCamera(this->camera);
    this->square.setVetices();
     
};
void BeginGame::gameControl(){
    this->time += *this->deltaTime;
    
    if(this->time > 5 && this->stateGame == StateGame::RunToPoint){
        this->stateGame = StateGame::OnlySquares;
        this->floor.setBackgroundColor(glm::vec3(1.0,0.0,0.0));
    }
    if(this->time > 7){
        this->stateGame = StateGame::RunToPoint;
        this->time -=6;
        this->floor.setBackgroundColor(glm::vec3(1.0,1.0,1.0));
        this->square.setPosition(glm::vec3(3.0,0.0001,35.0) );
    }

}
void BeginGame::Update(){
    this->handlerCollision.resertState();
    this->handlerCollision.loopState();
    this->gameControl();
    
    this->turtle.Update();
    this->square.Update();
};
void BeginGame::Render(){

    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0f, 0.003f, 0.03f,1.0f);
    this->floor.Render();
    this->turtle.Render();
    this->square.Render();
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
