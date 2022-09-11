#include "Task3.h"
#include "Methods.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <algorithm>
#include <thread>
#include <pthread.h>

std::string* Global = new std::string[GLOBAL_ARRAY];

pthread_mutex_t lock;
struct arg_struct {
    int arg1;
    std::vector<int> arg2;
};

int main(int argc, char** argv) {
    if (argc >= 3) {
        std::string argv1 = argv[1];
        std::string argv2 = argv[2];
        
        //array of filtered words that is returned from globalStringArray()
        std::string* arr = globalStringArray(argv1);
        
        //copying the contents of the returned array to global array created at the start
        int i = 0;
        while (i < GLOBAL_ARRAY){
            Global[i] = arr[i];
            i++;
        }

        //creating threads
        pthread_t thread_map3, thread_reduce3;
        
        //creating a new thread for map3()
        pthread_create(&thread_map3, NULL, &map3, NULL);
        //joining with the terminated thread
        pthread_join(thread_map3,NULL);

        //doing the same for reduce3()
        pthread_create(&thread_reduce3, NULL, &reduce3, NULL);
        pthread_join(thread_reduce3, NULL);
        
        std::cout << "Task 3 complete!" << std::endl;
        
        //deleting the temp array we created
        delete[] arr;
    }
    return EXIT_SUCCESS;
}

