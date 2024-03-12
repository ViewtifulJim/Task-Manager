#include "UserObserver.h"
#include "User.h"
#include "Windows.h"
#include <fstream>
#include <ctime>

UserObserver::UserObserver(const User& user) : user(user) {}

void UserObserver::update()
{
    // Get current time
    std::time_t currentTime;
    std::time(&currentTime);

    std::tm localTime;
    localtime_s(&localTime, &currentTime);

    char timestamp[20];
    std::strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", &localTime);

    std::cout << "New user added to log.txt: " << user.getUsername() << std::endl;
    std::ofstream logFile("log.txt", std::ios::app); // Open file in append mode
    if (logFile.is_open())
    {
        logFile << timestamp << " - New user created: " << user.getUsername() << std::endl;
        logFile.close();
    }
    else 
    {
        std::cerr << "Error: Unable to open log file for appending." << std::endl;
    }
}