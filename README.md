# Algorithms and data structures 2 - Lab 1

Implement two data structures and compare their work according to the task.
1. Create a structure for storing different types of data according to your variant. The structure Meme has the following fields: template name, text, number of likes.
2. Implement a dynamic array (with self-expansion):
    1. Create a DynamicArray structure to store the structures of your variant and implement the main functions of a dynamic array:
        - push_back() add an element to the end
        - pop_back() read and delete the item from the end
        - get() reading the n-th element
        - size() finding the number of elements
        - print() output of all elements with stored data
    2. Implement additional functions for a dynamic array:
        - push_front() add the element to the beginning
        - pop_front() read and delete the item from the beginning
3. Implement a single-linked list: 
    1. Create a Node structure for the base element of a single-linked list, it will contain the structure according to the option.
    2. Create a LinkedList structure and implement the main functions of a single-linked list:
        - push_front() add the element to the beginning
        - push_back() add an element to the end
        - get() reading the n-th element
        - pop_front() read and delete the item from the beginning
        - pop_back() read and delete the item from the end
        - size() finding the number of elements
        - print() output of all elements with stored data
4. Compare the work of a single-linked list and a dynamic array (perform each step for both structures, measure and compare the time of each step and all steps together):
    1. Add 50000 elements to the end
    2. Add 10000 items to the beginning
    3. Read 20000 elements under random indices
    4. Delete 5000 items from the beginning
    5. Remove 5000 items from the end

<b>Importantly!</b> Allowed libraries to connect:
- I / O libraries: \<iostream>, \<iomanip>, <stdio.h>, <conio.h>
- library of mathematical functions: \<cmath> (math.h)
- libraries for the randomize function: \<cstdlib> (stdlib.h), \<ctime> (time.h)
- library to support Cyrillic output: \<clocale> (locale.h)
- library for support of Ukrainian letters in the Windows console: <windows.h>
- libraries for working with string data: \<string>, \<cstring> (string.h)
