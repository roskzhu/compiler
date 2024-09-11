#ifndef WLP4GEN_H
#define WLP4GEN_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <memory>

// global constants
extern const std::string WLP4_CFG;
extern const std::string ptrType;
extern const std::string intType;

// mips assembly operations
std::string mult(int s, int t);
std::string divide(int s, int t);
std::string mfhi(int reg);
std::string mflo(int reg);
std::string add(int dest, int s, int t);
std::string sub(int dest, int s, int t);
std::string slt(int dest, int s, int t);
std::string sltu(int dest, int s, int t);
std::string beq(int s, int t, std::string dest);
std::string bne(int s, int t, std::string dest);
std::string jalr(int reg);
std::string jr(int reg);
std::string sw(int t, int offset, int s);
std::string lw(int t, int offset, int s);
std::string generateLabel();
std::string generateComment(std::string s);
std::string updatesp();
void setFramePointer();
void push(int reg);
void pop(int reg);

// class definitions
struct TreeNode
{
  std::string value;
  std::string type;
  std::vector<std::shared_ptr<TreeNode>> children;
  std::shared_ptr<TreeNode> parent;

  TreeNode(const std::string &val, const std::string type);

  void addChild(std::shared_ptr<TreeNode> child);
};

class Procedure
{ 
  std::string name;
  int offset;
  int numParams;
  std::map<std::string, std::pair<std::string, int>> symbolTable;

public:
  Procedure(std::string name);

  void insert(std::string var, std::string type);
  bool varExist(std::string var);
  void updateOffset(int count);
  int getOffset(std::string name);
  void popRegisters();
  void countParams();
};

// helper functions
void initProcedure(std::shared_ptr<TreeNode> node);
std::pair<std::string, int> getIdInfo(std::string procedure, std::shared_ptr<TreeNode> node);
void storeRegister(std::string procedure, int reg, std::shared_ptr<TreeNode> node);
int processArgList(std::string procedure, std::shared_ptr<TreeNode> node, int count);
void call(std::string procedure, std::shared_ptr<TreeNode> arglist);
void code(std::string procedure, std::string var);
int getParamcount(std::string procedure, std::shared_ptr<TreeNode> node, int count);
std::string getNum(std::shared_ptr<TreeNode> node);

// code generation functions
void processExpression(std::string procedure, std::shared_ptr<TreeNode> node);
void processDcl(std::string procedure, std::shared_ptr<TreeNode> node, int reg, bool store);
void processDcls(std::string procedure, std::shared_ptr<TreeNode> node);
void processPrintln(std::string procedure, std::shared_ptr<TreeNode> node);
int processLvalue(std::string procedure, std::shared_ptr<TreeNode> node);
void processFactor(std::string procedure, std::shared_ptr<TreeNode> node);
int processArgList(std::string procedure, std::shared_ptr<TreeNode> node, int count);
void processTest(std::string procedure, std::shared_ptr<TreeNode> node);
void processTerm(std::string procedure, std::shared_ptr<TreeNode> node);
void processExpression(std::string procedure, std::shared_ptr<TreeNode> node);
void processStatement(std::string procedure, std::shared_ptr<TreeNode> node);
void processStatements(std::string procedure, std::shared_ptr<TreeNode> node);
void processParamlist(std::string procedure, std::shared_ptr<TreeNode> node, bool store);
void processParams(std::string procedure, std::shared_ptr<TreeNode> node, bool store);
void processWain(std::shared_ptr<TreeNode> node);
void processProcedure(std::shared_ptr<TreeNode> node);
void processProcedures(std::shared_ptr<TreeNode> node);
void prologue(std::string procedure);
void epilogue(std::string procedure);

#endif // WLP4GEN_H