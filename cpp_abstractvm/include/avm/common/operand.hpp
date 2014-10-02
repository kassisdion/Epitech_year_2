#ifndef AVM_COMMON_OPERAND_H_
#define AVM_COMMON_OPERAND_H_

#include <iostream>
#include <sstream>
#include <limits>
#include <cmath>
#include <stdint.h>
#include "avm/common/exception.hpp"
#include "avm/common/ioperand.hpp"
#include "avm/common/operand_factory.hpp"

namespace avm
{
    namespace common
    {
        template<typename T, IOperand::eOperandType OpType>
        class Operand: public IOperand
        {
        public:
            inline Operand(const std::string &value_str)
                : m_value_str(value_str)
                , m_value_min(std::numeric_limits<T>::min())
                , m_value_max(std::numeric_limits<T>::max())
            {
                std::stringstream stream(value_str);
                double mvalue;

                if (!(stream >> mvalue))
                {
                    throw avm::common::AVMException("Bad operand value: " + value_str);
                }

                m_value = static_cast<T>(mvalue);
            }

        public:
            virtual inline const std::string &toString() const
            {
                return m_value_str;
            }

            virtual inline int getPrecision() const
            {
                return static_cast<int>(OpType);
            }

            virtual inline IOperand::eOperandType getType() const
            {
                return OpType;
            }

            virtual inline IOperand *operator+(const IOperand &rhs) const
            {
                if (getType() != rhs.getType())
                {
                    IOperand *opresult;
                    if (getPrecision() > rhs.getPrecision())
                    {
                        IOperand *other = OperandFactory::createOperand(getType(), rhs.toString());
                        opresult = (*this + *other);
                        delete other;
                    }
                    else
                    {
                        IOperand *self = OperandFactory::createOperand(rhs.getType(), toString());
                        opresult = (*self + rhs);
                        delete self;
                    }
                    return opresult;
                }

                double other;
                std::stringstream instream(rhs.toString());
                instream >> other;

                if (m_value + other < m_value_min)
                {
                    throw avm::common::AVMException("Underflow error.");
                }
                if (m_value + other > m_value_max)
                {
                    throw avm::common::AVMException("Overflow error.");
                }

                double result = m_value + other;
                std::stringstream outstream;
                outstream << result;
                IOperand *opresult = OperandFactory::createOperand(getType(), outstream.str());

                return opresult;
            }

            virtual inline IOperand *operator-(const IOperand &rhs) const
            {
                if (getType() != rhs.getType())
                {
                    IOperand *opresult;
                    if (getPrecision() > rhs.getPrecision())
                    {
                        IOperand *other = OperandFactory::createOperand(getType(), rhs.toString());
                        opresult = (*this - *other);
                        delete other;
                    }
                    else
                    {
                        IOperand *self = OperandFactory::createOperand(rhs.getType(), toString());
                        opresult = (*self - rhs);
                        delete self;
                    }
                    return opresult;
                }

                double other;
                std::stringstream instream(rhs.toString());
                instream >> other;

                if (m_value - other < m_value_min)
                {
                    throw avm::common::AVMException("Underflow error.");
                }
                if (m_value - other > m_value_max)
                {
                    throw avm::common::AVMException("Overflow error.");
                }

                double result = m_value - other;
                std::stringstream outstream;
                outstream << result;
                IOperand *opresult = OperandFactory::createOperand(getType(), outstream.str());

                return opresult;
            }

            virtual inline IOperand *operator*(const IOperand &rhs) const
            {
                if (getType() != rhs.getType())
                {
                    IOperand *opresult;
                    if (getPrecision() > rhs.getPrecision())
                    {
                        IOperand *other = OperandFactory::createOperand(getType(), rhs.toString());
                        opresult = (*this * *other);
                        delete other;
                    }
                    else
                    {
                        IOperand *self = OperandFactory::createOperand(rhs.getType(), toString());
                        opresult = (*self * rhs);
                        delete self;
                    }
                    return opresult;
                }

                double other;
                std::stringstream instream(rhs.toString());
                instream >> other;

                if (m_value * other < m_value_min)
                {
                    throw avm::common::AVMException("Underflow error.");
                }
                if (m_value * other > m_value_max)
                {
                    throw avm::common::AVMException("Overflow error.");
                }

                double result = m_value * other;
                std::stringstream outstream;
                outstream << result;
                IOperand *opresult = OperandFactory::createOperand(getType(), outstream.str());

                return opresult;
            }

            virtual inline IOperand *operator/(const IOperand &rhs) const
            {
                if (getType() != rhs.getType())
                {
                    IOperand *opresult;
                    if (getPrecision() > rhs.getPrecision())
                    {
                        IOperand *other = OperandFactory::createOperand(getType(), rhs.toString());
                        opresult = (*this / *other);
                        delete other;
                    }
                    else
                    {
                        IOperand *self = OperandFactory::createOperand(rhs.getType(), toString());
                        opresult = (*self / rhs);
                        delete self;
                    }
                    return opresult;
                }

                double other;
                std::stringstream instream(rhs.toString());
                instream >> other;

                if (other == 0)
                {
                    throw avm::common::AVMException("Divide by zero.");
                }

                double result = static_cast<T>(m_value / other);
                std::stringstream outstream;
                outstream << result;
                IOperand *opresult = OperandFactory::createOperand(getType(), outstream.str());

                return opresult;
            }

            virtual inline IOperand *operator%(const IOperand &rhs) const
            {
                if (getType() != rhs.getType())
                {
                    IOperand *opresult;
                    if (getPrecision() > rhs.getPrecision())
                    {
                        IOperand *other = OperandFactory::createOperand(getType(), rhs.toString());
                        opresult = (*this % *other);
                        delete other;
                    }
                    else
                    {
                        IOperand *self = OperandFactory::createOperand(rhs.getType(), toString());
                        opresult = (*self % rhs);
                        delete self;
                    }
                    return opresult;
                }

                double other;
                std::stringstream instream(rhs.toString());
                instream >> other;

                if (other == 0)
                {
                    throw avm::common::AVMException("Modulo by zero.");
                }

                double result = fmod(m_value, other);
                std::stringstream outstream;
                outstream << result;
                IOperand *opresult = OperandFactory::createOperand(getType(), outstream.str());

                return opresult;
            }

        private:
            IOperand::eOperandType m_type;

            std::string m_value_str;
            T m_value;

            T m_value_min;
            T m_value_max;
        };

        class Int8: public Operand<int8_t, IOperand::Int8>
        {
        public:
            inline Int8(const std::string &value_str)
                : Operand(value_str)
            {}
        };

        class Int16: public Operand<int16_t, IOperand::Int16>
        {
        public:
            inline Int16(const std::string &value_str)
                : Operand(value_str)
            {}
        };

        class Int32: public Operand<int32_t, IOperand::Int32>
        {
        public:
            inline Int32(const std::string &value_str)
                : Operand(value_str)
            {}
        };

        class Double: public Operand<double, IOperand::Double>
        {
        public:
            inline Double(const std::string &value_str)
                : Operand(value_str)
            {}
        };

        class Float: public Operand<float, IOperand::Float>
        {
        public:
            inline Float(const std::string &value_str)
                : Operand(value_str)
            {}
        };
    }
}

#endif /* AVM_COMMON_OPERAND_H_ */
