#ifndef _ERROR_HPP_
#define _ERROR_HPP_

#include <string>
#include <exception>
#include <map>

namespace error_handling
{
    enum ErrorType
    {
        LogicError,
        RunTimeError,
        IOError,
        UnKnownError
    };

    enum ErrorAction
    {
        Ignore,
        Retry,
        Abort,
        Log
    };

    struct ErrorDetails
    {
        ErrorType type;
        ErrorAction action;
        std::string message;
    };

    class ErrorManager : public std::exception
    {
        std::string message;

    public:
        ErrorManager(long long errorId)
        {
            ErrorDetails ed = errorMap[errorId];
            message = ed.message;
        }

        std::map<long long, ErrorDetails> errorMap = {
            {000001, {ErrorType::UnKnownError, ErrorAction::Abort, "Something Went Wrong"}},
            {000002, {ErrorType::IOError, ErrorAction::Abort, "Cannot Open CSV File"}},
            {000003, {ErrorType::LogicError, ErrorAction::Abort, "Cannot Initialize CURL"}},
            {000004, {ErrorType::LogicError, ErrorAction::Abort, "Cannot Fetch the Data from Site"}},
            {000005, {ErrorType::LogicError, ErrorAction::Abort, "Cannot Open Fetch File Stream"}}
        };

        const char *what() const noexcept override
        {
            return message.c_str();
        }
    };
}

#endif