#ifndef PYSTRING_H
#define PYSTRING_H

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>

class PyString
{
private:
  std::string message;

public:
  PyString(const char *message);
  PyString(char character);
  void display();
  PyString operator+(const PyString &other) const;
  bool operator==(const PyString &other) const;
  std::string operator()() const;
  bool operator>(const PyString &other) const;
  bool operator<(const PyString &other) const;
  bool operator<=(const PyString &other) const;
  bool operator>=(const PyString &other) const;
  PyString &operator+=(const PyString &other);
  char operator[](size_t index) const;
  char &operator[](size_t index);
  std::string operator[](const std::string &slice);
  const char *begin() const;
  const char *end() const;
  int len();
  std::string capitalize();
  std::string upper();
  std::string lower();
  int count(const std::string &substring);
  void pop(size_t index);
  void pop();
  int find(const std::string &substring);
  bool isalpha() const;
  bool isAscii() const;
  bool isdigit() const;
  bool isdecimal() const;
  bool islower() const;
  bool isnumeric() const;
  bool isalnum() const;
  bool isFloat();
  void reverse();
  bool isupper() const;
  std::string get_string();
  std::string sort();
  std::string replace(const std::string &old_substr, const std::string &new_substr);
  std::vector<std::string> split(const std::string &delimiter = " ");
  std::string title();
  std::string strip();
  void append(const PyString &other);
};
int len(PyString a);
std::string sorted(PyString a);
float Float(PyString a);
int Int(PyString a);

namespace Ps
{
  class string : public PyString
  {
  public:
    string(const char *message) : PyString(message)
    {
    }
  };
}
#endif