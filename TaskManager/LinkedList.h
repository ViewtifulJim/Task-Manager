#pragma once
#include "TaskNode.h"
#include <string>
using std::string;

// This class represents a doubly linked list of tasks
// Each task is represented by a TaskNode

class LinkedList
{
private:
	TaskNode* head;
	TaskNode* tail;
	int size;
public:
	LinkedList();
	~LinkedList();

	// General methods
	int getSize() const;
	bool isEmpty() const;

	// TaskNode methods
	void addTask(string taskName, string description, string startDate, string endDate, string priority, string status, string assignee);
	void editTask(int taskID, string taskName, string description, string startDate, string endDate, string priority, string status, string assignee);
	void removeTask(int taskID);
	void printTaskList();
	void printTaskListReverse();
	bool taskExists(int taskID);

	TaskNode* getHead() const; // for accessing the head in the decorator class
	void clear(); // for clearing the list in the decorator class

};