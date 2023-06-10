#include "events.hpp"
// class ButtonKey
ButtonKey::ButtonKey(){
  state= new ButtonState(ButtonState::None);
}
void ButtonKey::setState(ButtonState _state ){  
  *state=_state; 
} 
ButtonState ButtonKey::getState(){ 
  return *state;
}
void ButtonKey::Release(){ 
  *state=ButtonState::None ;
}
//Event
void Event::HandleEvent(GLFWwindow *window, int key, int scancode, int action, int mods, std::unordered_map<int, ButtonKey> *_keys){

  auto buttonKey = _keys->find(key) ;
  if (buttonKey == _keys->cend()) {
      return;
  }
  switch(action){
    case GLFW_PRESS:
        buttonKey->second.setState(ButtonState::Pressed);
      break;
    case GLFW_REPEAT:
        buttonKey->second.setState(ButtonState::Repeat);
      break;
    case GLFW_RELEASE:
        buttonKey->second.setState(ButtonState::Released);
      break;
  }
}
void Event::PreHandleEvent(std::unordered_map<int, ButtonKey> *_keys,Mouse *mouse,std::unordered_map<int,ButtonKey>*_mouseKeys){
  for ( auto &item : ( *_keys ) ){
    if(item.second.getState() == ButtonState::Released){
      item.second.setState(ButtonState::None);
    }
  };
  for ( auto &item : ( *_mouseKeys ) ){
    if(item.second.getState() == ButtonState::Released){
      item.second.setState(ButtonState::None);
    }
  };
  mouse->whell=WhellState::None;
};
void Event::scroll_callback(GLFWwindow *window, double xoffset, double yoffset, Mouse *mouse){
  if( yoffset == 1 ){
    (*mouse).whell = WhellState::Up;
  }else{
    (*mouse).whell = WhellState::Down;
  }
}

void Event::mouse_callback(GLFWwindow *window, double xposIn, double yposIn, Mouse *mouse){

  mouse->x = (float)xposIn;
  mouse->y = (float)yposIn;
}
void Event::mouse_button_callback(GLFWwindow *window, int button, int action, int mods, std::unordered_map<int, ButtonKey> *mouse){

  auto buttonKey = mouse->find(button) ;
  if (buttonKey == mouse->cend()) {
      return;
  }
  switch(action){
    case GLFW_PRESS:
        buttonKey->second.setState(ButtonState::Pressed);
      break;
    case GLFW_REPEAT:
        buttonKey->second.setState(ButtonState::Repeat);
      break;
    case GLFW_RELEASE:
        buttonKey->second.setState(ButtonState::Released);
      break;
  }
  
}
void Event::setKey(std::unordered_map<int, ButtonKey> *keys, unsigned int KEY){
    (*keys)[KEY] = ButtonKey();
}
bool Event::getIfStateKey(std::unordered_map<int, ButtonKey> *keys, unsigned int KEY, ButtonState state){

    auto Key= keys->find(KEY);
    if( Key->second.getState() == state ){
        return true;
    }
    return false;
}
bool Event::getIfStateKey(std::unordered_map<int, ButtonKey> *keys, unsigned int KEY, ButtonState state, ButtonState state1){

    auto Key= keys->find(KEY);
    ButtonState stateKey=Key->second.getState();
    if( stateKey == state  || stateKey == state1){
        return true;
    }
    return false;
}
