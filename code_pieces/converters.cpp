#include <iostream>
#include <string.h>
using namespace std;

int HexToDec(char hex[])
{
  int len = strlen(hex);
   int base = 1;
   int temp = 0;
   for (int i=len-1; i>=0; i--) {
      if (hex[i]>='0' && hex[i]<='9') {
         temp += (hex[i] - 48)*base;
         base = base * 16;
      }
      else if (hex[i]>='A' && hex[i]<='F') {
         temp += (hex[i] - 55)*base;
         base = base*16;
      }
   }
   return temp;
}


void DecToHex(int dec)
{
  char hex[100];
  int i = 0;
  while(dec != 0)
  {
    int temp = 0;
    temp = dec % 16;
    if (temp < 10)
    {
      hex[i] = temp + 48;
      i++;
    } else {
      hex[i] = temp + 55;
      i++;
    }
    dec /= 16;
  }
  for (int j = i-1; j>=0; j--)
  cout << hex[j];
}

void HexToBin(char hex[])
{
  int dec = HexToDec(hex);

     for (int i = 31; i >= 0; i--) {
      int k = dec >> i;
      if (k & 1)
         cout << "1";
      else
         cout << "0";
   }
}

int BinToDec(string bin) {
  string n = bin;
  int val = 0;
  int temp = 1;
  int len = n.length();
  for (int i = len - 1; i >= 0; i--)
  {
    if (n[i] == '1')
    val += temp;
    temp *= 2;
  }
  return val;
}


int main() {
  char hex[] = "3F456A";
  int dec = 6789;
  string bin = "11101";

  cout << hex << " converted to decimal: " << HexToDec(hex) << endl;
  cout << dec << " converted to hexadecimal: ";
  DecToHex(dec);
  cout << "\n" << hex << " converted to binary: ";
  HexToBin(hex);
  cout << "\n" << bin << " converted to decimal: " << BinToDec(bin);


  return 0;
}
