#include <string>
#include <fstream>
#include <iostream>
using namespace std;

string day(string date)
{
  string key; int bfr = 0; char val[10];
  bfr = stoi(date.substr(0,2));
  sprintf (val, "%.i", bfr);
  key += val; key += ".";
  bfr = stoi(date.substr(3,6));
  sprintf (val, "%.i", bfr);
  key += val; key += ".";
  bfr = stoi(date.substr(6,10));
  sprintf (val, "%.i", bfr);
  key += val;
  return key;
}

int main()
{
  int bfr = 0;
  char pay[6];
  string text, buf;
  string name, surname, payment, date;

  ifstream statement;
  statement.open ("C:\\wfiles\\statement.txt");
  while (statement >> name >> surname >> payment >> date)
  {
    bfr = stoi(payment);
    sprintf (pay, "%.i", bfr);
    date = day(date);

    buf = name + " " + surname + "\n" + pay + "rub." + "\t\t";
    text += buf;
    buf = date + "\n~~~~~~~~~~~~~~~~~~~~~~~\n";
    text += buf;
  }
  statement.close();

  ofstream account ("C:\\wfiles\\account.txt");
  account << text;
  account.close();
  cout << "C:\\wfiles\\account.txt" << endl;
}
