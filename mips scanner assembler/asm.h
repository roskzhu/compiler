#ifndef ASSEMBLER_PARSER_H
#define ASSEMBLER_PARSER_H
#include <string>
#include <vector>
#include <set>
#include <cstdint>
#include <ostream>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstdint>
#include <limits>

#include "scanner.h"

class MIPSAssembler
{
private:
  int instr;
  std::unordered_map<std::string, int> labelsToLinenum;

  void handleWordDirective(const Token &token, int currlineNum);
  void handleAdd(const Token &d, const Token &s, const Token &t);
  void handleSub(const Token &d, const Token &s, const Token &t);
  void handleMult(const Token &s, const Token &t);
  void handleMultu(const Token &s, const Token &t);
  void handleDiv(const Token &s, const Token &t);
  void handleDivu(const Token &s, const Token &t);
  void handleMfhi(const Token &d);
  void handleMflo(const Token &d);
  void handleLis(const Token &d);
  void handleLw(const Token &t, const Token &i, const Token &s, int currlineNum);
  void handleSw(const Token &t, const Token &i, const Token &s, int currlineNum);
  void handleSlt(const Token &d, const Token &s, const Token &t);
  void handleSltu(const Token &d, const Token &s, const Token &t);
  void handleBeq(const Token &s, const Token &t, const Token &i, int currlineNum);
  void handleBne(const Token &s, const Token &t, const Token &i, int currlineNum);
  void handleJr(const Token &s, int currlineNum);
  void handleJalr(const Token &s, int currlineNum);

public:
  MIPSAssembler();

  void storeLabels(std::string line, int &lineNum, bool firstPass);
  void assemble(std::string line, int currlineNum);
  void printMemoryContent();
};

#endif // ASSEMBLER_PARSER_H