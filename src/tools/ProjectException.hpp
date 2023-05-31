/*
** PROJECT, 2023
** BY Gérard TOUDOGUIN
** File description:
** ProjectException
*/

#ifndef PROJECTEXCEPTION_HPP_
#define PROJECTEXCEPTION_HPP_

#include <exception>
#include <string>

#define WHERE ("exception at : \n\t" + std::string(__FILE__) + " l:" + std::to_string(__LINE__))

namespace project {
    class ProjectException : public std::exception {
        public:
            ProjectException(const std::string &what): _what(what) {};
            ~ProjectException() override = default;

            /**
             * @brief Get the exception
             * 
             * @return ** const char* 
             */
            const char *what() const noexcept override {
                return _what.c_str();
            }
        private:
            std::string _what;
    };
};

#endif /* !PROJECTEXCEPTION_HPP_ */
