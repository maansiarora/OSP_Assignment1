#include "Methods.h"
#include "Task2.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <algorithm>

pid_t pid; //for fork

int main(int argc, char** argv) {
    if (argc >= 3) {
        std::string argv1 = argv[1];
        std::string argv2 = argv[2];
        Task1filter(argv1,argv2);
        //calling map2() to separate words into differnt files according to their lengths
        map2();
            if (pid > 0) {  
                //calling reduce2() to merge the previously created 13 files into one using merge sort
                reduce2();
            }
    }
    return EXIT_SUCCESS;
}

//this method is to separate the clean file created using task 1 into 13 differnt files
//according to the lengths of the words.
void map2(){
    std::string line;

    //creating vectors that would contain word with particular lengths
    std::vector<std::string> length3, length4, length5, length6, length7, length8, length9,
                             length10, length11, length12, length13, length14, length15;

    //opening clean file that was created using Task1filter()
    std::ifstream input_file("Cleanfile.txt");
    
    // writing different length of words into different vectors created above
    while (getline(input_file, line)) {
        switch (line.size()){
            case 3:
                length3.push_back(line);
                break;
            case 4:
                length4.push_back(line);
                break;
            case 5:
                length5.push_back(line);
                break;
            case 6:
                length6.push_back(line);
                break;
            case 7:
                length7.push_back(line);
                break;
            case 8:
                length8.push_back(line);
                break;
            case 9:
                length9.push_back(line);
                break;
            case 10:
                length10.push_back(line);
                break;
            case 11:
                length11.push_back(line);
                break;
            case 12:
                length12.push_back(line);
                break;
            case 13:
                length13.push_back(line);
                break;
            case 14:
                length14.push_back(line);
                break;
            case 15:
                length15.push_back(line);
                break;
            default:
                break;
            }
        }
        
    // fork() to create processes
    pid = fork();
    if (pid > 0) {

        //this will sort all the vectors in the parent process
        std::sort(length3.begin(),length3.end(), comparator);
        std::sort(length4.begin(),length4.end(), comparator);
        std::sort(length5.begin(),length5.end(), comparator);
        std::sort(length6.begin(),length6.end(), comparator);
        std::sort(length7.begin(),length7.end(), comparator);
        std::sort(length8.begin(),length8.end(), comparator);
        
        //calling write_file() written below to write all the words stored in different vectors
        //to different files of their respective lengths
        write_file("length3.txt", length3);
        write_file("length4.txt", length4);
        write_file("length5.txt", length5);
        write_file("length6.txt", length6);
        write_file("length7.txt", length7);
        write_file("length8.txt", length8);
        wait(nullptr);  
    }

    else {

        //child processes
        std::sort(length9.begin(),length9.end(), comparator);
        std::sort(length10.begin(),length10.end(), comparator);
        std::sort(length11.begin(),length11.end(), comparator);
        std::sort(length12.begin(),length12.end(), comparator);
        std::sort(length13.begin(),length13.end(), comparator);
        std::sort(length14.begin(),length14.end(), comparator);
        std::sort(length15.begin(),length15.end(), comparator);
        
        //calling write_file() written below to write all the words stored in different vectors
        //to different files of their respective lengths
        write_file("length9.txt", length9);
        write_file("length10.txt", length10);
        write_file("length11.txt", length11);
        write_file("length12.txt", length12);
        write_file("length13.txt", length13);
        write_file("length14.txt", length14);
        write_file("length15.txt", length15);
    }
}

//method to write the vectors into different files
void write_file(std::string file1, std::vector<std::string> vec) {
    
    //opening the file
    std::fstream file2;
    std::string out_files = file1;
    file2.open(out_files, std::ios::out);

    //looping though the vector until its length
    int i = 0;
    while (i < (int)vec.size()){
        //writing it to a file
        file2 << vec[i] << std::endl;
        i++;
    }
    //closing the file
    file2.close();
}

