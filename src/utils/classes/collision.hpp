#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <unordered_map>
#include <cmath>
#include <iostream>
using namespace std;

enum class TypeObjet{
    Square,
    Nave,
    Bullet
};

class Iobjet_colicion{
    public:
        glm::vec3 *position;
        TypeObjet type;
    public:
        virtual glm::vec3 getPosition(){return glm::vec3(0.0);};
        virtual double getRadio(){return 0;};
        virtual void colision(Iobjet_colicion *a){};
        virtual bool getRun(){return false;};
};
enum class StateCls{
  None,
  True,
  False,
};

class CollisionsHandler{

  private:
    unordered_map<int,Iobjet_colicion*>mapObj; 
    unordered_map<Iobjet_colicion*,int>mapObjnum; 
    //matriz
    unordered_map<Iobjet_colicion*,unordered_map<Iobjet_colicion*,StateCls>*>mtrBase;
    unordered_map<Iobjet_colicion*,StateCls>*mtrTmp;
    int num=0;
  public:
    void add(Iobjet_colicion *_obj);
    void del(Iobjet_colicion *_obj);
    void setState(Iobjet_colicion *n, Iobjet_colicion*n1,StateCls stt);
    void delState(Iobjet_colicion *n, Iobjet_colicion*n1);
    StateCls getState(Iobjet_colicion *n, Iobjet_colicion*n1);
    void resertState();
    void loopState();
    private:
        StateCls crash(Iobjet_colicion *a , Iobjet_colicion *b);

};
