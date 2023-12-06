#ifndef STUDENT_H
#define STUDENT_H

using namespace std;

class Student {
	public:
  		Student();
  		~Student(); 
  		char* getName();
	private:
  		char Name[20];
};
#endif
