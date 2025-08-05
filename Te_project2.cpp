#include <iostream>
#include <omp.h>

using namespace std;

int main()
{
    int count = 1;
    int is[5] = {0,0,0,0,0};
    int i = 1;
    int sum = 0;

    omp_set_dynamic(0);
    omp_set_num_threads(6);

    #pragma omp parallel
    {
        int no = omp_get_thread_num();

        for (int j = 0; i<10; j++){

            switch (no)
            {
            case 0: is[0] = i++; break;
            case 1: is[1] = i--; break;
            case 2: is[2] = i*i; break;
            case 3: is[3] = ++i; break;
            case 4: is[4] = --i; break;
            }

            count++;

            #pragma omp barrier

            if(no == 5){
                sum = is[0] + is[1] + is[2] + is[3] + is[4];
            }

            #pragma omp barrier

            #pragma omp critical
            {
                cout << ++count << ". Thread " << no << ": ";
                if(no < 5) cout << i;
                else cout << sum;
                cout << endl;
            }

        }
        
    }
    return 0;
}
