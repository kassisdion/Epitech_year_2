#ifndef AVM_VM_IVM_H_
#define AVM_VM_IVM_H_

#include "avm/common/ioperand.hpp"

namespace avm
{
    namespace parser
    {
        class IParser;
    }

    namespace vm
    {
        class IVM
        {
        public:
            virtual void push(parser::IParser *parser, common::IOperand *value) = 0;
            virtual void pop(parser::IParser *parser) = 0;
            virtual void dump(parser::IParser *parser) = 0;
            virtual void assert(parser::IParser *parser, common::IOperand *value) = 0;
            virtual void add(parser::IParser *parser) = 0;
            virtual void sub(parser::IParser *parser) = 0;
            virtual void mul(parser::IParser *parser) = 0;
            virtual void div(parser::IParser *parser) = 0;
            virtual void mod(parser::IParser *parser) = 0;
            virtual void print(parser::IParser *parser) = 0;
            virtual void exit(parser::IParser *parser) = 0;
        };
    }
}

#endif /* AVM_VM_IVM_H_ */
