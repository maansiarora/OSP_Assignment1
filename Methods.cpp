#include "Methods.h"

//this method is to remove all the punctuations, symbols or any other non ascii characters 
//from the words. It would just keep all the alphabets that make the word.
//here, 'find_first_not_of' is a built-in function searches the words for the first character that does
// not match the ones that aren't specified in its arguments. 
bool justAlphabets(std::string const &str) {
    return str.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") == std::string::npos;
}

//creating a method name 'Task1filter' as mentioned in the spec for cleaning the dirty file for task 1
bool Task1filter(std::string argv1, std::string argv2) {

    //new_file -- DirtyFile on the command line as asked in the spec
    std::string new_file = argv1;

    //"DirtyFile.txt" is by default, the dirty file that will be used if nothing is provided on
    //the command line or if the user types in "default"
    if (argv1 != "default") {
        new_file = argv1; 
    }
    
    //creating an empty list where we can push the words from the new_file created above
    std::list<std::string> list_in; 
    //each individual word
    std::string word;

    //adding words into list created above line by line
    std::ifstream input_file(new_file);
    while (getline(input_file, word)) {
        list_in.push_back(word);
    }
    
    //removing duplicates from the list though unique() function
    list_in.unique();

    //creating a vector
    std::vector<std::string> li_vec;
    //defining an iteration variable to pass through the list
    std::list<std::string>::iterator xx;

    //defining xx to be the starting of the list
    xx = list_in.begin();
    //iterating until the end of the list
    while(xx != list_in.end()){
        //adding to the vector as we iterate through the list
        li_vec.push_back(*xx);
        xx++;
    }

    //final file to write into
    std::fstream file_save;
    //output file provide on command line
    std::string out_file = argv2;

    //opening the output file passed through the command line by the user
    file_save.open(out_file, std::ios::out);

    //adding only those words that have length greater than or equal to 3 and less than or equal
    //to 15 as mentioned in the spec sheet
    //using justAlphabets method created above to make sure that all the words with just alphabets and no other
    //symbol remain in the output file
    for (int i = 0; i < (int)li_vec.size(); i++) {
            if (li_vec[i].size() >= 3 && li_vec[i].size() <= 15 && justAlphabets(li_vec[i])) {
                file_save << li_vec[i] << std::endl;
            }
        }
        //file closed
        file_save.close();
    
    std::cout << "Task 1 complete!" << std::endl;
    return true;
}

//this method is to compare the parameters- string 1 and string 2 on the basis of the third letter of the word
//this comparator is used in task 2 onwards when we are sorting the files on the basis of the third letter
bool comparator(std::string str1, std::string str2) {
    return (str1[2] < str2[2]);
}

//this method will filter the dirty data of the file and return the array of the clean data for task3.
std::string* globalStringArray(std::string argv1) {
    
    //an empty array with size equal to the size of the input dirty file
    std::string* output_array = new std::string[GLOBAL_ARRAY];
    std::string new_file = argv1; // dirtyfile given on the command line
    if (argv1 != "default") {
        new_file = argv1;
    }

    //creating an empty list where we can push the words from the new_file created above
    std::list<std::string> list_in; 
    //each individual word
    std::string word;

    //adding words into list created above line by line
    std::ifstream input_file(new_file);
    while (getline(input_file, word)) {
        list_in.push_back(word);
    }

    //removing duplicates from the list though unique() function
    list_in.unique();
    //creating a vector
    std::vector<std::string> li_vec;
    //defining an iteration variable to pass through the list
    std::list<std::string>::iterator xx;
    
    //defining xx to be the starting of the list
    xx = list_in.begin();
    //iterating until the end of the list
    while(xx != list_in.end()){
        //adding to the vector as we iterate through the list
        li_vec.push_back(*xx);
        xx++;
    }

    //creating another clean list where the filtered words will be added
    std::vector<std::string> li_clean;
    
    //adding only those words that have length greater than or equal to 3 and less than or equal
    //to 15 as mentioned in the spec sheet
    //using justAlphabets method created above to make sure that all the words with just alphabets and no other
    //symbol remain in the clean list
    for (int i = 0; i < (int)li_vec.size(); i++) {
        if (li_vec[i].size() >= 3 && li_vec[i].size() <= 15 && justAlphabets(li_vec[i])) {
            li_clean.push_back(li_vec[i]);
        }
    }

    //adding the words from the clean list to the array that we need to return as filtered words
    for (int i = 0; i < GLOBAL_ARRAY; i++) {
        output_array[i] = li_clean[i];
    }

    return output_array;
}


