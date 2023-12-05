// Header guards
#ifndef MEDIAH
#define MEDIAH

#include <iostream>
#include <cstring>

class dmedia {
public:
    dmedia();
    char* getTitle();
    int* getYear();
    virtual int getType();

private:
    char title[30];
    int year;
};

#endif

