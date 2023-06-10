#pragma once


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
class Camera{
  public:
    unsigned int WIDTH;
    unsigned int HEIGHT;

    glm::vec3 cameraPos   = glm::vec3(0.0f, 0.0f, 3.0f);
    glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    float fov=45.0f;
    float yaw   = -90.0f ;
    double yaww   = -1.5708 ;
    float pitch =  0.0f;
    float sensitivity = 0.1f; // change this value to your liking

    float lastX =  1000.0 / 2.0;
    float lastY =  1000.0 / 2.0;
    double giro;

  public:
    glm::mat4 *projection;
    glm::mat4 *view;
    glm::vec3 cameraUp    = glm::vec3(0.0f, 1.0f, 0.0f);
    float cameraVelocity=2.5;

    Camera( unsigned int width , unsigned int height );
    ~Camera(){};

    void zooming(float sum);

    void left(float deltaTime);
    void move(glm::vec3 translate);
    void right(float deltaTime);
    void up(float deltaTime);
    void down(float deltaTime);

    void angleChange(float xpos ,float ypos);
    
};
