/*- Задание-1 (посвящается очереди клиентов) -*/

#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>

std::atomic<int> counterClients(0); // подсчёт клиентов
int maxClients = 10;                // максимальное кол-во клиентов

void noteClients()
{
  for (int i = 0; i < maxClients; ++i)
  {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    counterClients++;
    std::cout << "Uvelichil: " << counterClients << std::endl;
  };
};

void Operator()
{
  while (counterClients < (maxClients / 2))
  {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    counterClients--;
    std::cout << "Prinyal: " << counterClients << std::endl;
  };
};

int main()
{
  std::thread t1(noteClients);
  std::thread t2(Operator);

  t1.join();
  t2.detach();
  return 0;
};