#include <iostream>

enum class ErrorCode : int
{
    Bad_Request,
    Not_Found,
    Server_Error,
    Gateway_Time
};

void Print_Error(ErrorCode var)
{
    if (var == ErrorCode::Bad_Request)
        std::cout << "400 Bad Request" << std::endl;
    else if (var == ErrorCode::Not_Found)
        std::cout << "404 Not Found" << std::endl;
    else if (var == ErrorCode::Server_Error)
        std::cout << "500 Server Error" << std::endl;
    else if (var == ErrorCode::Gateway_Time)
        std::cout << "504 Gateway Timeout" << std::endl;
    else
        std::cout << "Unknown error code" << std::endl;
}

int main()
{
    int input;
    std::cout << "Enter an error code (0 for Bad Request, 1 for Not Found, 2 for Server Error, 3 for Gateway Timeout): ";
    std::cin >> input;

    // Convert input to ErrorCode enum
    ErrorCode error = static_cast<ErrorCode>(input);

    Print_Error(error);

    return 0;
}