//map3() function will create 13 index arrays and threads, one for each word length
//FIFO files will also be created by map3() itself.
void* map3(void *varg){
    
    //initializing the sizes for 13 index arrays
    int size_arr3 = 0, size_arr4 = 0, size_arr5 = 0, size_arr6 = 0, size_arr7 = 0, size_arr8 = 0, size_arr9 = 0,
        size_arr10 = 0, size_arr11 = 0, size_arr12 = 0, size_arr13 = 0, size_arr14 = 0, size_arr15 = 0;
    
    for (int i = 0; i < GLOBAL_ARRAY; i++) {
        switch (Global[i].size()){
            case 3:
                size_arr3++;
                break;
            case 4:
                size_arr4++;
                break;
            case 5:
                size_arr5++;
                break;
            case 6:
                size_arr6++;
                break;
            case 7:
                size_arr7++;
                break;
            case 8:
                size_arr8++;
                break;
            case 9:
                size_arr9++;
                break;
            case 10:
                size_arr10++;
                break;
            case 11:
                size_arr11++;
                break;
            case 12:
                size_arr12++;
                break;
            case 13:
                size_arr13++;
                break;
            case 14:
                size_arr14++;
                break;
            case 15:
                size_arr15++;
                break;
            default:
                break;
        }
    }

    //index arrays of the size of that particular array
    int index_arr3[size_arr3], index_arr4[size_arr4], index_arr5[size_arr5], index_arr6[size_arr6],
        index_arr7[size_arr7], index_arr8[size_arr8], index_arr9[size_arr9], index_arr10[size_arr10],
        index_arr11[size_arr11], index_arr12[size_arr12], index_arr13[size_arr13], index_arr14[size_arr14],
        index_arr15[size_arr15];

    //initial sizes of the arrays
    size_arr3 = 0, size_arr4 = 0, size_arr5 = 0, size_arr6 = 0, size_arr7 = 0, size_arr8 = 0,
    size_arr9 = 0, size_arr10 = 0, size_arr11 = 0, size_arr12 = 0, size_arr13 = 0, size_arr14 = 0,
    size_arr15 = 0;

    //appending words of particular lengths to the respective index arrays created above
    for (int i = 0; i < GLOBAL_ARRAY; i++) {
        switch (Global[i].size()){
            case 3:
                index_arr3[size_arr3] = i;
                size_arr3++; //incrementing size array
                break;
            case 4:
                index_arr4[size_arr4] = i;
                size_arr4++; //incrementing size array
                break;
            case 5:
                index_arr5[size_arr5] = i;
                size_arr5++; //incrementing size array
                break;
            case 6:
                index_arr6[size_arr6] = i;
                size_arr6++; //incrementing size array
                break;
            case 7:
                index_arr7[size_arr7] = i;
                size_arr7++; //incrementing size array
                break;
            case 8:
                index_arr5[size_arr5] = 8;
                size_arr8++; //incrementing size array
                break;
            case 9:
                index_arr9[size_arr9] = i;
                size_arr9++; //incrementing size array
                break;
            case 10:
                index_arr10[size_arr10] = i;
                size_arr10++; //incrementing size array
                break;
            case 11:
                index_arr11[size_arr11] = i;
                size_arr11++; //incrementing size array
                break;
            case 12:
                index_arr12[size_arr12] = i;
                size_arr12++; //incrementing size array
                break;
            case 13:
                index_arr13[size_arr13] = i;
                size_arr13++; //incrementing size array
                break;
            case 14:
                index_arr14[size_arr14] = i;
                size_arr14++; //incrementing size array
                break;
            case 15:
                index_arr15[size_arr15] = i;
                size_arr15++; //incrementing size array
                break;
        }
    }
    
    //creating vectors for each of the index arrays of words with differnt lengths
    std::vector<int> arr3_vec, arr4_vec, arr5_vec, arr6_vec, arr7_vec, arr8_vec, arr9_vec, arr10_vec,
                     arr11_vec, arr12_vec, arr13_vec, arr14_vec, arr15_vec;

    //adding words into vectors from their respective index arrays
    for (int i = 0; i < size_arr3; i++) {
        arr3_vec.push_back(index_arr3[i]);
    }
    for (int i = 0; i < size_arr4; i++) {
        arr4_vec.push_back(index_arr4[i]);
    }
    for (int i = 0; i < size_arr5; i++) {
        arr5_vec.push_back(index_arr5[i]);
    }
    for (int i = 0; i < size_arr6; i++) {
        arr6_vec.push_back(index_arr6[i]);
    }
    for (int i = 0; i < size_arr7; i++) {
        arr7_vec.push_back(index_arr7[i]);
    }
    for (int i = 0; i < size_arr8; i++) {
        arr8_vec.push_back(index_arr8[i]);
    }
    for (int i = 0; i < size_arr9; i++) {
        arr9_vec.push_back(index_arr9[i]);
    }
    for (int i = 0; i < size_arr10; i++) {
        arr10_vec.push_back(index_arr10[i]);
    }
    for (int i = 0; i < size_arr11; i++) {
        arr11_vec.push_back(index_arr11[i]);
    }
    for (int i = 0; i < size_arr12; i++) {
        arr12_vec.push_back(index_arr12[i]);
    }
    for (int i = 0; i < size_arr13; i++) {
        arr13_vec.push_back(index_arr13[i]);
    }
    for (int i = 0; i < size_arr14; i++) {
        arr14_vec.push_back(index_arr14[i]);
    }
    for (int i = 0; i < size_arr15; i++) {
        arr15_vec.push_back(index_arr15[i]);
    }

    pthread_mutex_init(&lock, NULL);
    //creating threads for sorting
    pthread_t t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15;

    struct arg_struct args3, args4, args5, args6, args7, args8, args9, args10, args11, args12, args13, args14, args15;
    args3.arg1 = 3;
    args3.arg2 = arr3_vec;
    
    //creating threads
    pthread_create(&t3, NULL, &threadFIFO, (void *)&args3);
    args4.arg1 = 4;
    args4.arg2 = arr4_vec;
    pthread_create(&t4, NULL, &threadFIFO, (void *)&args4);
    args5.arg1 = 5;
    args5.arg2 = arr5_vec;
    pthread_create(&t5, NULL, &threadFIFO, (void *)&args5);
    args6.arg1 = 6;
    args6.arg2 = arr6_vec;
    pthread_create(&t6, NULL, &threadFIFO, (void *)&args6);
    args7.arg1 = 7;
    args7.arg2 = arr7_vec;
    pthread_create(&t7, NULL, &threadFIFO, (void *)&args7);
    args8.arg1 = 8;
    args8.arg2 = arr8_vec;
    pthread_create(&t8, NULL, &threadFIFO, (void *)&args8);
    args9.arg1 = 9;
    args9.arg2 = arr9_vec;
    pthread_create(&t9, NULL, &threadFIFO, (void *)&args9);
    args10.arg1 = 10;
    args10.arg2 = arr10_vec;
    pthread_create(&t10, NULL, &threadFIFO, (void *)&args10);
    args11.arg1 = 11;
    args11.arg2 = arr11_vec;
    pthread_create(&t11, NULL, &threadFIFO, (void *)&args11);
    args12.arg1 = 12;
    args12.arg2 = arr12_vec;
    pthread_create(&t12, NULL, &threadFIFO, (void *)&args12);
    args13.arg1 = 13;
    args13.arg2 = arr13_vec;
    pthread_create(&t13, NULL, &threadFIFO, (void *)&args13);
    args14.arg1 = 14;
    args14.arg2 = arr14_vec;
    pthread_create(&t14, NULL, &threadFIFO, (void *)&args14);
    args15.arg1 = 15;
    args15.arg2 = arr15_vec;
    pthread_create(&t15, NULL, &threadFIFO, (void *)&args15);

    //joining the threads as they terminate
    pthread_join(t3,NULL);
    pthread_join(t4,NULL);
    pthread_join(t5,NULL);
    pthread_join(t6,NULL);
    pthread_join(t7,NULL);
    pthread_join(t8,NULL);
    pthread_join(t9,NULL);
    pthread_join(t10,NULL);
    pthread_join(t11,NULL);
    pthread_join(t12,NULL);
    pthread_join(t13,NULL);
    pthread_join(t14,NULL);
    pthread_join(t15,NULL);
    pthread_mutex_destroy(&lock);
    pthread_exit(NULL);
    return NULL;
}

