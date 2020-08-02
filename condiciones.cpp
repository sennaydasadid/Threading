#include <iostream>
#include <thread>
#include <functional>
#include <mutex>
#include <condition_variable>
using namespace std::placeholders;

class Aplicaciones
{
  std::mutex m_mutex;
  std::condition_variable m_condVar;
  bool m_bDataLoaded;
public:
  Aplicaciones(){
    m_bDataLoaded = false;
  }
  void loadData(){
   // Haz que este hilo duerma durante 1 segundo
   std::this_thread::sleep_for(std::chrono::milliseconds(1000));
   std::cout<<"Cargar datos desde XML"<<std::endl;
    //bloquear la estructura de datos
   std::lock_guard<std::mutex> guard(m_mutex);
   // Establece el indicador en verdadero, los datos cargados
   m_bDataLoaded = true;
   // Notificar la variable de condici+on
   m_condVar.notify_one();
  }
  bool isDataLoaded(){
    return m_bDataLoaded;
  }
  void mainTask(){
    std::cout<<"hola"<<std::endl;
    // Adquiere la cerradura
    std::unique_lock<std::mutex> mlock(m_mutex);
    / Comience a esperar a que se señale la Variable de condición
     // Wait () liberará internamente el bloqueo y hará que el hilo se bloquee
     // Tan pronto como se señale la variable de condición, reanude el hilo y
     // de nuevo adquiere la cerradura. Luego verifique si la condición se cumple o no
     // Si se cumple la condición, continúe de nuevo, vaya en espera.
    m_condVar.wait(mlock, std::bind(&Aplicaciones::isDataLoaded, this));
    std::cout<<"Do Processing On loaded Data"<<std::endl;
  }
};
int main()
{
   Aplicaciones app;
   std::thread thread_1(&Aplicaciones::mainTask, &app);
   std::thread thread_2(&Aplicaciones::loadData, &app);
   thread_2.join();
   thread_1.join();
   return 0;
}