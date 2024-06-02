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

  // Overload [] operator to perform slicing
  std::string operator[](const std::string &slice)
  {
    int start = 0, stop = message.length(), step = 1;

    // Parse slice string
    size_t colonPos = slice.find(':');
    if (colonPos != std::string::npos)
    {
      start = slice.substr(0, colonPos).empty() ? 0 : std::stoi(slice.substr(0, colonPos));
      stop = slice.substr(colonPos + 1).empty() ? stop : std::stoi(slice.substr(colonPos + 1));
    }

    std::string result;
    for (int i = start; i < stop; i += step)
    {
      result += message[i];
    }
    return result;
  }

  // len
  int len()
  {
    return message.length();
  }

  // capitalize
  std::string capitalize()
  {
    if ('a' <= message[0] && message[0] <= 'z')
    {
      char a = message[0] - 32;
      message[0] = a;
      return message;
    }
    else
    {
      if ('A' < message[0] < 'Z')
      {
        return message;
      }
      else
      {
        throw -1;
      }
    }
  }

  //count
  int count(const std::string& substring)
{
    if (substring.empty()) return 0; 

    int count = 0;
    size_t pos = message.find(substring); 

    while (pos != std::string::npos)
    {
        count++;
        pos = message.find(substring, pos + substring.size()); 
    }

    return count;
}

  // count
  int count(const std::string &substring)
  {
    if (substring.empty())
      return 0;

    int count = 0;
    size_t pos = message.find(substring);

    while (pos != std::string::npos)
    {
      count++;
      pos = message.find(substring, pos + substring.size());
    }

    return count;
  }

private:
  std::string message;
};

class len : public PyString
{
};

int main()
{
  PyString obj1 = "Hello, world!"; // Object instantiated with a string literal
  // obj1.display();                  // Output: Hello, world!

  // PyString obj2 = " hihi"; // Object instantiated with a character literal

  // obj2.display(); // Output: A

  // PyString obj3 = obj1 + obj2;
  // obj3 += PyString("KKK");
  // obj3.display();

  // obj1[4] = 'P';
  // obj1.display();
  // std::cout << obj1["1:3"];
  // std::cout << obj1.len();
  std::cout << obj1.capitalize();
  std::cout << obj1.count("Hello") << std::endl;
  return 0;
}
