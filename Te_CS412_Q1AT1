#include <iostream>
#include <omp.h>

using namespace std;


int main()
{
    int count = 1;
    omp_set_num_threads(4);

    #pragma omp parallel
    {
        for (int i = 0; i<10; i++){
            cout <<count <<". Hello World from Number:" << omp_get_thread_num()<<endl;
            count++;
        }
        
    }
    return 0;
}
