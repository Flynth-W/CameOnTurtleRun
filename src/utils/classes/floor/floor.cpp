#include "floor.hpp"

void Floor::Init(Camera *camera_){
    camera = camera_;
    float planeVertices[] = {
        // positions              // texcoords
         20.0f, -0.5f,  40.0f,    10.0f,  0.0f,
        -20.0f, -0.5f,  40.0f,     0.0f,  0.0f,
        
        -20.0f, -0.5f, -40.0f,     0.0f, 10.0f,

         20.0f, -0.5f,  40.0f,    10.0f,  0.0f,
        
        -20.0f, -0.5f, -40.0f,     0.0f, 10.0f,
         20.0f, -0.5f, -40.0f,    10.0f, 10.0f
    };
    // plane VAO
    glGenVertexArrays(1, &planeVAO);
    glGenBuffers(1, &planeVBO);
    glBindVertexArray(planeVAO);
    glBindBuffer(GL_ARRAY_BUFFER, planeVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(planeVertices), planeVertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    
    this->shader= new Shader("./shader/floor/floor.vs" ,"./shader/floor/floor.fs");
    shader->use();
    woodTexture = Textures::loadTexture("./img/wood.png");
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
    glBindVertexArray(planeVAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);

}
