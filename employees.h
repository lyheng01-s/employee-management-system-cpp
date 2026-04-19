#ifndef EMPLOYEES_H_INCLUDED
#define EMPLOYEES_H_INCLUDED

#include <iostream>    // Include standard Input-Output stream library
#include <sstream>    // header file,for string stream classes and functionality.
#include <fstream>   // Includes the file stream library for file and work with CSV.

using namespace std;

// Structure of Employee
struct Employee_management {
    string first_name;
    string last_name;
    string id;
    string gender;
    int age;
    string designation;
    string email;
    float salary;
    // Pointer to previous
    Employee_management *prev;
    // Pointer ti=o next
    Employee_management *next;
};


// Structure that represent list of emoloyee
struct List_Employee {
    // Let n represent number of nodes
    int n;
    Employee_management *head;
    Employee_management *tail;
};


// Create empty list
List_Employee *createEmptyList() {
    List_Employee *List = new List_Employee();
    List->n = 0;
    List->head = NULL;
    List->tail = NULL;
    return List;
}


// Function to check List empty or not
bool isEmpty(List_Employee *List){
    if(List->n == 0){
        cout << "\n\t\t\t---------------------------------------------------------" << endl;
        cout << "\t\t\t==================>>> LIST IS EMPTY <<<==================" << endl;
        cout << "\t\t\t============>>> There are no employee yet <<<============" << endl;
        cout << "\t\t\t---------------------------------------------------------" << endl;
        return true;
    }
    return false;
}

// Function to add Employee to begin of the list
void addEmployeToBegin(List_Employee *List, string first_name, string last_name, string id, string gender, int age, string designation, string email, float salary) {
    system("CLS");      //Clear screen
    Employee_management *newEmployee = new Employee_management();
    newEmployee->first_name = first_name;
    newEmployee->last_name = last_name;
    newEmployee->id = id;
    newEmployee->gender = gender;
    newEmployee->age = age;
    newEmployee->designation = designation;
    newEmployee->email = email;
    newEmployee->salary = salary;
    newEmployee->prev = NULL;
    newEmployee->next = List->head;

    if(List->n == 0) {
        List->tail = newEmployee;
    }
    if(List->n != 0) {
        List->head->prev = newEmployee;
    }
    List->head = newEmployee;
    List->n++;
}


// Function to add Employee to End of the list
void addEmployeToEnd(List_Employee *List, string first_name, string last_name, string id, string gender, int age, string designation, string email, float salary) {
    system("CLS");
    Employee_management *newEmployee = new Employee_management();
    newEmployee->first_name = first_name;
    newEmployee->last_name = last_name;
    newEmployee->id = id;
    newEmployee->gender = gender;
    newEmployee->age = age;
    newEmployee->designation = designation;
    newEmployee->email = email;
    newEmployee->salary = salary;
    newEmployee->next = NULL;
    newEmployee->prev = List->tail;

    if(List->n == 0) {
        List->head = newEmployee;
    }
    if(List->n != 0) {
        List->tail->next = newEmployee;
    }
    List->tail = newEmployee;
    List->n++;
}


// Function to search or find employee by using NAME
void searchEmployee_ByName(List_Employee *List, string target_Name) {
    system("CLS");
    if(isEmpty(List)){      //If it empty message to tell user
        return;
    }

    string first_name, last_name;
    istringstream iss(target_Name);
    iss >> first_name >> last_name;

    Employee_management *tmp = List->head;
    int found = false;

    while(tmp != NULL) {
        if(tmp->first_name == first_name && tmp->last_name == last_name) {
            cout << "\n||==================================================================================================================||";
            cout << "\n||>>>>----------------------------------------EMPLOYEE INFORMATION LIST-----------------------------------------<<<<||";
            cout << "\n||==================================================================================================================||";
            cout << "\n----------------------------------------------------------------------------------------------------------------------";
            cout << "\n||      FULLNAME      ||     ID      ||  GENDER  ||    AGE    ||    DESIGNATION    ||       EMAIL       ||  SALARY  ||";
            cout << "\n||==================================================================================================================||";
            cout << "\n\t" << tmp->first_name << " " << tmp->last_name << "\t  " << tmp->id << "\t  " << tmp->gender << "\t\t" << tmp->age << "\t    " << tmp->designation << "\t\t" << tmp->email << "\t   " << tmp->salary << endl;
            found = true;
            break;
        }
        tmp = tmp->next;
    }
    cout << "\n----------------------------------------------------------------------------------------------------------------------";

    if (!found) {
        cout << "\n\t\t\t\t\tEmployee with name >|" << target_Name << "|< not found!";
        cout << "\n----------------------------------------------------------------------------------------------------------------------";
    }
}


