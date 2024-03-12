#include "TaskFileDecorator.h"
#include <fstream>
#include <iostream>

TaskFileDecorator::TaskFileDecorator(LinkedList* list) : linkedList(list) {}

TaskFileDecorator::~TaskFileDecorator() 
{
    delete linkedList; // Ownership of LinkedList is transferred to TaskFileDecorator
}

bool TaskFileDecorator::writeToFile(const std::string& filename) 
{
    std::ofstream file(filename);
    if (!file.is_open()) 
    {
        std::cerr << "Error: Unable to open file for writing\n";
        return false;
    }
    
    TaskNode* current = linkedList->getHead();
    while (current != nullptr) 
    {
        file << current->getTaskID() << "," << current->getTaskName() << "," << current->getDescription() << "," << current->getStartDate() << "," << current->getEndDate() << "," << current->getPriority() << "," << current->getStatus() << "," << current->getAssignedUser() << "\n";
        current = current->getNext();
    }

    file.close();
    return true;
}

bool TaskFileDecorator::readFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file for reading\n";
        return false;
    }

    linkedList->clear();

    std::string line;

    while (std::getline(file, line)) {
        // Parse task data from each line
        std::string taskIDStr, taskName, description, startDate, endDate, priority, status, assignee;

        std::stringstream ss(line);

        // Read each field directly from the stringstream
        std::getline(ss, taskIDStr, ',');
        std::getline(ss, taskName, ',');
        std::getline(ss, description, ',');
        std::getline(ss, startDate, ',');
        std::getline(ss, endDate, ',');
        std::getline(ss, priority, ',');
        std::getline(ss, status, ',');
        std::getline(ss, assignee, ',');
        

        // Convert taskIDStr to integer
        int taskID = std::stoi(taskIDStr);

        // Add the parsed task to the linked list
        linkedList->addTask(taskName, description, startDate, endDate, priority, status, assignee);
    }

    file.close();
    return true;
}