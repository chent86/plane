#include "defines.hpp"
bool gameover = false;

void Start_hero() {
  m_map.change(m_enemy_vec, m_bullet_vec, m_plane);
  char c;   
  static struct termios oldt, newt;
  tcgetattr( STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON);          
  tcsetattr( STDIN_FILENO, TCSANOW, &newt);
  system("stty -echo");
  while((c=getchar())!= 'o') {
    m_plane.move_command(c);
    m_map.change(m_enemy_vec, m_bullet_vec, m_plane); 
  }     

  system("stty echo");              
  tcsetattr( STDIN_FILENO, TCSANOW, &oldt);
}

void shot_bullet() {
  while(!gameover) {
    usleep(250000);
    m_plane.shot(m_bullet_vec);
    for(auto &i: m_bullet_vec)
      i.move();
    for(auto i = m_bullet_vec.begin(); i != m_bullet_vec.end(); )
      if(i->out())
        i = m_bullet_vec.erase(i);
      else
        i++;

    m_map.change(m_enemy_vec, m_bullet_vec, m_plane);
  }
}

void enemy_come() {
  srand(time(0));
  int num;
  while(!gameover) {
    sleep(1);
    num = rand() % 79+1;
    m_enemy_vec.push_back(enemy(make_pair(1, num)));
    for(auto &i: m_enemy_vec)
      i.move();
    m_map.change(m_enemy_vec, m_bullet_vec, m_plane);  
  }
}

bool verify() {
  while(1) {
    usleep(200000);
    for(auto i = m_enemy_vec.begin(); i != m_enemy_vec.end(); )
    if(i->out() || i->dead(m_bullet_vec))
      i = m_enemy_vec.erase(i);
    else
      i++;
  }
}
int main() {
  thread plane(Start_hero);
  thread Bullet(shot_bullet);
  thread Enemy(enemy_come);
  thread Verify(verify);
  plane.join();
  Bullet.join();
  Enemy.join();
  Verify.join();
}