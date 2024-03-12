#pragma once
#include "LinkedList.h"
#include "TaskNode.h"
#include <string>
#include <fstream>
#include <sstream>


class TaskFileComponent 
{
public:
    virtual bool writeToFile(const std::string& filename) = 0;
    virtual bool readFromFile(const std::string& filename) = 0;
};


class TaskFileDecorator : public TaskFileComponent
{
private:
    LinkedList* linkedList;
public:
    TaskFileDecorator(LinkedList* list);
    ~TaskFileDecorator();

    bool writeToFile(const std::string& filename) override;
    bool readFromFile(const std::string& filename) override;
};
