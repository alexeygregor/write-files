#include <ctime>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

int main ()
{
  char pic[3000];
  vector <int> buf;
  srand(time(nullptr));

  for (int i = 0; i < 3000; ++i)
  {
    buf.push_back(rand() % 2);
    pic[i] = buf[i] + '0';
  }

  ofstream picture ("C:\\wfiles\\random_picture.bin");

  for (int i = 0; i < 3000; ++i)
  {
    if (i % 100 == 0) picture << endl;
    else picture << pic[i];
  }
  picture.close();
  cout << "C:\\wfiles\\random_picture.bin" << endl;
}
