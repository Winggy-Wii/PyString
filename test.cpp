#include "PyString.h"
#include "iostream"
int main()
{
  PyString obj1 = "Hello, ";
  PyString obj2 = "world!";
  PyString obj3 = obj1 + obj2;

  obj3.display();

  if (obj1 == obj2)
  {
    std::cout << "Objects are equal." << std::endl;
  }
  else
  {
    std::cout << "Objects are not equal." << std::endl;
  }

  return 0;
}
