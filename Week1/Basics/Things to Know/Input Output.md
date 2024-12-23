# C++ Input/Output Basics #

## Understanding the Core ##
A C++ program typically consists of two main components:
### Library Inclusion:
C++ relies on libraries to access various functionalities.
For input/output operations, we commonly include the <iostream> library:
```
#include <iostream>
```
### Main Function:

The main() function serves as the entry point of the program.
It's where the execution begins.
```
int main() {
    // Your code here
    return 0;
}
```

## Outputting to the Console
Use `std::cout` to print text to the console:
 ```
std::cout << "Hello, World!" << std::endl;
```

```std::endl``` inserts a newline character and flushes the output buffer.
Taking Input from the User
Use std::cin to read input from the user:
 C++
int x;
std::cin >> x;
std::cout << "You entered: " << x << std::endl;


## Key Points:
Namespace:
std:: is the standard namespace in C++.
To avoid repeatedly typing std::, you can use using namespace std; at the beginning of your program.
Data Types:
C++ supports various data types to store different kinds of data, such as int, float, double, char, and bool.
Formatting Output:
You can format output using manipulators like std::setw, std::setprecision, and std::fixed.
Example: A Simple Calculator
```
#include <iostream>

using namespace std;

int main() {
    int num1, num2;
    char operation;

    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    cout << "Enter an operation (+, -, *, /): ";
    cin >> operation;

    switch (operation) {
        case '+':
            cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
            break;
        // ... other cases for subtraction, multiplication, and division
        default:
            cout << "Invalid operation." << endl;
    }

    return 0;
}
```
## Additional Tips:
* Indentation: Use consistent indentation to improve code readability.
* Comments: Add comments to explain your code's logic.
* Error Handling: Consider using try-catch blocks to handle potential exceptions.
* Best Practices: Follow C++ coding standards and guidelines.
* By understanding these fundamental concepts, you can start building more complex C++ programs.

## Resources:
https://takeuforward.org/c/c-basic-input-output/
