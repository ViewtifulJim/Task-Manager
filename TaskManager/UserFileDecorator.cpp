#include "UserFileDecorator.h"
#include <fstream>
#include <iostream>

UserFileDecorator::UserFileDecorator(std::vector<User*> users_vec) : users(users_vec) {}

UserFileDecorator::~UserFileDecorator() {}

bool UserFileDecorator::writeToFile(const std::string& filename)
{
    std::ofstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error: Unable to open file for writing\n";
        return false;
    }

    for (const auto& user : users)
    {
        file << user->getUsername() << "," << user->getFirstName() << "," << user->getLastName() << "\n";
    }

    file.close();
    return true;
}

bool UserFileDecorator::readFromFile(const std::string& filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error: Unable to open file for reading\n";
        return false;
    }

    users.clear(); // Clear existing users before reading from file

    std::string line;
    while (std::getline(file, line))
    {
        std::string username, firstName, lastName;
        std::stringstream ss(line);

        std::getline(ss, username, ',');
        std::getline(ss, firstName, ',');
        std::getline(ss, lastName, ',');

        users.emplace_back(username, firstName, lastName); // Add a new user to the vector
    }

    file.close();
    return true;
}