# SQL-Connected-With-CPlus

     implementing an efficient join algorithm 
     
C++ program for the following Query: 

SELECT D.age, SUM(X.fee) 
FROM Dogs D, Exmaine X 
WHERE D.did=X.did 
GROUP BY D.age

With the fee being in the range:  [20, 99], and age is in the range:  [8, 11]

 DFile.txt and EFile.txt used as input for the program
 
 
 
 Program run on a unix enviroment
 
 > g++ sqlJoined.cpp  
> a.out 

Opening DFile.txt
Commence in DFile.txt

Size or Total Number in Dog file: 800001

Data saving in sorted_DFile.txt

Opening EFile.txt 
Commence Sorted EFile.txt

Size or Total Number in Examine file: 1200001

Data saving in sorted_EFile.txt 

 Joining Dogs and Examine 
Size of the Joined Dogs and Examine list 1200001

 Age                     Sum of Fee 
8                       17847109
9                       17809963
10                      17812154
11                      17916492

 Time for completion: 12.21s
> exit 
