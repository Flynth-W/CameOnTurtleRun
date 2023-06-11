#include "limb.hpp"


DrawLimbOfTurtle::DrawLimbOfTurtle(){
    this->angle=0.0f;
    this->translate= new glm::vec3(0.0);
    this->model= new glm::mat4(1.0);
    this->reverse = false;

}
void DrawLimbOfTurtle::Update(){

    
    glm::mat4 modelTmp = glm::mat4(*this->modelBody);
    modelTmp = glm::translate(modelTmp,initPosition );
    modelTmp = glm::rotate(modelTmp, this->angle, glm::vec3(0.0,1.0,0.0));
    modelTmp = glm::translate(modelTmp,addPosition );

   
    *this->translate=glm::vec3(0.0);
    this->shader->use();
    
    this->shader->setMat4("model", modelTmp);
}
void DrawLimbOfTurtle::Render(){
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);
    this->shader->use();
    
    this->shader->setMat4("view", *this->camera->view);
    this->shader->setMat4("projection", *this->camera->projection);
    
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);
    
}


void DrawLimbOfTurtle::setVetices(){
    float limitTop=-0.2;
    float vertex[] = {
        -0.3f, -0.07f, -0.1f,         0.0f, 0.0f,
         0.3f, -0.07f, -0.1f,         1.0f, 0.0f,
         0.3f,  0.07f, -0.1f,         1.0f, 1.0f,
         0.3f,  0.07f, -0.1f,         1.0f, 1.0f,
        -0.3f,  0.07f, -0.1f,         0.0f, 1.0f,
        -0.3f, -0.07f, -0.1f,         0.0f, 0.0f,

        -0.3f, -0.07f,  0.1f,         0.0f, 0.0f,
         0.3f, -0.07f,  0.1f,         1.0f, 0.0f,
         0.3f,  0.07f,  0.1f,         1.0f, 1.0f,
         0.3f,  0.07f,  0.1f,         1.0f, 1.0f,
        -0.3f,  0.07f,  0.1f,         0.0f, 1.0f,
        -0.3f, -0.07f,  0.1f,         0.0f, 0.0f,

        -0.3f,  0.07f,  0.1f,         1.0f, 0.0f,
        -0.3f,  0.07f, -0.1f,         1.0f, 1.0f,
        -0.3f, -0.07f, -0.1f,         0.0f, 1.0f,
        -0.3f, -0.07f, -0.1f,         0.0f, 1.0f,
        -0.3f, -0.07f,  0.1f,         0.0f, 0.0f,
        -0.3f,  0.07f,  0.1f,         1.0f, 0.0f,

         0.3f,  0.07f,  0.1f,         1.0f, 0.0f,
         0.3f,  0.07f, -0.1f,         1.0f, 1.0f,
         0.3f, -0.07f, -0.1f,         0.0f, 1.0f,
         0.3f, -0.07f, -0.1f,         0.0f, 1.0f,
         0.3f, -0.07f,  0.1f,         0.0f, 0.0f,
         0.3f,  0.07f,  0.1f,         1.0f, 0.0f,

        -0.3f, -0.07f, -0.1f,         0.0f, 1.0f,
         0.3f, -0.07f, -0.1f,         1.0f, 1.0f,
         0.3f, -0.07f,  0.1f,         1.0f, 0.0f,
         0.3f, -0.07f,  0.1f,         1.0f, 0.0f,
        -0.3f, -0.07f,  0.1f,         0.0f, 0.0f,
        -0.3f, -0.07f, -0.1f,         0.0f, 1.0f,

        -0.3f,  0.07f, -0.1f,         0.0f, 1.0f,
         0.3f,  0.07f, -0.1f,         1.0f, 1.0f,
         0.3f,  0.07f,  0.1f,         1.0f, 0.0f,
         0.3f,  0.07f,  0.1f,         1.0f, 0.0f,
        -0.3f,  0.07f,  0.1f,         0.0f, 0.0f,
        -0.3f,  0.07f, -0.1f,         0.0f, 1.0f
    };
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // texture cords attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    this->texture= Textures::loadTexture("./img/turtleShell.jpg");
    
    this->shader= new Shader("./shader/turtle/turtle.vs" ,"./shader/turtle/turtle.fs");
    this->shader->use();
    this->shader->setInt("texture1", 0);
}
void DrawLimbOfTurtle::move(glm::vec3 translate){
    *this->translate= *this->translate + translate;
}
void DrawLimbOfTurtle::rotate(double angle) {
    float limitAngle=0.5;
    if(this->angle > limitAngle || this->angle < -limitAngle){
        this->reverse=!this->reverse;
    }

    if(reverse){
        this->angle -= angle;
    }else{
        this->angle += angle;
    }
}

void DrawLimbOfTurtle::setPosition(glm::vec3 initPosition){
    this->initPosition= initPosition;
}
void DrawLimbOfTurtle::setCamera(Camera *camera){
    this->camera = camera ;
}
void DrawLimbOfTurtle::setModel(glm::mat4 *modelBody){
    this->modelBody = modelBody;
}
void DrawLimbOfTurtle::setPositionAdd(glm::vec3 addPosition){
    this->addPosition= addPosition;
}
