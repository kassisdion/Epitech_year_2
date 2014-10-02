//
// ioperand.hpp for ioperand.hpp in /home/faisan_f/Desktop/project/cpp_abstractvm
// 
// Made by florian faisant
// Login   <faisan_f@epitech.net>
// 
// Started on  Tue Feb 25 20:59:19 2014 florian faisant
// Last update Tue Feb 25 20:59:20 2014 florian faisant
//

#ifndef AVM_COMMON_IOPERAND_H_
#define AVM_COMMON_IOPERAND_H_

#include <string>

namespace avm
{
    namespace common
    {
        class IOperand
        {
        public:
            enum eOperandType
            {
                Int8 = 0,
                Int16 = 1,
                Int32 = 2,
                Float = 3,
                Double = 4,
            };

        public:
            virtual inline ~IOperand() {}

        public:
            virtual const std::string &toString() const = 0;

            virtual int getPrecision() const = 0;
            virtual eOperandType getType() const = 0;

            virtual IOperand *operator+(const IOperand &rhs) const = 0;
            virtual IOperand *operator-(const IOperand &rhs) const = 0;
            virtual IOperand *operator*(const IOperand &rhs) const = 0;
            virtual IOperand *operator/(const IOperand &rhs) const = 0;
            virtual IOperand *operator%(const IOperand &rhs) const = 0;
        };
    }
}

#endif /* AVM_COMMON_IOPERAND_H_ */
