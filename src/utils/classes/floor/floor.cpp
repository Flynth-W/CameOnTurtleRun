#include "floor.hpp"

void Floor::Init(Camera *camera_){
    camera = camera_;
    float planeVertices[] = {
        // positions              // texcoords
         20.0f, -0.5f,  40.0f,     10.0f, 10.0f,
        -20.0f, -0.5f,  40.0f,     0.0f, 10.0f,
        -20.0f, -0.5f, -40.0f,     0.0f, 0.0f,

         20.0f, -0.5f,  40.0f,    10.0f, 10.0f,
        -20.0f, -0.5f, -40.0f,    0.0f, 0.0f,
         20.0f, -0.5f, -40.0f,    10.0f, 0.0f
    };
    float vertex[] = {
        -20.0f, -0.5f, -40.0f,  0.0f, 0.0f,
         20.0f, -0.5f, -40.0f,  1.0f, 0.0f,
         20.0f, -0.5f,  40.0f,  1.0f, 1.0f,

         20.0f, -0.5,   40.0f,  1.0f, 1.0f,
        -20.0f, -0.5f,  40.0f,  0.0f, 1.0f,
        -20.0f, -0.5,  -40.0f,  0.0f, 0.0f,

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
    
    this->shader= new Shader("./shader/square/floor.vs" ,"./shader/square/floor.fs");
    shader->use();
    this->woodTexture= Textures::loadTexture("./img/white.jpg");
    //woodTexture = loadTexture("./img/wood.png", false) ;
    this->shader->setInt("texture1", 0);
}

void Floor::Render(){
    
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, woodTexture);
    
    shader->use();
    glm::mat4 projection = *this->camera->projection;
    glm::mat4 view = *this->camera->view;
    glm::mat4 model = glm::mat4(1.0);
    model = glm::translate(model, glm::vec3(0.0,0.0,0.0));

    shader->setMat4("projection", projection);
    shader->setMat4("view", view);
    shader->setMat4("model",model);

    
    // floor
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);

}
void Floor::setBackgroundColor(glm::vec3 color){
    this->shader->use();
    this->shader->setVec3("color", color);
}
