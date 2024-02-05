#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

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

int main() {
    cout << "****************************************" << endl;
    cout << "*    Welcome to the Student Grade      *" << endl;
    cout << "*         Management System!           *" << endl;
    cout << "****************************************" << endl;
    cout << endl;
    int choice = 0;
    char repeat = 'a';
    do {
        cout << "Enter 1 for Adding a Student record,                   Enter 2 for Removing a Student record,"
                "\nEnter 3 for Updating a Student record,                 Enter 4 for Calculating GPA,"
                "\nEnter 5 for Displaying Student Info,                   Enter 6 for Generate Class Report,"
                "\nEnter 7 to Rank Students,                              Enter 8 to See the Top Performer,"
                "\nEnter 9 to Search for a student based on his/her ID,   Enter 10 to see Graphical Representation of the class statistics"
             << endl;
        cout << endl;
        cout << "Enter your Choice: ";
        cin >> choice;
        switch (choice) {

            case 1: {
                cout << "Adding a Student Record: " << endl;
                int count = 0;
                cout << endl;
                cout << "How many students do you want to add?: ";
                cin >> count;
                if (count > 50) {
                    cout << "You cannot add more than 50 students." << endl;
                } else {
                    int new_ID = 0;
                    string new_first_name = "Michael";
                    string new_second_name = "Jackson";
                    string new_phonenumber = "2139075130";
                    for (int i = 0; i < count; i++) {
                        cout << "Enter the ID of the student: ";
                        cin >> new_ID;
                        for (int j = 0; j < 50; j++) {
                            if (ID[j] == new_ID) {
                                do {
                                    cout << "Two students cannot have same IDs.Please enter a valid ID: " << endl;
                                    cin >> new_ID;
                                } while (ID[j] == new_ID);
                            }
                        }
                        cout << "Enter the First name of the student: ";
                        cin >> new_first_name;
                        cout << "Enter the Second name of the student: ";
                        cin >> new_second_name;
                        string new_full_name = new_first_name + " " + new_second_name;
                        cout << "Enter the phone number of the student: ";
                        cin >> new_phonenumber;
                        AddStudent(new_ID, new_full_name, new_phonenumber);
                        cout << endl;
                        cout << "Note: You would have to calculate their GPA!" << endl;
                    }
                }
            }
                break;

            case 2: {
                cout << "Removing a Student Record: " << endl;
                cout << endl;
                int removal_ID = 0;
                int count = 0;
                cout << "How many students do you want to remove?: ";
                cin >> count;
                for (int i = 0; i < count; i++) {
                    cout << "Enter the ID of the student: ";
                    cin >> removal_ID;
                    RemoveStudent(removal_ID);
                }
            }
                break;

            case 3: {
                cout << "Updating Contact Information: " << endl;
                cout << endl;
                int update_ID = 0;
                string update_first_name = "null";
                string update_second_name = "null";
                string update_phonenumber = "null";
                int count = 0;
                cout << "How many students do you want to update?: ";
                cin >> count;
                for (int i = 0; i < count; i++) {
                    cout << "Enter the ID of the student: " << endl;
                    cin >> update_ID;
                    cout << "Enter the Updated First Name of the student: ";
                    cin >> update_first_name;
                    cout << "Enter the Updated Second Name of the student: ";
                    cin >> update_second_name;
                    string update_full_name = update_first_name + " " + update_second_name;
                    cout << "Enter the Updated Phone Number of the student: ";
                    cin >> update_phonenumber;
                    if (UpdateRecord(update_ID, update_full_name, update_phonenumber)) {
                        cout << "Record Successfully Updated!" << endl;
                    } else {
                        cout << "Error! Failed to Update Record. Make sure your inputs are correct." << endl;
                    }
                }
            }
                break;

            case 4: {
                cout << "Calculating GPA: " << endl;
                cout << endl;
                double marks1 = 0;
                double marks2 = 0;
                double marks3 = 0;
                int input_ID = 0;
                bool calculated = false;
                int count = 0;
                cout << "How many GPAs do you want to calculate?: ";
                cin >> count;
                for (int j = 0; j < count; j++) {
                    cout << "What is the ID of the student whose GPA is to be calculated?: ";
                    cin >> input_ID;
                    for (int i = 0; i < 50; i++) {
                        if (ID[i] == input_ID) {
                            cout << "Enter marks of the first subject (4 for A,3 for B,2 for C and 0 for F): ";
                            cin >> marks1;
                            cout << "Enter marks of the second subject (4 for A,3 for B,2 for C and 0 for F): ";
                            cin >> marks2;
                            cout << "Enter marks of the third subject (4 for A,3 for B,2 for C and 0 for F): ";
                            cin >> marks3;
                            GPAcalculate(input_ID, marks1, marks2, marks3);
                            calculated = true;
                        }
                    }
                    if (!calculated) {
                        cout << "Entered ID does not match any student. Please enter valid ID by rerunning the program!"
                             << endl;
                    }
                }
            }
                break;

            case 5: {
                cout << "Displaying Student Information: " << endl;
                cout << endl;
                int ID_input = 0;
                int count = 0;
                cout << "How many Student's Information do you want to see?: ";
                cin >> count;
                for (int j = 0; j < count; j++) {
                    cout << "Enter the Student's ID to see his/her information: ";
                    cin >> ID_input;
                    DisplayStudent(ID_input);
                }
            }
                break;

            case 6: {
                cout << "Generate Class Report: " << endl;
                cout << endl;
                ClassReport();
            }
                break;

            case 7: {
                cout << "Ranking Students: " << endl;
                cout << endl;
                char order = 'T';
                cout << "What should be the order of the ranking?" << endl;
                cout << "For Low to High: L" << endl;
                cout << "For High to Low: H" << endl;
                cout << endl;
                cout << "Enter your choice: ";
                cin >> order;
                RankStudents(order);
            }
                break;

            case 8: {
                cout << "Top Performers: " << endl;
                cout << endl;
                TopPerformer();
            }
                break;

            case 9: {
                cout << "Searching Student: " << endl;
                cout << endl;
                int input_ID = 0;
                cout << "Enter the ID of the student: ";
                cin >> input_ID;
                SearchStudent(input_ID);
            }
                break;

            case 10: {
                cout << "Graphical Representation: " << endl;
                cout << endl;
                GraphicalRepresentation();
            }
                break;

            default: {
                cout << "Incorrect Choice. Try Again!" << endl;
            }
        }
        cout << "Do you want to rerun the program? (y/Y for yes,n/N for no): ";
        cin >> repeat;
        cout << endl;
    } while (repeat == 'Y' || repeat == 'y');
    return 0;
}

