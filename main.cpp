#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

//Declaring and initializing all arrays in global scope for easier access in all functions.

int ID[50] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
              -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
string name[50] = {"null", "null", "null", "null", "null", "null", "null", "null", "null", "null", "null", "null",
                   "null", "null", "null", "null", "null", "null", "null", "null", "null", "null", "null", "null",
                   "null", "null", "null", "null", "null", "null", "null", "null", "null", "null", "null", "null",
                   "null", "null", "null", "null", "null", "null", "null", "null", "null", "null", "null", "null",
                   "null", "null"};
string phone_number[50] = {"null", "null", "null", "null", "null", "null", "null", "null", "null", "null", "null",
                           "null", "null", "null", "null", "null", "null", "null", "null", "null", "null", "null",
                           "null", "null", "null", "null", "null", "null", "null", "null", "null", "null", "null",
                           "null", "null", "null", "null", "null", "null", "null", "null", "null", "null", "null",
                           "null", "null", "null", "null", "null", "null"};
double GPA[50] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                  0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                  0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};

//Function Declarations

void swapstring(string &, string &);

void swap(double &, double &);

void AddStudent(int, string, string);

void RemoveStudent(int);

bool UpdateRecord(int, string, string);

void GPAcalculate(int, double, double, double);

void DisplayStudent(int);

void ClassReport();

void RankStudents(char);

void TopPerformer();

void SearchStudent(int);

void GraphicalRepresentation();

//End of Function Declaration

