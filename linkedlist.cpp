//Firaol code thingy pt1
//linked list cpp file
//12/1/23
#include <iostream>
#include <cstring>
#include <iomanip>
#include <stdio.h>

#include "student.h"
#include "node.h"

using namespace std;

int main() {
	
	//student Class		char input[20];
	


	Student* student1 = new Student;

	cout << "First Student Name? " << endl;
		cin.get(student1 -> getName(), 20);
			cin.get();
		Student* student2 = new Student;
	cout << "Second Student Name? " << endl;
	cin.get(student2 -> getName(), 20);
	cin.get();

	cout << "Student 1 Name is: " << student1 -> getName() << endl;
	cout << "Student 2 Name is: " << student2 -> getName() << endl;

		
	//Nodes
	Node* node1 = new Node(student1);
	Node* node2 = new Node(student2);
	node1 -> setStudent(student1);
	node1 -> setNext(node2);
	node2 -> setStudent(student2);

	cout << "First Node: " << node1 -> getStudent() -> getName() << endl;
	cout << "Second Node: " << node1 -> getNext() -> getStudent() -> getName() << endl;	
	return 0;

}
