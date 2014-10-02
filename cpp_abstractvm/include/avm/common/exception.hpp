//
// exeption.hpp for expetion in /home/faisan_f/Bureau/project/cpp_abstractvm
// 
// Made by florian faisant
// Login   <faisan_f@epitech.net>
// 
// Started on  Tue Feb 25 20:56:22 2014 florian faisant
// Last update Tue Feb 25 21:00:05 2014 florian faisant
//

#ifndef		__AVM_COMMON_EXCEPTION_HPP__
# define	__AVM_COMMON_EXCEPTION_HPP__

#include <string>
#include <stdexcept>

namespace avm
{
    namespace common
    {
        class AVMException: public std::runtime_error
        {
        public:
            inline AVMException(const std::string &msg)
                : std::runtime_error(msg)
            {
            }
        };

        class AVMSourceException: public AVMException
        {
        public:
            inline AVMSourceException(int line, const std::string &msg)
                 : AVMException(build_message(line, msg))
            {
            }

        private:
            std::string build_message(int line, const std::string &msg);
        };
    }
}

#endif
