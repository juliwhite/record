/*
These libraries will be available at compile time. 
Here to make the code function we need to implement 
a couple of libraries.
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

// The class Person will let us create an object for every name that is inserted.
class Person{
    // Every student will be assign wit a status.
    std::string status = "student";
    // We made every member in this class public, by default members in class are private. 
    public:
        std::string first_name;
        std::string get_status()
        {
            return status;
        }
};

/*
This function allows to insert unique names in our list of students. 
In the parameters we assign with "&", this is pass by reference to be able to change the vector
or we aren't going to be able to see it when vector is called outside the function.
*/ 
int add_person(std::vector<Person> &names, Person name)
{
    for(int i = 0; i < names.size(); i++)
    {
        if(names[i].first_name == name.first_name)
        {
            return i;
        }
    }
    names.push_back(name);
    return names.size() - 1;
}

/*
The function print_list() will print a list with all the students that had been 
inserted in the list. 
*/
void print_list(std::vector<Person> names)
{
    for(int i = 0; i < names.size(); i++)
    {
        std::cout << "\t" << names[i].first_name << std::endl;
    }
}

/*
Every c++ program must have a main function. This function is called 
implicitly every time we run our program.
The main function is type integer and it will return tipically 0..
*/
int main()
{
    // To store the option that the user will chose, we created an integer variable to store that input.
    int choice;
    std::string n;

    // We create a vector of the class Person. 
    std::vector<Person> names;
    
    // This do while loop will keep asking the user for an optin to choose. 
    do
    {
        std::cout << "\n";
        std::cout << "0. Quit.\n";
        std::cout << "1. Show list.\n";
        std::cout << "2. Add student to a list.\n";
        std::cout << "\n";
        std::cout << "Choose an option: "; 
        std::cin >> choice;

        // c++ supports a switch statement. Here the user will have a variaty of
        // option to choose to execute the program. 
        switch (choice)
        {
            case 0:
                std::cout << "Done.\n";
                break;
            case 1:
                std::cout << "List of students:\n";
                std::cout << "-----------------\n";
                print_list(names);
                break;
            case 2:
                std::cout << "Insert name: ";
                std::cin >> n; 
                Person name;
                name.first_name = n;
                add_person(names, name);
                break;
            //default:
                //break;
        }
    } while (choice != 0);

    return 0;
}
