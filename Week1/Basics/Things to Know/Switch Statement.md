# Switch statement in C++
In C++, the switch statement is a flow control statement that is used to execute the different blocks of statements based on the value of the given expression. It is an alternative to the long if-else-if ladder which provides an easy way to execute different parts of code based on the value of the expression.

Let’s take a look at an example:
```
#include <iostream>
using namespace std;

int main() {
      
    // Variable to the used as switch expression
    char x = 'A';

    // Switch statement with three cases
    switch (x) {
    case 'A':
        cout << "A";
        break;
    case 'B':
        cout << "B";
        break;
    default:
        cout << "Other than A and B";
        break;
    }
    return 0;
}
```
Output:
`A`
## Syntax
```
switch (expression) {
    case value_1:
        // statements_break.
        break;
    case value_2:
        // statements_2;
        break;
    …..
    …..
    default:
        // default_statements;
        break;
}
```
The default case is executed if none of the cases are matched.
The break keyword in each case is used to break out of the switch statement after the matching case is found. Otherwise, all the statements after the matching case will be executed.

## Rules of the switch Statement in C++
There are some rules that we need to follow when using switch statements in C++. They are as follows:

The case value must be either int or char type.

There can be any number of cases.

No duplicate case values are allowed.

Each statement of the case can have a break statement. It is optional.

The default Statement is also optional.
![image](https://github.com/user-attachments/assets/94d837ed-3151-4ea2-8c47-c072acb072e1)

## Example: Simple calculator using switch
```
#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {

    // Switch variable for operation choice
    char c;

    // Operands
    int x, y;

    cout << "Enter the two numbers: ";
    cin >> x >> y;

    cout << "Enter the Operator (+,-,*,/)\nEnter any other to "
            "exit\n";
    cin >> c;

    // switch case with operation for each operator
    switch (c) {
    case '+':
        cout << x << " + " << y << " = " << x + y << endl;
        break;

    case '-':
        cout << x << " - " << y << " = " << x - y << endl;
        break;

    case '*':
        cout << x << " * " << y << " = " << x * y << endl;
        break;
    case '/':
        cout << x << " / " << y << " = " << x / y << endl;
        break;
    default:
        printf("Exiting\n");
    }

    return 0;
}
```
## Resources:
https://www.geeksforgeeks.org/switch-statement-in-cpp/

https://takeuforward.org/switch-case/switch-case-statements/
