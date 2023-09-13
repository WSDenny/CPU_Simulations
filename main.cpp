/*
    Author: William Denny
    Creation Date: 05/05/2022
    Last Update: 05/09/2022
    Description: Creates a simulation of a CPU at different process loads and execution time
    User: inputs cores, max and min exe cycles, priority levels, length, number of new processes per cycle
*/
#include <iostream>
#include <vector>

#include "PriorityQueue.h"
#include "Process.h"
#include <time.h>
#include <iomanip>

using namespace std;

void println(string s = "")
{
    cout << s << endl;
}

int main()
{
    // initializing variables
    PriorityQueue<Process> queue;       // queue
    Process proc;                       // process instance
    Process temp;                       // temp process instance
    long core = 0;                      // number of cores
    long minExe = 0;                    // min exe time
    long maxExe = 0;                    // max exe time
    long maxPrior = 0;                  // max prior level
    double newProcessAmount = 0;        // used for loop
    double maxNumberOfNewProcessesPerCycle = 0;     // maximum number of processes per cycle
    double minNumberOfNewProcessesPerCycle = 0;     // minimum number of processes per cycle
    double stepSize = 0;            // amount of increase per run
    long len = 0;                   // length of sim
    srand(time(0));                 // set seed
    long exeTime = 0;               // execution time
    long timeStamp = 0;             // time stamp
    long prior = 0;                 // prior level
    long idle = 0;                  // idle amount
    long amount = 0;                // processes completed
    long wait = 0;                  // part of wait time calculation
    long totWait = 0;               // total wait time
    long remTime = 0;               // executions remaine
    long unprocWait = 0;            // unprocessed wait time
    long count = 0;                 // counter
    long exeNeeded = 0;             // executions needed for last process

    // user input
    cout << "Input the number of CPU cores: ";
    cin >> core;
    cout << "Input the minumum number of execution cycles per process: ";
    cin >> minExe;
    cout << "Input the maximum number of execution cycles per process: ";
    cin >> maxExe;
    cout << "Input the number of priority levels: ";
    cin >> maxPrior;
    cout << "Input the minimum number of new processes per cycle: ";
    cin >> minNumberOfNewProcessesPerCycle;
    cout << "Input the maximum number of new processes per cycle: ";
    cin >> maxNumberOfNewProcessesPerCycle;
    cout << "Input new processes per cycle step size: ";
    cin >> stepSize;
    cout << "Input the length of the new simulation in cycles ";
    cin >> len;

    println();

    long CPU [core];        // initialze core

    // print
    cout << setw(10) << "============   Simulation Results  ============" << endl;
    cout << setw(10) << "Load" << "\t" << setw(10) << "Idle" << "\t" << setw(10) << "Completed" << "\t" << setw(10) << "Process Wait" << "\t" << setw(10) << "Unprocessed" << "\t" << setw(10) << "Exe. Needed" << "\t" << setw(10) << "Unpr. Wait" << "\t" << setw(10) << "Unpr. Max. Wait" << endl;

    // loop to run program mulitple times
    while (minNumberOfNewProcessesPerCycle <= maxNumberOfNewProcessesPerCycle)
    {
        // resetting all variables to zero for next run
        newProcessAmount = 0;
        exeTime = 0;
        timeStamp = 0;
        prior = 0;
        idle = 0;
        amount = 0;
        wait = 0;
        totWait = 0;
        remTime = 0;
        unprocWait = 0;
        count = 0;
        exeNeeded = 0;

        for (long i = 0; i < core; i++)
            CPU[i] = 0;             // resetting CPU

        queue.clear();              // clearing queue

        for (int i = 0; i < len; i++)
        {
            // adding a process to the queue once it is >= 1
            newProcessAmount += minNumberOfNewProcessesPerCycle;
            while (newProcessAmount >= 1)
            {
                exeTime = rand() % maxExe + minExe;
                timeStamp = i;
                prior = rand() % maxPrior + 1;
                proc.setExeTime(exeTime);
                proc.setTimeStamp(timeStamp);
                queue.enqueue(proc, prior);

                newProcessAmount -= 1;
            }
            // running through each core
            for (int j = 0; j < core; j++)
            {
                // if possible to put process into CPU
                if (CPU[j] == 0 && queue.isEmpty() != true)
                {
                    temp = queue.dequeue();
                    wait = (i - temp.getTimeStamp());
                    totWait += wait;
                    CPU[j] = temp.getExeTime();
                    amount++;
                }
                // if a CPU core is ready but nothing is in it
                else if (CPU[j] == 0)
                    idle++;
            }
            // decrement each core to represent completed cycle
            for (int k = 0; k < core; k++)
            {
                if (CPU[k] > 0)
                {
                    CPU[k] = CPU[k] - 1;
                }
            }

        }
        // geting remaining exe time and unprocessed wait time
        for (int i = 0; i < queue.size(); i++)
        {
            temp = queue[i];
            remTime += temp.getExeTime();
            unprocWait += (len - temp.getTimeStamp());
        }

        // dequing to get remaining execution times
        if (queue.isEmpty() != true)
        {
            for (int i = 0; i < queue.size(); i++)
            {
                temp = queue.dequeue();
                count = temp.getExeTime();
            }
        }

        // finding executions needed
        exeNeeded = remTime - count;

        // resetting counter
        count = 0;

        // including CPU processes left as part of unprocessed
        for (int i = 0; i < core; i++)
        {
            if (CPU[i] != 0)
            {
                count++;
                remTime += CPU[i];
            }
        }

        // Printing data
        cout << setw(10) << minNumberOfNewProcessesPerCycle << "\t" << setw(10) << idle << "\t" << setw(10) << amount << "\t" << setw(10) << totWait << "\t" << setw(10) << queue.size() + count << "\t" << setw(10) << remTime << "\t" << setw(10) << unprocWait << "\t" << setw(10) << exeNeeded << endl;

        // increasing by stepsize for next run
        minNumberOfNewProcessesPerCycle += stepSize;

    }

    cout << endl;
    return 0;
}
