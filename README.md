# Ormuco
Please find below the code for all the 3 questions. The code is written in C++ language and appropriate comments have been added. Also, the codes include various test cases.

## Answer 1:
In this, the points are sorted in the ascending order, i.e. if we have x1,x2 and x3,x4, if x1>x2 we will swap this. Same rule goes with x3,x4.
Now if, x1>x3 we will swap both the points. Further we will check if x3 lies between x1 and x2. If true, return overlapping else return not overlapping.

## Answer 2:
A header file is created which includes the signature of the functions. It is further included in the cpp file.

The question states that we have 2 strings. So, I will run the iterator till '.' for both the strings. I will convert the string (i.e. substring from string1) to number by applying formula, n1 = n1*10 + (s[i] - '0'). Same formula, n2 for string 2. 
Now if n1>n2 we will return that string 1 is greater than string 2.
else if n2>n1 will will return that string 2 is greater that string 1.
else if both the strings are over will will return that both strings are equal.

## Answer 3:
In this, we have to implement least recently used cache. The path that i choose is that I have created a doubly linked list. I have also created a hashmap to store the reference of the node linked to the key. 
I have created 3 functions to put, get and print the values.
For put, i will update the value if key already exists. Otherwise, add the key value to the front of DLL. If the capacity is reached, remove the least recently used i.e. delete the last node from the DLL.
For get, i have checked that if the key is present in map, then return the value. Also, delete the node and add it to the front as it the newly used cache. If the key is not present in the map, then return -1.
For print, it will simply iterate over the map and print the key-value pair.
