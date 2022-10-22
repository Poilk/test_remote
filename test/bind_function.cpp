//
// Created by 文欣 on 2022/6/7.
//

#include <functional>
#include <iostream>

using namespace  std;

int fx(int x, int y, int z){
  cout << x << ' ' << y << ' ' << z << endl;
}

typedef std::shared_ptr<int> Ptr;
int fy(std::weak_ptr<int> p1, int x){
  cout << p1.use_count() << endl;
}

int main(int argc, char *argv[]){
  auto gx = std::bind(fx, 100, 10, std::placeholders::_1);
  gx(1);
  gx(500, 400, 10);
  gx(3, 2, 1);
  std::function<void(int)> gy;
  {
    Ptr py{new int(10)};
    gy = std::bind(fy, std::weak_ptr<int> {py}, std::placeholders::_1);
  }
  auto ggy = gy;
  auto gggy = gy;
  gy(10);
  ggy(100);
  return 0;
}