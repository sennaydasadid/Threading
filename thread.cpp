#include <iostream>
#include <thread>

using namespace std;

void Ejem1(int x){
    cout<<x*2<<endl;
}

class Ejemplo{
    public:
    void Mostrar( int x){
        std::cout<<x<<endl;
    }
};

class EjemploF{
    public:
    void MostrarF( int x){
        cout<<x<<endl;
    }
};

int main(){
    //crea un hilo
    thread th1(Ejem1,10);//Ejem1 es la funcion a ejeccutar y 10 es el argumento


    Ejemplo ejem;
    thread th2(&Ejemplo::Mostrar,&ejem,23);//pase 10 a la función mimebro
    

    EjemploF ejemF;
    thread th3(ejemF,5);//pasa 5 al objeto functor
    //el objeto creador functor se ejecutara en un hilo separado

    th1.join();//espera a que el hilo termine, operación de bloqueo
    th2.join();
    th3.join();
    return 0;
}