//
// Created by 文欣 on 2022/6/6.
//
#include <memory>
#include <iostream>
#include <vector>

class Frame{
 public:
  typedef std::shared_ptr<Frame> Ptr;
  Frame(){
    std::cout << "Frame Constructor" << std::endl;
  }
  ~Frame(){
    std::cout << "Frame Destructor" << std::endl;
  }
};

class FramePool: public std::enable_shared_from_this<FramePool>{
 public:
  typedef std::shared_ptr<FramePool> Ptr;
  FramePool() = delete;
  explicit FramePool(int max_frame) : max_frame_count(max_frame){
  }
  Frame::Ptr get_frame(){
    std::lock_guard<std::mutex> guard(mutex_);
    std::weak_ptr<FramePool> weak_this(shared_from_this());
    auto f = std::bind(FramePool::delete_frame, weak_this, std::placeholders::_1);
    Frame::Ptr new_frame(new Frame(), f);
    frame_count++;
    std::cout << "after get_frame " << frame_count << std::endl;
    return new_frame;
  }
  int get_pool_size() const {
    std::lock_guard<std::mutex> guard(mutex_);
    return frame_count;
  }
 private:
  static void delete_frame(std::weak_ptr<FramePool> frame_pool, Frame *del_frame){
    std::cout << "gw.use_count() == " << frame_pool.use_count() << "; ";
    // we have to make a copy of shared pointer before usage:
    if (auto spt = frame_pool.lock()) {
      std::cout << "*spt == " << spt << '\n';
      std::cout << "frame_pool" << " delete_frame " << del_frame << std::endl;
      spt->put_frame();
      delete del_frame;
    }
    else {
      std::cout << "gw is expired\n";
    }
  }
  void put_frame(){
    std::lock_guard<std::mutex> guard(mutex_);
    frame_count--;
    std::cout << "after put frame, frame_count " << frame_count << std::endl;
  }
  mutable std::mutex mutex_;
  const int max_frame_count;
  int frame_count = 0;
};

int main(int argc, char *argv[]){
  Frame::Ptr f2;
  {
    FramePool::Ptr frame_pool{new FramePool(10)};
    std::cout << "frame_pool " << frame_pool << std::endl;

    auto f1 = frame_pool->get_frame();
    std::cout << "f1 " << f1.get() << std::endl;

    f2 = frame_pool->get_frame();
    std::cout << "f2 " << f2.get() << std::endl;
  }
  std::shared_ptr<int> p2(new int{10});
  std::cout << *p2 << std::endl;
  return 0;
}
