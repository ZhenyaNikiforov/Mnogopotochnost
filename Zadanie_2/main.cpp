/*-Задание-2, посвящается
параллельным вычислениям-*/

#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <iomanip>
using namespace std;

void cleanVectors(vector<int> &a)
{
  for (int i = 0; i < a.size(); ++i)
  {
    a[i] = 0;
  };

  return;
};

void addItems(vector<int> &a, vector<int> &b, vector<int> &c, int startPoint, int endPoint)
{
  for (int i = startPoint; i < endPoint; ++i)
  {
    c[i] = a[i] + b[i];
  };

  return;
}

void addVectors(vector<int> &a, vector<int> &b, vector<int> &c, int jets)
{
  auto startTime = chrono::high_resolution_clock::now();

  int itemsInOneJet = a.size() / jets;
  int remainderItems = a.size() % jets;

  int startPoint = 0;
  int endPoint = itemsInOneJet;

  vector<thread> threads;

  for (int i = 0; i < jets; ++i)
  {
    if ((i + 1) == jets)
    {
      endPoint += remainderItems;
    };

    threads.emplace_back(addItems, ref(a), ref(b), ref(c), startPoint, endPoint);
    startPoint = endPoint;
    endPoint += itemsInOneJet;
  };

  for (auto &t : threads)
  {
    if (t.joinable())
    {
      t.join();
    };
  };

  auto endTime = chrono::high_resolution_clock::now();
  chrono::duration<double, std::micro> duration = endTime - startTime;
  cout << setw(15) << duration.count() << setw(5) << "mks.";
  return;
}

int main()
{
  unsigned int nuclears = thread::hardware_concurrency();
  cout << "Yader: " << nuclears << endl;

  /*-Вектора на 1000 единиц-*/
  vector<int> first_1_000(1000, 1);
  vector<int> second_1_000(1000, 2);
  vector<int> result_1_000(1000, 0);

  /*-Вектора на 10 000 единиц-*/
  vector<int> first_10_000(10000, 1);
  vector<int> second_10_000(10000, 2);
  vector<int> result_10_000(10000, 0);

  /*-Вектора на 100 000 единиц-*/
  vector<int> first_100_000(100000, 1);
  vector<int> second_100_000(100000, 2);
  vector<int> result_100_000(100000, 0);

  /*-Вектора на 1000 000 единиц-*/
  vector<int> first_1000_000(1000000, 1);
  vector<int> second_1000_000(1000000, 2);
  vector<int> result_1000_000(1000000, 0);

  cout << setw(20) << "Potoki"
       << setw(20) << 1000
       << setw(20) << 10000
       << setw(20) << 100000
       << setw(20) << 1000000
       << endl;

  cout << string(100, '-') << endl;

  /*-Сложение в одном потоке-*/
  cleanVectors(result_1_000);
  cleanVectors(result_10_000);
  cleanVectors(result_100_000);
  cleanVectors(result_1000_000);
  cout << setw(20) << "1 potok";
  addVectors(first_1_000, second_1_000, result_1_000, 1);
  addVectors(first_10_000, second_10_000, result_10_000, 1);
  addVectors(first_100_000, second_100_000, result_100_000, 1);
  addVectors(first_1000_000, second_1000_000, result_1000_000, 1);
  cout << endl;

  /*-Теперь сложение векторов в двух потоках-*/
  cleanVectors(result_1_000);
  cleanVectors(result_10_000);
  cleanVectors(result_100_000);
  cleanVectors(result_1000_000);
  cout << setw(20) << "2 potoka";
  addVectors(first_1_000, second_1_000, result_1_000, 2);
  addVectors(first_10_000, second_10_000, result_10_000, 2);
  addVectors(first_100_000, second_100_000, result_100_000, 2);
  addVectors(first_1000_000, second_1000_000, result_1000_000, 2);
  cout << endl;

  /*-...в четырёх потоках-*/
  cleanVectors(result_1_000);
  cleanVectors(result_10_000);
  cleanVectors(result_100_000);
  cleanVectors(result_1000_000);
  cout << setw(20) << "4 potoka";
  addVectors(first_1_000, second_1_000, result_1_000, 4);
  addVectors(first_10_000, second_10_000, result_10_000, 4);
  addVectors(first_100_000, second_100_000, result_100_000, 4);
  addVectors(first_1000_000, second_1000_000, result_1000_000, 4);
  cout << endl;

  /*-...в восьми потоках-*/
  cleanVectors(result_1_000);
  cleanVectors(result_10_000);
  cleanVectors(result_100_000);
  cleanVectors(result_1000_000);
  cout << setw(20) << "8 potokov";
  addVectors(first_1_000, second_1_000, result_1_000, 8);
  addVectors(first_10_000, second_10_000, result_10_000, 8);
  addVectors(first_100_000, second_100_000, result_100_000, 8);
  addVectors(first_1000_000, second_1000_000, result_1000_000, 8);
  cout << endl;

  /*-...в шестнадцати потоках-*/
  cleanVectors(result_1_000);
  cleanVectors(result_10_000);
  cleanVectors(result_100_000);
  cleanVectors(result_1000_000);
  cout << setw(20) << "16 potokov";
  addVectors(first_1_000, second_1_000, result_1_000, 16);
  addVectors(first_10_000, second_10_000, result_10_000, 16);
  addVectors(first_100_000, second_100_000, result_100_000, 16);
  addVectors(first_1000_000, second_1000_000, result_1000_000, 16);
  cout << endl;

  return 0;
}