#include <iostream>
#include <chrono>
#include <thread>
 
using namespace std;
template <class T>
std::decay_t<T> decay_copy(T&& v) { return std::forward<T>(v); }
void funcion(int& num){
    num=100;
    cout << num << endl;
}
//-----
void func(const bool& empezar){
    while(!empezar){
        this_thread::sleep_for(chrono::milliseconds(1));//espera un milisegundo, evita sobrecarga de la CPU
    }
    cout << "X" << endl;
}

int main(){
    int num = 10;
    thread th{funcion, ref(num)};// num ahora se pasa como referencia
    th.join();
    cout << num << endl;// imprime 100
    //--------
    bool stard_ = false;
    thread th1(func, ref(stard_)); //stard_ se pasa como referencia constante
    cout<<"O"<<endl;
    stard_=true;
    th1.join();
    return 0;  
}