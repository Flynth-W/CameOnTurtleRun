#include "app.hpp"

std::unordered_map<int,ButtonKey>keys;
Mouse mouse ;
std::unordered_map<int,ButtonKey>mouseKeys;
void key_callback( GLFWwindow * window, int key, int scancode, int action, int mods){
  Event::HandleEvent(window, key,scancode,action,mods, &keys) ;
  return;
}
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
  Event::scroll_callback(window, xoffset,yoffset, &mouse);
}
void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
{
  Event::mouse_callback(window, xposIn, yposIn, &mouse);
}
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods){
  Event::mouse_button_callback(window, button, action, mods, &mouseKeys);
}

App factoryApp(){
    App app;
    //events
        // ad keys
    keys[GLFW_KEY_P] =  ButtonKey();
    keys[GLFW_KEY_K] =  ButtonKey();
    
    keys[GLFW_KEY_W] =  ButtonKey();
    keys[GLFW_KEY_S] =  ButtonKey();
    keys[GLFW_KEY_A] =  ButtonKey();
    keys[GLFW_KEY_D] =  ButtonKey();
    Event::setKey(&keys, GLFW_KEY_ENTER);
    //add mouse buttons 
    mouseKeys[GLFW_MOUSE_BUTTON_RIGHT] = ButtonKey();
    //mouseKeys[GLFW_MOUSE_BUTTON_LEFT] = ButtonKey();
    Event::setKey(&mouseKeys, GLFW_MOUSE_BUTTON_LEFT);
    mouseKeys[GLFW_MOUSE_BUTTON_MIDDLE] = ButtonKey();
    mouseKeys[GLFW_MOUSE_BUTTON_4] = ButtonKey();
    mouseKeys[GLFW_MOUSE_BUTTON_5] = ButtonKey();
    //mouse.x=500.0;
    //mouse.y=500.0;

    app.setKeys(&keys);
    app.setMouse(&mouse);
    app.setMouseKeys(&mouseKeys);
    
    app.Init();

    glfwSetKeyCallback (app.window, key_callback);
    glfwSetScrollCallback(app.window, scroll_callback);
    glfwSetCursorPosCallback(app.window, mouse_callback);
    glfwSetMouseButtonCallback(app.window,mouse_button_callback );
    //glfwSetInputMode(app.window,GLFW_CURSOR,GLFW_CURSOR_DISABLED) ;

    return app;
};
