#ifndef INIT_HPP
#define INIT_HPP
#include <iostream>
#include <vector>
#include <mutex>
#include <thread>
#include <stdio.h>
#include <termios.h>           
#include <unistd.h>
#include <ctime>
#include "bullet.hpp"
#include "enemy.hpp"
#include "hero.hpp" 
#include "map.hpp"
using namespace std;

 std::vector<enemy> m_enemy_vec;

 std::vector<bullet> m_bullet_vec;

 hero m_plane;

 Map m_map;

#endif
