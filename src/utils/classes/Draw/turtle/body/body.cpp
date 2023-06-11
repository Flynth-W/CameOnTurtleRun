#include "body.hpp"
#include <iostream>

DrawBodyOfTurtle::DrawBodyOfTurtle(){
    this->angle=0.0f;
    this->translate= new glm::vec3(0.0);
    this->model= glm::mat4(1.0);
}
void DrawBodyOfTurtle::Update(){
    
    glm::mat4 modelTmp = glm::mat4(1.0);
    modelTmp = glm::translate(modelTmp,*this->position );
    modelTmp = glm::rotate(modelTmp, this->angle, glm::vec3(0.0f, 1.0f, 0.0f));
    modelTmp = glm::translate(modelTmp,*this->translate );
    this->model=modelTmp;

    this->position->x=this->model[3][0];
    this->position->y=this->model[3][1];
    this->position->z=this->model[3][2];
   
    *this->translate=glm::vec3(0.0);
}
void DrawBodyOfTurtle::Render(){
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);
    
    this->shader->use();
    
    this->shader->setMat4("model", this->model);
    this->shader->setMat4("view", *this->camera->view);
    this->shader->setMat4("projection", *this->camera->projection);
    
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);
    
}


void DrawBodyOfTurtle::setVetices(){
    float limitTop=-0.2;
    float vertex[] = {
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
         0.5f, limitTop, -0.5f,  1.0f, 1.0f,
         0.5f, limitTop, -0.5f,  1.0f, 1.0f,
        -0.5f, limitTop, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         0.5f, limitTop,  0.5f,  1.0f, 1.0f,
         0.5f, limitTop,  0.5f,  1.0f, 1.0f,
        -0.5f, limitTop,  0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

        -0.5f, limitTop,  0.5f,  1.0f, 0.0f,
        -0.5f, limitTop, -0.5f,  1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f, limitTop,  0.5f,  1.0f, 0.0f,

         0.5f, limitTop,  0.5f,  1.0f, 0.0f,
         0.5f, limitTop, -0.5f,  1.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         0.5f, limitTop,  0.5f,  1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

        -0.5f, limitTop, -0.5f,  0.0f, 1.0f,
         0.5f, limitTop, -0.5f,  1.0f, 1.0f,
         0.5f, limitTop,  0.5f,  1.0f, 0.0f,
         0.5f, limitTop,  0.5f,  1.0f, 0.0f,
        -0.5f, limitTop,  0.5f,  0.0f, 0.0f,
        -0.5f, limitTop, -0.5f,  0.0f, 1.0f
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
void DrawBodyOfTurtle::move(glm::vec3 translate){
    *this->translate= *this->translate + translate;
}
void DrawBodyOfTurtle::rotate(double angle) {
    this->angle += angle;
}

void DrawBodyOfTurtle::setPosition(glm::vec3 *position){
    this->position = position;
}
void DrawBodyOfTurtle::setCamera(Camera *camera){
    this->camera = camera ;
}
