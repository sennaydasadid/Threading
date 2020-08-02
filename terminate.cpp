#include <iostream> 
#include <utility> 
#include <thread> 
#include <chrono>
class thread_joiner{
    public:
    thread_joiner(std::thread t)
        : t_(std::move(t))
    { }
    ~thread_joiner(){
        if(t_.joinable()) {
            t_.join();
        }
    }
    private:
    std::thread t_;
};
void Ejemplo(){
    std::cout<<"Progrmacion";
}
void E(){
    thread_joiner tj{std::thread(Ejemplo)};
}