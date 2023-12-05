#ifndef NODE_H
#define NODE_H

#include <iostream>
#include "student.h"

class Node {
public:
  	Node(Student*);
  	~Node(); 
  
  	void setStudent(Student*);
  	void setNext(Node*);
  
  	Student* getStudent();
  	Node* getNext();
private: 
  	Student* student;
  	Node* next;
};

// Implementation for the member functions
Node::Node(Student* s) : student(s), next(NULL) {}

Node::~Node() {
	    // Assuming proper memory management for Student objects is handled elsewhere
}

void Node::setStudent(Student* s) {
    student = s;
}

void Node::setNext(Node* n) {
				
		    next = n;
}

Student* Node::getStudent() {
    return student