int main() {
    cout << "****************************************" << endl;
    cout << "*    Welcome to the Student Grade      *" << endl;
    cout << "*         Management System!           *" << endl;
    cout << "****************************************" << endl;
    cout << endl;

    //Variable initialization

    int choice = 0;
    char repeat = 'a';
    do {

        //Prompting user the functionalities of the Program.

        cout << "Enter 1 for Adding a Student record,                   Enter 2 for Removing a Student record,"
                "\nEnter 3 for Updating a Student record,                 Enter 4 for Calculating GPA,"
                "\nEnter 5 for Displaying Student Info,                   Enter 6 for Generate Class Report,"
                "\nEnter 7 to Rank Students,                              Enter 8 to See the Top Performer,"
                "\nEnter 9 to Search for a student based on his/her ID,   Enter 10 to see Graphical Representation of the class statistics"
             << endl;
        cout << endl;
        cout << "Enter your Choice: ";//Prompting user to enter their choice
        cin >> choice;
        switch (choice) {

            case 1: {
                cout << "Adding a Student Record: " << endl;//Prompting user what they chose
                int count = 0;
                cout << endl;
                cout << "How many students do you want to add?: ";//Prompting user to input the amount of record they want to input
                cin >> count;

                //Since the size of all arrays is 50, so we cannot add more than 50 students.

                if (count > 50) {
                    cout << "You cannot add more than 50 students." << endl;
                } else {

                    //Variable initialization

                    int new_ID = 0;
                    string new_first_name = "Michael";
                    string new_second_name = "Jackson";
                    string new_phonenumber = "2139075130";

                    //This for loop takes input from user while i<count

                    for (int i = 0; i < count; i++) {
                        cout << "Enter the ID of the student: ";
                        cin >> new_ID;

                        //This for loop checks for all the values making sure 2 students dont have same ID

                        for (int j = 0; j < 50; j++) {
                            if (ID[j] == new_ID) {
                                do {
                                    cout << "Two students cannot have same IDs.Please enter a valid ID: " << endl;
                                    cin >> new_ID;
                                } while (ID[j] == new_ID);
                            }
                        }

                        //Prompting user to input other records.

                        cout << "Enter the First name of the student: ";
                        cin >> new_first_name;
                        cout << "Enter the Second name of the student: ";
                        cin >> new_second_name;

                        //I had to take first name and second name separately as cin doesn't take spaces in string kindly

                        string new_full_name = new_first_name + " " + new_second_name;

                        //Concatenating both first and second name into 1 string with space in between to overcome the problem.

                        cout << "Enter the phone number of the student: ";
                        cin >> new_phonenumber;

                        //Calling the function by values.

                        AddStudent(new_ID, new_full_name, new_phonenumber);
                        cout << endl;

                        //Prompting user that he/she has to calculate GPA individually for every student

                        cout << "Note: You would have to calculate their GPA!" << endl;
                    }
                }

                //End of case 1
            }
                break;

            case 2: {
                cout << "Removing a Student Record: " << endl;//Prompting user what they chose
                cout << endl;

                //Variable initialization

                int removal_ID = 0;
                int count = 0;

                //Prompting user to input the amount of record they want to remove

                cout << "How many students do you want to remove?: ";
                cin >> count;

                //This for loop takes ID as input from user while i<count

                for (int i = 0; i < count; i++) {

                    //Prompting user to enter the ID of the student, that they want to remove

                    cout << "Enter the ID of the student: ";
                    cin >> removal_ID;

                    //Calling the function by value

                    RemoveStudent(removal_ID);
                }

                //End of case 2
            }
                break;

            case 3: {
                cout << "Updating Contact Information: " << endl;//Prompting user what they chose
                cout << endl;

                //Variable initialization

                int update_ID = 0;
                string update_first_name = "null";
                string update_second_name = "null";
                string update_phonenumber = "null";
                int count = 0;

                //Prompting user to input the amount of record they want to remove

                cout << "How many students do you want to update?: ";
                cin >> count;

                //This for loop takes values as input from user while i<count

                for (int i = 0; i < count; i++) {

                    //Prompting user to enter the ID of the student they want to update record of.

                    cout << "Enter the ID of the student: " << endl;
                    cin >> update_ID;
                    cout << "Enter the Updated First Name of the student: ";
                    cin >> update_first_name;
                    cout << "Enter the Updated Second Name of the student: ";
                    cin >> update_second_name;

                    //I had to take first name and second name separately as cin doesn't take spaces in string kindly

                    string update_full_name = update_first_name + " " + update_second_name;

                    //Concatenating both first and second name into 1 string with space in between to overcome the problem.

                    cout << "Enter the Updated Phone Number of the student: ";
                    cin >> update_phonenumber;

                    //Checking if Record was updated or not

                    if (UpdateRecord(update_ID, update_full_name, update_phonenumber)) {
                        cout << "Record Successfully Updated!" << endl;
                    } else {
                        cout << "Error! Failed to Update Record. Make sure your inputs are correct." << endl;
                    }
                }

                //End of case 3
            }
                break;

            case 4: {
                cout << "Calculating GPA: " << endl;//Prompting user what they chose
                cout << endl;

                //Variable initialization

                double marks1 = 0;
                double marks2 = 0;
                double marks3 = 0;
                int input_ID = 0;
                bool calculated = false;
                int count = 0;

                //Prompting user to input the amount of GPAs they want to calculate

                cout << "How many GPAs do you want to calculate?: ";
                cin >> count;

                //This for loop takes values as input from user while i<count

                for (int j = 0; j < count; j++) {

                    //Prompting user to enter the ID of the student they want to calculate GPA of.

                    cout << "What is the ID of the student whose GPA is to be calculated?: ";
                    cin >> input_ID;

                    //This for loop checks if the inputted ID matches any ID in record.

                    for (int i = 0; i < 50; i++) {
                        if (ID[i] == input_ID) {
                            cout << "Enter marks of the first subject (4 for A,3 for B,2 for C and 0 for F): ";
                            cin >> marks1;
                            cout << "Enter marks of the second subject (4 for A,3 for B,2 for C and 0 for F): ";
                            cin >> marks2;
                            cout << "Enter marks of the third subject (4 for A,3 for B,2 for C and 0 for F): ";
                            cin >> marks3;

                            //Calling the function by values

                            GPAcalculate(input_ID, marks1, marks2, marks3);

                            //Updating the boolean value of calculated to true,
                            //Which is later used to check wether GPA was calculated or not.

                            calculated = true;
                        }
                    }
                    //if calculated is not true, then ID must be invalid
                    //So, we prompt user that he/she has inputted invalid ID.
                    if (!calculated) {
                        cout << "Entered ID does not match any student. Please enter valid ID by rerunning the program!"
                             << endl;
                    }
                }

                //End of case 4
            }
                break;

            case 5: {
                cout << "Displaying Student Information: " << endl;//Prompting user what they chose
                cout << endl;

                //Variable initialization

                int ID_input = 0;
                int count = 0;

                //Prompting user to input the amount of GPAs they want to calculate.

                cout << "How many Student's Information do you want to see?: ";
                cin >> count;

                //This for loop takes values as input from user while i<count

                for (int j = 0; j < count; j++) {

                    //Prompting user to input student's ID.

                    cout << "Enter the Student's ID to see his/her information: ";
                    cin >> ID_input;

                    //Calling the function by value.

                    DisplayStudent(ID_input);
                }

                //End of case 5
            }
                break;

            case 6: {
                cout << "Generate Class Report: " << endl;//Prompting user what they chose
                cout << endl;

                //Calling the function.

                ClassReport();

                //End of case 6
            }
                break;

            case 7: {
                cout << "Ranking Students: " << endl;//Prompting user what they chose
                cout << endl;

                //Variable initialization

                char order = 'T';

                //Prompting user to input the order of ranking.

                cout << "What should be the order of the ranking?" << endl;
                cout << "For Low to High: L" << endl;
                cout << "For High to Low: H" << endl;
                cout << endl;
                cout << "Enter your choice: ";
                cin >> order;

                //Calling function by value.

                RankStudents(order);

                //End of case 7
            }
                break;

            case 8: {
                cout << "Top Performers: " << endl;//Prompting user what they chose
                cout << endl;

                //Calling the function

                TopPerformer();

                //End of case 8
            }
                break;

            case 9: {
                cout << "Searching Student: " << endl;//Prompting user what they chose
                cout << endl;

                //Variable initialization

                int input_ID = 0;

                //Prompting user to enter the ID of the student they want to search.

                cout << "Enter the ID of the student: ";
                cin >> input_ID;

                //Calling function by value

                SearchStudent(input_ID);

                //End of case 9
            }
                break;

            case 10: {
                cout << "Graphical Representation: " << endl;//Prompting user what they chose
                cout << endl;

                //Calling the function

                GraphicalRepresentation();

                //End of case 10
            }
                break;

            default: {
                cout << "Incorrect Choice. Try Again!" << endl;//Prompting user that their input wasn't valid.
            }
        }
        cout << "Do you want to rerun the program? (y/Y for yes,n/N for no): ";
        //Prompting user to enter y/Y to rerun the program or n/N to end the program.
        cin >> repeat;
        cout << endl;
    } while (repeat == 'Y' || repeat == 'y'); //Checking what user has inputted and wether to rerun the program or not

    return 0;//Returning 0 when the program has successfully run and has ended.
}

