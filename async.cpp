#include <future>
#include <iostream>
unsigned int  par (unsigned int a){
    return a*2;
}
int main(){
    auto a =std::async(std::launch::async, par,7);
    std::cout<<"La funcion 'par' actualmente ejecutandose"<<std::endl;
    std::cout<<"Resultado: "<<a.get()<<std::endl;
}