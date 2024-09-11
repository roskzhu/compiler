#ifndef WLP4SCAN_H
#define WLP4SCAN_H

#include <iostream>
#include <sstream>
#include <string>
#include <limits>
#include <vector>
#include <cstring>

bool isNumericChar(char c);

bool isOutOfRange(const std::string &numStr);

const std::string transition(const std::string &s);

std::string checkType(char c);

class ScanningError : public std::exception
{
private:
  std::string message;

public:
  ScanningError(std::string message);
  const char *what() const noexcept override;
};

#endif // WLP4SCAN_H
