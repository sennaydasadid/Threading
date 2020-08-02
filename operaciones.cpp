#include <iostream> 
#include <utility> 
#include <thread> 
#include <chrono>
//---get_id----
void ejemplo(){
    std::cout<<std::this_thread::get_id()<<std::endl;
}

//---sleep_util-------
void foo(){
    std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::hours(3));
}

//----yield---------------
void foo(int a){
    for (int i = 0; i < al ++i)
    std::this_thread::yield(); //ahora otros hilos tienen prioridad
    //ese hilo no está haciendo nada importante
    std::cout << "Hello World!\n";
}
int main(){
    //---get_id----
    std::thread th{ejemplo};
    th.join();
    ejemplo();

    //------sleep_for--- 
    std::cout << "countdown:\n";
    for (int i=10; i>0; --i) {
        std::cout << i << std::endl;
        std::this_thread::sleep_for (std::chrono::seconds(1));
    }
    std::cout << "Lift off!\n";

    //------sleep_util-------
    std::thread th1{ foo };
    th1.join();
    std::cout << "Ahora estamos ubicados 3 horas después de que el hilo ha sido llamado\n";

    //----yield---------------
    std::thread th2{ foo, 10 };
    th2.join();
    return 0;
}