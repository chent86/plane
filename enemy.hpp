#ifndef ENEMY_HPP
#define ENEMY_HPP
using namespace std;
#include "set.hpp"
#include "bullet.hpp"
class enemy {
public:
  enemy(pair<int, int> init_location)
  :location(init_location) {}

  void move() {
    location.first++;
  }

  bool dead(std::vector<bullet>& m_bullet_vec) {
    for(auto & i: m_bullet_vec)
      if(i.get_locate() == location)
        return true;
    return false;
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