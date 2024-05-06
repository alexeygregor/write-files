#include <ctime>
#include <vector>
#include <limits>
#include <numeric>
#include <fstream>
#include <iostream>
using namespace std;

int collector (char* enter)
{
  srand(time(nullptr));
  int a = 0, b = 0;
  char buffer[10];

  ifstream cash;
  cash.open("C:\\wfiles\\cash.bin", ios::binary);
  ofstream terminal ("C:\\wfiles\\terminal.bin");
  for (int i = 0; i < 5000; ++i)
  {
    a = rand() % 6 + 1;
    cash.seekg(a * 10);
    cash.read(buffer, sizeof(buffer));
    b = stoi (buffer);
    if (i % 10 == 0 && i != 0);
    if (i % 500 == 0);
    terminal << b << endl;
  }
  cash.close();
  terminal.close();
}

void transfer (vector <int> cnt)
{
  int a = 0, b = 0, in = 0, out = 0;
  string buf1, scope;
  int buf2 = 0;
  char buf3[10], buf4[10];

  ifstream read;
  read.open ("C:\\wfiles\\terminal.bin");
  ifstream cash;
  cash.open("C:\\wfiles\\cash.bin", ios::binary);
  while (read >> buf1)
  {
    for (int i = 1; i <= 6; ++i)
    {
      if (cnt[i] < 0)
      { a = cnt[i]; b = i; }
    }
    buf2 = stoi(buf1);
    cash.seekg(b * 10);
    cash.read(buf4, sizeof(buf4));
    out = stoi(buf4);
    if (out == buf2  && cnt[b] < 0 && a < 0)
    {
      for (int i = 1; i <= 6; ++i)
      {
        if (out == buf2)
        { a++; cnt[b] += 1; break; }
      }
    }
    else
    {
      sprintf(buf3,"%.i",buf2);
      scope += buf3; scope += "\n";
    }
  }
  read.close();
  cash.close();

  ofstream write ("C:\\wfiles\\terminal.bin");
  write << scope << endl;
  write.close();
}

void cashback (int sum)
{
  vector <int> cnt = {0, 0, 0, 0, 0, 0, 0};
  int buf = 0, note = 0, out = 0;
  char buf1[10];

  ifstream cash;
  cash.open("C:\\wfiles\\cash.bin", ios::binary);
  for (int i = 6; i > 0; --i)
  {
    cash.seekg(i * 10);
    cash.read(buf1, sizeof(buf1));
    out = stoi (buf1);
    if (sum >= out)
    { buf = sum % out; note = sum / out; cnt[i] -= note;
      cout << note << "^" << out << " ";  sum = buf; }
  }
  cout << endl;
  cash.close();
  transfer(cnt);
}

void balance (int sum)
{
  int scope = 0;
  int cnt1 = 0, cnt2 = 0, cnt3 = 0;
  int cnt4 = 0, cnt5 = 0, cnt6 = 0;

  cout << "$" << endl;
  ifstream terminal ("C:\\wfiles\\terminal.bin");
  while (terminal >> scope)
  {
    if (scope == 100)  cnt1++; if (scope == 200)  cnt2++;
    if (scope == 500)  cnt3++; if (scope == 1000) cnt4++;
    if (scope == 2000) cnt5++; if (scope == 5000) cnt6++;
  }
  cout << cnt1 << "  100 rub."  << endl;
  cout << cnt2 << "  200 rub."  << endl;
  cout << cnt3 << "  500 rub."  << endl;
  cout << cnt4 << "  1000 rub." << endl;
  cout << cnt5 << "  2000 rub." << endl;
  cout << cnt6 << "  5000 rub." << endl;
  terminal.close();
}

int main ()
{
  char enter[20];
  int sum = 0;
  while (true)
  {
    cout << "Enter: ";
    cin >> enter;
    if (cin.fail() || cin.peek() != '\n')
    {
      cerr << "Error\n";
      cin.clear();
      cin.ignore(numeric_limits < streamsize > ::max(), '\n');
    }
    else
    {
      if (enter[0] == '+')
      collector(enter);
      else if (enter[0] == '-')
      {
        cout << "Sum: "; cin >> sum;
        if (sum <= 0) { cerr << "Error\n"; return 0; }
        cout << "$" << endl;
        cashback(sum);
      }
      balance(sum);
      return 0;
    }
  }
}

