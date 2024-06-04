#include <iostream>
#include <string>
#include <algorithm>

class PyString
{
private:
  std::string message;

public:
  PyString(const char *message) : message(message) {}
  PyString(char character) : message(1, character) {}

  void display()
  {
    std::cout << message << std::endl;
  }

  PyString operator+(const PyString &other) const
  {
    return PyString((message + other.message).c_str());
  }
  bool operator>(const PyString &other) const
  {
    return (message > other.message);
  }
  bool operator<(const PyString &other) const
  {
    return (message < other.message);
  }
  bool operator==(const PyString &other) const
  {
    return (message == other.message);
  }
  bool operator>=(const PyString &other) const
  {
    return (message >= other.message);
  }
  bool operator<=(const PyString &other) const
  {
    return (message <= other.message);
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

  const char *begin() const
  {
    return message.data();
  }

  // Iterator for range-based for loops (end)
  const char *end() const
  {
    return message.data() + message.size();
  }
  // len
  int len()
  {
    return message.length();
  }

  // capitalize
  std::string capitalize()
  {
    if (!message.empty() && std::isalpha(static_cast<unsigned char>(message[0])))
    {
      message[0] = std::toupper(static_cast<unsigned char>(message[0]));
    }
    return message;
  }

  std::string upper()
  {
    std::string temp;
    if (!message.empty())
    {
      for (unsigned char c : message)
      {
        temp += std::toupper(c);
      }
    }
    return temp;
  }

  std::string lower()
  {
    std::string temp;
    if (!message.empty())
    {
      for (unsigned char c : message)
      {
        temp += std::tolower(c);
      }
    }
    return temp;
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

  void pop(size_t index)
  {
    if (index < message.size())
    {
      message.erase(index, 1);
    }
    else
    {
      std::cerr << "Index out of range." << std::endl;
    }
  }

  void pop()
  {
    if (!message.empty())
    {
      message.erase(message.end() - 1);
    }
  }

  // find
  int find(const std::string &substring)
  {
    size_t index = message.find(substring);
    if (index == std::string::npos)
    {
      throw std::out_of_range("Substring not found");
    }
    return static_cast<int>(index);
  }

  // isalpha
  bool isalpha() const
  {
    for (char c : message)
    {
      if (!std::isalpha(static_cast<unsigned char>(c)))
      {
        return false;
      }
    }
    return true;
  }
  // isascii()
  bool isAscii() const
  {
    for (char c : message)
    {
      if (static_cast<unsigned char>(c) > 127)
      { // ASCII values range from 0 to 127
        return false;
      }
    }
    return true;
  }

  // isdigit()
  bool isdigit() const
  {
    for (char c : message)
    {
      if (!std::isdigit(static_cast<unsigned char>(c)))
      {
        return false;
      }
    }
    return true;
  }

  bool isdecimal() const
  {
    for (char c : message)
    {
      if (!std::isdigit(static_cast<unsigned char>(c)) || c < '0' || c > '9')
      {
        return false;
      }
    }
    return true;
  }

  // islower()
  bool islower() const
  {
    for (char c : message)
    {
      if (!std::islower(static_cast<unsigned char>(c)))
      {
        return false;
      }
    }
    return true;
  }

  // isupper()
  bool isupper() const
  {
    for (char c : message)
    {
      if (!std::isupper(static_cast<unsigned char>(c)))
      {
        return false;
      }
    }
    return true;
  }

  // isnumeric()
  bool isnumeric() const
  {
    for (char c : message)
    {
      if (!(std::isdigit(static_cast<unsigned char>(c)) || std::isalnum(static_cast<unsigned char>(c))))
      {
        return false;
      }
    }
    return true;
  }

  // isalnum
  bool isalnum() const
  {
    for (char c : message)
    {
      if (!std::isalnum(static_cast<unsigned char>(c)))
      {
        return false;
      }
    }
    return true;
  }

  bool isFloat()
  {
    bool decimalPointSeen = false;
    bool hasDigit = false;

    for (char c : message)
    {
      if (c >= '0' && c <= '9')
      {
        hasDigit = true;
      }
      else if (c == '.')
      {
        if (decimalPointSeen)
        {
          return false; // More than one decimal point
        }
        decimalPointSeen = true;
      }
      else if ((c == '+' || c == '-') && !hasDigit)
      {
        // Allow signs only before digits
      }
      else
      {
        return false; // Invalid character
      }
    }

    return hasDigit; // Must have at least one digit
  }

  void reverse()
  {
    int left = 0;
    int right = message.length() - 1;

    while (left < right)
    {
      std::swap(message[left], message[right]);
      left++;
      right--;
    }
  }

  std::string get_string()
  {
    return message;
  }

  std::string sort()
  {
    std::sort(message.begin(), message.end());
    std::string temp = message;
    return temp;
  }
};

int len(PyString a)
{
  return a.get_string().length();
}

std::string sorted(PyString a)
{
  std::string b = a.get_string();
  std::sort(b.begin(), b.end());
  std::string temp = b;
  return temp;
}

int Int(PyString a)
{
  if (a.isdecimal())
  {
    return std::stoi(a.get_string());
  }
  else
  {
    throw "The string is not an integer";
  }
}

float Float(PyString a)
{

  if (a.isFloat())
  {
    return std::stof(a.get_string());
  }
  else
  {
    throw "The string is not a float";
  }
}

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
  std::cout << obj1.capitalize() << std::endl;
  std::cout << obj1.count("Hello") << std::endl;
  std::cout << obj1.find("af!") << std::endl;
  return 0;
}
