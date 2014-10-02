//
// operand_factory.hpp for operand_factory in /home/faisan_f/Bureau/project/cpp_abstractvm
// 
// Made by florian faisant
// Login   <faisan_f@epitech.net>
// 
// Started on  Thu Feb 27 17:36:02 2014 florian faisant
// Last update Thu Feb 27 17:36:03 2014 florian faisant
//

#ifndef OPERAND_FACTORY_H_
#define OPERAND_FACTORY_H_

#include <string>
#include "avm/common/ioperand.hpp"

namespace avm
{
    namespace common
    {
        class OperandFactory
        {
        public:
            static IOperand *createOperand(IOperand::eOperandType type, const std::string &value);

        private:
            static IOperand *createInt8(const std::string &value);
            static IOperand *createInt16(const std::string &value);
            static IOperand *createInt32(const std::string &value);
            static IOperand *createFloat(const std::string &value);
            static IOperand *createDouble(const std::string &value);
        };
    }
}

#endif /* OPERAND_FACTORY_H_ */
