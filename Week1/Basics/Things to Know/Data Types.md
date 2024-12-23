# Data Types in C++
While writing program in any language, you need to use various variables to store various information. Variables are nothing but reserved memory locations to store values. This means that when you create a variable you reserve some space in memory.

You may like to store information of various data types like character, wide character, integer, floating point, double floating point, boolean etc. Based on the data type of a variable, the operating system allocates memory and decides what can be stored in the reserved memory.
Data Types in C++ are Mainly Divided into 3 Types: 
## Primitive Built-in Types
C++ offers the programmer a rich assortment of built-in as well as user defined data types. Following table lists down seven basic C++ data types −
| Type | Keyword |
| --- | --- |
| Boolean | bool |
| Character | char |
| Integer | int |
| Floating point | float |
| Double floating point | double |
| Valueless | void |
| Wide character | wchar_t |

Several of the basic types can be modified using one or more of these type modifiers −
* signed
* unsigned
* short
* long

### Example
The size of variables might be different from those shown in the above table, depending on the compiler and the computer you are using.
```
// C++ Program to Demonstrate the correct size
// of various data types on your computer.
#include <iostream>
using namespace std;

int main()
{
    cout << "Size of char : " << sizeof(char) << endl;
    cout << "Size of int : " << sizeof(int) << endl;

    cout << "Size of long : " << sizeof(long) << endl;
    cout << "Size of float : " << sizeof(float) << endl;

    cout << "Size of double : " << sizeof(double) << endl;

    return 0;
}
```
### Output
```
Size of char : 1
Size of int : 4
Size of long : 8
Size of float : 4
Size of double : 8
```
## Derived Data Types
Derived data types that are derived from the primitive or built-in datatypes are referred to as Derived Data Types. These can be of four types namely: 
* Function
* Array
* Pointer
* Reference

## Abstract or User-Defined Data Types 
Abstract or User-Defined data types are defined by the user itself. Like, defining a class in C++ or a structure. C++ provides the following user-defined datatypes:  
* Class
* Structure
* Union
* Enumeration
* Typedef defined Datatype

## Resources:
https://www.geeksforgeeks.org/cpp-data-types/

https://www.w3schools.com/cpp/cpp_data_types.asp
