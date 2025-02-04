# Conventions

This file outlines the conventions of the project, including the *writing and code* ones.

## Writing Conventions

**All documentations** have to be written in **proper English**.

- **All the folders** have to be named in **PascalCase**.

❌

```md
./folder
./some_Folders
```

✅

```md
./Folder
./SomeFolders
```

- **All the files** have to be named in **camelCase**.

❌

```md
./File
./Another-file
```

✅

```md
./file
./anotherFile
```

- **All the parts' title** have to be named in **PascalCase**, with spaces.

❌

```md
## part
## the-Other-Part
```

✅

```md
## Part
## The Other Part
```

### Commits Conventions

- **All the commits** have to be named regarding what changes have been done.

❌

```md
Updated functionalSpecifications.md
done check algo
```

✅

```md
Added requirements part
Implemented the checking algorithm
```

- **All the commits** have to contain a proper description regarding what changes have been done.

❌

```md
the algo is done
```

✅

```md
The requirements part has been added to the functional specifications. The glossary has been updated too.

The checking algorithm has been implemented into the code base. It returns the expected time to the main program.
```

---

## Code Conventions

- **All the classes** have to be named in **PascalCase**.

❌

```c++
class the_class;
class anotherClass;
```

✅

```c++
class MainClass;
class AnotherClass;
```

- **All the functions** have to be named in **camelCase**.

❌

```c++
int MAIN(){}
int Function(){}
```

✅

```c++
int main(){}
int anotherFunction(){}
```

- **All the variables** have to be named in **snake_case**.

❌

```c++
int VAr;
std::string Second_VAR = "Hello";
```

✅

```c++
int var = 1;
std::string second_var = "Hello";
```

- Although, the **constants** have to be written in **UPPER_SNAKE_CASE**.

❌

```c++
const int constant = 1;
std::string Second_Constant = "Hello";
```

✅

```c++
const int CONSTANT = 1;
std::string SECOND_CONSTANT = "Hello";
```

- **Some comments** have to be written within the code base, outlining what a class or a function should do. **All the comments** have to be written to serve specific purposes. Software Engineers have to avoid writing useless comments.

❌

```c++
// initializing an integer variable called var to 1
int var = 1;
```

```c++
// this function returns if a number is even or not
bool isEven(int number){
    return number % 2; // returns if the number is even or not by using modulo
}
```

✅

```c++
int var = 1;
```

```c++
/*
    Checks whether a specific number is even
    This function returns a boolean (true if even, false if odd)

    Parameters:
        - number, integer as the number to check
*/
bool isEven(int number){
    return number % 2;
}
```

- **Classes** must be initialized in a dedicated header file, named with their class name. Defining classes, data should be **encapsulated**. Every variable of a class will be declared as *private*, and some methods will be declared as *public*. The public methods of a class can manipulate private data. This prevents end users from directly accessing sensitive information. In creating an object of a class, a **constructor** must be called. It is named with its class name, and allocates data as soon as the object is created. A **destructor** should also be defined.
- Once defined in a header file, the methods' functionalities should be set in a dedicated file.

`student.hpp`

```c++
class Student 
{
    // protected data 
    private: 
        std::string name;
        int age;
        int year_of_enrolment;

    // accessible data
    public:
        /* 
            Constructor of the class
            Sets given data as soon as the child is created

            Parameters: 
                - id1 (constant integer)
                - id2 (constant integer)
                - time (constant integer)
        */
        Student(const string given_name, const int given_age, const int given_year_of_enrolment);

        /* 
            Destructor of the class
        */
        ~Student() = default;

        // other public methods...
}
```

`student.cpp`

```c++
#include "student.hpp"

Student::Student(const string given_name, const int given_age, const int given_year_of_enrolment)
{
    this->name = given_name;
    this->age = given_age;
    this->year_of_enrolment = given_year_of_enrolment;
}
```
