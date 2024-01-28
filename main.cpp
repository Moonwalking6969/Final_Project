#include <iostream>
#include <string>

using namespace std;

int ID[6]={1,2,0,4,5,0};
string name[6]={"Ahmad Hassan","Hassaan Shahid","null","Ibrahim Waseek","Huraira Khan","null"};
string phone_number[6]={"+14057089729","+18183903573","null","+18447609632","+14475153344","null"};
double GPA[6]={3.4,3.7,0.0,3.5,3.3,0.0};

void AddStudent(int,string,string,double);
void RemoveStudent(int);
bool UpdateRecord(int,string,string);
double GPAcalculate(int,int,int);
void DisplayStudent(int);
void ClassReport();
void RankStudents();
void TopPerformer();
string SearchStudent(int);
void GraphicalRepresentation();

int main() {
    cout<<"Welcome to the Student Grade Management System!"<<endl;
    int choice=0;
    char repeat='a';
    do{
        cout<<"Enter 1 for Adding a Student record,\nEnter 2 for Removing a Student record,\nEnter 3 for Updating a Student record,\nEnter 4 for Calculating GPA,\nEnter 5 for Displaying Student Info,\nEnter 6 for Ranking Students,\nEnter 8 to See the Top Performer,\nEnter 9 to Search for a student based on his/her ID,\nEnter 10 to see the Graphical Representation of the class statistics: ";
        cin>>choice;
        switch(choice){
            case 1:{
                cout<<"Adding a Student Record: "<<endl;
                int new_ID=0;
                string new_first_name="lol";
                string new_second_name="lol";
                string new_phonenumber="lol";
                double new_GPA=0.0;
                cout<<"Enter the ID of the student to be added: ";
                cin>>new_ID;
                cout<<"Enter the First name of the student to be added: ";
                cin>>new_first_name;
                cout<<"Enter the Second name of the student to be added: ";
                cin>>new_second_name;
                string new_full_name=new_first_name+" "+new_second_name;
                cout<<"Enter the phone number of the student to be added: ";
                cin>>new_phonenumber;
                cout<<"Enter the GPA of the student to be added: ";
                cin>>new_GPA;
                if(new_GPA>4 || new_GPA<0){
                    cout<<"GPA cannot be greater than 4 or less than 0."<<endl;
                    cout<<"Please enter the correct GPA: ";
                    do{
                        cin>>new_GPA;
                    }while(new_GPA>4 || new_GPA<0);
                }
                AddStudent(new_ID,new_full_name,new_phonenumber,new_GPA);
            }break;
            case 2:{
                cout<<"Removing a Student Record: "<<endl;
                int removal_ID=0;
                cout<<"Enter the ID of the student who is to be removed: ";
                cin>>removal_ID;
                RemoveStudent(removal_ID);
            }break;
            case 3:{
                cout<<"Updating Contact Information: "<<endl;
                int update_ID=0;
                string update_first_name="null";
                string update_second_name="null";
                string update_phonenumber="null";
                cout<<"Enter the ID of the student: "<<endl;
                cin>>update_ID;
                cout<<"Enter the Updated First Name of the student: ";
                cin>>update_first_name;
                cout<<"Enter the Updated Second Name of the student: ";
                cin>>update_second_name;
                string update_full_name=update_first_name+" "+update_second_name;
                cout<<"Enter the Updated Phone Number of the student: ";
                cin>>update_phonenumber;
                if(UpdateRecord(update_ID,update_full_name,update_phonenumber)){
                    cout<<"Record Successfully Updated!"<<endl;
                }else{
                    cout<<"Error! Failed to Update Record. Make sure your inputs are correct."<<endl;
                }
            }break;
            case 4:{

            }break;
            case 5:{
                cout<<"Displaying Student Information: "<<endl;
                int ID_input=0;
                cout<<"Enter the Student's ID to see his/her information: ";
                cin>>ID_input;
                DisplayStudent(ID_input);
            }break;
            case 6:{
                cout<<"Generate Class Report: "<<endl;
                ClassReport();
            }break;
            case 7:{

            }break;
            case 8:{

            }break;
            case 9:{

            }break;
            case 10:{

            }break;
            default:{
                cout<<"Incorrect Choice. Try Again!"<<endl;
            }
        }
        cout<<"Do you want to rerun the program? (y/Y for yes,n/N for no): ";
        cin>>repeat;
    }while(repeat=='Y'||repeat=='y');
    return 0;
}

void AddStudent(int ID_input,string name_input,string phone_input,double GPA_input){
    bool added=false;
    for(int i=0;i<6;i++){
        if(ID[i]==0 && name[i]=="null" && phone_number[i]=="null" && GPA[i]==0.0 && !added){
            ID[i]=ID_input;
            name[i]=name_input;
            phone_number[i]=phone_input;
            GPA[i]=GPA_input;
            cout<<"Student Successfully Added"<<endl;
            added=true;
        }
    }
    if(!added){
        cout<<"Class full."<<endl;
    }
}

void RemoveStudent(int input_ID){
    bool removed=false;
    for(int i=0;i<6;i++){
        if(ID[i]==input_ID){
            ID[i]=-1;
            name[i]="null";
            phone_number[i]="null";
            GPA[i]=0.0;
            removed=true;
            cout<<"Student Successfully removed!"<<endl;
        }
    }
    if(!removed){
        cout<<"Error! Input ID does not match any student in the record."<<endl;
    }
}

bool UpdateRecord(int update_ID, string update_name, string update_phonenumber){
    bool student_found=false;
    int position=0;
    for(int i=0;i<6;i++){
        if(ID[i]==update_ID){
            student_found=true;
            position=i;
        }
    }
    if(student_found){
        name[position]=update_name;
        phone_number[position]=update_phonenumber;
        return true;
    }else{
        return false;
    }
}

void DisplayStudent(int input_ID){
    bool student_found=false;
    for(int i=0;i<6;i++){
        if(ID[i]==input_ID){
            cout<<"Student ID: "<<ID[i]<<endl;
            cout<<"Student Name: "<<name[i]<<endl;
            cout<<"Student Phone Number: "<<phone_number[i]<<endl;
            cout<<"Student GPA: "<<GPA[i]<<endl;
            student_found=true;
        }
    }
    if(!student_found){
        cout<<"Provided ID does not match any students in the record."<<endl;
    }
}

void ClassReport(){

}