void swap(double &first_entry, double &last_entry) {
    double temp = 0;
    temp = first_entry;
    first_entry = last_entry;
    last_entry = temp;
}

void swapstring(string &first_entry, string &last_entry) {
    string temp = "null";
    temp = first_entry;
    first_entry = last_entry;
    last_entry = temp;
}

void AddStudent(int ID_input, string name_input, string phone_input) {
    bool added = false;
    for (int i = 1; i < 50; i++) {
        if (ID[i] == -1 && name[i] == "null" && phone_number[i] == "null" && !added) {
            ID[i] = ID_input;
            name[i] = name_input;
            phone_number[i] = phone_input;
            cout << "Student Successfully Added" << endl;
            added = true;
        }
    }
    if (!added) {
        cout << "Class full." << endl;
    }
}

void RemoveStudent(int input_ID) {
    bool removed = false;
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
    cout << endl;
    if (!removed) {
        cout << "Error! Input ID does not match any student in the record." << endl;
        cout << endl;
    }
}

bool UpdateRecord(int update_ID, string update_name, string update_phonenumber) {
    bool student_found = false;
    int position = 0;
    for (int i = 1; i < 50; i++) {
        if (ID[i] == update_ID) {
            student_found = true;
            position = i;
        }
    }
    if (student_found) {
        name[position] = update_name;
        phone_number[position] = update_phonenumber;
        return true;
    } else {
        return false;
    }
}

void GPAcalculate(int input_ID, double marks1, double marks2, double marks3) {
    double calculatedgpa = (marks1 * 3 + marks2 * 3 + marks3 * 3) / 12;
    GPA[input_ID] = calculatedgpa;
    cout << "GPA calculated and stored successfully!" << endl;
}

