//
// vm.cpp for pop in /home/faisan_f/Desktop/project/cpp_abstractvm
// 
// Made by florian faisant
// Login   <faisan_f@epitech.net>
// 
// Started on  Tue Feb 25 21:42:34 2014 florian faisant
// Last update Wed Feb 26 10:23:29 2014 florian faisant
//

#include <iostream>
#include <sstream>
#include <cstdio>
#include "avm/parser/iparser.hpp"
#include "avm/common/exception.hpp"
#include "avm/common/ioperand.hpp"
#include "avm/vm/vm.hpp"

avm::vm::VM::~VM()
{
    while (!m_stack.empty())
    {
        common::IOperand *top = m_stack.top();
        m_stack.pop();

        delete top;
    }
}

void avm::vm::VM::push(parser::IParser *parser, avm::common::IOperand *value)
{
    m_stack.push(value);
}

void avm::vm::VM::pop(parser::IParser *parser)
{
    if (m_stack.empty())
    {
        throw avm::common::AVMSourceException(parser->get_error_line(), "Stack vide.");
    }
    m_stack.pop();
}

void avm::vm::VM::dump(parser::IParser *parser)
{
    std::stack<common::IOperand *> stack(m_stack);

    while (!stack.empty())
    {
        common::IOperand *top = stack.top();
        stack.pop();

        std::cout << top->toString() << std::endl;
    }
}

void avm::vm::VM::assert(parser::IParser *parser, common::IOperand *value)
{
    if (m_stack.empty())
    {
        throw avm::common::AVMSourceException(parser->get_error_line(), "Stack vide.");
    }
    common::IOperand *top = m_stack.top();

    if (top->toString() != value->toString())
    {
        throw avm::common::AVMSourceException(parser->get_error_line(), "Assert fail avec " + top->toString());
    }
}

void avm::vm::VM::add(parser::IParser *parser)
{
    if (m_stack.size() < 2)
    {
        throw avm::common::AVMSourceException(parser->get_error_line(), "Stack pas assez grande.");
    }

    common::IOperand *a, *b;
    a = m_stack.top();
    m_stack.pop();
    b = m_stack.top();
    m_stack.pop();

    try
    {
        common::IOperand *result = (*a) + (*b);
        m_stack.push(result);
    }
    catch (avm::common::AVMException &e)
    {
        throw avm::common::AVMSourceException(parser->get_error_line(), e.what());
    }
}

void avm::vm::VM::sub(parser::IParser *parser)
{
    if (m_stack.size() < 2)
    {
        throw avm::common::AVMSourceException(parser->get_error_line(), "Stack pas assez grande.");
    }

    common::IOperand *a, *b;
    a = m_stack.top();
    m_stack.pop();
    b = m_stack.top();
    m_stack.pop();

    try
    {
        common::IOperand *result = (*a) - (*b);
        m_stack.push(result);
    }
    catch (avm::common::AVMException &e)
    {
        throw avm::common::AVMSourceException(parser->get_error_line(), e.what());
    }
}

void avm::vm::VM::mul(parser::IParser *parser)
{
    if (m_stack.size() < 2)
    {
        throw avm::common::AVMSourceException(parser->get_error_line(), "Stack pas assez grande.");
    }

    common::IOperand *a, *b;
    a = m_stack.top();
    m_stack.pop();
    b = m_stack.top();
    m_stack.pop();

    try
    {
        common::IOperand *result = (*a) * (*b);
        m_stack.push(result);
    }
    catch (avm::common::AVMException &e)
    {
        throw avm::common::AVMSourceException(parser->get_error_line(), e.what());
    }
}

void avm::vm::VM::div(parser::IParser *parser)
{
    if (m_stack.size() < 2)
    {
        throw avm::common::AVMSourceException(parser->get_error_line(), "Stack pas assez grande.");
    }

    common::IOperand *a, *b;
    a = m_stack.top();
    m_stack.pop();
    b = m_stack.top();
    m_stack.pop();

    try
    {
        common::IOperand *result = (*a) / (*b);
        m_stack.push(result);
    }
    catch (avm::common::AVMException &e)
    {
        throw avm::common::AVMSourceException(parser->get_error_line(), e.what());
    }
}

void avm::vm::VM::mod(parser::IParser *parser)
{
    if (m_stack.size() < 2)
    {
        throw avm::common::AVMSourceException(parser->get_error_line(), "Stack pas assez grande.");
    }

    common::IOperand *a, *b;
    a = m_stack.top();
    m_stack.pop();
    b = m_stack.top();
    m_stack.pop();

    try
    {
        common::IOperand *result = (*a) % (*b);
        m_stack.push(result);
    }
    catch (avm::common::AVMException &e)
    {
        throw avm::common::AVMSourceException(parser->get_error_line(), e.what());
    }
}

void avm::vm::VM::print(parser::IParser *parser)
{
    if (m_stack.empty())
    {
        throw avm::common::AVMSourceException(parser->get_error_line(), "Stack vide.");
    }
    common::IOperand *top = m_stack.top();
    if (top->getType() != common::IOperand::Int8)
    {
        throw avm::common::AVMSourceException(parser->get_error_line(), "Mauvais type pour print.");
    }
    int value;
    std::stringstream instream(top->toString());
    instream >> value;

    std::cout << (char)value;
}

void avm::vm::VM::exit(parser::IParser *parser)
{
    if (!m_stack.empty())
    {
        std::cerr << "Warning: La stack n'est pas vide." << std::endl;
    }
}
