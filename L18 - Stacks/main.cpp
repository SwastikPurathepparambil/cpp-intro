#include <iostream>
#include <stack>
using namespace std;

int main() {

    stack<int> numbers;
    cout << "Size of stack: " << numbers.size() << endl;

    if (numbers.empty()) {
        cout << "Empty Stack" << endl;
    }

    numbers.push(1);
    cout << "Size of stack: " << numbers.size() << endl;

    if (!numbers.empty()) {
        cout << "Not Empty Stack" << endl;
    }

    cout << "===============" << endl;
    cout << "Number at top of stack: " << numbers.top() << endl;
    numbers.push(2);
    numbers.push(3);
    cout << "Number at top of stack: " << numbers.top() << endl;
    numbers.pop(); //In C++, does not return value
    cout << "Popped top number off stack!" << endl;
    cout << "Number at top of stack: " << numbers.top() << endl;
    cout << "===============" << endl;

    stack<int> other_stack;
    other_stack.push(8);
    cout << "Size of stack -- numbers: " << numbers.size() << endl;
    cout << "Size of stack -- other_stack: " << other_stack.size() << endl;
    other_stack.swap(numbers);
    cout << "Size of stack -- numbers: " << numbers.size() << endl;
    cout << "Size of stack -- other_stack: " << other_stack.size() << endl;

    // Could also add your own classes and objects onto the stack
    // Watch here for video: https://www.youtube.com/watch?v=WEwD-ZuTc1w 10:05 onwards
    


    return 0;
}