// Function to search or find employee by using ID
void searchEmployee_ById(List_Employee *List, string target_Id) {
    system("CLS");
    if(isEmpty(List)){      //If it empty message to tell user
        return;
    }

    Employee_management *tmp = List->tail;
    int found = false;

    while(tmp != NULL) {
        if(tmp->id == target_Id) {
            cout << "\n||==================================================================================================================||";
            cout << "\n||>>>>----------------------------------------EMPLOYEE INFORMATION LIST-----------------------------------------<<<<||";
            cout << "\n||==================================================================================================================||";
            cout << "\n----------------------------------------------------------------------------------------------------------------------";
            cout << "\n||      FULLNAME      ||     ID      ||  GENDER  ||    AGE    ||    DESIGNATION    ||       EMAIL       ||  SALARY  ||";
            cout << "\n||==================================================================================================================||";
            cout << "\n\t" << tmp->first_name << " " << tmp->last_name << "\t  " << tmp->id << "\t  " << tmp->gender << "\t\t" << tmp->age << "\t    " << tmp->designation << "\t\t" << tmp->email << "\t   " << tmp->salary << endl;
            found = true;
            break;
        }
        tmp = tmp->prev;
    }
    cout << "\n----------------------------------------------------------------------------------------------------------------------";

    if (!found) {
        cout << "\n\t\t\t\t\tEmployee with ID |" << target_Id << " not found!";
        cout << "\n----------------------------------------------------------------------------------------------------------------------";
    }
}


// Function to delete employee from the begin of the list
void Remove_Employee_Begin(List_Employee *List) {
    system("CLS");
    if(isEmpty(List)){      //If it empty message to tell user
        return;
    }

    Employee_management *tmp;
    tmp = List->head;

    if(List->n == 1){
        List->head = NULL;
        List->tail = NULL;
    }
    else{
        List->head = tmp->next;
        if(List->head != NULL){
            List->head->prev = NULL;
        }
    }
    delete tmp;
    List->n = List->n - 1;  // Decrease number of node by 1

    cout << "\n\t\t\t||******************************************************||";
    cout << "\n\t\t\t||>>>---- EMPLOYEE HAS BEEN DELETE FROM CSV FILE ----<<<||";
    cout << "\n\t\t\t||******************************************************||";
}


// Function to delete employee from the End of the list
void Remove_Employee_End(List_Employee *List) {
    system("CLS");
    if(isEmpty(List)){      //If it empty message to tell user
        return;
    }

    Employee_management *tmp;
    tmp = List->tail;

    List->tail = List->tail->prev;
    if(List->tail != NULL) {
        List->tail->next = NULL;
    }
    else{
        List->head = NULL;
    }
    delete tmp;
    List->n = List->n - 1;  // Decrease number of node by 1

    // Pop up message to tell user that information has been deleted
    cout << "\n\t\t\t||******************************************************||";
    cout << "\n\t\t\t||>>>---- EMPLOYEE HAS BEEN DELETE FROM CSV FILE ----<<<||";
    cout << "\n\t\t\t||******************************************************||";
}


// Function to delete which employee by using ID to find employee, then delete
void Remove_Employee_ById(List_Employee *List, string target_id) {
    system("CLS");
    if(isEmpty(List)){      //If it empty message to tell user
        return;
    }
    int found = false;
    Employee_management *tmp = List->head;

     //If have only one employee and id correct with target id call Remove_Employee_Begin
    if(List->n == 1 && tmp->id == target_id){
        Remove_Employee_Begin(List);
        return;
    }

    while(tmp != NULL){
        if(tmp->id == target_id){
            //update previous and next
            if(tmp->prev != NULL){
                tmp->prev->next = tmp->next;
            }
            else{
                List->head = tmp->next;
            }
            if(tmp->next != NULL){
                tmp->next->prev = tmp->prev;
            }
            else{
                List->tail = tmp->prev;
            }
            delete tmp;
            found = true;
            List->n = List->n - 1;

            cout << "\n\t\t\t||******************************************************||";
            cout << "\n\t\t\t||>>>---- EMPLOYEE HAS BEEN DELETE FROM CSV FILE ----<<<||";
            cout << "\n\t\t\t||******************************************************||";
            break;
        }
        tmp = tmp->next;
    }
    if(!found){
        cout<<"\n\t\t\t\t=====Employee with ID "<<target_id<<"not found=====!"<<endl;
    }
}


