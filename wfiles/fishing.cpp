#include <string>
#include <fstream>
#include <iostream>
using namespace std;

void cnt_floats (string check)
{
  int cnt = 0;
  string cnt_float;
  ifstream river ("C:\\wfiles\\river.txt");

  while (river >> cnt_float)
  {
    if (check == cnt_float) cnt++;
  }
  cout << cnt << ";  ";
  river.close();
}

int main ()
{
  int cnt = 0;
  string fish, floats, check, buff;
  cout << "What fish we will catch: "; cin >> fish;

  ifstream river ("C:\\wfiles\\river.txt");
  while (river >> floats)
  {
    if (fish == floats) cnt++;
    else buff += floats + "\n";
  }
  cout << "\nFishes it`s cautch: " << cnt << "\n" << endl;
  river.close();

  ofstream scope ("C:\\wfiles\\river.txt");
  scope << buff;
  scope.close();

  ofstream basket ("C:\\wfiles\\basket.txt", ios::app);
  if (cnt > 0) { basket << fish << "_" << cnt << endl; }
  basket.close();

  ifstream checklist ("C:\\wfiles\\checklist.txt");
  while (checklist >> check)
  {
    if (check != fish) { cout << check; cnt_floats(check); }
  }
  cout << endl;
  checklist.close();
}
