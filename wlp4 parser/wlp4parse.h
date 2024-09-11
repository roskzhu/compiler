#ifndef WLP4_PARSER_H
#define WLP4_PARSER_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <memory>

extern const std::string WLP4_COMBINED;

const std::string CFG = ".CFG";
const std::string END = ".END";
const std::string EMPTY = ".EMPTY";
const std::string INPUT = ".INPUT";
const std::string TRANSITIONS = ".TRANSITIONS";
const std::string REDUCTIONS = ".REDUCTIONS";
const std::string ACCEPT = ".ACCEPT";

struct Token
{
  std::string kind;
  std::string lexeme;
};

struct Rule
{
  std::string lhs;
  std::vector<std::string> rhs;
};

struct Transition
{
  int fromState;
  std::string onSymbol;
  int toState;
};

struct Reduction
{
  int state;
  int ruleIndex;
  std::string reductionSymbol;
};

struct TreeNode
{
  std::string value;
  std::string lexeme = "";
  std::vector<std::shared_ptr<TreeNode>> children{nullptr};
  TreeNode(const std::string &val, const std::string lex = "") : value(val), lexeme(lex) {}
  void addChild(std::shared_ptr<TreeNode> child);
};

void shift(std::vector<Token> &inputSeq, std::vector<std::string> &reductionSeq);

void reduce(std::vector<std::string> &reductionSeq, const Rule &rule);

void printProgress(const std::vector<std::string> &reductionSeq, const std::vector<Token> &inputSeq);

bool parseWLP4(std::vector<Rule> &cfgRules, std::vector<std::string> &reductionSeq,
               std::map<std::pair<int, std::string>, int> &transitions, std::vector<Reduction> &reductions);

void printTree(std::shared_ptr<TreeNode> node);

#endif // WLP4_PARSER_H
