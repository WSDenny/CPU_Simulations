#ifndef PROCESS_H
#define PROCESS_H

#include <iostream>
#include <math.h>

/*
    Author: Don Spickler
    Creation Date: 10/25/2018
    Last Update: 10/26/2018
    Description: Header file for the Complex class, An example of operator overloading.
*/
using namespace std;

class Process
{
  private:
    int exeTime; // Execution time of the process.
    int timeStamp; // Time stamp of the process creation.

  public:
// Constructors and Destructor
    Process(int time = 1, int stamp = 0);
    Process(const Process &obj);
//~Process();

// Acessors and Mutators
    void setExeTime(int);
    int getExeTime();
    void setTimeStamp(int);
    int getTimeStamp();

// Overloaded operator functions
    const Process operator=(const Process &right);
    friend ostream &operator << (ostream &, const Process &);
};
#endif