// Function to update new infomation which employee by using ID to find employee, then update
void updateEmployeeById(List_Employee *List, string target_Id) {
    system("CLS");
    if (isEmpty(List)) {        //If it empty message to tell user
        return;
    }

    Employee_management *tmp = List->head;
    int found = false;

    while (tmp != NULL) {
        if (tmp->id == target_Id) {
            found = true;
            char choice;
            string input;
            char updateMore;
            cout << "\t\t\t\t\t=========================================================" << endl;
            cout << "\t\t\t\t\t|>>>>>>>>----------- EMPLOYEE FOUND -----------<<<<<<<<<|" << endl;
            cout << "\t\t\t\t\t=========================================================" << endl;
            cout << "\n\t|--------------------------------------------------------------------------------------------------------------------|";
            cout << "\n\t|=================================<<<What information would you like to update?>>>===================================|";
            cout << "\n\t|--------------------------------------------------------------------------------------------------------------------|";
            cout << "\n\t|| [1]-First Name || [2]-Last Name || [3]-ID || [4]-Gender || [5]-Age || [6]-Designation || [7]-Email || [8]-Salary ||";
            cout << "\n\t|--------------------------------------------------------------------------------------------------------------------|";

            do {
                cout << "\n\t\t\t\t\t\tEnter your choice: ";
                cin >> choice;
                cin.ignore(); // To clear the newline character from input buffer

                // Give choice to user whether which one user want to update like name, id, salary....
                switch (choice) {
                    case '1':
                        cout << "\t\tCurrent First Name: " << tmp->first_name << "\n\t\tNew First Name: ";
                        getline(cin, input);
                        tmp->first_name = input;
                        break;
                    case '2':
                        cout << "\t\tCurrent Last Name: " << tmp->last_name << "\n\t\tNew Last Name: ";
                        getline(cin, input);
                        tmp->last_name = input;
                        break;
                    case '3':
                        cout << "\t\tCurrent ID: " << tmp->id << "\n\t\tNew ID: ";
                        getline(cin, input);
                        tmp->id = input;
                        break;
                    case '4':
                        cout << "\t\tCurrent Gender: " << tmp->gender << "\n\t\tNew Gender: ";
                        getline(cin, input);
                        tmp->gender = input;
                        break;
                    case '5':
                        cout << "\t\tCurrent Age: " << tmp->age << "\n\t\tNew Age: ";
                        getline(cin, input);
                        tmp->age = stoi(input);
                        break;
                    case '6':
                        cout << "\t\tCurrent Department: " << tmp->designation << "\n\t\tNew Department: ";
                        getline(cin, input);
                        tmp->designation = input;
                        break;
                    case '7':
                        cout << "\t\tCurrent Email: " << tmp->email << "\n\t\tNew Email: ";
                        getline(cin, input);
                        tmp->email = input;
                        break;
                    case '8':
                        cout << "\t\tCurrent Salary: " << tmp->salary << "\n\t\tNew Salary: ";
                        getline(cin, input);
                        tmp->salary = stof(input);
                        break;
                    default:
                        cout << "\t\tInvalid choice. Please try again.\n";
                        break;
                }

                //Use do while loop to ensure user input Y or N and for another key it will work to ask again
                do {
                    cout << "\t\tEnter [Y]: to update more information || Enter [N]: To stop updating\n";
                    cout << "\t\tEnter: ";
                    cin >> updateMore;

                    if(toupper(updateMore) == 'N') {
                        break;
                    } else if (toupper(updateMore) != 'Y') {
                        cout << "\t\tInvalid choice. Please enter [Y] or [N]." << endl;
                    }
                    cin.ignore(); // Clear the input
                } while (toupper(updateMore) != 'Y' && toupper(updateMore) != 'N');


            } while (toupper(updateMore) == 'Y');

            cout << "\n\t\t\t=========================================================";
            cout << "\n\t\t\t||>>>>>>>>>>>>> EMPLOYEE INFORMATION UPDATED <<<<<<<<<<||";
            cout << "\n\t\t\t=========================================================\n";
            break;
        }
        tmp = tmp->next;
    }

    if (!found) {
        cout << "\t\t\t\t\tEmployee with ID " << target_Id << " not found!\n";
    }
}


