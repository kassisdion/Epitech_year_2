#include <stdlib.h>
#include "avm/common/ioperand.hpp"
#include "avm/common/operand.hpp"
#include "avm/common/operand_factory.hpp"

using namespace avm::common;

IOperand *OperandFactory::createOperand(IOperand::eOperandType type, const std::string &value)
{
    IOperand *op = NULL;

    switch (type)
    {
        case IOperand::Int8:
            op = createInt8(value);
            break;
        case IOperand::Int16:
            op = createInt16(value);
            break;
        case IOperand::Int32:
            op = createInt32(value);
            break;
        case IOperand::Float:
            op = createFloat(value);
            break;
        case IOperand::Double:
            op = createDouble(value);
            break;
    }

    return op;
}

IOperand *OperandFactory::createInt8(const std::string &value)
{
    return new Int8(value);
}

IOperand *OperandFactory::createInt16(const std::string &value)
{
    return new Int16(value);
}

IOperand *OperandFactory::createInt32(const std::string &value)
{
    return new Int32(value);
}

IOperand *OperandFactory::createFloat(const std::string &value)
{
    return new Float(value);
}

IOperand *OperandFactory::createDouble(const std::string &value)
{
    return new Double(value);
}
