#include <iostream>
#include "KeyValuePair.h"
/*
Exercise 12-1: Write a KeyValuePair class template with two template type parameters: Key
and Value. The class should have two private data members to store a key and a value. Pro-
vide a constructor accepting a key and a value, and add appropriate getters and setters. Test
your class by creating a few instantiations in your main() function and try class template
argument deduction.

Exercise 12-2: The KeyValuePair class template from Exercise 12-1 supports all kind of data
types for both its key and value template type parameters. For example, the following instan-
tiates the class template with std::string as the type for both the key and the value:
KeyValuePair<std::string, std::string> kv { "John Doe", "New York" };
However, using const char* as the type will result in data members of type const char*,
which is not what we want.
Write a class template specialization for const char* keys and values that converts the given
strings to std::strings.

Exercise 12-3: Take your solution from Exercise 12-1 and make the appropriate changes to
only allow integer types as the type of the key and only floating-point types as the type of
the value.*/


int main(int argc, char* argv[])
{
    KeyValuePair pair{10,40.4};

    std::cout << " Key: "   << pair.GetKey()
              << " Value: " << pair.GetValue();
    
    pair.SetValue(100.33);

    std::cout << " Key: "   << pair.GetKey()
              << " Value: " << pair.GetValue();


    return 0;
}