void swap(double &first_entry, double &last_entry) {

    //Function to swap doubles. Used later in another function

    double temp = 0;
    temp = first_entry;
    first_entry = last_entry;
    last_entry = temp;

    //End of function
}

void swapstring(string &first_entry, string &last_entry) {

    //Function to swap strings. Used later in another function.

    string temp = "null";
    temp = first_entry;
    first_entry = last_entry;
    last_entry = temp;

    //End of function
}

void AddStudent(int ID_input, string name_input, string phone_input) {

    //Boolean initialization

    bool added = false;

    /*This for loop look for index where the student information can be stored, i.e. where the ID=-1, name=null and
    phone number=null*/

    for (int i = 1; i < 50; i++) {
        if (ID[i] == -1 && name[i] == "null" && phone_number[i] == "null" && !added) {
            ID[i] = ID_input;
            name[i] = name_input;
            phone_number[i] = phone_input;
            cout << "Student Successfully Added" << endl;
            added = true;
        }
    }

    //This if statement checks wether the arrays had places to store the student information or not.

    if (!added) {
        cout << "Class full." << endl;
    }

    //End of function
}

void RemoveStudent(int input_ID) {

    //Boolean initialaztion

    bool removed = false;

    /*This for loop looks for student with matching ID. If ID matches, then boolean removed is set to true
      And student's information is set to the default values.*/

    for (int i = 1; i < 50; i++) {
        if (ID[i] == input_ID) {
            ID[i] = -1;
            name[i] = "null";
            phone_number[i] = "null";
            GPA[i] = 0.0;
            removed = true;
            cout << "Student Successfully removed!" << endl;
            cout << endl;
        }
    }

    /*This if-else statement sees if the student was removed or not, if not removed, then most probably the inputted ID
      didn't match any student's ID in the record. */

    if (!removed) {

        //Prompting user to input correct ID next time.

        cout << "Error! Input ID does not match any student in the record." << endl;
        cout << endl;
    }

    //End of function
}

