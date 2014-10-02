#ifndef AVM_VM_VM_H_
#define AVM_VM_VM_H_

#include <stack>
#include "avm/vm/ivm.hpp"
#include "avm/common/ioperand.hpp"

namespace avm
{
    namespace vm
    {
        class VM: public IVM
        {
        public:
            virtual ~VM();

        public:
            virtual void push(parser::IParser *parser, common::IOperand *value);
            virtual void pop(parser::IParser *parser);
            virtual void dump(parser::IParser *parser);
            virtual void assert(parser::IParser *parser, common::IOperand *value);
            virtual void add(parser::IParser *parser);
            virtual void sub(parser::IParser *parser);
            virtual void mul(parser::IParser *parser);
            virtual void div(parser::IParser *parser);
            virtual void mod(parser::IParser *parser);
            virtual void print(parser::IParser *parser);
            virtual void exit(parser::IParser *parser);

        private:
            std::stack<common::IOperand *> m_stack;
        };
    }
}

#endif /* AVM_VM_VM_H_ */
