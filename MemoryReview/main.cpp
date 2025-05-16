#include <iostream>
using namespace std;

struct Person
{
	char name[32];
	int id;
};

void Square(int& i) {
	i *= i;
}

void Double(int *i) {
	*i *= 2;
}

int main()
{
	// ** REFERENCE **
	// 
	// declare an int variable and set the value to some number (less than 10)
	// declare a int reference and set it to the int variable above
  int value = 0;
  int& value_ref = value;

	// output the int variable
  std::cout << value << '\n';

	// set the int reference to some number
	// output the int variable

  value_ref = 5;
  std::cout << value << '\n';

	// what happened to the int variable when the reference was changed? (insert answer)
	// ANSWER: the int variable was modified through the int& alias from 0 to 5

	// output the address of the int variable
	// output the address of the int reference

	std::cout << &value << " | " << &value_ref << '\n';

	// are the addresses the same or different? (insert answer)
	// ANSWER: The addresses are the same

	// ** REFERENCE PARAMETER **
	//
	// create a function above main() called Square that takes in an int parameter
	// in the function, multiply the int parameter by itself and assign it back to the parameter (i = i * i)
	// call the Square function with the int variable created in the REFERENCE section

	// output the int variable to the console
	Square(value);
	std::cout << value << '\n';

	// !! notice how the variable has not changed, this is because we only passed the value to the function !!
	// change the Square function to take a int reference
	// !! notice how the calling variable has now changed, this is because we 'passed by reference' !!
	// !! when a function takes a reference parameter, any changes to the parameter changes the calling variable ""

	// ** POINTER VARIABLE **
	// 
	// declare an int pointer, set it to nullptr (it points to nothing)
	// set the int pointer to the address of the int variable created in the REFERENCE section

	int *value_ptr = nullptr;
	value_ptr = &value;

	// output the value of the pointer

	std::cout << value_ptr << '\n';
	
	// what is this address that the pointer is pointing to? (insert answer)
	// ANSWER: The address the pointer is pointing to is the memory address of the "value" variable
	
	// output the value of the object the pointer is pointing to (dereference the pointer)
	std::cout << *value_ptr << '\n';

	// ** POINTER PARAMETER **
	//
	// create a function above main() called Double that takes in an int pointer parameter
	// in the function, multiply the int pointer parameter by 2 and assign it back to the parameter (i = i * 2)
	// !! make sure to dereference the pointer to set the value and not set the address !!
	// call the Double function with the pointer created in the POINTER VARIABLE section

	Double(value_ptr);
	
	// output the dereference pointer
	// output the int variable created in the REFERENCE section
	std::cout << *value_ptr << '\n';

	// did the int variable's value change when using the pointer?
	// ANSWER: Yes, it did change when using a pointer
}


