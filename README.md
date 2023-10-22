# Steps for Code Execution:
1.Open the C++ code file in your compiler.
2.Attach the required input files along with the code file.
3.Now compile and run the code.
4.The output will get printed in output.txt



# Approach and Time Complexity of the algorithm

(1) First read the input from the INPUT.txt file and store the string in the vector "str" and unordered_set "s".
(2) The code initializes two empty strings longest and sec_longest to keep track of the longest and second longest compounded words found.
(3) It creates a boolean vector dp of size 1001 to keep track of whether a word can be compounded from other words in the list.
(4) Now iterate through the words of vector:

    a. Initializes a dynamic programming (DP) array dp with "false" values.
    b. For each substring of the current word, it checks if the substring exists in the set s(meaning it's a valid word in the list).
    c. If a valid word is found, it updates the DP array based on certain conditions.
    d. The DP array is used to determine if the entire word can be compounded from other words.

If a word is coumpounded then we accordingly update the "longest" and "sec_longest" compounded word based on the maximum size.

After processing all words, it prints the longest compounded word, the second longest compounded word and Time of execution.

# Time complexity:
Time complexity of the given solution in average case is O(nk), where n is number of strings and k is maximum length of strings.
Space complexity of the solution is O(n).






