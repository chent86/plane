#ifndef MAP_HPP
#define MAP_HPP
#include "set.hpp"
#include <mutex>
#include "enemy.hpp"
#include "bullet.hpp"
#include "hero.hpp"
std::mutex mtx;
class Map {
public: 
  Map() {
    for(int i = 0; i < width; i++) {
      picture[hight-1][i] = '#';
    }
    for(int i = 0; i < hight; i++) {
      picture[i][0] = '#';
      picture[i][width-1] = '#';
    }
  }
  void change(std::vector<enemy>& m_enemy_vec, std::vector<bullet>& m_bullet_vec, hero& m_plane) {
      std::unique_lock<std::mutex> lck(mtx);
      printf("\033[%d;%dH", 0, 0);

      clean();
      write(m_enemy_vec, m_bullet_vec, m_plane);
      print();
  }

  void clean() {
    for(int i = 0; i < hight-1; i++)
      for(int j= 1; j < width-1; j++)
        picture[i][j] = ' ';
  }

  void write(std::vector<enemy>& m_enemy_vec, std::vector<bullet>& m_bullet_vec, hero& m_plane) {

    for(auto &i : m_bullet_vec)
      picture[i.get_locate().first][i.get_locate().second] = '?';
    
    for(auto &i : m_enemy_vec)
      picture[i.get_locate().first][i.get_locate().second] = '@';

    int x = m_plane.get_head_locate().first;
    int y = m_plane.get_head_locate().second;
    picture[x][y] = '!';
    picture[x+1][y] = '+';
    picture[x+1][y-1] = '=';
    picture[x+1][y+1] = '=';

  }

  void print() {
    for(int i = 0; i < hight; i++) {
      for(int j = 0; j < width; j++) 
        cout << picture[i][j];
      cout << endl;
    }
  }

private:
  char picture[hight][width];  
};

#endif