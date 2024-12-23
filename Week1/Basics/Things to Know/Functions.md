# Functions
A function is a set of statements that takes input, does some specific computation, and produces output. The idea is to put some commonly or repeatedly done tasks together to make a function so that instead of writing the same code again and again for different inputs, we can call this function.
In simple terms, a function is a block of code that runs only when it is called.

## Syntax
```
return_type function_name(parameters) {
    // Function body
    return value;
}
```
* return_type: Specifies the type of value the function returns (e.g., int, void, etc.).
* function_name: The name of the function.
* parameters: A list of inputs the function accepts.
* Function body: Contains the code to execute.

## Types of Function
### User Defined Function
User-defined functions are user/customer-defined blocks of code specially customized to reduce the complexity of big programs. They are also commonly known as “tailor-made functions” which are built only to satisfy the condition in which the user is facing issues meanwhile reducing the complexity of the whole program.

### Library Function
Library functions are also called “built-in Functions“. These functions are part of a compiler package that is already defined and consists of a special function with special and different meanings. Built-in Function gives us an edge as we can directly use them without defining them whereas in the user-defined function we have to declare and define a function before using them. 
For Example: sqrt(), setw(), strcat(), etc.

## Parameter Passing to Functions
The parameters passed to the function are called actual parameters. For example, in the program below, 5 and 10 are actual parameters. 
The parameters received by the function are called formal parameters. For example, in the above program x and y are formal parameters.
![image](https://github.com/user-attachments/assets/8d3c32df-ea3c-4cd7-9632-a01422df081c)

There are two most popular ways to pass parameters:

Pass by Value: In this parameter passing method, values of actual parameters are copied to the function’s formal parameters. The actual and formal parameters are stored in different memory locations so any changes made in the functions are not reflected in the actual parameters of the caller. 
 
Pass by Reference: Both actual and formal parameters refer to the same locations, so any changes made inside the function are reflected in the actual parameters of the caller.

## Resources
https://www.geeksforgeeks.org/functions-in-cpp/

https://www.w3schools.com/cpp/cpp_functions.asp





