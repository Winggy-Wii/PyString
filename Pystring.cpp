#include "PyString.h"

PyString::PyString(const char *message)
{
  this->message = message;
}
PyString::PyString(char character)
{
}
void PyString::display()
{
  std::cout << message << std::endl;
}

PyString PyString::operator+(const PyString &other) const
{
  return PyString((message + other.message).c_str());
}
bool PyString::operator>(const PyString &other) const
{
  return (message > other.message);
}
bool PyString::operator<(const PyString &other) const
{
  return (message < other.message);
}
bool PyString::operator==(const PyString &other) const
{
  return (message == other.message);
}
bool PyString::operator>=(const PyString &other) const
{
  return (message >= other.message);
}
bool PyString::operator<=(const PyString &other) const
{
  return (message <= other.message);
}
PyString &PyString::operator+=(const PyString &other)
{
  message = message + other.message;
  return *this;
}

// Overload [] operator for read-only access
char PyString::operator[](size_t index) const
{
  if (index >= message.length())
  {
    throw std::out_of_range("Index out of range");
  }
  return message[index];
}

// Overload [] operator for write access
char &PyString::operator[](size_t index)
{
  if (index >= message.length())
  {
    throw std::out_of_range("Index out of range");
  }
  return message[index];
}

// Overload [] operator to perform slicing
std::string PyString::operator[](const std::string &slice)
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

const char *PyString::begin() const
{
  return message.data();
}

// Iterator for range-based for loops (end)
const char *PyString::end() const
{
  return message.data() + message.size();
}
// len
int PyString::len()
{
  return message.length();
}

// capitalize
std::string PyString::capitalize()
{
  if (!message.empty() && std::isalpha(static_cast<unsigned char>(message[0])))
  {
    message[0] = std::toupper(static_cast<unsigned char>(message[0]));
  }
  return message;
}

std::string PyString::upper()
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

std::string PyString::lower()
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
int PyString::count(const std::string &substring)
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

void PyString::pop(size_t index)
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

void PyString::pop()
{
  if (!message.empty())
  {
    message.erase(message.end() - 1);
  }
}

// find
int PyString::find(const std::string &substring)
{
  size_t index = message.find(substring);
  if (index == std::string::npos)
  {
    throw std::out_of_range("Substring not found");
  }
  return static_cast<int>(index);
}

// isalpha
bool PyString::isalpha() const
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
bool PyString::isAscii() const
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
bool PyString::isdigit() const
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

bool PyString::isdecimal() const
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
bool PyString::islower() const
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
bool PyString::isupper() const
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
bool PyString::isnumeric() const
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
bool PyString::isalnum() const
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

// append
void PyString::append(const PyString &other)
{
  message += other.message;
}

// title
std::string PyString::title()
{
  std::string titled;
  bool capitalizeNext = true; // Indicates if the next character should be capitalized

  for (char c : message)
  {
    if (std::isalpha(static_cast<unsigned char>(c)))
    {
      if (capitalizeNext)
      {
        titled += std::toupper(static_cast<unsigned char>(c));
        capitalizeNext = false;
      }
      else
      {
        titled += std::tolower(static_cast<unsigned char>(c));
      }
    }
    else
    {
      titled += c;
      capitalizeNext = true;
    }
  }

  return titled;
}

// strip
void PyString::strip()
{
  auto start = std::find_if_not(message.begin(), message.end(), ::isspace);
  auto end = std::find_if_not(message.rbegin(), message.rend(), ::isspace).base();
  if (start < end)
  {
    message = std::string(start, end);
  }
  else
  {
    message.clear(); // the string is all whitespace
  }
}

// split function
std::vector<std::string> PyString::split(const std::string &delimiter)
{
  std::vector<std::string> tokens;
  std::string token;
  size_t start = 0, end;

  if (delimiter.empty())
  { // Handle edge case where delimiter is empty
    tokens.push_back(message);
    return tokens;
  }

  while ((end = message.find(delimiter, start)) != std::string::npos)
  {
    token = message.substr(start, end - start);
    if (!token.empty())
    { // Avoid adding empty strings
      tokens.push_back(token);
    }
    start = end + delimiter.length();
  }
  token = message.substr(start);
  if (!token.empty())
  {
    tokens.push_back(token);
  }
  return tokens;
}

// replace function
std::string PyString::replace(const std::string &old_substr, const std::string &new_substr)
{
  std::string result = message;
  size_t pos = 0;

  while ((pos = result.find(old_substr, pos)) != std::string::npos)
  {
    result.replace(pos, old_substr.length(), new_substr);
    pos += new_substr.length();
  }
  return result;
}

bool PyString::isFloat()
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

void PyString::reverse()
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

std::string PyString::get_string()
{
  return message;
}

std::string PyString::sort()
{
  std::sort(message.begin(), message.end());
  std::string temp = message;
  return temp;
}

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