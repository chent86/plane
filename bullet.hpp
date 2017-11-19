#ifndef BULLET_HPP
#define BULLET_HPP
#include "set.hpp"
using namespace std;
class bullet {
public:
  bullet(pair<int, int> init_location) 
  : location(init_location) {}

  bool move() {
    location.first--;
  }

  bool out() {
    if(location.first < 1 || location.first > hight-1
      || location.second < 1 || location.second > width-1)
      return true;
    return false;    
  }
  pair<int, int> get_locate() {
    return location;
  }
private:
  pair<int, int> location;
};
#endif