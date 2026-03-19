/*-Задание-2, посвящается
параллельным вычислениям-*/

#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
using namespace std;

void resultVector(vector<int> &a, vector<int> &b, vector<int> &res, int start, int end)
{
  for (int i = start; i < end; ++i)
  {
    res[i] = a[i] + b[i];
  }
};

void addVector(vector<int> &a, vector<int> &b, vector<int> &c)
{
  for (int i = 0; i < a.size(); ++i)
  {
    c[i] = a[i] + b[i];
  };
};

int main()
{
  /*-Вектора на 1000 единиц-*/
  vector<int> first_1_000(1000, 1);
  vector<int> second_1_000(1000, 2);
  vector<int> result_1_000(1000);

  /*-Вектора на 10 000 единиц-*/
  vector<int> first_10_000(10000, 1);
  vector<int> second_10_000(10000, 2);
  vector<int> result_10_000(10000);

  /*-Вектора на 100 000 единиц-*/
  vector<int> first_100_000(100000, 1);
  vector<int> second_100_000(100000, 2);
  vector<int> result_100_000(100000);

  /*-Вектора на 1000 000 единиц-*/
  vector<int> first_1000_000(1000000, 1);
  vector<int> second_1000_000(1000000, 2);
  vector<int> result_1000_000(1000000);

  /*-Сложение векторов в одном потоке-*/
  auto startTime1000ItemsOneJet = chrono::high_resolution_clock::now();
  thread t_1_1000(addVector, ref(first_1_000), ref(second_1_000), ref(result_1_000));
  t_1_1000.join();
  auto endTime1000ItemsOneJet = chrono::high_resolution_clock::now();
  chrono::duration<double, std::micro> duration1000ItemsOneJet = endTime1000ItemsOneJet - startTime1000ItemsOneJet;
  cout << "1 potok, 1000 elementov: " << duration1000ItemsOneJet.count() << ", ";

  auto startTime10_000ItemsOneJet = chrono::high_resolution_clock::now();
  thread t_1_10_000(addVector, ref(first_10_000), ref(second_10_000), ref(result_10_000));
  t_1_10_000.join();
  auto endTime10_000ItemsOneJet = chrono::high_resolution_clock::now();
  chrono::duration<double, std::micro> duration10_000ItemsOneJet = endTime10_000ItemsOneJet - startTime10_000ItemsOneJet;
  cout << "10 000 elementov: " << duration10_000ItemsOneJet.count() << ", ";

  auto startTime100_000ItemsOneJet = chrono::high_resolution_clock::now();
  thread t_1_100_000(addVector, ref(first_100_000), ref(second_100_000), ref(result_100_000));
  t_1_100_000.join();
  auto endTime100_000ItemsOneJet = chrono::high_resolution_clock::now();
  chrono::duration<double, std::micro> duration100_000ItemsOneJet = endTime100_000ItemsOneJet - startTime100_000ItemsOneJet;
  cout << "100 000 elementov: " << duration100_000ItemsOneJet.count() << ", ";

  auto startTime1000_000ItemsOneJet = chrono::high_resolution_clock::now();
  thread t_1_1000_000(addVector, ref(first_1000_000), ref(second_1000_000), ref(result_1000_000));
  t_1_1000_000.join();
  auto endTime1000_000ItemsOneJet = chrono::high_resolution_clock::now();
  chrono::duration<double, std::micro> duration1000_000ItemsOneJet = endTime1000_000ItemsOneJet - startTime1000_000ItemsOneJet;
  cout << "1000 000 elementov: " << duration1000_000ItemsOneJet.count() << endl;

  /*-Теперь сложение векторов в двух потоках-*/
  result_1_000.clear();
  result_10_000.clear();
  result_100_000.clear();
  result_1000_000.clear();

  auto startTime1000TwoJet = chrono::high_resolution_clock::now();
  thread t2_1_1000(resultVector, ref(first_1_000), ref(second_1_000), ref(result_1_000), 0, 500);
  thread t2_2_1000(resultVector, ref(first_1_000), ref(second_1_000), ref(result_1_000), 500, 1000);
  t2_1_1000.join();
  t2_2_1000.join();
  auto endTime1000TwoJet = chrono::high_resolution_clock::now();
  chrono::duration<double, std::micro> duration1000TwoJet = endTime1000TwoJet - startTime1000TwoJet;
  cout << "2 potoka, 1000 elementov: " << duration1000TwoJet.count() << ", ";

  auto startTime10_000TwoJet = chrono::high_resolution_clock::now();
  thread t2_1_10_000(resultVector, ref(first_10_000), ref(second_10_000), ref(result_10_000), 0, 5000);
  thread t2_2_10_000(resultVector, ref(first_10_000), ref(second_10_000), ref(result_10_000), 5000, 10000);
  t2_1_10_000.join();
  t2_2_10_000.join();
  auto endTime10_000TwoJet = chrono::high_resolution_clock::now();
  chrono::duration<double, std::micro> duration10_000TwoJet = endTime10_000TwoJet - startTime10_000TwoJet;
  cout << "10 000 elementov: " << duration10_000TwoJet.count() << ", ";

  auto startTime100_000TwoJet = chrono::high_resolution_clock::now();
  thread t2_1_100_000(resultVector, ref(first_100_000), ref(second_100_000), ref(result_100_000), 0, 50000);
  thread t2_2_100_000(resultVector, ref(first_100_000), ref(second_100_000), ref(result_100_000), 50000, 100000);
  t2_1_100_000.join();
  t2_2_100_000.join();
  auto endTime100_000TwoJet = chrono::high_resolution_clock::now();
  chrono::duration<double, std::micro> duration100_000TwoJet = endTime100_000TwoJet - startTime100_000TwoJet;
  cout << "100 000 elementov: " << duration100_000TwoJet.count() << ", ";

  auto startTime1000_000TwoJet = chrono::high_resolution_clock::now();
  thread t2_1_1000_000(resultVector, ref(first_1000_000), ref(second_1000_000), ref(result_1000_000), 0, 500000);
  thread t2_2_1000_000(resultVector, ref(first_1000_000), ref(second_1000_000), ref(result_1000_000), 500000, 1000000);
  t2_1_1000_000.join();
  t2_2_1000_000.join();
  auto endTime1000_000TwoJet = chrono::high_resolution_clock::now();
  chrono::duration<double, std::micro> duration1000_000TwoJet = endTime1000_000TwoJet - startTime1000_000TwoJet;
  cout << "1000 000 elementov: " << duration1000_000TwoJet.count() << endl;

  /*-Сложение векторов в четырёх потоках-*/
  result_1_000.clear();
  result_10_000.clear();
  result_100_000.clear();
  result_1000_000.clear();

  auto start1000_4_jet = chrono::high_resolution_clock::now();
  thread t4_1_1000(resultVector, ref(first_1_000), ref(second_1_000), ref(result_1_000), 0, 250);
  thread t4_2_1000(resultVector, ref(first_1_000), ref(second_1_000), ref(result_1_000), 250, 500);
  thread t4_3_1000(resultVector, ref(first_1_000), ref(second_1_000), ref(result_1_000), 500, 750);
  thread t4_4_1000(resultVector, ref(first_1_000), ref(second_1_000), ref(result_1_000), 750, 1000);
  t4_1_1000.join();
  t4_2_1000.join();
  t4_3_1000.join();
  t4_4_1000.join();
  auto end1000_4_jet = chrono::high_resolution_clock::now();
  chrono::duration<double, std::micro> duration1000_4_jet = end1000_4_jet - start1000_4_jet;
  cout << "4 potoka, 1000 elementov: " << duration1000_4_jet.count() << ", ";

  auto start10_000_4_jet = chrono::high_resolution_clock::now();
  thread t4_1_10_000(resultVector, ref(first_10_000), ref(second_10_000), ref(result_10_000), 0, 2500);
  thread t4_2_10_000(resultVector, ref(first_10_000), ref(second_10_000), ref(result_10_000), 2500, 5000);
  thread t4_3_10_000(resultVector, ref(first_10_000), ref(second_10_000), ref(result_10_000), 5000, 7500);
  thread t4_4_10_000(resultVector, ref(first_10_000), ref(second_10_000), ref(result_10_000), 7500, 10000);
  t4_1_10_000.join();
  t4_2_10_000.join();
  t4_3_10_000.join();
  t4_4_10_000.join();
  auto end10_000_4_jet = chrono::high_resolution_clock::now();
  chrono::duration<double, std::micro> duration10_000_4_jet = end10_000_4_jet - start10_000_4_jet;
  cout << "10 000 elementov: " << duration10_000_4_jet.count() << ", ";

  auto start100_000_4_jet = chrono::high_resolution_clock::now();
  thread t4_1_100_000(resultVector, ref(first_100_000), ref(second_100_000), ref(result_100_000), 0, 25000);
  thread t4_2_100_000(resultVector, ref(first_100_000), ref(second_100_000), ref(result_100_000), 25000, 50000);
  thread t4_3_100_000(resultVector, ref(first_100_000), ref(second_100_000), ref(result_100_000), 50000, 75000);
  thread t4_4_100_000(resultVector, ref(first_100_000), ref(second_100_000), ref(result_100_000), 75000, 100000);
  t4_1_100_000.join();
  t4_2_100_000.join();
  t4_3_100_000.join();
  t4_4_100_000.join();
  auto end100_000_4_jet = chrono::high_resolution_clock::now();
  chrono::duration<double, std::micro> duration100_000_4_jet = end100_000_4_jet - start100_000_4_jet;
  cout << "100 000 elementov: " << duration100_000_4_jet.count() << ", ";

  auto start1000_000_4_jet = chrono::high_resolution_clock::now();
  thread t4_1_1000_000(resultVector, ref(first_1000_000), ref(second_1000_000), ref(result_1000_000), 0, 250000);
  thread t4_2_1000_000(resultVector, ref(first_1000_000), ref(second_1000_000), ref(result_1000_000), 250000, 500000);
  thread t4_3_1000_000(resultVector, ref(first_1000_000), ref(second_1000_000), ref(result_1000_000), 500000, 750000);
  thread t4_4_1000_000(resultVector, ref(first_1000_000), ref(second_1000_000), ref(result_1000_000), 750000, 1000000);
  t4_1_1000_000.join();
  t4_2_1000_000.join();
  t4_3_1000_000.join();
  t4_4_1000_000.join();
  auto end1000_000_4_jet = chrono::high_resolution_clock::now();
  chrono::duration<double, std::micro> duration1000_000_4_jet = end1000_000_4_jet - start1000_000_4_jet;
  cout << "1000 000 elementov: " << duration1000_000_4_jet.count() << endl;

  /*-Сложение векторов в восьми потоках-*/
  result_1_000.clear();
  result_10_000.clear();
  result_100_000.clear();
  result_1000_000.clear();

  auto start1000_8_jet = chrono::high_resolution_clock::now();
  thread t8_1_1000(resultVector, ref(first_1_000), ref(second_1_000), ref(result_1_000), 0, 125);
  thread t8_2_1000(resultVector, ref(first_1_000), ref(second_1_000), ref(result_1_000), 125, 250);
  thread t8_3_1000(resultVector, ref(first_1_000), ref(second_1_000), ref(result_1_000), 250, 375);
  thread t8_4_1000(resultVector, ref(first_1_000), ref(second_1_000), ref(result_1_000), 375, 500);
  thread t8_5_1000(resultVector, ref(first_1_000), ref(second_1_000), ref(result_1_000), 500, 625);
  thread t8_6_1000(resultVector, ref(first_1_000), ref(second_1_000), ref(result_1_000), 625, 750);
  thread t8_7_1000(resultVector, ref(first_1_000), ref(second_1_000), ref(result_1_000), 750, 875);
  thread t8_8_1000(resultVector, ref(first_1_000), ref(second_1_000), ref(result_1_000), 875, 1000);
  t8_1_1000.join();
  t8_2_1000.join();
  t8_3_1000.join();
  t8_4_1000.join();
  t8_5_1000.join();
  t8_6_1000.join();
  t8_7_1000.join();
  t8_8_1000.join();
  auto end1000_8_jet = chrono::high_resolution_clock::now();
  chrono::duration<double, std::micro> duration1000_8_jet = end1000_8_jet - start1000_8_jet;
  cout << "8 potokov, 1000 elementov: " << duration1000_8_jet.count() << ", ";

  auto start10_000_8_jet = chrono::high_resolution_clock::now();
  thread t8_1_10_000(resultVector, ref(first_10_000), ref(second_10_000), ref(result_10_000), 0, 1250);
  thread t8_2_10_000(resultVector, ref(first_10_000), ref(second_10_000), ref(result_10_000), 1250, 2500);
  thread t8_3_10_000(resultVector, ref(first_10_000), ref(second_10_000), ref(result_10_000), 2500, 3750);
  thread t8_4_10_000(resultVector, ref(first_10_000), ref(second_10_000), ref(result_10_000), 3750, 5000);
  thread t8_5_10_000(resultVector, ref(first_10_000), ref(second_10_000), ref(result_10_000), 5000, 6250);
  thread t8_6_10_000(resultVector, ref(first_10_000), ref(second_10_000), ref(result_10_000), 6250, 7500);
  thread t8_7_10_000(resultVector, ref(first_10_000), ref(second_10_000), ref(result_10_000), 7500, 8750);
  thread t8_8_10_000(resultVector, ref(first_10_000), ref(second_10_000), ref(result_10_000), 8750, 10000);
  t8_1_10_000.join();
  t8_2_10_000.join();
  t8_3_10_000.join();
  t8_4_10_000.join();
  t8_5_10_000.join();
  t8_6_10_000.join();
  t8_7_10_000.join();
  t8_8_10_000.join();
  auto end10_000_8_jet = chrono::high_resolution_clock::now();
  chrono::duration<double, std::micro> duration10_000_8_jet = end10_000_8_jet - start10_000_8_jet;
  cout << "10 000 elementov: " << duration10_000_8_jet.count() << ", ";

  auto start100_000_8_jet = chrono::high_resolution_clock::now();
  thread t8_1_100_000(resultVector, ref(first_100_000), ref(second_100_000), ref(result_100_000), 0, 12500);
  thread t8_2_100_000(resultVector, ref(first_100_000), ref(second_100_000), ref(result_100_000), 12500, 25000);
  thread t8_3_100_000(resultVector, ref(first_100_000), ref(second_100_000), ref(result_100_000), 25000, 37500);
  thread t8_4_100_000(resultVector, ref(first_100_000), ref(second_100_000), ref(result_100_000), 37500, 50000);
  thread t8_5_100_000(resultVector, ref(first_100_000), ref(second_100_000), ref(result_100_000), 50000, 62500);
  thread t8_6_100_000(resultVector, ref(first_100_000), ref(second_100_000), ref(result_100_000), 62500, 75000);
  thread t8_7_100_000(resultVector, ref(first_100_000), ref(second_100_000), ref(result_100_000), 75000, 87500);
  thread t8_8_100_000(resultVector, ref(first_100_000), ref(second_100_000), ref(result_100_000), 87500, 100000);
  t8_1_100_000.join();
  t8_2_100_000.join();
  t8_3_100_000.join();
  t8_4_100_000.join();
  t8_5_100_000.join();
  t8_6_100_000.join();
  t8_7_100_000.join();
  t8_8_100_000.join();
  auto end100_000_8_jet = chrono::high_resolution_clock::now();
  chrono::duration<double, std::micro> duration100_000_8_jet = end100_000_8_jet - start100_000_8_jet;
  cout << "100 000 elementov: " << duration100_000_8_jet.count() << ", ";

  auto start1000_000_8_jet = chrono::high_resolution_clock::now();
  thread t8_1_1000_000(resultVector, ref(first_1000_000), ref(second_1000_000), ref(result_1000_000), 0, 125000);
  thread t8_2_1000_000(resultVector, ref(first_1000_000), ref(second_1000_000), ref(result_1000_000), 125000, 250000);
  thread t8_3_1000_000(resultVector, ref(first_1000_000), ref(second_1000_000), ref(result_1000_000), 250000, 375000);
  thread t8_4_1000_000(resultVector, ref(first_1000_000), ref(second_1000_000), ref(result_1000_000), 375000, 500000);
  thread t8_5_1000_000(resultVector, ref(first_1000_000), ref(second_1000_000), ref(result_1000_000), 500000, 625000);
  thread t8_6_1000_000(resultVector, ref(first_1000_000), ref(second_1000_000), ref(result_1000_000), 625000, 750000);
  thread t8_7_1000_000(resultVector, ref(first_1000_000), ref(second_1000_000), ref(result_1000_000), 750000, 875000);
  thread t8_8_1000_000(resultVector, ref(first_1000_000), ref(second_1000_000), ref(result_1000_000), 875000, 1000000);
  t8_1_1000_000.join();
  t8_2_1000_000.join();
  t8_3_1000_000.join();
  t8_4_1000_000.join();
  t8_5_1000_000.join();
  t8_6_1000_000.join();
  t8_7_1000_000.join();
  t8_8_1000_000.join();
  auto end1000_000_8_jet = chrono::high_resolution_clock::now();
  chrono::duration<double, std::micro> duration1000_000_8_jet = end1000_000_8_jet - start1000_000_8_jet;
  cout << "1000 000 elementov: " << duration1000_000_8_jet.count() << endl;

  return 0;
}