void DisplayStudent(int input_ID) {
    bool student_found = false;
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
    cout << endl;
    if (!student_found) {
        cout << "Provided ID does not match any students in the record." << endl;
        cout << endl;
    }
}

void ClassReport() {
    double averageGPA = 0.0;
    int count = 0;
    for (int i = 1; i < 50; i++) {
        if (GPA[i] != 0.0) {
            count++;
        }
    }
    for (int j = 1; j < count; j++) {
        averageGPA = averageGPA + GPA[j];
    }
    if (count > 0) {
        averageGPA = averageGPA / count;
    }
    cout << "Average GPA in the class is: " << averageGPA << endl;
    double maximum = 0.0;
    double minimum = GPA[1];
    string highest_name = "null";
    string lowest_name = "null";
    for (int i = 1; i < 50; i++) {
        if (GPA[i] > maximum && GPA[i] != 0.0) {
            maximum = GPA[i];
            highest_name = name[i];
        }
        if ((GPA[i] < minimum || minimum == GPA[1])) {
            minimum = GPA[i];
            lowest_name = name[i];
        }
    }
    cout << "Highest GPA: " << highest_name << " has achieved a GPA of: " << maximum << endl;
    cout << "Lowest GPA: " << lowest_name << " has achieved a GPA of: " << minimum << endl;
}

void RankStudents(char order) {
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

    for (int i = 0; i < 50; i++) {
        GPAhightolow[i] = GPA[i];
        GPAlowtohigh[i] = GPA[i];
        namehightolow[i] = name[i];
        namelowtohigh[i] = name[i];
        phonenumberlowtohigh[i] = phone_number[i];
        phonenumberhightolow[i] = phone_number[i];
    }
    if (order == 'L') {
        for (int i = 0; i < 49; i++) {
            for (int j = 0; j < 49; j++) {
                if (GPAlowtohigh[j] > GPAlowtohigh[j + 1]) {
                    swap(GPAlowtohigh[j], GPAlowtohigh[j + 1]);
                    swapstring(namelowtohigh[j], namelowtohigh[j + 1]);
                    swapstring(phonenumberlowtohigh[j], phonenumberlowtohigh[j + 1]);
                }
            }
        }
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
        for (int i = 0; i < 49; i++) {
            for (int j = 0; j < 49; j++) {
                if (GPAhightolow[j] < GPAhightolow[j + 1]) {
                    swap(GPAhightolow[j + 1], GPAhightolow[j]);
                    swapstring(namehightolow[j + 1], namehightolow[j]);
                    swapstring(phonenumberhightolow[j + 1], phonenumberhightolow[j]);
                }
            }
        }
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
        cout << "Invalid choice!" << endl;
    }

}

void TopPerformer() {
    double top_GPA = 0.0;
    string top_performer = "null";
    for (int i = 1; i < 50; i++) {
        if (GPA[i] > top_GPA && GPA[i] != 0.0) {
            top_GPA = GPA[i];
            top_performer = name[i];
        }
    }
    cout << "Top Performer of the class is " << top_performer << " with GPA of " << top_GPA << endl;
}

void SearchStudent(int input_ID) {
    bool found = false;
    for (int j = 1; j < 50; j++) {
        if (ID[j] == input_ID) {
            cout << "Student Name: " << name[j] << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Student not found! Please enter correct ID by rerunning the program." << endl;
    }
}

void GraphicalRepresentation() {
    const int maxBarLength = 8;
    const int maxLength = 20;


    for (int i = 0; i < 5; i++) {
        if (name[i] != "null") {

            cout << left << setw(maxLength) << setfill(' ') << name[i];
            cout << "|";

            // Calculate the length of the bar based on GPA (scaled to maxBarLength)
            int barLength = round(GPA[i] * 0.5 * maxBarLength);

            // Print the bar without moving to a new line
            for (int j = 0; j < barLength; j++) {
                cout << '*';
            }
            cout << endl;
            cout << left << setw(maxLength) << setfill(' ') << " ";
            cout << "|";
            for (int j = 0; j < barLength; j++) {
                cout << '*';
            }
            // Move to a new line after printing the bars
            cout << endl;
            cout << endl;
        }
    }
    cout << "Note: One '*' is equal to 0.25 GPA." << endl;
}