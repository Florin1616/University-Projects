# Data Structures and Algorithms - Lab 1: Dynamic Array

Implement in C++ the given container (ADT) using a given representation and a dynamic array <br/>
as a data structure. You are not allowed to use the vector from STL or from any other library. <br/>
Obs: <br/>
- Since your implementation will use dynamic allocation, it is a good practice to implement a  <br/>
destructor, copy constructor and assignment operator as well (even if they are not on the  <br/>
interface). <br/>
- You are not allowed to use the functions memcpy and realloc, because it is not safe to use  <br/>
memcpy and realloc on memory that was allocated with new. Also, if the memory location  <br/>
contains objects, undefined behavior can occur. The implementation might still work with  <br/>
these functions, but it is not a good practice to use them. <br/>
- If you need auxiliary functions, fell free to add them to the interface of the ADT, but make  <br/>
them private.<br/>

## 2. ADT Matrix – represented as a sparse matrix, compressed sparse column representation using dynamic arrays.