bool UpdateRecord(int update_ID, string update_name, string update_phonenumber) {

    //Boolean initialization

    bool student_found = false;

    //position variable initialization

    int position = 0;

    //This for loop looks for student with matching ID. If ID matches, then boolean student_found is set to true.
    //And that index is stored in position variable.

    for (int i = 1; i < 50; i++) {
        if (ID[i] == update_ID) {
            student_found = true;
            position = i;
        }
    }

    /*This if-else statement sees if the student was found or not, if the student was found then it updates the name at
      the position where it was found*/

    if (student_found) {
        name[position] = update_name;
        phone_number[position] = update_phonenumber;
        return true; //Returning the status of the function, wether student record was updated or not.
    } else {
        return false; //Returning the status of the function, wether student record was updated or not.
    }

    //End of function
}

void GPAcalculate(int input_ID, double marks1, double marks2, double marks3) {

    //Initializing the value of the calculatedgpa to the GPA that gets calculated from the formula.

    double calculatedgpa = (marks1 * 3 + marks2 * 3 + marks3 * 3) / 12;

    //Update the GPA for the student with the specified input_ID

    GPA[input_ID] = calculatedgpa;

    //Prompting the user that the GPA was succesfully calculated and stored.

    cout << "GPA calculated and stored successfully!" << endl;

    //End of function
}

void DisplayStudent(int input_ID) {

    //Boolean initialization

    bool student_found = false;

    //This for loop looks for the student with matching ID.

    for (int i = 1; i < 50; i++) {
        if (ID[i] == input_ID) {
            cout << "Student ID: " << ID[i] << endl;
            cout << "Student Name: " << name[i] << endl;
            cout << "Student Phone Number: " << phone_number[i] << endl;
            cout << "Student GPA: " << GPA[i] << endl;
            student_found = true;
            cout << endl;
        }
    }

    /*if in the previous loop the student wasn't found meaning the value of student_found was not set to true by the loop.
      then we prompt the user that no student with the inputted ID were found in the record.*/

     if (!student_found) {
        cout << "Provided ID does not match any students in the record." << endl;
        cout << endl;
    }

    //End of function
}

void ClassReport() {

    //Section 1: Calculating Average
    //First section's variable initializtions

    double averageGPA = 0.0;
    int count = 0;

    //This for loop calculates how many students are there to calculate average from

    for (int i = 1; i < 50; i++) {
        if (name[i] != "null") {
            count++;
        }
    }

    //This for loop adds all the GPA.

    for (int j = 1; j < count; j++) {
        averageGPA = averageGPA + GPA[j];
    }

    //This if statement sees if count is greater than 0 or not, meaning it checks wether if there were any elements in the name array or not.

    if (count > 0) {
        averageGPA = averageGPA / count;
    }
    cout << "Average GPA in the class is : " << averageGPA << endl; //Prompting the result to the user

    //Section 2: Checking the maximum and minimum GPA obtained and by which students.
    //2nd Section's Variable initialization

    double maximum = 0.0;
    double minimum = GPA[1];
    string highest_name = "null";
    string lowest_name = "null";

    //This for loop checks for the maximum GPA holder.

    for (int i = 1; i < 50; i++) {
        if (GPA[i] > maximum && GPA[i] != 0.0) {
            maximum = GPA[i];
            highest_name = name[i];
        }
    }

    //This for loop checks for the miniumum GPA holder.

    for (int i = 1; i < 50; i++) {
        if (GPA[i] < minimum) {
            minimum = GPA[i];
            lowest_name = name[i];
        }
    }

    cout << "Highest GPA : " << highest_name << " has achieved a GPA of : " << maximum << endl; //Prompting the user maximum GPA holder's name and his/her GPA
    cout << "Lowest GPA  : " << lowest_name << " has achieved a GPA of : " << minimum << endl; //Prompting the user minimum GPA holder's name and his/her GPA

    //End of function
}