//reduce3() is to read the FIFO files that were created by map3() and sort them into one single file
void* reduce3(void *varg){
    
    //defining all the FIFO files
    std::ifstream words3_sorted, words4_sorted, words5_sorted, words6_sorted, words7_sorted, words8_sorted, 
                  words9_sorted, words10_sorted, words11_sorted, words12_sorted, words13_sorted,
                  words14_sorted, words15_sorted;
    
    //output file variable
    std::ofstream sortedFile;

    std::string words3, words4, words5, words6, words7, words8, words9, words10,
                words11, words12, words13, words14, words15;

    //opening each FIFO file
    words3_sorted.open("./FIFO3.txt");
    words4_sorted.open("./FIFO4.txt");
    words5_sorted.open("./FIFO5.txt");
    words6_sorted.open("./FIFO6.txt");
    words7_sorted.open("./FIFO7.txt");
    words8_sorted.open("./FIFO8.txt");
    words9_sorted.open("./FIFO9.txt");
    words10_sorted.open("./FIFO10.txt");
    words11_sorted.open("./FIFO11.txt");
    words12_sorted.open("./FIFO12.txt");
    words13_sorted.open("./FIFO13.txt");
    words14_sorted.open("./FIFO14.txt");
    words15_sorted.open("./FIFO15.txt");

    //opening the final file that we are going wrtie the merged words
    sortedFile.open("sortedFile.txt", std::ios::out);

    int count3 = 0, count4 = 0, count5 = 0, count6 = 0, count7 = 0, count8 = 0, count9 = 0, count10 = 0,
        count11 = 0, count12 = 0, count13 = 0, count14 = 0, count15 = 0;
    
    words3_sorted >> words3;
    words4_sorted >> words4;
    words5_sorted >> words5;
    words6_sorted >> words6;
    words7_sorted >> words7;
    words8_sorted >> words8;
    words9_sorted >> words9;
    words10_sorted >> words10;
    words11_sorted >> words11;
    words12_sorted >> words12;
    words13_sorted >> words13;
    words14_sorted >> words14;
    words15_sorted >> words15;
    
    //loop until the end of all the files
    while (!words3_sorted.eof() || !words4_sorted.eof() || !words5_sorted.eof() || !words6_sorted.eof() ||
           !words7_sorted.eof() || !words8_sorted.eof() || !words9_sorted.eof() || !words10_sorted.eof() ||
           !words11_sorted.eof() || !words12_sorted.eof() || !words13_sorted.eof() || !words14_sorted.eof() ||
           !words15_sorted.eof()) {
        
        //similar condition that was used for task2
        if (words3_sorted.eof() && words3 != EOF_STRING) {
            words3 = EOF_STRING;
        }
        if (words4_sorted.eof() && words4 != EOF_STRING) {
            words4 = EOF_STRING;
        }
        if (words5_sorted.eof() && words5 != EOF_STRING) {
            words5 = EOF_STRING;
        }
        if (words6_sorted.eof() && words6 != EOF_STRING) {
            words6 = EOF_STRING;
        }
        if (words7_sorted.eof() && words7 != EOF_STRING) {
            words7 = EOF_STRING;
        }
        if (words8_sorted.eof() && words8 != EOF_STRING) {
            words8 = EOF_STRING;
        }
        if (words9_sorted.eof() && words9 != EOF_STRING) {
            words9 = EOF_STRING;
        }
        if (words10_sorted.eof() && words10 != EOF_STRING) {
            words10 = EOF_STRING;
        }
        if (words11_sorted.eof() && words11 != EOF_STRING) {
            words11 = EOF_STRING;
        }
        if (words12_sorted.eof() && words12 != EOF_STRING) {
            words12 = EOF_STRING;
        }
        if (words13_sorted.eof() && words13 != EOF_STRING) {
            words13 = EOF_STRING;
        }
        if (words14_sorted.eof() && words14 != EOF_STRING) {
            words14 = EOF_STRING;
        }
        if (words15_sorted.eof() && words15 != EOF_STRING) {
            words15 = EOF_STRING;
        }
        
        //finding the minimum word among all the words
        if (words3 < words4 && words3 < words5 && words3 < words6 && words3 < words7 &&
            words3 < words8 && words3 < words9 && words3 < words10 && words3 < words11 &&
            words3 < words12 && words3 < words13 && words3 < words14 && words3 < words15) {
            //writing that word into the final merged file
            sortedFile << words3 << std::endl;
            //moving on to the next word in the same file
            words3_sorted >> words3;
            count3++;
        }
        else if (words4 < words3 && words4 < words5 && words4 < words6 && words4 < words7 &&
                words4 < words8 && words4 < words9 && words4 < words10 && words4 < words11 &&
                words4 < words12 && words4 < words13 && words4 < words14 && words4 < words15) {
            sortedFile << words4 << std::endl;
            words4_sorted >> words4;
            count4++;
        }
        else if (words5 < words3 && words5 < words4 && words5 < words6 && words5 < words7 &&
                words5 < words8 && words5 < words9 && words5 < words10 && words5 < words11 &&
                words5 < words12 && words5 < words13 && words5 < words14 && words5 < words15) {
            sortedFile << words5 << std::endl;
            words5_sorted >> words5;
            count5++;
        }
        else if (words6 < words3 && words6 < words4 && words6 < words5 && words6 < words7 &&
                words6 < words8 && words6 < words9 && words6 < words10 && words6 < words11 &&
                words6 < words12 && words6 < words13 && words6 < words14 && words6 < words15) {
            sortedFile << words6 << std::endl;
            words6_sorted >> words6;
            count6++;
        }
        else if (words7 < words3 && words7 < words4 && words7 < words5 && words7 < words6 &&
                words7 < words8 && words7 < words9 && words7 < words10 && words7 < words11 &&
                words7 < words12 && words7 < words13 && words7 < words14 && words7 < words15) {
            sortedFile << words7 << std::endl;
            words7_sorted >> words7;
            count7++;
        }
        else if (words8 < words3 && words8 < words4 && words8 < words5 && words8 < words6 &&
                words8 < words7 && words8 < words9 && words8 < words10 && words8 < words11 &&
                words8 < words12 && words8 < words13 && words8 < words14 && words8 < words15) {
            sortedFile << words8 << std::endl;
            words8_sorted >> words8;
            count8++;
        }
        else if (words9 < words3 && words9 < words4 && words9 < words5 && words9 < words6 &&
                words9 < words7 && words9 < words8 && words9 < words10 && words9 < words11 &&
                words9 < words12 && words9 < words13 && words9 < words14 && words9 < words15) {
            sortedFile << words9 << std::endl;
            words9_sorted >> words9;
            count9++;
        }
        else if (words10 < words3 && words10 < words4 && words10 < words5 && words10 < words6 &&
                words10 < words7 && words10 < words8 && words10 < words9 && words10 < words11 &&
                words10 < words12 && words10 < words13 && words10 < words14 && words10 < words15) {
            sortedFile << words10 << std::endl;
            words10_sorted >> words10;
            count10++;
        }
        else if (words11 < words3 && words11 < words4 && words11 < words5 && words11 < words6 &&
                words11 < words7 && words11 < words8 && words11 < words9 && words11 < words10 &&
                words11 < words12 && words11 < words13 && words11 < words14 && words11 < words15) {
            sortedFile << words11 << std::endl;
            words11_sorted >> words11;
            count11++;
        }
        else if (words12 < words3 && words12 < words4 && words12 < words5 && words12 < words6 &&
                words12 < words7 && words12 < words8 && words12 < words9 && words12 < words10 &&
                words12 < words11 && words12 < words13 && words12 < words14 && words12 < words15) {
            sortedFile << words12 << std::endl;
            words12_sorted >> words12;
            count12++;
        }
        else if (words13 < words3 && words13 < words4 && words13 < words5 && words13 < words6 &&
                words13 < words7 && words13 < words8 && words13 < words9 && words13 < words10 &&
                words13 < words11 && words13 < words12 && words13 < words14 && words13 < words15) {
            sortedFile << words13 << std::endl;
            words13_sorted >> words13;
            count13++;
        }
        else if (words14 < words3 && words14 < words4 && words14 < words5 && words14 < words6 &&
                words14 < words7 && words14 < words8 && words14 < words9 && words14 < words10 &&
                words14 < words11 && words14 < words12 && words14 < words13 && words14 < words15) {
            sortedFile << words14 << std::endl;
            words14_sorted >> words14;
            count14++;
        }
        else if (words15 < words3 && words15 < words4 && words15 < words5 && words15 < words6 &&
                words15 < words7 && words15 < words8 && words15 < words9 && words15 < words10 &&
                words15 < words11 && words15 < words12 && words15 < words13 && words15 < words14) {
            sortedFile << words15 << std::endl;
            words15_sorted >> words15;
            count15++;
        }
    }
    
    words3_sorted.close();
    words4_sorted.close();
    words5_sorted.close();
    words6_sorted.close();
    words7_sorted.close();
    words8_sorted.close();
    words9_sorted.close();
    words10_sorted.close();
    words11_sorted.close();
    words12_sorted.close();
    words13_sorted.close();
    words14_sorted.close();
    words15_sorted.close();
    sortedFile.close();

    pthread_exit(NULL);
    return NULL;
   
}

