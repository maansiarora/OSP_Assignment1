# Assignment 1 for Operating System Principles

- To run and test the shell file for task 1, use the following command on the terminal: `./Task1.sh`. 
This will create all the essential `.txt` files from each step, the final one being 'shuffled_words.txt'.
And also, top 10 words from the file will be printed on the terminal as a check to ensure everything is happening as it should.

- To compile all the tasks, `make` command needs to be used. This will generate all the object and supporting files.
- To execute specific tasks, use the command: `./Task1 DirtyFile.txt Cleanfile.txt` where you can write any number 1, 2 or 3 in
place of the '1' shown in the example command.
- After running task 1, a single file will be generated having the name mentioned through the commandline.
- After running task 2, 3 'types' of files will be generated - 
    - the first one would be same as task 1 output file, 
    - the second one would be a bunch of files (total 13 - `length3.txt`, `length4.txt`, ...) having words with particular lengths.
    - third would be the sorted file `final_sort.txt` after merging these 13 files.
- After running task 3, 13 FIFO files (namely `FIFO3.txt`, etc) and one sorted file `sortedFile.txt`after merging fifo files would be
generated.