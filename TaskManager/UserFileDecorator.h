#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include "User.h"
#include <vector>


class UserFileComponent
{
public:
	virtual bool writeToFile(const std::string& filename) = 0;
	virtual bool readFromFile(const std::string& filename) = 0;
};

class UserFileDecorator : public UserFileComponent 
{
private:
    std::vector<User*> users;

public:
    UserFileDecorator(const std::vector<User*> users);
    ~UserFileDecorator();

    bool writeToFile(const std::string& filename) override;
    bool readFromFile(const std::string& filename) override;
};