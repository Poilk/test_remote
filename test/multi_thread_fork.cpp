//
// Created by 文欣 on 2022/6/8.
//

#include <iostream>
#include <unistd.h>
using namespace std;

class Foo{
 public:
  Foo(){
    cout << "Foo" << endl;
  }
  ~Foo(){
    cout << "~Foo" << endl;
  }

  void doit(){
    cout << "do it" << endl;
  }
 private:
  Foo(Foo &) = default;
};

int main(int argc, char *argv[]){
  Foo foo;
  foo.doit();
  fork();
  sleep(3);
  return 0;
}