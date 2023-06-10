#include "collision.hpp"

void CollisionsHandler::add(Iobjet_colicion *_obj){
      mapObj[num]= _obj;
      mapObjnum[_obj]= num;
      num++;
      mtrTmp=new unordered_map<Iobjet_colicion*,StateCls> ; 
      for(auto item: mapObj){
        if(item.second != _obj){
          (*mtrTmp)[item.second]=StateCls::None;
        }
      } 
      mtrBase[_obj]=mtrTmp;
};
StateCls CollisionsHandler::getState(Iobjet_colicion *n, Iobjet_colicion *n1){
      auto num_n  = mapObjnum.find(n);
      auto num_n1 = mapObjnum.find(n1); 
      if( num_n->second > num_n1->second ){
        auto map=mtrBase.find(n);
        auto state=(*map->second).find(n1);
        return state->second;
      }else{
        auto map=mtrBase.find(n1);
        auto state=(*map->second).find(n);
        return state->second;
      }
};
void CollisionsHandler::setState(Iobjet_colicion *n, Iobjet_colicion *n1,StateCls stt){
      auto num_n  = mapObjnum.find(n);
      auto num_n1 = mapObjnum.find(n1); 
      if( num_n->second > num_n1->second ){
        auto map=mtrBase.find(n);
        auto state=(*map->second).find(n1);
        state->second=stt;
      }else{
        auto map=mtrBase.find(n1);
        auto state=(*map->second).find(n);
        state->second=stt;
      }
};
void CollisionsHandler::resertState(){
  for(auto item: mapObj){
    for(auto itemj: mapObj){
      if(itemj != item){
        setState(item.second, itemj.second, StateCls::None);
      }
    } 
  }
}
void CollisionsHandler::loopState(){
     for(auto item: mapObj){
        for(auto itemj: mapObj){
          if(itemj != item){
            if(getState(item.second,itemj.second)==StateCls::None){
              setState(item.second, itemj.second, this->crash(itemj.second ,item.second));
            }; 
            if(getState(item.second,itemj.second)==StateCls::True){
               item.second->colision(itemj.second);
            }; 
          }
        } 
      } 
}
void CollisionsHandler::delState(Iobjet_colicion *n, Iobjet_colicion *n1){
      auto num_n  = mapObjnum.find(n);
      auto num_n1 = mapObjnum.find(n1); 
      if( num_n->second > num_n1->second ){
        auto map=mtrBase.find(n);
        map->second->erase(n1);
      }else{
        auto map=mtrBase.find(n1);
        map->second->erase(n);
      }
};
void CollisionsHandler::del(Iobjet_colicion *_obj){
  
  int objNum = mapObjnum[_obj]; 
  for(auto itemj: mapObj){
    if(itemj.second != _obj ){
      delState(_obj, itemj.second);
    }
  }
  mapObj.erase(objNum);
  mapObjnum.erase(_obj);
}
StateCls CollisionsHandler::crash(Iobjet_colicion *a , Iobjet_colicion *b){
    if( a->getRun() && b->getRun() ){

        StateCls state=StateCls::None;
        double distance = a->getRadio() + b->getRadio();
        double distanceP = pow( (a->position->x - b->position->x),2 ) + pow( (a->position->y - b->position->y),2 )  + pow(( a->position->z - b->position->z ),2);
        distanceP = pow(distanceP ,0.5);
        if(distanceP > distance ){
            return StateCls::False;
        }
        return StateCls::True;
    }else{
        return StateCls::False;
    }
};
