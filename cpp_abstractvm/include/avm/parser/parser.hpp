//
// parser.hpp for parser in /home/faisan_f/Desktop/project/cpp_abstractvm
// 
// Made by florian faisant
// Login   <faisan_f@epitech.net>
// 
// Started on  Tue Feb 25 16:13:44 2014 florian faisant
// Last update Thu Feb 27 19:12:23 2014 florian faisant
//

#ifndef AVM_PARSER_PARSER_H_
#define AVM_PARSER_PARSER_H_

#include <istream>
#include <map>
#include <vector>
#include "avm/vm/ivm.hpp"
#include "avm/parser/iparser.hpp"
#include "avm/common/ioperand.hpp"

namespace avm
{
  namespace parser
  {
    class Parser: public IParser
    {
    public:
      Parser();
      void parse(vm::IVM &vm, std::istream &input);
      int get_error_line();
    private:
      bool check_line(const std::vector<std::string> &line);
      common::IOperand *get_operand(const std::vector<std::string> &line);
      void parse_file(std::istream &input);
      void parse_cin(std::istream &input);
    private:
      bool push(const std::vector<std::string> &line);
      bool pop(const std::vector<std::string> &line);
      bool dump(const std::vector<std::string> &line);
      bool add(const std::vector<std::string> &line);
      bool assert(const std::vector<std::string> &line);
      bool sub(const std::vector<std::string> &line);
      bool mul(const std::vector<std::string> &line);
      bool div(const std::vector<std::string> &line);
      bool mod(const std::vector<std::string> &line);
      bool print(const std::vector<std::string> &line);
      bool exit(const std::vector<std::string> &line);
      bool comm(const std::vector<std::string> &line);
    private:
      int error_line;
      std::map<std::string, bool (avm::parser::Parser::*)(const std::vector<std::string> &line)> func_tab;
      std::map<std::string, common::IOperand::eOperandType> types_tab;
      vm::IVM *vm;
    };
  }
}

#endif /* AVM_PARSER_PARSER_H_ */
