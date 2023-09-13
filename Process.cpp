/*
    Author: William Denny
    Creation Date: 05/05/2022
    Last Update: 05/09/2022
    Description: Implementation file for the Process class
*/
#include <iostream>
#include <math.h>
#include "Process.h"
#include "PriorityQueue.h"

using namespace std;

/*
    Description: Constructor takes in two parameters
    Parameters: int time, int stamp
    Return: None
*/
Process::Process(int time, int stamp)
{
    exeTime = time;
    timeStamp = stamp;
}
/*
    Description: Copy Constructor takes in one reference to a process object
    Parameters: const Process &
    Return: None
*/
Process::Process(const Process &obj)
{
    exeTime = obj.exeTime;
    timeStamp = obj.timeStamp;
}
/*
    Description: Mutator sets the execution time
    Parameters: int time
    Return: None
*/
void Process::setExeTime(int time)
{
    if (time < 1)
        exeTime = 1;
    else
        exeTime = time;
}
/*
    Description: Accessor gets the execution time
    Parameters: None
    Return: int
*/
int Process::getExeTime()
{
    return exeTime;
}
/*
    Description: Mutator sets the time stamp
    Parameters: int stamp
    Return: None
*/
void Process::setTimeStamp(int stamp)
{
    timeStamp = stamp;
}
/*
    Description: Accessor gets the time stamp
    Parameters: None
    Return: int
*/
int Process::getTimeStamp()
{
    return timeStamp;
}
/*
    Description: Overloaded = operator
    Parameters: const Process &
    Return: const Process
*/
const Process Process::operator=(const Process &right)
{
    exeTime = right.exeTime;
    timeStamp = right.timeStamp;
    // might have to change priority aswell

    return *this;
}
/*
    Description: Overloaded outstream
    Parameters: ostream &, const PRocess &
    Return: ostream&
*/
ostream& operator <<(ostream &strm, const Process &obj)
{
    strm << "[" << obj.exeTime << ", " << obj.timeStamp << "]";

    return strm;
}

