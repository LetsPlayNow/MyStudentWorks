#pragma once
#include <iostream>
#include <cstdlib>
#include "omp.h"
using namespace std;

int task_1a()
{
    int p = 1;
#pragma omp parallel shared(p)
    {
#pragma omp single
        {
            cout << "Single - "<< omp_get_thread_num() << endl;
            while (p)
            {
#pragma omp task
                {
                    int n = rand() % 100;
                    if (n < 50)
                    {
                        p = 0;
                        cout << "Finished" << omp_get_thread_num()
                        << endl;
                    }
                    else
                    {
                        cout << omp_get_thread_num() << endl;
                    }
                }
            }
        }
    }
}

void task_1b(){
    int p = 1;
#pragma omp parallel shared(p)
    {
#pragma omp single
        {
            cout << "Single - "<< omp_get_thread_num() << endl;
            while (p)
            {
                int n = rand() % 100;
                if (n < 50)
                {
                    p = 0;
                    cout << "Finished" << omp_get_thread_num() << endl;
                }
                else
                {
                    cout << omp_get_thread_num() << endl;
                }
            }
        }
    }
}