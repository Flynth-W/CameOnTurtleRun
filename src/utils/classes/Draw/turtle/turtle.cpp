#include "turtle.hpp"

void DrawTurtle::Init(glm::vec3 *position){
    this->body.setPosition(position);
    this->body.setCamera(this->camera);
    this->body.setVetices();

    this->head.setCamera(this->camera);
    this->head.setVetices();
    this->head.setModel(&this->body.model);
    this->head.setPosition(glm::vec3(0.0,-0.31,-0.6));

    this->limbTopRight.setCamera(this->camera);
    this->limbTopRight.setVetices();
    this->limbTopRight.setModel(&this->body.model);
    this->limbTopRight.setPosition(glm::vec3(-0.5,-0.31,-0.3));
    this->limbTopRight.setPositionAdd(glm::vec3(-0.26,0.0,0.0));
    
    this->limbTopLeft.setCamera(this->camera);
    this->limbTopLeft.setVetices();
    this->limbTopLeft.setModel(&this->body.model);
    this->limbTopLeft.setPosition(glm::vec3(0.5,-0.31,-0.3));
    this->limbTopLeft.setPositionAdd(glm::vec3(0.26,0.0,0.0));
    
    this->limbButtomRight.setCamera(this->camera);
    this->limbButtomRight.setVetices();
    this->limbButtomRight.setModel(&this->body.model);
    this->limbButtomRight.setPosition(glm::vec3(-0.5,-0.31,0.4));
    this->limbButtomRight.setPositionAdd(glm::vec3(-0.26,0.0,0.0));
    
    this->limbButtomLeft.setCamera(this->camera);
    this->limbButtomLeft.setVetices();
    this->limbButtomLeft.setModel(&this->body.model);
    this->limbButtomLeft.setPosition(glm::vec3(0.5,-0.31,0.4));
    this->limbButtomLeft.setPositionAdd(glm::vec3(0.26,0.0,0.0));
}
void DrawTurtle::Update(){
    this->body.Update();
    this->head.Update();
    
    this->limbTopRight.Update();
    this->limbTopLeft.Update();
    this->limbButtomRight.Update();
    this->limbButtomLeft.Update();
}
void DrawTurtle::Render(){
    this->body.Render();
    this->head.Render();
    
    this->limbTopRight.Render();
    this->limbTopLeft.Render();
    this->limbButtomRight.Render();
    this->limbButtomLeft.Render();
}

void DrawTurtle::setCamera(Camera *camera){
    this->camera=camera;
}
glm::mat4 DrawTurtle::getModel(){
    return this->body.model;
}

void DrawTurtle::move(float translate){
    this->body.move(glm::vec3(0.0,0.0,-translate));
    this->limbTopRight.rotate(translate );
    this->limbButtomLeft.rotate(-translate );
    
    this->limbTopLeft.rotate(translate );
    this->limbButtomRight.rotate(-translate );
}
void DrawTurtle::rotate(double angle){
    this->body.rotate(angle);
}
void DrawTurtle::headRotate(double angle){
    this->head.rotate(angle);
}

