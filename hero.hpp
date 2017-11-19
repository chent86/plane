#ifndef HERO_HPP
#define HERO_HPP
#include "set.hpp"
#include "bullet.hpp"
#include "enemy.hpp"
class hero {
public:
  hero() {
    location.push_back(make_pair(19, 40));
    location.push_back(make_pair(20, 40));
    location.push_back(make_pair(20, 39));
    location.push_back(make_pair(20, 41));
  }
  pair<int, int> get_head_locate() {
    return location[0];
  }
  void move_command(char c) {
    switch(c) {
      case 'a':
        move_left();
        break;
      case 'd':
        move_right();
        break;
      case 'w':
        move_forward();
        break;
      case 's':
        move_back();
        break;
    }
  }
  void move_forward() {
    if(get_head_locate().first != 1) {
      for(auto &i : location)
        i.first--;
    }
  }
  void move_back() {
    if(get_head_locate().first != hight-3) {
      for(auto &i : location)
        i.first++;
    }
  }
  void move_left() {
    if(get_head_locate().second != 2) {
      for(auto &i : location)
        i.second--;
    }
  }
  void move_right() {
    if(get_head_locate().second != width-3) {
      for(auto &i : location)
        i.second++;
    }    
  }
  void shot(std::vector<bullet>& m_bullet_vec) {
    if(get_head_locate().first) {
      m_bullet_vec.push_back(bullet(get_head_locate()));
    }
  }
  bool dead(std::vector<enemy> m_enemy_vec) {
    for(auto &i: m_enemy_vec)
      if(overlap(i.get_locate()))
        return true;
    return false;
  }
  bool overlap(pair<int, int> enemy_location) {
    for(auto &i: location)
      if(i == enemy_location)
        return true;
    return false;
  }
private:
  std::vector<pair<int, int>> location;
};
#endif