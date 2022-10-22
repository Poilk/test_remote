//
// Created by 文欣 on 2022/6/12.
//
#include "t.h"
#include <iostream>

class PD{
 public:
  int x;
  int y;
};

int main(int argc, char *argv[]){
  TPD tpd;
  tpd.pd = new PD();
  std::cout << tpd.x << tpd.y << tpd.pd->x << tpd.pd->y << std::endl;
  return 0;
}
