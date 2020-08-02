#include <iostream>
#include <mutex>
#include <thread>

std::mutex mutex_;
void ejemplo(){
    //se adquiere un candado en el mutex
    std::lock_guard<std::mutex>guardar(mutex_);

    std::unique_lock<std::mutex>guard1(mutex_,std::defer_lock);
    guard1.lock();
    guard1.unlock();
}