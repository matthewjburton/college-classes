// This program is intended to investigate the properties of passing by value-result in C++
#include <iostream>
using namespace std;

int subInt(int integer) // declaring a subroutine which takes in an integer parameter by value and returns the result
{
    integer = 0; // alter the value
    return integer;
}

float subFloat(float floating) // declaring a subroutine which takes in a float parameter by value and returns the result
{
    floating = 0.0; // alter the value
    return floating;
}

bool subBool(bool boolean) // declaring a subroutine which takes in a boolean parameter by value and returns the result
{
    boolean = false; // alter the value
    return boolean;
}

char subChar(char character) // declaring a subroutine which takes in a char parameter by value and returns the result
{
    character = 'z'; // alter the value
    return character;
}

void subArray (int array[], const int size) // declaring a subroutine which takes in an integer array parameter by value and returns the result
{
    for (int i = 0; i < size; i++)
    {
        array[i] = 1;
    }
}

void outArray(const int array[], const int size) // utility function for outputting the values in an array
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i];
        if (i < size)
            cout << " ";
    }
    cout << endl;
}

int main () {
    // Declare multiple variables with initial values
    int integer = 1;
    float floating = 1.0;
    bool boolean = true;
    char character = 'a';
    // Declare multiple arrays of different sizes
    int smallSize = 5;
    int smallArray[smallSize] = {0};
    int largeSize = 50;
    int largeArray[largeSize] = {0};

    // Display the value of each test before and after being passed into their respective subroutines
    cout << "Integer\n=======" << endl;
    cout << "before: " << integer << endl;
    integer = subInt(integer);
    cout << " after: " << integer << endl;

    cout << "\nFloat\n=====" << endl;
    cout << "before: " << floating << endl;
    floating = subFloat(floating);
    cout << " after: " << floating << endl;

    cout << "\nBoolean\n=======" << endl;
    cout << "before: " << boolean << endl;
    boolean = subBool(boolean);
    cout << " after: " << boolean << endl;

    cout << "\nCharacter\n=========" << endl;
    cout << "before: " << character << endl;
    character = subChar(character);
    cout << " after: " << character << endl;

    cout << "\nSmall Array\n===========" << endl;
    cout << "before: "; outArray(smallArray, smallSize);
    subArray(smallArray, smallSize);
    cout << " after: "; outArray(smallArray, smallSize);

    cout << "\nLarge Array\n===========" << endl;
    cout << "before: "; outArray(largeArray, largeSize);
    subArray(largeArray, largeSize);
    cout << " after: "; outArray(largeArray, largeSize);
}