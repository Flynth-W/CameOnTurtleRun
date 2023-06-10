#pragma once

#include <GLFW/glfw3.h>
#include <unordered_map>
#include <iostream>

enum class ButtonState{
    None,
    Pressed,
    Repeat ,
    Released
};
enum class WhellState{
  None,
  Up,
  Down
};

class ButtonKey{
  public:
    ButtonKey();
    void setState( ButtonState  );
    ButtonState getState();
    void Release();
  private:
    ButtonState *state;

};

class Mouse{
  public:
  float x=0.0,y=0.0;
  WhellState whell=WhellState::None;
};



class Event{
  public:
    static void PreHandleEvent(std::unordered_map<int,ButtonKey>*_keys,Mouse *mouse,std::unordered_map<int,ButtonKey>*_mouseKeys);
    static void HandleEvent(GLFWwindow * window, int key, int scancode, int action, int mods, std::unordered_map<int,ButtonKey>*_keys);

    static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset,Mouse * mouse);
    static void mouse_callback(GLFWwindow* window, double xposIn, double yposIn, Mouse * mouse);
    static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods, std::unordered_map<int,ButtonKey>*mouse) ;
    static bool getIfStateKey(std::unordered_map<int,ButtonKey>*keys,unsigned int KEY,ButtonState state);
    static bool getIfStateKey(std::unordered_map<int,ButtonKey>*keys,unsigned int KEY,ButtonState state, ButtonState state1);
    static void setKey(std::unordered_map<int,ButtonKey>*keys,unsigned int KEY);
};
