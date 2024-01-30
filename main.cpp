#include <iostream>
#include <string>

using namespace std;

int ID[50]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
string name[50]={"null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null"};
string phone_number[50]={"null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null","null"};
double GPA[50]={0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};

void AddStudent(int,string,string);
void RemoveStudent(int);
bool UpdateRecord(int,string,string);
void GPAcalculate(int,int,int,int);
void DisplayStudent(int);
void ClassReport();
void RankStudents();
void TopPerformer();
void SearchStudent(int);
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
                cout<<"Enter the ID of the student to be added: ";
                cin>>new_ID;
                cout<<"Enter the First name of the student to be added: ";
                cin>>new_first_name;
                cout<<"Enter the Second name of the student to be added: ";
                cin>>new_second_name;
                string new_full_name=new_first_name+" "+new_second_name;
                cout<<"Enter the phone number of the student to be added: ";
                cin>>new_phonenumber;
                cout<<"Note: You would have to calculate the GPA of the student you are adding by rerunning the program!"<<endl;
                AddStudent(new_ID,new_full_name,new_phonenumber);
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
                cout<<"Calculating GPA: "<<endl;
                int marks1=0;
                int marks2=0;
                int marks3=0;
                int input_ID=0;
                bool calculated=false;
                cout<<"What is the ID of the student whose GPA is to be calculated?: ";
                cin>>input_ID;
                for(int i=0;i<50;i++){
                    if(ID[i]==input_ID){
                        cout<<"Enter marks of the first subject (4 for A,3 for B,2 for C and 0 for F): ";
                        cin>>marks1;
                        cout<<"Enter marks of the second subject (4 for A,3 for B,2 for C and 0 for F): ";
                        cin>>marks2;
                        cout<<"Enter marks of the third subject (4 for A,3 for B,2 for C and 0 for F): ";
                        cin>>marks3;
                        GPAcalculate(input_ID,marks1,marks2,marks3);
                        calculated=true;
                    }
                }
                if(!calculated){
                    cout<<"Entered ID does not match any student. Please enter valid ID by rerunning the program!"<<endl;
                }
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
                cout<<"Ranking Students: "<<endl;
                RankStudents();
            }break;
            case 8:{
                cout<<"Top Performers: "<<endl;
                TopPerformer();
            }break;
            case 9:{
                cout<<"Searching Student: "<<endl;
                int input_ID=0;
                cout<<"Enter the ID of the student you want to search: ";
                cin>>input_ID;
                SearchStudent(input_ID);
            }break;
            case 10:{
                cout<<"Graphical Representation: "<<endl;
                GraphicalRepresentation();
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

void AddStudent(int ID_input,string name_input,string phone_input){
    bool added=false;
    for(int i=0;i<50;i++){
        if(ID[i]==-1 && name[i]=="null" && phone_number[i]=="null" && !added){
            ID[i]=ID_input;
            name[i]=name_input;
            phone_number[i]=phone_input;
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
    for(int i=0;i<50;i++){
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
    for(int i=0;i<50;i++){
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

void GPAcalculate(int input_ID,int marks1,int marks2,int marks3){
    double calculatedgpa=(marks1*3+marks2*3+marks3*3)/12;
    GPA[input_ID-1]=calculatedgpa;
    cout<<"GPA calculated and stored successfully!"<<endl;
}

void DisplayStudent(int input_ID){
    bool student_found=false;
    for(int i=0;i<50;i++){
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
    double averageGPA=0.0;
    int count=0;
    for(int i=0;i<50;i++){
        if(GPA[i]!=0.0){
            count++;
        }
    }
    for(int j=0;j<count;j++){
        averageGPA=averageGPA+GPA[j];
    }
    if(count>0){
        averageGPA=averageGPA/count;
    }
    cout<<"Average GPA in the class is: "<<averageGPA<<endl;
    double maximum=GPA[0];
    double minimum=GPA[0];
    string highest_name="null";
    string lowest_name="null";
    for(int i=0;i<50;i++){
            if(GPA[i]>maximum && (GPA[i]!=0.0 && maximum!=0.0)){
                maximum=GPA[i];
                highest_name=name[i];
        }else if(GPA[i]<minimum && (GPA[i]!=0.0 && minimum!=0.0)){
                minimum=GPA[i];
                lowest_name=name[i];
            }
    }
    cout<<highest_name<<" has achieved a GPA of: "<<maximum<<endl;
    cout<<lowest_name<<" has achieved a GPA of: "<<minimum<<endl;
}

void RankStudents(){

}

void TopPerformer(){

}

void SearchStudent(int input_ID){
    bool found=false;
    for(int j=0;j<50;j++){
        if(ID[j]==input_ID){
            cout<<"Student Name: "<<name[j]<<endl;
            found=true;
        }
    }
    if(!found){
            cout<<"Student not found! Please enter correct ID by rerunning the program."<<endl;
    }
}

void GraphicalRepresentation(){

}