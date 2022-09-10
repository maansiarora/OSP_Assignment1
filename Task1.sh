# this .sh file is equivalent for the TaskFilter() function 
# that has been created

# let's first remove all the punctuations and symbols
# from the input text file. we then store the that into a new 
# file named "no_punct.txt"
tr -d '[:punct:]' <wlist_all/wlist_match12.txt> no_punct.txt

# we then remove all the duplicate of the words from the file
# and store it in "no_duplicates.txt"
awk '!seen[$0]++' no_punct.txt > no_duplicates.txt

# we also remove any numbers that may exist between words in the
# form 'sing231lequo56te'which ideally should be 'singlequote'
# we store the data in "no_numberical.txt"
sed -e 's/[0-9]//g' no_duplicates.txt > no_numerical.txt

# we may remove any empty lines without any text as well,
# even though this may be done by itself when we further remove
# the lines with words less than 3 letter, but in case we had
# no such filter, we would have done this to remove empty lines anyways
sed '/^$/d' no_numerical.txt > no_empty_lines.txt 

# we then filter out words on the basis of their lengths
# we just keep words that have lengths greater than or equal 
# to 3 or words that have lengths less than or equal to 15
grep ".\{3,\}" no_empty_lines.txt > no_lower_len.txt
grep -v '.\{15\}' no_lower_len.txt > no_upper_len.txt

# we then shuffle the order of the words and store it into
# our final file "shuffled_words.txt"
shuf  no_upper_len.txt > shuffled_words.txt

# displaying the top 10 words on the terminal to check if
# everything is working well
head -n 10 shuffled_words.txt