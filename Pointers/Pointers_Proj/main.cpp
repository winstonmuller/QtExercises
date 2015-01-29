#include <string>
#include <iostream>

using namespace std;

class Person
{
public:
    Person();
    ~Person();
    
    void SetName(string Name);
    string GetName();
private:
    string _personName;
};

Person::Person(){}
Person::~Person(){}

void Person::SetName(string const Name)
{
    _personName = Name;
}

string Person::GetName()
{
    return  _personName;
}

int main()
{
    //  Declare x, a plain old variable
    int x = 100;
    
    cout << "x " << x << endl;  // Value of x is 100

    //  1. Pointer Declaration: * - when used in variable declaration, before variable name, indicates a pointer variable.
    //  Declare a pointer variable, y (variable to store memory locations)
    int* y; 
    
    //  2. Address of Operator: &
    //  When used in assignment, before a variable name, returns the memory address of the variable
    y = &x;

    // In this case, y is not an integer variable. Rather, it is a pointer to an integer variable 
    // The following line returns a memory address, not an integer value
    cout << "y " << y << endl;

    //  3. Dereferencing Operator: * - when used in front of an existing pointer variable, returns the value of the memory location the pointer
    //  points to. int pointer will return an int, MyClass will return MyClass etc. cout << *y; // outputs the value of y
    cout << "*y " << *y << endl;

    //  The derefercing operator can also be used to change the data in the memory location.
	*y = 45;
	
	cout << "*y " << *y << endl;
	cout << "x " << x << endl;
	
    //  Pointers and Classes
    //  4. Dynamic Variables: Variables that are created during program execution are called dynamic variables.
    //  Dynamic variables are created with the "new" keyword.
    
    //  5. new DataType; - allocate memory for a single variable
    Person *Tom = new Person();
    
    //  6. Member Access Operator Arrow: -> 
    //  Simplifies accessing of class members via pointer.
    //  Class members can also be access via the dereference operator but this is more clumsy because brackets are required
    //  , i.e. (*Tom).GetName();
    Tom->SetName("Tom Tomoson");
    cout << "Address of Tom: " << Tom->GetName() << endl;
    
    //  7. Null Pointer: p = 0 - Sets the value of p to the null pointer if p is a pointer type.
    Tom = 0;
    cout << "Never attempt to dereference a null pointer" << endl;
    
    //  8. new DataType[intExp]; allocate an array of variables
    
    return 0;
}

