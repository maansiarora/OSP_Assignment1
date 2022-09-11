#include "Task3.h"
#include "Methods.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <algorithm>
#include <thread>
#include <pthread.h>

//creating a global array
std::string* Global = new std::string[ARRAY_GLOBAL];

pthread_mutex_t lock;
struct arg_struct {
    int arg1;
    std::vector<int> arg2; };

int main(int argc, char** argv) {
    if (argc >= 3) {
        std::string argv1 = argv[1];
        std::string argv2 = argv[2];

        //array of filtered words that is returned from globalStringArray()
        std::string* arr = globalStringArray(argv1);

        //copying the contents of the returned array to global array created at the start
        int i = 0;
        while (i < ARRAY_GLOBAL){
            Global[i] = arr[i];
            i++;
        }
        
        //creating threads
        pthread_t thread_map3, thread_reduce3;

        //creating a new thread for map3()
        pthread_create(&thread_map3, NULL, &map3, NULL);
        //joining with the terminated thread
        pthread_join(thread_map3, NULL);

        //doing the same for the reduce3()
        pthread_create(&thread_reduce3, NULL, &reduce3, NULL);
        pthread_join(thread_reduce3, NULL);

        std::cout << "Task 3 completed!" << std::endl;

        //deleting the temp array we created
        delete[] arr;
    }

    return EXIT_SUCCESS;  
}


