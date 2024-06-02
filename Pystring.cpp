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
  PyString operator+(const PyString &other) const
  {
    return PyString((message + other.message).c_str());
  }
  PyString &operator+=(const PyString &other)
  {
    message = message + other.message;
    return *this;
  }

  // Overload [] operator for read-only access
  char operator[](size_t index) const
  {
    if (index >= message.length())
    {
      throw std::out_of_range("Index out of range");
    }
    return message[index];
  }

  // Overload [] operator for write access
  char &operator[](size_t index)
  {
    if (index >= message.length())
    {
      throw std::out_of_range("Index out of range");
    }
    return message[index];
  }

private:
  std::string message;
};

int main()
{
  // PyString obj1 = "Hello, world!"; // Object instantiated with a string literal
  // obj1.display();                  // Output: Hello, world!

  // PyString obj2 = " hihi"; // Object instantiated with a character literal

  // obj2.display(); // Output: A

  // PyString obj3 = obj1 + obj2;
  // obj3 += PyString("KKK");
  // obj3.display();

  PyString obj1 = "heloo";

  obj1[4] = 'P';
  obj1.display();

  return 0;
}
