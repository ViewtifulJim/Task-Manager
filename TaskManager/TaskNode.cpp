#include "TaskNode.h"

int TaskNode::lastAssignedID = 0;

TaskNode::TaskNode(string taskName, string description, string priority, string startDate, string endDate, string status, string assignee)
{
	lastAssignedID++;
	taskID = lastAssignedID;

	this->taskName = taskName;
	this->description = description;
	this->priority = priority;
	this->startDate = startDate;
	this->endDate = endDate;
	this->status = status;
	this->assignedUser = assignee;
	this->next = nullptr;
	this->prev = nullptr;
}

TaskNode::TaskNode()
{
	taskID = 0;
	taskName = "";
	description = "";
	startDate = "";
	endDate = "";
	priority = "";
	status = "";
	assignedUser = "";
	next = nullptr;
	prev = nullptr;
}

TaskNode::~TaskNode()
{



}

int TaskNode::getTaskID() const
{
	return taskID;
}

string TaskNode::getTaskName() const
{
	return taskName;
}

string TaskNode::getDescription() const
{
	return description;
}

string TaskNode::getStartDate() const
{
	return startDate;
}

string TaskNode::getEndDate() const
{
	return endDate;
}

string TaskNode::getPriority() const
{
	return priority;
}

string TaskNode::getStatus() const
{
	return status;
}

string TaskNode::getAssignedUser() const
{
	return assignedUser;
}

TaskNode* TaskNode::getNext() const
{
	return next;
}




