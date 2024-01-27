#include <iostream>
#include <string>

using namespace std;

int ID[6]={1,2,3,4,5,0};
string name[6]={"Ahmad Hassan","Hassaan Shahid","Hamza Shafique","Ibrahim Waseek","Huraira Khan","null"};
string phone_number[6]={"+14057089729","+18183903573","+12542576737","+18447609632","+14475153344","null"};
double GPA[6]={3.4,3.7,4,3.5,3.3,0.0};

void AddStudent(int,string,string,double);
void RemoveStudent(int);
bool UpdateRecord(int);
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
                string new_name="lol";
                string new_phonenumber="lol";
                double new_GPA=0.0;
                cout<<"Enter the ID of the student to be added: ";
                cin>>new_ID;
                cout<<"Enter the name of the student to be added: ";
                cin>>new_name;
                cout<<"Enter the phone number of the student to be added: ";
                cin>>new_phonenumber;
                cout<<"Enter the GPA of the student to be added: ";
                cin>>new_GPA;
                AddStudent(new_ID,new_name,new_phonenumber,new_GPA);
            }break;
            case 2:{

            }break;
            case 3:{

            }break;
            case 4:{

            }break;
            case 5:{

            }break;
            case 6:{

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
    int count=0;
    for(int i=0;i<6;i++){
        if(ID[i]==0 && name[i]=="null" && phone_number[i]=="null" && GPA[i]==0.0){
            ID[i]=ID_input;
            name[i]=name_input;
            phone_number[i]=phone_input;
            GPA[i]=GPA_input;
            cout<<"Student Successfully Added"<<endl;
        }else{
            cout<<"Class full"<<endl;
        }
    }
}