//reduce2() function is used to merge the 13 files created above into into one single file on the 
//basis of their third character of each word using 13 -> 1 merge sort
void reduce2() {
    std::ifstream sorted3, sorted4, sorted5, sorted6, sorted7, sorted8, sorted9,
                  sorted10, sorted11, sorted12, sorted13, sorted14, sorted15;
     
    //output file
    std::ofstream final_sort;

    std::string word3, word4, word5, word6, word7, word8, word9, word10, word11,
                word12, word13, word14, word15;

    //Opening the files
    sorted3.open("./length3.txt");
    sorted4.open("./length4.txt");
    sorted5.open("./length5.txt");
    sorted6.open("./length6.txt");
    sorted7.open("./length7.txt");
    sorted8.open("./length8.txt");
    sorted9.open("./length9.txt");
    sorted10.open("./length10.txt");
    sorted11.open("./length11.txt");
    sorted12.open("./length12.txt");
    sorted13.open("./length13.txt");
    sorted14.open("./length14.txt");
    sorted15.open("./length15.txt");
    //opening the final output file
    final_sort.open("final_sort.txt", std::ios::out);
    
    //13 -> 1 merge sort
    sorted3 >> word3;
    sorted4 >> word4;
    sorted5 >> word5;
    sorted6 >> word6;
    sorted7 >> word7;
    sorted8 >> word8;
    sorted9 >> word9;
    sorted10 >> word10;
    sorted11 >> word11;
    sorted12 >> word12;
    sorted13 >> word13;
    sorted14 >> word14;
    sorted15 >> word15;
    //we need to make sure that the while loop goes on until all the 13 files have reached the end
    while (!sorted3.eof() || !sorted4.eof() || !sorted5.eof() || !sorted6.eof() || !sorted7.eof() ||
           !sorted8.eof() || !sorted9.eof() || !sorted10.eof()|| !sorted11.eof()|| !sorted12.eof()||
           !sorted13.eof()|| !sorted14.eof()||!sorted15.eof()) {
        //assigning the file that has reached eof the EOF_STRING counter
        //the EOF_STRING is the last word possible "zzzzzzzzzzzzzzz" as there cannot be anything after this
        //in any of our files because of the filtering process we did earlier.
        if (sorted3.eof() && word3 != EOF_STRING) {
            word3 = EOF_STRING;
        }
        if (sorted4.eof() && word4 != EOF_STRING) {
            word4 = EOF_STRING;
        }
        if (sorted5.eof() && word5 != EOF_STRING) {
            word5 = EOF_STRING;
        }
        if (sorted6.eof() && word6 != EOF_STRING) {
            word6 = EOF_STRING;
        }
        if (sorted7.eof() && word7 != EOF_STRING) {
            word7 = EOF_STRING;
        }
        if (sorted8.eof() && word8 != EOF_STRING) {
            word8 = EOF_STRING;
        }
        if (sorted9.eof() && word9 != EOF_STRING) {
            word9 = EOF_STRING;
        }
        if (sorted10.eof() && word10 != EOF_STRING) {
            word10 = EOF_STRING;
        }
        if (sorted11.eof() && word11 != EOF_STRING) {
            word11 = EOF_STRING;
        }
        if (sorted12.eof() && word12 != EOF_STRING) {
            word12 = EOF_STRING;
        }
        if (sorted13.eof() && word13 != EOF_STRING) {
            word13 = EOF_STRING;
        }
        if (sorted14.eof() && word14 != EOF_STRING) {
            word14 = EOF_STRING;
        }
        if (sorted15.eof() && word15 != EOF_STRING) {
            word15 = EOF_STRING;
        }

        //minimum word from the 13 files that we have
        if (word3 < word4 && word3 < word5 && word3 < word6 && word3 < word7 &&
            word3 < word8 && word3 < word9 && word3 < word10 && word3 < word11 &&
            word3 < word12 && word3 < word13 && word3 < word14 && word3 < word15) {
            //writing the lowest word into the file
            final_sort << word3 << std::endl;
            //reading the next word from the same file
            sorted3 >> word3;
        }
        else if (word4 < word3 && word4 < word5 && word4 < word6 && word4 < word7 && word4 
                < word8 && word4 < word9 && word4 < word10 && word4 < word11 && word4 
                < word12 && word4 < word13 && word4 < word14 && word4 < word15) {
            final_sort << word4 << std::endl; //writing
            sorted4 >> word4; //reading
        }
        else if (word5 < word3 && word5 < word4 && word5 < word6 && word5 < word7 && word5 
                < word8 && word5 < word9 && word5 < word10 && word5 < word11 && word5 
                < word12 && word5 < word13 && word5 < word14 && word5 < word15) {
            final_sort << word5 << std::endl; //writing
            sorted5 >> word5; //reading
        }
        else if (word6 < word3 && word6 < word4 && word6 < word5 && word6 < word7 && word6 
                < word8 && word6 < word9 && word6 < word10 && word6 < word11 && word6 
                < word12 && word6 < word13 && word6 < word14 && word6 < word15) {
            final_sort << word6 << std::endl;
            sorted6 >> word6;
        }
        else if (word7 < word3 && word7 < word4 && word7 < word5 && word7 < word6 && word7 
                < word8 && word7 < word9 && word7 < word10 && word7 < word11 && word7 
                < word12 && word7 < word13 && word7 < word14 && word7 < word15) {
            final_sort << word7 << std::endl;
            sorted7 >> word7;
        }
        else if (word8 < word3 && word8 < word4 && word8 < word5 && word8 < word6 && word8 
                < word7 && word8 < word9 && word8 < word10 && word8 < word11 && word8 
                < word12 && word8 < word13 && word8 < word14 && word8 < word15) {
            final_sort << word8 << std::endl;
            sorted8 >> word8;
        }
        else if (word9 < word3 && word9 < word4 && word9 < word5 && word9 < word6 && word9 
                < word7 && word9 < word8 && word9 < word10 && word9 < word11 && word9 
                < word12 && word9 < word13 && word9 < word14 && word9 < word15) {
            final_sort << word9 << std::endl;
            sorted9 >> word9;
        }
        else if (word10 < word3 && word10 < word4 && word10 < word5 && word10 < word6 && word10 
                < word7 && word10 < word8 && word10 < word9 && word10 < word11 && word10 
                < word12 && word10 < word13 && word10 < word14 && word10 < word15) {
            final_sort << word10 << std::endl;
            sorted10 >> word10;
        }
        else if (word11 < word3 && word11 < word4 && word11 < word5 && word11 < word6 && word11 
                < word7 && word11 < word8 && word11 < word9 && word11 < word10 && word11 
                < word12 && word11 < word13 && word11 < word14 && word11 < word15) {
            final_sort << word11 << std::endl;
            sorted11 >> word11;
        }
        else if (word12 < word3 && word12 < word4 && word12 < word5 && word12 < word6 && word12 
                < word7 && word12 < word8 && word12 < word9 && word12 < word10 && word12
                < word11 && word12 < word13 && word12 < word14 && word12 < word15) {
            final_sort << word12 << std::endl;
            sorted12 >> word12;
        }
        else if (word13 < word3 && word13 < word4 && word13 < word5 && word13 < word6 && word13 
                < word7 && word13 < word8 && word13 < word9 && word13 < word10 && word13 
                < word11 && word13 < word12 && word13 < word14 && word13 < word15) {
            final_sort << word13 << std::endl;
            sorted13 >> word13;
        }
        else if (word14 < word3 && word14 < word4 && word14 < word5 && word14 < word6 && word14
                < word7 && word14 < word8 && word14 < word9 && word14 < word10 && word14
                < word11 && word14 < word12 && word14 < word13 && word14 < word15) {
            final_sort << word14 << std::endl;
            sorted14 >> word14;
        }
        else if (word15 < word3 && word15 < word4 && word15 < word5 && word15 < word6 && word15
                < word7 && word15 < word8 && word15 < word9 && word15 < word10 && word15 
                < word11 && word15 < word12 && word15 < word13 && word15 < word14) {
            final_sort << word15 << std::endl;
            sorted15 >> word15;
        }
    }

    //closing all the files
    sorted3.close();
    sorted4.close();
    sorted5.close();
    sorted6.close();
    sorted7.close();
    sorted8.close();
    sorted9.close();
    sorted10.close();
    sorted11.close();
    sorted12.close();
    sorted13.close();
    sorted14.close();
    sorted15.close();
    final_sort.close();
    std::cout<<"Task 2 complete!"<<std::endl;
}

