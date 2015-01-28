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
    
/*
     1. Pointer Declaration: * - when used in variable declaration, before variable name, indicates a pointer variable.	int* y;
     2. Address of Operator: & - when used in assignment, before a variable name, returns the memory address of the variable	int* y = &x;
     
     3. Dereferencing Operator: * - when used in front of an existing pointer variable, returns the value of the memory location the pointer
        points to. int pointer will return an int, MyClass will return MyClass etc. cout << *y; // outputs the value of y
        
     4. Member Access Operator Arrow: -> - Simplifies accessing of class components via pointer. Tom->GetName();
     5. Null Pointer: p = 0 - Sets the value of p to the null pointer if p is a pointer type.
     
     6. Dynamic Variables: Variables that are created during program execution are called dynamic variables.
     
     7. new DataType; - allocate a single variable
     8. new DataType[intExp]; allocate an array of variables
*/
    
    //  Declare x, a plain old variable
    int x = 100;
    
    cout << "x " << x << endl;  // Value of x is 100

    //  We use * before a variable name to declare a pointer variable
    int* y; // Declare a pointer variable, y (variable to store memory locations)
    
    //  We can use the & character in front of a variable to get its memory address
    y = &x; // Set y equal to memory location of x

    // In this case, y is not an integer variable. Rather, it is a pointer to an integer variable 
    // The following line returns a memory address, not an integer value
    cout << "y " << y << endl;
    cout << "*y " << *y << endl;
    
	//	Because y refers to the memory location of x, changes to the content of y change x
	*y = 45;
	
	cout << "*y " << *y << endl;
	cout << "x " << x << endl;
	
    //  Pointers and Classes
    Person jim;
    
    jim.SetName("Jim Johnson");
    
    cout << jim.GetName() << endl;
    
    Person *Tom = new Person();
    Tom->SetName("Tom Tomoson");
    cout << "Address of Tom: " << Tom->GetName() << endl;
    
    Tom = 0;
    cout << "Attempting to dereference null pointer" << endl;
    
    return 0;
}

