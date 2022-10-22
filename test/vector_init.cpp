//
// Created by poilk on 2022/7/1.
//
#include <vector>
#include <iostream>

struct Base{
  int x;
  int y;
};

struct Derived : public Base{
  int z;
};


int main(int argc, char *argv[]){
  using  namespace  std;
  Base b = {1, 2};
  std::vector<Base> d{Base{1, 2}, Derived{}, Base{1, 2}};
  for(auto bb: d){
    std::cout << bb.x << ' ' << bb.y << std::endl;
  }
  return 0;
}