void RankStudents(char order) {

    //Array initializations

    double GPAhightolow[50] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                               0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                               0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    double GPAlowtohigh[50] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                               0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                               0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    string namehightolow[50] = {"null", "null", "null", "null", "null", "null", "null", "null", "null", "null", "null",
                                "null", "null", "null", "null", "null", "null", "null", "null", "null", "null", "null",
                                "null", "null", "null", "null", "null", "null", "null", "null", "null", "null", "null",
                                "null", "null", "null", "null", "null", "null", "null", "null", "null", "null", "null",
                                "null", "null", "null", "null", "null", "null"};
    string namelowtohigh[50] = {"null", "null", "null", "null", "null", "null", "null", "null", "null", "null", "null",
                                "null", "null", "null", "null", "null", "null", "null", "null", "null", "null", "null",
                                "null", "null", "null", "null", "null", "null", "null", "null", "null", "null", "null",
                                "null", "null", "null", "null", "null", "null", "null", "null", "null", "null", "null",
                                "null", "null", "null", "null", "null", "null"};
    string phonenumberlowtohigh[50] = {"null", "null", "null", "null", "null", "null", "null", "null", "null", "null",
                                       "null", "null", "null", "null", "null", "null", "null", "null", "null", "null",
                                       "null", "null", "null", "null", "null", "null", "null", "null", "null", "null",
                                       "null", "null", "null", "null", "null", "null", "null", "null", "null", "null",
                                       "null", "null", "null", "null", "null", "null", "null", "null", "null", "null"};
    string phonenumberhightolow[50] = {"null", "null", "null", "null", "null", "null", "null", "null", "null", "null",
                                       "null", "null", "null", "null", "null", "null", "null", "null", "null", "null",
                                       "null", "null", "null", "null", "null", "null", "null", "null", "null", "null",
                                       "null", "null", "null", "null", "null", "null", "null", "null", "null", "null",
                                       "null", "null", "null", "null", "null", "null", "null", "null", "null", "null"};

    //This for loop assigns all globally declared array values at index i to the values in the local arrays at index i

    for (int i = 0; i < 50; i++) {
        GPAhightolow[i] = GPA[i];
        GPAlowtohigh[i] = GPA[i];
        namehightolow[i] = name[i];
        namelowtohigh[i] = name[i];
        phonenumberlowtohigh[i] = phone_number[i];
        phonenumberhightolow[i] = phone_number[i];
    }

    //These if-else if statement checks for what the user has inputted.

    if (order == 'L') {

        //If user has inputted 'L' these for loops will sort the values in their appropriate place,i.e. in ascending order.

        for (int i = 0; i < 49; i++) {
            for (int j = 0; j < 49; j++) {
                if (GPAlowtohigh[j] > GPAlowtohigh[j + 1]) {
                    swap(GPAlowtohigh[j], GPAlowtohigh[j + 1]);
                    swapstring(namelowtohigh[j], namelowtohigh[j + 1]);
                    swapstring(phonenumberlowtohigh[j], phonenumberlowtohigh[j + 1]);
                }
            }
        }

        //Prompting the result to the user,i.e. Students ranked from Lowest GPA to Highest GPA

        cout << "Students Ranked from Lowest to Highest: " << endl;
        for (int i = 0; i < 50; i++) {
            if (namelowtohigh[i] != "null") {
                cout << "Name: " << namelowtohigh[i] << endl;
                cout << "GPA: " << GPAlowtohigh[i] << endl;
                cout << "Phone: " << phonenumberlowtohigh[i] << endl;
                cout << endl;
            }
        }
    } else if (order == 'H') {

        //If user has inputted 'H' these for loops will sort the values in their appropriate place,i.e. in descending order.

        for (int i = 0; i < 49; i++) {
            for (int j = 0; j < 49; j++) {
                if (GPAhightolow[j] < GPAhightolow[j + 1]) {
                    swap(GPAhightolow[j + 1], GPAhightolow[j]);
                    swapstring(namehightolow[j + 1], namehightolow[j]);
                    swapstring(phonenumberhightolow[j + 1], phonenumberhightolow[j]);
                }
            }
        }

        //Prompting the result to the user,i.e. Students ranked from Highest GPA to Lowest GPA

        cout << "Students Ranked from Highest to Lowest: " << endl;
        for (int i = 0; i < 50; i++) {
            if (namehightolow[i] != "null") {
                cout << "Name: " << namehightolow[i] << endl;
                cout << "GPA: " << GPAhightolow[i] << endl;
                cout << "Phone number: " << phonenumberhightolow[i] << endl;
                cout << endl;
            }
        }
    } else {
        cout << "Invalid choice!" << endl; //Prompting user that he has entered wrong input.
    }

    //End of function
}

