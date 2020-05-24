/*Formatting Output 
**Goal: practice using cout to format output to console
**Print the variables in three columns:
**Ints, Floats, Doubles
*/

#include <iostream>
#include <iomanip>

int main()
{
  int a = 45;
  std::cout << "a" << std::setw(5) << "= " << a << "\n";

  float b = 45.323;
  std::cout << "b" << std::setw(5) << "= " << b << "\n";

  double c = 45.5468;
  std::cout << "c" << std::setw(5) << "= " << c << "\n"; 
  
  int aa = a + 9;
  std::cout << "aa" << std::setw(4) << "= " << aa << "\n"; 
  
  float bb = b + 9;
  std::cout << "bb" << std::setw(4) << "= " << bb << "\n"; 
  
  double cc = c + 9;
  std::cout << "cc" << std::setw(4) << "= " << cc << "\n"; 
  
  int aaa = aa + 9;
  std::cout << "aaa" << std::setw(3) << "= " << aaa << "\n"; 
  
  float bbb = bb + 9;
  std::cout << "bbb" << std::setw(3) << "= " << bbb << "\n"; 
  
  double ccc = cc + 9;
  std::cout << "ccc" << std::setw(3) << "= " << ccc << "\n";

  return 0;
}
