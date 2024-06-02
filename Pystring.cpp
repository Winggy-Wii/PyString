#include <iostream>
#include <string>

class PyString
{
public:
  PyString(const char *message) : message(message) {}
  PyString(char character) : message(1, character) {}

  void display()
  {
    std::cout << message << std::endl;
  }
  void whatever()
  {
    std::cout << *message.begin() << std::endl;
    std::cout << *message.end() << std::endl;
  }

private:
  std::string message;
};

int main()
{
  PyString obj1 = "Hello, world!"; // Object instantiated with a string literal
  obj1.display();                  // Output: Hello, world!
  obj1.whatever();

  PyString obj2 = 'Kienngu123456'; // Object instantiated with a character literal
  obj2.display();                 // Output: A
  obj2.whatever();

  return 0;
}
