#include "turtle.hpp"
void Turtle::events(){
    float translationSpeed = 1.5 * *this->deltaTime;
    float rotationSpeed = 2.0 * *this->deltaTime;

    // up
    if( Event::getIfStateKey(keys, GLFW_KEY_W,ButtonState::Pressed ,ButtonState::Repeat) ){
        this->drawTurtle.move(translationSpeed);
        // left
        if( Event::getIfStateKey(keys, GLFW_KEY_A,ButtonState::Pressed ,ButtonState::Repeat) ){
            this->drawTurtle.rotate(rotationSpeed);
        }
        // right
        if( Event::getIfStateKey(keys, GLFW_KEY_D,ButtonState::Pressed ,ButtonState::Repeat) ){
            this->drawTurtle.rotate(-rotationSpeed);
        }
    }
    // down
    if( Event::getIfStateKey(keys, GLFW_KEY_S,ButtonState::Pressed ,ButtonState::Repeat) ){
        this->drawTurtle.move(-translationSpeed);
        // left
        if( Event::getIfStateKey(keys, GLFW_KEY_A,ButtonState::Pressed ,ButtonState::Repeat) ){
            this->drawTurtle.rotate(-rotationSpeed);
        }
        // right
        if( Event::getIfStateKey(keys, GLFW_KEY_D,ButtonState::Pressed ,ButtonState::Repeat) ){
            this->drawTurtle.rotate(rotationSpeed);
        }
    }
    // rotate head
    // left
    if( Event::getIfStateKey(keys, GLFW_KEY_A,ButtonState::Pressed ,ButtonState::Repeat) ){
        drawTurtle.headRotate(rotationSpeed);
    }
    // right
    if( Event::getIfStateKey(keys, GLFW_KEY_D,ButtonState::Pressed ,ButtonState::Repeat) ){
        drawTurtle.headRotate(-rotationSpeed);
    }
}

void Turtle::view(){
    glm::mat4 model = this->drawTurtle.getModel();
    
    glm::mat4 front = glm::mat4(model);
              front = glm::translate(front, glm::vec3(0.0,1.5,-2.0));
    glm::vec3 cameraFront = glm::vec3(front[3][0],front[3][1],front[3][2]);
    
    glm::mat4 position  = glm::mat4(model);
              position  = glm::translate(position, glm::vec3( 0.0 , 5.0 , 8.0));
    glm::vec3 cameraPos = glm::vec3(position[3][0] , position[3][1] , position[3][2]);

    glm::vec3 cameraUp = glm::vec3(0.0,1.0,0.0);
    *camera->view = glm::lookAt(cameraPos,  cameraFront, cameraUp);
}

void Turtle::Init(){
    this->position=new glm::vec3(0.0);

    this->drawTurtle.setCamera(this->camera);
    this->drawTurtle.Init(this->position);
}
void Turtle::Update(){
    this->events();
    this->drawTurtle.Update();
}
void Turtle::Render(){
    this->view();
    this->drawTurtle.Render();
}

void Turtle::setKeys(std::unordered_map<int, ButtonKey> *keys){
    this->keys=keys;
}
void Turtle::setDeltaTime(double *deltaTime){
    this->deltaTime=deltaTime;
}
void Turtle::setCamera(Camera *camera){
    this->camera=camera;
}

// inherit
void Turtle::colision(Iobjet_colicion *a){
    
}
double Turtle::getRadio(){
    return this->radius;
}
glm::vec3 Turtle::getPosition(){
    return glm::vec3(*this->position);
}