void TopPerformer() {
    double top_GPA = 0.0;
    string top_performer = "null";

    /*This for loop checks for the highest GPA in the whole array and then store that value in local variable total_GPA
     * and the name of that student in top_performer*/

    for (int i = 1; i < 50; i++) {
        if (GPA[i] > top_GPA && GPA[i] != 0.0) {
            top_GPA = GPA[i];
            top_performer = name[i];
        }
    }

    //Prompting the result to the user

    cout << "Top Performer of the class is " << top_performer << " with GPA of " << top_GPA << endl;

    //End of function
}

void SearchStudent(int input_ID) {

    //Boolean initialization

    bool found = false;

    //This for loop checks the whole array for the ID that matches the inputted ID

    for (int j = 1; j < 50; j++) {
        if (ID[j] == input_ID) {

            //If it's found, the name is prompted to the user.

            cout << "Student Name: " << name[j] << endl;
            found = true; //boolean value is set to true to make sure the value is found and result is prompted
        }
    }

    /*if the boolean found stays false then that means the for loop was unable to find the user,
     So we prompt the user to enter correct ID next time.*/

    if (!found) {
        cout << "Student not found! Please enter correct ID by rerunning the program." << endl;
    }

    //End of function
}

void GraphicalRepresentation() {

    //This for loop checks for every non-null elements of name array. Then prompts the graph.

    for (int i = 0; i < 5; i++) {
        if (name[i] != "null") {

            //This prints the name of the student if its non-null, with enough spacing for names that are 20 characters long
            //setfill(' ') function will fill the empty places with spaces to make it so that the graph is uniform.
            //left object will line the names on the left side of the console.

            cout << left << setw(20) << setfill(' ') << name[i];
            cout << "|";

            //Calculate the length of the bar based on GPA

            int barLength = round(GPA[i] * 0.5 * 8);

            //Print the first bar

            for (int j = 0; j < barLength; j++) {
                cout << '*';
            }

            /*This new line object will make it so that there's a new line after the first bar.
            So that the next bar can appear without an issue */

            cout << endl;

            //This will print "|" right under the previous one.

            cout << left << setw(20) << setfill(' ') << " ";
            cout << "|";

            //Print the second bar

            for (int j = 0; j < barLength; j++) {
                cout << '*';
            }

            // Move to a new line after printing the bars

            cout << endl;
            cout << endl;
        }
    }
    cout << "Note: One '*' is equal to 0.25 GPA." << endl; //Prompting user the value of one "*"

    //End of function
}