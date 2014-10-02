//
// iparser.hpp for iparser.hpp in /home/faisan_f/Desktop/project/cpp_abstractvm
// 
// Made by florian faisant
// Login   <faisan_f@epitech.net>
// 
// Started on  Tue Feb 25 16:56:44 2014 florian faisant
// Last update Tue Feb 25 21:20:27 2014 florian faisant
//

#ifndef AVM_PARSER_IPARSER_H_
#define AVM_PARSER_IPARSER_H_

#include <istream>
#include "avm/vm/ivm.hpp"

namespace avm
{
    namespace parser
    {
        class IParser
        {
        public:
	  IParser();
	  virtual void parse(vm::IVM &vm, std::istream &input) = 0;
	  virtual int get_error_line() = 0;
        };
    }
}

#endif /* AVM_PARSER_IPARSER_H_ */