void writeFIFO(std::string name, std::vector<std::string> vector) {
    std::fstream savedfile;
    
    //opening the file
    savedfile.open(name, std::ios::out);
    //looping though the vector
    for (int i = 0; i < (int)vector.size(); i++) {
        savedfile << vector[i] << std::endl;
    }
    //closing the file
    savedfile.close();
}

void* threadFIFO(void* arguments) {
    struct arg_struct *args = (struct arg_struct *)arguments;
    int n = args->arg1;

    std::vector<int> v = args->arg2;
    std::vector<std::string> list;
    pthread_mutex_lock(&lock);

    int i = 0;
    while(i < (int)v.size()){
        list.push_back(Global[v[i]]);
        i++;
    }
    
    pthread_mutex_unlock(&lock);
    //sorting
    std::sort(list.begin(), list.end(), comparator);
    std::fstream savedfile;
    //writing into respective files
    if (n == 3) {
        std::string name = "./FIFO3.txt";
        writeFIFO(name, list);
    }
    if (n == 4) {
        std::string name = "./FIFO4.txt";
        writeFIFO(name, list);
    }
    if (n == 5) {
        std::string name = "./FIFO5.txt";
        writeFIFO(name, list);
    }
    if (n == 6) {
        std::string name = "./FIFO6.txt";
        writeFIFO(name, list);
    }
    if (n == 7) {
        std::string name = "./FIFO7.txt";
        writeFIFO(name, list);
    }
    if (n == 8) {
        std::string name = "./FIFO8.txt";
        writeFIFO(name, list);
    }
    if (n == 9) {
        std::string name = "./FIFO9.txt";
        writeFIFO(name, list);
    }
    if (n == 10) {
        std::string name = "./FIFO10.txt";
        writeFIFO(name, list);
    }
    if (n == 11) {
        std::string name = "./FIFO11.txt";
        writeFIFO(name, list);
    }
    if (n == 12) {
        std::string name = "./FIFO12.txt";
        writeFIFO(name, list);
    }
    if (n == 13) {
        std::string name = "./FIFO13.txt";
        writeFIFO(name, list);
    }
    if (n == 14) {
        std::string name = "./FIFO14.txt";
        writeFIFO(name, list);
    }
    if (n == 15) {
        std::string name = "./FIFO15.txt";
        writeFIFO(name, list);
    }

    pthread_exit(NULL);
    return NULL;
}

void read_FIFO (std::vector<std::string> &vector, std::string name){
    std::ifstream file_in;
    std::string word;
    file_in.open(name);
    while (file_in >> word) {
        vector.push_back(word);
    }
}
