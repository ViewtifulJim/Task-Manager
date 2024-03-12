#pragma once
#include "Subject.h"
#include <string>
using std::string;


class TaskNode
{
private:

	static int lastAssignedID;
	int taskID;
	string taskName;
	string description;
	string startDate;
	string endDate;
	string priority;
	string status;
	string assignedUser;

	TaskNode* next;
	TaskNode* prev;

	// Allow TaskList to access private members
	friend class LinkedList;

public:
	TaskNode(string taskName, string description, string startDate, string endDate, string priority, string status, string assignee);
	TaskNode();
	~TaskNode();

	int getTaskID() const;
	string getTaskName() const;
	string getDescription() const;
	string getStartDate() const;
	string getEndDate() const;
	string getPriority() const;
	string getStatus() const;
	string getAssignedUser() const;
	TaskNode* getNext() const;

};