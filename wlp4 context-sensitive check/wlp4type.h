#ifndef WLP4TYPE_H
#define WLP4TYPE_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <memory>

extern const std::string EMPTY;
extern const std::string ptrType;
extern const std::string intType;

// struct and class definitions
struct TreeNode
{
  std::string value;
  std::string type;
  std::vector<std::shared_ptr<TreeNode>> children;
  std::shared_ptr<TreeNode> parent;
  bool searched = false;

  TreeNode(const std::string &val, const std::string type);

  void addChild(std::shared_ptr<TreeNode> child);
};

class Procedure
{ 
  std::string name;
  std::vector<std::string> signature; 
  std::map<std::string, std::string> table;

  std::vector<std::string> signatureVars;
  int argSize;

  void setSignature(std::shared_ptr<TreeNode> node);
  int countParams(std::shared_ptr<TreeNode> root);

public:
  Procedure(std::string name, std::vector<std::string> signature, std::map<std::string, std::string> table);

  void insert(std::string var, std::string type);
  bool inTable(std::string var);
  std::string getType(std::string name);
  void initProcedure(std::shared_ptr<TreeNode> root);
  int getArgSize();
  void checkArglist(Procedure procedureScope, std::shared_ptr<TreeNode> args);
  void setName(std::string name);
  std::string getName();
  void printTable();
};

std::vector<std::string> getArgTypes(Procedure procedure, std::shared_ptr<TreeNode> node);
void treeTraversal(Procedure procedure, std::shared_ptr<TreeNode> node);
void printTree(std::shared_ptr<TreeNode> node);
std::shared_ptr<TreeNode> searchTree(std::shared_ptr<TreeNode> node, std::string value);
std::shared_ptr<TreeNode> constructTree(std::istream &in);

std::pair<std::string, std::string> checkDcl(Procedure procedure, std::shared_ptr<TreeNode> node);
std::string checkDcls(Procedure procedure, std::shared_ptr<TreeNode> node);
std::string checkExpression(Procedure procedure, std::shared_ptr<TreeNode> node);
std::string checkFactor(Procedure procedure, std::shared_ptr<TreeNode> node);
std::pair<std::string, std::string> checkID(Procedure procedure, std::shared_ptr<TreeNode> node);
std::string checkLvalue(Procedure procedure, std::shared_ptr<TreeNode> node);
std::string checkTerm(Procedure procedure, std::shared_ptr<TreeNode> node);
std::string checkStatement(Procedure procedure, std::shared_ptr<TreeNode> node);
std::string checkStatements(Procedure procedure, std::shared_ptr<TreeNode> node);
std::string checkTest(Procedure procedure, std::shared_ptr<TreeNode> node);
bool checkProcedure(Procedure procedure, std::shared_ptr<TreeNode> root);
bool checkWain(Procedure procedure, std::shared_ptr<TreeNode> root);

#endif // WLP4TYPE_H