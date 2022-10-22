//
// Created by 文欣 on 2022/5/18.
//

#include <mutex>
#include <thread>

class Foo{
 public:
  std::mutex mtx;
  std::condition_variable cv;
  bool first_done{};
  bool second_done{};
  Foo(){
  }

  void first() {

    puts("begin first");

    std::lock_guard<std::mutex> lck(mtx);
    // printFirst() outputs "first". Do not change or remove this line.
    puts("first");
    cv.notify_one();
    first_done = true;
    puts("first_done");
  }

  void second() {

    std::unique_lock<std::mutex> lck(mtx);
    cv.wait(lck, [&]{return first_done;});
    //cv.wait(lck);
    // printSecond() outputs "second". Do not change or remove this line.
    puts("second");
    cv.notify_one();
    second_done = true;
  }

  void third() {

    puts("begin thread");
    std::unique_lock<std::mutex> lck(mtx);
    cv.wait(lck, [&]{return second_done;});
    // printThird() outputs "third". Do not change or remove this line.
    puts("third");
  }

  void test(){

  }
};

int main(int argc, char *argv[]){
  Foo foo;
  std::thread t3{&Foo::third, &foo};
  std::thread t2{&Foo::second, &foo};
  std::thread t1{&Foo::first, &foo};
  t1.join();
  t2.join();
  t3.join();
  return 0;
}