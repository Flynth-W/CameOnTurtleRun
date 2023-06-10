#include "camera.hpp"

Camera::Camera(unsigned int width , unsigned int height) {
  WIDTH  = width;
  HEIGHT = height ;
  projection= new glm::mat4(1.0f);
  ( *projection ) = glm::perspective(glm::radians(45.0f), (float)this->WIDTH / (float)this->HEIGHT , 0.1f, 100.0f);
  view= new glm::mat4(1.0f);
  ( *view  )= glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
};

void Camera::zooming(float sum){ 
  fov += sum;
  if (fov < 1.0f)
      fov = 1.0f;
  if (fov > 45.0f)
      fov = 45.0f;
  *projection = glm::perspective(glm::radians(fov), (float)this->WIDTH / (float)this->HEIGHT , 0.1f, 100.0f);
};

void Camera::right(float deltaTime){
  float cameraSpeed = static_cast<float>(cameraVelocity * deltaTime);
  cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
  *view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
}
void Camera::left(float deltaTime){
  float cameraSpeed = static_cast<float>(cameraVelocity * deltaTime);
  cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
  *view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
}
void Camera::move(glm::vec3 translate){
  cameraPos += translate ; 
  *view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);

};
void Camera::up(float deltaTime){
  float cameraSpeed = static_cast<float>(cameraVelocity * deltaTime);
  cameraPos += cameraSpeed * cameraFront;
  *view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
}
void Camera::down(float deltaTime){
  float cameraSpeed = static_cast<float>(cameraVelocity * deltaTime);
  cameraPos -= cameraSpeed * cameraFront;
  *view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
}

void Camera::angleChange(float xpos ,float ypos){
  float xoffset = ( xpos - lastX );
  float yoffset = ( lastY - ypos ); // reversed since y-coordinates go from bottom to top
  lastX = xpos;
  lastY = ypos;

  xoffset *= sensitivity;
  yoffset *= sensitivity;

  yaw += xoffset;
  pitch += yoffset;
  
  std::cout << " x: " << yaw <<" y: "<< pitch << std::endl;
  // make sure that when pitch is out of bounds, screen doesn't get flipped
  if (pitch > 45.0f)
      pitch = 45.0f;
  if (pitch < -45.0f)
      pitch = -45.0f;
  glm::vec3 front;
  front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
  front.y = sin(glm::radians(pitch));
  front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
  cameraFront = glm::normalize(front);
  *view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
};