// Function to display list of employee from Begin
void displayList_Begin(List_Employee *List) {
    system("CLS");

    if(isEmpty(List)){
        return;
    } else {
        cout << "\n||==================================================================================================================||";
        cout << "\n||>>>>----------------------------------------EMPLOYEE INFORMATION LIST-----------------------------------------<<<<||";
        cout << "\n||==================================================================================================================||";
        cout << "\n----------------------------------------------------------------------------------------------------------------------";
        cout << "\n||      FULLNAME      ||     ID      ||  GENDER  ||    AGE    ||    DESIGNATION    ||       EMAIL       ||  SALARY  ||";
        cout << "\n||==================================================================================================================||";

        Employee_management *tmp = List->head;
        while(tmp != NULL) {
            cout << "\n\t" << tmp->first_name << " " << tmp->last_name << "\t  " << tmp->id << "\t  " << tmp->gender << "\t\t" << tmp->age << "\t    " << tmp->designation << "\t\t" << tmp->email << "\t    " << tmp->salary << endl;
            tmp = tmp->next;
        }
        cout << "\n---------------------------------------------------------------------------------------------------------------------";
    }
}


// Function to display list of employee from End
void displayList_End(List_Employee *List) {
    system("CLS");
    if(isEmpty(List)){
        return;
    } else {
        Employee_management *tmp = List->tail;
        cout << "\n||==================================================================================================================||";
        cout << "\n||>>>>----------------------------------------EMPLOYEE INFORMATION LIST-----------------------------------------<<<<||";
        cout << "\n||==================================================================================================================||";
        cout << "\n----------------------------------------------------------------------------------------------------------------------";
        cout << "\n||      FULLNAME      ||     ID      ||  GENDER  ||    AGE    ||    DESIGNATION    ||       EMAIL       ||  SALARY  ||";
        cout << "\n||==================================================================================================================||";

        while(tmp != NULL) {
            cout << "\n\t" << tmp->first_name << " " << tmp->last_name << "\t  " << tmp->id << "\t  " << tmp->gender << "\t\t" << tmp->age << "\t    " << tmp->designation << "\t\t" << tmp->email << "\t    " << tmp->salary << endl;
            tmp = tmp->prev;
        }
        cout << "\n----------------------------------------------------------------------------------------------------------------------";
    }
}


// Function to write all information of employee to CSV file
void WriteTo_CSVfile(List_Employee *List, string Name_EmployeeFile){
    ofstream file(Name_EmployeeFile);
    if(file.is_open()){

        //Write name id age.... to header file or first line
        file << "Full Name,ID,Gender,Age,Designation,Email,Salary" << endl;

        Employee_management *tmp = List->head;
        while(tmp != NULL){
            string Full_name = tmp->first_name + " " + tmp->last_name;
            file << Full_name << "," << tmp->id << "," << tmp->gender << "," << tmp->age << ","
                 << tmp->designation << "," << tmp->email << "," << tmp->salary <<endl;
            tmp = tmp->next;
        }
        //Close file
        file.close();
    }
//    }else {
//        cout << "\n\t\t\t----------------------------------------------------------" << endl;
//        cout << "\t\t\t=============>>> ERROR WRITE TO CSV FILE <<<==============" << endl;
//        cout << "\t\t\t----------------------------------------------------------" << endl;
//    }
}


// Function to Read from CSV file
void readFileCSV(List_Employee *List) {
    // Use ifstream to read from employee.csv

    ifstream file("employee.csv");

    if(file.is_open()) {
        string line, first_name, last_name, id, gender, designation, email;
        int age;
        float salary;

        //Skip the header line
        getline(file, line);

        //Read all line from file
        while(getline(file, line)) {
            istringstream ss(line);
            string fullname;

            // Extract fields separated by commas
            getline(ss, fullname, ',');
            getline(ss, id, ',');
            getline(ss, gender, ',');
            ss >> age;
            ss.ignore(); // Ignore the comma
            getline(ss, designation, ',');
            getline(ss, email, ',');
            ss >> salary;

            // Split full name into first and last name
            istringstream name_ss(fullname);
            name_ss >> first_name >> last_name;

            // Add the extracted employee data to begin of list
            addEmployeToBegin(List, first_name, last_name, id, gender, age, designation, email, salary);
        }
        // Close file
        file.close();

        // Pop to tell user that file read and working success
        cout << "\n\t\t\t----------------------------------------------------------" << endl;
        cout << "\t\t\t====================>>> CSV FILE <<<======================" << endl;
        cout << "\t\t\t==================>>>>> WORKING <<<<<=====================" << endl;
        cout << "\t\t\t----------------------------------------------------------" << endl;

    } else {
        cout << "\n\t\t\t---------------------------------------------------------" << endl;
        cout << "\t\t\t=============>>> DO NOT HAVE CSV FILE YET <<<============" << endl;
        cout << "\t\t\t---------------------------------------------------------" << endl;
        return;
    }

}

#endif // EMPLOYEES_H_INCLUDED
