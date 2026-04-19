#include <iostream>     // Include standard Input-Output stream library
#include <conio.h>      // include to use to clear screen
#include <fstream>      // Includes the file stream library for file and work with CSV
#include "employees.h"  // include all function from header file

using namespace std;

int main() {
    //Method to set color on character, and 3 represent of blue
    system("color 3");
    // Create list to store employee (Empty list)
    List_Employee *List = createEmptyList();


    //Make menu for user
    int option;
    // Call function to read all memu that we work
    readFileCSV(List);
    do {
        // Display memu
        cout << "\n\t\t\t---------------------------------------------------------";
        cout << "\n\t\t\t||               EMPLOYEE MANAGEMENT SYSTEM            ||";
        cout << "\n\t\t\t---------------------------------------------------------\n";
        cout << "\n\t\t\t\t\t [1]- Insert employee.\n";
        cout << "\n\t\t\t\t\t [2]- Search employee.\n";
        cout << "\n\t\t\t\t\t [3]- Delete employee.\n";
        cout << "\n\t\t\t\t\t [4]- Display employee.\n";
        cout << "\n\t\t\t\t\t [5]- Update information of employee.\n";
        cout << "\n\t\t\t\t\t [0]- Exit.\n";
        cout << "\n\t\t\t\t\t Please enter your choice: ";
        cin >> option;
        cin.ignore(); // This can handle newline character

        switch(option) {
            case 1: {
                char choice;
                string first_name, last_name, id, gender, designation, email;
                int age;
                float salary;
                cout << "\n\t\t\t\t  --------------------------------------" << endl;
                cout << "\t\t\t\t  ----->>GET EMPLOYEE INFORMATION<<-----"<< endl;
                cout << "\t\t\t\t  --------------------------------------" << endl;

                cout << "\t\t\t\t\t Enter first name: ";
                getline(cin, first_name);
                cout << "\t\t\t\t\t Enter last name: ";
                getline(cin, last_name);
                cout << "\t\t\t\t\t Enter ID: ";
                getline(cin, id);
                cout << "\t\t\t\t\t Enter gender: ";
                getline(cin, gender);
                cout << "\t\t\t\t\t Enter age: ";
                cin >> age;
                cin.ignore();
                cout << "\t\t\t\t\t Enter designation: ";
                getline(cin, designation);
                cout << "\t\t\t\t\t Enter email: ";
                getline(cin, email);
                cout << "\t\t\t\t\t Enter salary: ";
                cin >> salary;
                cin.ignore();

                cout << "\n\t\t\t\t  Where do you want to add the employee?\n";
                cout << "\n\t\t\t\t\t[B]- Beginning / [E]- End \n";
                cout << "\n\t\t\t\t\t Enter: ";
                cin >> choice;
                cin.ignore();
                if (choice == 'B' || choice == 'b') {
                    //Call function from "employees.h" to add employee to begin
                    addEmployeToBegin(List, first_name, last_name, id, gender, age, designation, email, salary);

                    //Pop up message to tell user that information has been stored
                    cout << "\t\t\t=========================================================" << endl;
                    cout << "\t\t\t||>>>----Information has been stored to CSV file----<<<||" << endl;
                    cout << "\t\t\t=========================================================" << endl;
                } else if (choice == 'E' || choice == 'e') {
                    //Call function from "employees.h" to add employee to end
                    addEmployeToEnd(List, first_name, last_name, id, gender, age, designation, email, salary);

                    // Pop up message to tell user that information has been stored
                    cout << "\t\t\t=========================================================" << endl;
                    cout << "\t\t\t||>>>----Information has been stored to CSV file----<<<||" << endl;
                    cout << "\t\t\t=========================================================" << endl;
                } else {
                    cout << "\n\t\t\t\t Invalid option!";
                }
                break;
            }
            case 2: {
                char choice;
                string searchTarget;
                cout << "\n\t\t\t\t\t [A]- Search by name.\n";
                cout << "\n\t\t\t\t\t [B]- Search by ID.\n";
                cout << "\n\t\t\t\t\t Please enter your choice: ";
                cin >> choice;
                cin.ignore();
                if (choice == 'A' || choice == 'a') {
                    cout << "\n\t\t\t\t\t Enter the full name: ";
                    getline(cin, searchTarget);
                    //Call function from "employees.h" to search employee in list by using name
                    searchEmployee_ByName(List, searchTarget);
                } else if (choice == 'B' || choice == 'b') {
                    cout << "\n\t\t\t\t\t Enter the ID: ";
                    getline(cin, searchTarget);
                    //Call function from "employees.h" to search employee in list by using id
                    searchEmployee_ById(List, searchTarget);
                } else {
                    cout << "\n\t\t\t\t\t Invalid option!";
                }
                break;
            }
            case 3: {
                char choose_delete;
                string target_id;
                cout << "\n\t\t\t\t [A]- Delete employee from begin of the list.\n";
                cout << "\n\t\t\t\t [B]- Delete employee from end of the list.\n";
                cout << "\n\t\t\t\t [C]- Delete employee from by ID.\n";
                cout << "\n\t\t\t\t Enter your choice: ";
                cin >> choose_delete;

                if(choose_delete == 'a' || choose_delete == 'A'){
                    //Call function from "employees.h" to remove employee from the begin of the list
                    Remove_Employee_Begin(List);
                }
                else if(choose_delete == 'b' || choose_delete == 'B'){
                    //Call function from "employees.h" to remove employee from the end of the list
                    Remove_Employee_End(List);
                }else if(choose_delete == 'c' || choose_delete == 'C'){
                    cout<<"\n\t\t\t\t Enter employee's ID to delete: ";
                    cin>>target_id;
                    //Call function from "employees.h" to remove who user want to delete by using employee's ID
                    Remove_Employee_ById(List, target_id);
                }

                //After delete call function to update new list
                WriteTo_CSVfile(List, "employee.csv");
                break;
            }

            case 4: {
                char choose_display;
                cout << "\n\t\t\t\t [A]- Display employee from begin of the list.\n";
                cout << "\n\t\t\t\t [B]- Display employee from end of the list.\n";
                cout << "\n\t\t\t\t Enter your choice: ";
                cin >> choose_display;

                if(choose_display == 'a' || choose_display == 'A'){
                    //Call function from "employees.h" to display employee from begin
                    displayList_Begin(List);
                }
                else if(choose_display == 'b' || choose_display == 'b'){
                    //Call function from "employees.h" to display employee from end
                    displayList_End(List);
                }
                else{
                    cout << "\n\t\t\t\t Invalid choose!";
                }
                break;
            }
            case 5: {
                    string id;
                    cout << "\n\t\t\t\t\t Enter employee Id to update: ";
                    cin >> id;
                    //After get ID call function from "employees.h" to update new information
                    updateEmployeeById(List, id);
                    //After update call function to update new list
                    WriteTo_CSVfile(List, "employee.csv");
                break;
            }
            case 0:
                // Call function to save all data to CSV file before exit
                WriteTo_CSVfile(List, "employee.csv");
                cout << "\n\t\t\t\t\t Exiting Employee Management System.\n";
                break;
            default:
                cout << "\n\t\t\t\t\t Invalid option! Please try again.\n";
        }
    } while (option != 0);      //If option equal to zero then program will stop

    return 0;
}


