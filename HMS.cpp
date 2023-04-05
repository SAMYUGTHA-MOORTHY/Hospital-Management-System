//HOSPITAL MANAGEMENT SYSTEM
#include<iostream>
#include<iomanip>
#include<string.h>
#include<fstream>
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
#include<string>
using namespace std;
//INPUT VALIDATIONS
int checkInt(int Age)
{
                if(Age>0 && Age<100)
                {
                                return 0;
                }
                else
                {
                                return 1;
                }
}
int checkFloat(float n)
{
                if(n>0)
                {
                                return 0;
                }
                else
                {
                                return 1;
                }
}
int checkUpdate(int opt,int limit)
{
                if(opt>0&&opt<=limit)
                {
                                return 0;
                }
                else
                {
                                return 1;
                }
}
int checkShift(char *s)
{
                if((!strcmp(s,"MORNING"))||(!strcmp(s,"NIGHT")))
                {
                                return 0;
                }
                else
                {
                                return 1;
                }
}
//DEFINING THE CLASS HOSPITAL
class Person
{
private:
                char name[30];
                int age;
                char address[60];
public:
                void display();
                void newRecord();
                void updateRecord(int);
                char* getName();
                //FRIEND FUNCTIONS
                friend int checkAge(int);
};
//DEFINING THE FUNCTIONS OF THE HOSPITAL CLASS
void Person::newRecord()
{
                char tempName[30],tempAddress[60];
                cout<<"ENTER THE NAME : ";
                cin>>tempName;
                strcpy(name,tempName);
                cout<<"ENTER THE AGE : ";
                L1 : cin>>age;
                if(checkInt(age))
                {
                                cout<<"ENTER PROPER AGE : ";
                                goto L1;
                }
                cout<<"ENTER THE ADDRESS IN ONE LINE : ";
                scanf("%*c%[^\n]",&tempAddress);
                strcpy(address,tempAddress);
}
void Person::display()
{
                cout<<setw(30)<<left<<"NAME"<<" : "<<name<<endl<<setw(30)<<left<<"AGE"<<" : "<<age<<endl<<setw(30)<<left<<"ADDRESS"<<" : "<<address<<endl;
}
void Person::updateRecord(int choice)
{
                switch(choice)
                {
                                case 1 ://TO CHANGE THE NAME
                                {
                                                char newName[30];
                                                cout<<"ENTER THE NEW NAME : ";
                                                cin>>newName;
                                                strcpy(name,newName);
                                                break;
                                }
                                case 2 ://TO CHANGE THE AGE
                                {
                                                cout<<"ENTER THE NEW AGE : ";
                                                L2 : cin>>age;
                                                if(checkInt(age))
                                                {
                                                                cout<<"ENTER PROPER AGE : ";
                                                                goto L2;
                                                }
                                                break;
                                }
                                case 3 ://TO CHANGE THE ADDRESS
                                {
                                                cout<<"ENTER THE NEW ADDRESS : ";
                                                char newAddress[60];
                                                scanf("%*c%[^\n]",&newAddress);
                                                strcpy(address,newAddress);
                                                break;
                                }
                }
}
char* Person::getName()
{
                return(name);
}
//DEFINING THE CLASS DOCTOR
class Doctor:public Person
{
private:
                char specialist[30];
                int experience;
                float salary;
                char shift[20];

public:
                void newRecord2();
                void display2();
                void update(int);
                void storeDoctor();
                void readAllDoctor();
                void searchDoctor();
                void deleteDoctor();
                void updateDoctor();
                void DisplayShift();
                void DisplayExperience();
                void DisplaySpecialization();
                //FRIEND FUNCTIONS
                friend int checkFloat(float);
                friend int checkUpdate(int);
                friend int checkShift(char*);
};
void Doctor::newRecord2()
{
                char tempspecialist[30],tempShift[20];
                Person::newRecord();
                cout<<"ENTER THE SPECIALISATION OF THE DOCTOR : ";
                cin>>tempspecialist;
                strcpy(specialist,tempspecialist);
                cout<<"ENTER THE NUMBER OF YEARS OF EXPERIENCE : ";
                L3 : cin>>experience;
                if(checkInt(experience))
                {
                                cout<<"ENTER VALID EXPERIENCE : ";
                                goto L3;
                }
                cout<<"ENTER THE MONTHLY SALARY OF THE DOCTOR : ";
                L4 : cin>>salary;
                if(checkFloat(salary))
                {
                                cout<<"ERROR PROPER SALARY : ";
                                goto L4;
                }
                cout<<"ENTER THE SHIFT DETAILS [MORNING or NIGHT ]: ";
                L8 : cin>>tempShift;
                if(checkShift(tempShift))
                {
                                cout<<"NO SUCH SHIFT EXISTS.";
                                cout<<"ENTER VALID SHIFT : ";
                                goto L8;
                }
                strcpy(shift,tempShift);
}
void Doctor::display2()
{
                Person::display();
                cout<<setw(30)<<left<<"SPECIALISATION"<<" : "<<specialist<<endl<<setw(30)<<left<<"NO.OF YEARS OF WORKING"<<" : "<<experience<<endl<<setw(30)<<left<<"SALARY"<<" : "<<salary<<endl<<setw(30)<<left<<"SHIFT DETAILS"<<" : "<<shift<<endl;
}
void Doctor::update(int choice)
{
                switch(choice)
                {
                                case 1://TO CHANGE THE NAME
                                {
                                                Person::updateRecord(choice);
                                                break;
                                }
                                case 2://TO CHANGE THE AGE
                                {
                                                Person::updateRecord(choice);
                                                break;
                                }
                                case 3://TO CHANGE THE ADDRESS
                                {
                                                Person::updateRecord(choice);
                                                break;
                                }
                                case 4 ://TO CHANGE THE SPECIALISATION
                                {
                                                char tempspecialist[20];
                                                cout<<"ENTER THE UPDATED SPECIALISATION : ";
                                                cin>>tempspecialist;
                                                strcpy(specialist,tempspecialist);
                                                break;
                                }
                                case 5 ://TO CHANGE THE YEAR OF EXPERIENCE
                                {
                                                cout<<"ENTER THE YEARS OF EXPERIENCE : ";
                                                L5 : cin>>experience;
                                                if(checkInt(experience))
                                                {
                                                                cout<<"ENTER VALID EXPERIENCE : ";
                                                                goto L5;
                                                }
                                                break;
                                }
                                case 6 ://TO CHANGE THE SALARY
                                {
                                                cout<<"ENTER THE NEW SALARY : ";
                                                L6 : cin>>salary;
                                                if(checkFloat(salary))
                                                {
                                                                cout<<"ENTER PROPER SALARY : ";
                                                                goto L6;
                                                }
                                                break;
                                }
                                case 7 ://TO CHANGE THE SHIFT DETAILS
                                {
                                                char tempShift[20];
                                                cout<<"ENTER THE NEW SHIFT DETAILS : ";
                                                L9: cin>>tempShift;
                                                if(checkShift(tempShift))
                                                {
                                                                cout<<"NO SUCH SHIFT EXISTS.";
                                                                cout<<"ENTER VALID SHIFT : ";
                                                                goto L9;
                                                }
                                                strcpy(shift,tempShift);
                                                break;
                                }
                }
}
void Doctor::storeDoctor()
{
                fstream fout;
                fout.open("DOCTOR DETAILS.txt",ios::in|ios::out|ios::binary|ios::app);
                if(!fout)
                {
                                cout<<"ERROR OPENING THE FILE"<<endl;
                                return;
                }
                fout.write((char*)this,sizeof(*this));
                fout.close();
}
void Doctor::readAllDoctor()
{
                fstream fin;
                int flag=0;
                fin.open("DOCTOR DETAILS.txt",ios::in|ios::out|ios::binary);
                if(!fin)
                {
                                cout<<"ERROR OPENING THE FILE"<<endl;
                }
                else
                {
                                cout<<setw(35)<<right<<"DOCTOR DETAILS"<<endl<<endl;
                                fin.read((char*)this,sizeof(*this));
                                while(fin)
                                {
                                                flag=1;
                                                display2();
                                                cout<<"--------------------------------------------------------------------------------"<<endl;
                                                cout<<endl;
                                                fin.read((char*)this,sizeof(*this));
                                }
                                fin.close();
                }
                if(flag==0)
                {
                                cout<<"NO DOCTOR RECORDS ARE REGISTERED"<<endl;
                }
}
void Doctor::searchDoctor()
{
                fstream fin;
                char tempName[30];
                cout<<"ENTER THE NAME OF THE DOCTOR YOU WANT TO SEARCH : ";
                cin>>tempName;
                int flag=0;
                fin.open("DOCTOR DETAILS.txt",ios::in|ios::out|ios::binary);
                if(!fin)
                {
                                cout<<"ERROR OPENING THE FILE"<<endl;
                                return;
                }
                else
                {
                                cout<<setw(35)<<right<<"DOCTOR DETAILS"<<endl<<endl;
                                fin.read((char*)this,sizeof(*this));
                                while(!fin.eof())
                                {
                                                if(!strcmp(tempName,getName()))
                                                {
                                                                flag=1;
                                                                display2();
                                                                break;
                                                }
                                                else
                                                {
                                                                fin.read((char*)this,sizeof(*this));
                                                }
                                }
                                fin.close();
                                if(flag==0)
                                {
                                                cout<<"SORRY! NO SUCH DOCTOR WORKS HERE."<<endl;
                                }
                }
}
void Doctor::deleteDoctor()
{
                fstream fin,fout;
                char tempName[30];
                int flag=0;
                cout<<"ENTER THE NAME OF THE DOCTOR WHOSE RECORD YOU WANT TO DELETE : ";
                cin>>tempName;
                fin.open("DOCTOR DETAILS.txt",ios::in|ios::out|ios::binary);
                if(!fin)
                {
                                cout<<"ERROR OPENING THE FILE"<<endl;
                }
                else
                {
                                fout.open("TEMP.txt",ios::out|ios::binary|ios::app);
                                fin.read((char*)this,sizeof(*this));
                                while(!fin.eof())
                                {
                                                if (strcmp(tempName,getName()))
                                                {
                                                                fout.write((char*)this,sizeof(*this));
                                                }
                                                else
                                                {
                                                                flag=1;
                                                }
                                                fin.read((char*)this,sizeof(*this));
                                }
                                fin.close();
                                fout.close();
                                remove("DOCTOR DETAILS.txt");
                                rename("TEMP.txt","DOCTOR DETAILS.txt");
                                if(flag==1)
                                {
                                                cout<<"THE RECORD HAS BEEN SUCCESFULLY DELETED"<<endl<<endl;
                                }
                                else
                                {
                                                cout<<"SORRY NO SUCH DOCTOR WORKS HERE"<<endl;
                                }
                }

}
void Doctor::updateDoctor()
{
                char tempName[30];
                cout<<"ENTER THE NAME OF THE DOCTOR : ";
                cin>>tempName;
                int flag=0;
                fstream fout,fin;
                fin.open("DOCTOR DETAILS.txt",ios::in|ios::binary);
                if(!fin)
                {
                                cout<<"ERROR OPENING THE FILE"<<endl;
                                return;
                }
                fout.open("TEMP.txt",ios::out|ios::binary|ios::app);
                if(!fout)
                {
                                cout<<"ERROR OPENING THE FILE"<<endl;
                                return;
                }
                fin.read((char*)this,sizeof(*this));
                while(fin)
                {
                                if(!strcmp(tempName,getName()))
                                {
                                                flag=1;
                                                int choice;
                                                cout<<"AVAILABLE OPTIONS"<<endl;
                                                cout<<"[1].EDIT NAME"<<endl<<"[2].EDIT AGE"<<endl<<"[3].CHANGE ADDRESS"<<endl<<"[4].UPDATE SPECIALIZATION"<<endl<<"[5].UPDATE EPERIENCE"<<endl<<"[6].UPDATE SALARAY"<<endl<<"[7].CHANGE SHIFT DETAILS"<<endl;
                                                cout<<"ENTER YOUR CHOICE : ";
                                                L7 : cin>>choice;
                                                if(checkUpdate(choice,7))
                                                {
                                                                cout<<"ENTER A VALID OPTION : ";
                                                                goto L7;
                                                }
                                                update(choice);
                                                fout.write((char*)this,sizeof(*this));
                                }
                                else
                                {
                                                fout.write((char*)this,sizeof(*this));
                                }
                                fin.read((char*)this,sizeof(*this));
                }
                fin.close();
                fout.close();
                remove("DOCTOR DETAILS.txt");
                rename("TEMP.txt","DOCTOR DETAILS.txt");
                if(flag==0)
                {
                                cout<<endl<<"SORRY! NO SUCH DOCTOR WORKS HERE"<<endl;
                }
}
void Doctor::DisplayShift()
{
                char tempShift[20];
                cout<<"ENTER THE SHIFT : ";
                L10: cin>>tempShift;
                if(checkShift(tempShift))
                {
                                cout<<"NO SUCH SHIFT EXISTS.";
                                cout<<"ENTER VALID SHIFT : ";
                                goto L10;
                }
                fstream fin;
                int flag=0;
                fin.open("DOCTOR DETAILS.txt",ios::in|ios::binary);
                if(!fin)
                {
                                cout<<"ERROR OPENING THE FILE"<<endl;
                                return;
                }
                cout<<"\t\t\t\t"<<tempShift<<" SHIFT DETAILS"<<endl<<endl;
                fin.read((char*)this,sizeof(*this));
                while(fin)
                {
                                if(!strcmp(tempShift,shift))
                                {
                                                flag=1;
                                                display2();
                                                cout<<endl;
                                }
                                fin.read((char*)this,sizeof(*this));
                }
                fin.close();
                if(flag==0)
                {
                                cout<<"NO DOCTORS WORK ON THAT SHIFT"<<endl;
                }
}
void Doctor::DisplayExperience()
{
                int years;
                cout<<"ENTER THE MINIMUM EXPERIENCE IN YEARS : ";
                L11:cin>>years;
                if(checkInt(years))
                {
                                cout<<"ENTER VALID YEARS OF EXPERIENCE : ";
                                goto L11;
                }
                int flag=0;
                fstream fin;
                fin.open("DOCTOR DETAILS.txt",ios::out|ios::in|ios::binary);
                if(!fin)
                {
                                cout<<"ERROR OPENING THE FILE"<<endl;
                                return;
                }
                fin.read((char*)this,sizeof(*this));
                while(fin)
                {
                                if(experience>=years)
                                {
                                                flag=1;
                                                display2();
                                                cout<<endl;
                                }
                                fin.read((char*)this,sizeof(*this));
                }
                fin.close();
                if(flag==0)
                {
                                cout<<endl<<"DOCTORS WITH EXPERIENCE GREATER THAN "<<years<<" YEARS DO NOT WORK HERE."<<endl;
                }
}
void Doctor::DisplaySpecialization()
{
                char tempSpecialization[30];
                cout<<"ENTER THE SPECIALIZATION YOU WANT TO CHECK : ";
                cin>>tempSpecialization;
                int flag=0;
                fstream file;
                file.open("DOCTOR DETAILS.txt",ios::in|ios::out|ios::binary);
                if(!file)
                {
                                cout<<"ERROR OPENING THE FILE"<<endl;
                                return;
                }
                file.read((char*)this,sizeof(*this));
                while(file)
                {
                                if(!strcmp(specialist,tempSpecialization))
                                {
                                                flag=1;
                                                display2();
                                                cout<<endl;
                                }
                                file.read((char*)this,sizeof(*this));
                }
                file.close();
                if(flag==0)
                {
                                cout<<endl<<"WE DO NOT HAVE DOCTORS SPECIALIZED IN THAT FIELD."<<endl;
                }
}
//DEFINING THE PATIENT CLASS
class Patient:public Person
{
private:
                char disease[50];
                char date_of_admission[15];
                float medicine_cost;
                float labtest_cost;
public:
                void newRecord3();
                void display3();
                void update(int);
                float sum();
                char* getAdmission();
                char* getDisease();
                //FRIEND DUNCTIONS
                friend int checkFloat(float);
};
//DEFINING THE FUNCTIONS OF THE PATIENT CLASS
char* Patient::getAdmission()
{
                return date_of_admission;
}
char* Patient::getDisease()
{
                return disease;
}
void Patient::newRecord3()
{
                char tempDisease[50],tempAdmissionDate[15];
                Person::newRecord();
                cout<<"ENTER THE DISEASE : ";
                cin>>tempDisease;
                strcpy(disease,tempDisease);
                cout<<"ENTER THE DATE OF ADMISSION : ";
                cin>>tempAdmissionDate;
                strcpy(date_of_admission,tempAdmissionDate);
                cout<<"ENTER THE TOTAL MEDICINE COST : ";
                L12 : cin>>medicine_cost;
                if(checkFloat(medicine_cost))
                {
                                cout<<"ENTER VALID MEDICINE COST : ";
                                goto L12;
                }
                cout<<"ENTER THE TOTAL LAB TEST COSTS : ";
                L13 : cin>>labtest_cost;
                if(checkFloat(labtest_cost))
                {
                                cout<<"ENTER VALID LABTEST COST : ";
                                goto L13;
                }
}
void Patient::display3()
{
                Person::display();
                cout<<setw(30)<<left<<"DISEASE"<<" : "<<disease<<endl<<setw(30)<<left<<"DATE OF ADMISSION"<<" : "<<date_of_admission<<endl<<setw(30)<<left<<"MEDICINE BILL"<<" : "<<medicine_cost<<endl<<setw(30)<<left<<"LAB TEST BILL"<<" : "<<labtest_cost<<endl;
}
void Patient::update(int choice)
{
                switch(choice)
                {
                                case 1://TO CHANGE THE NAME
                                {
                                                Person::updateRecord(choice);
                                                break;
                                }
                                case 2://TO CHANGE THE AGE
                                {
                                                Person::updateRecord(choice);
                                                break;
                                }
                                case 3://TO CHANGE THE ADDRESS
                                {
                                                Person::updateRecord(choice);
                                                break;
                                }
                                case 4 ://TO CHANGE THE DISEASE NAME
                                {
                                                char tempDisease[50];
                                                cout<<"ENTER THE DISEASE NAME : ";
                                                cin>>tempDisease;
                                                strcpy(disease,tempDisease);
                                                break;
                                }
                                case 5 ://TO CHANGE THE DATE OF ADMISSION
                                {
                                                char tempDate[15];
                                                cout<<"ENTER THE DATE OF ADMISSION : ";
                                                cin>>tempDate;
                                                strcpy(date_of_admission,tempDate);
                                                break;
                                }
                                case 6 ://TO UPDATE THE MEDICINE COST
                                {
                                                cout<<"ENTER THE UPDATED MEDICINE COST : ";
                                                L14 : cin>>medicine_cost;
                                                if(checkFloat(medicine_cost))
                                                {
                                                                cout<<"ENTER VALID MEDICINE COST : ";
                                                                goto L14;
                                                }
                                                break;
                                }
                                case 7 ://TO UPDATE THE LAB COST
                                {
                                                cout<<"ENTER THE UPDATED LAB TEST COST : ";
                                                L15 : cin>>labtest_cost;
                                                if(checkFloat(labtest_cost))
                                                {
                                                                cout<<"ENTER VALID LABTEST COST : ";
                                                                goto L15;
                                                }
                                                break;
                                }
                }
}
float Patient::sum()
{
                float b = medicine_cost + labtest_cost;
                return b;
}
//DEFINING TWO SUBLASSES OF PATIENT CLASS
class InPatient:public Patient
{
private:
                char date_of_discharge[15];
                int days;
                float accomodation_cost;
                float bill;
public:
                void newRecord4();
                void display4();
                void update(int);
                float compute_bill();
                void storeInPatient();
                void readAllInPatients();
                void SearchInPatient();
                void DeleteIPR();
                void UpdateIPR();
                void DisplayAdmission();
                void DisplayDischarge();
                void DisplayDisease();
                //FRIEND FUNCTIONS
                friend int checkFloat(float);
                friend int checkInt(int);
};
//DEFINING THE FUNCTIONS OF THE INPATIENT CLASS
void InPatient::newRecord4()
{
                Patient::newRecord3();
                char tempDate[15];
                cout<<"ENTER THE DATE OF DISCHARGE : ";
                cin>>tempDate;
                strcpy(date_of_discharge,tempDate);
                cout<<"ENTER THE NO. OF DAYS SPENT IN THE HOSPITAL : ";
                L16 : cin>>days;
                if(checkInt(days))
                {
                                cout<<"ENTER VALID NO OF DAYS : ";
                                goto L16;
                }
                cout<<"ENTER THE ACCOMODATION COSTS PER DAY: ";
                L17 : cin>>accomodation_cost;
                if(checkFloat(accomodation_cost))
                {
                                cout<<"ENTER VALID COST : ";
                                goto L17;
                }
                bill=compute_bill();
}
void InPatient::display4()
{
                Patient::display3();
                cout<<setw(30)<<left<<"ACCOMODATION COST PER DAY"<<" : "<<accomodation_cost<<endl<<setw(30)<<left<<"DATE OF DISCHARGE"<<" : "<<date_of_discharge<<endl<<setw(30)<<left<<"NO. OF DAYS ADMITTED"<<" : "<<days<<endl<<setw(30)<<left<<"TOTAL BILL"<<" : "<<bill<<endl;
}
float InPatient::compute_bill()
{
                float b;
                b=(accomodation_cost*days) + Patient::sum();
                return b;
}
void InPatient::update(int choice)
{
                if(choice==1||choice==2||choice==3||choice==4||choice==5||choice==6||choice==7)
                {
                                Patient::update(choice);
                                if(choice==6||choice==7)
                                {
                                                goto L17;
                                }
                }
                else
                {
                                switch(choice)
                                {
                                                case 8:
                                                {
                                                                char n[15];
                                                                cout<<"ENTER THE NEW DATE OF DISCHARGE : ";
                                                                cin>>n;
                                                                strcpy(date_of_discharge,n);
                                                }
                                                case 9:
                                                {
                                                                cout<<"ENTER THE NO.OF DAYS ADMITTED : ";
                                                                L18:cin>>days;
                                                                if(checkInt(days))
                                                                {
                                                                                cout<<"ENTER VALID NO OF DAYS : ";
                                                                                goto L18;
                                                                }
                                                                goto L17;
                                                                break;
                                                }
                                                case 10:
                                                {
                                                                cout<<"ENTER THE NEW ACCOMODATION COST PER DAY : ";
                                                                L19 : cin>>accomodation_cost;
                                                                if(checkFloat(accomodation_cost))
                                                                {
                                                                                cout<<"ENTER VALID ACCOMODATION COST : ";
                                                                                goto L19;
                                                                }
                                                }
                                                case 11:
                                                {
                                                                L17 : bill=compute_bill();
                                                                break;
                                                }
                                }
                }
}
void InPatient::storeInPatient()
{
                fstream file;
                file.open("IN PATIENT DETAILS.txt",ios::out|ios::binary|ios::app);
                if(!file)
                {
                                cout<<"ERROR OPENING THE FILE"<<endl;
                                return;
                }
                file.write((char*)this,sizeof(*this));
                file.close();
}
void InPatient::readAllInPatients()
{
                fstream file;
                int flag=0;
                file.open("IN PATIENT DETAILS.txt",ios::in|ios::out|ios::binary);
                if(!file)
                {
                                cout<<"ERROR OPENING THE FILE"<<endl;
                                return;
                }
                cout<<"\t\t\t\tIN PATIENT RECORDS"<<endl<<endl;
                file.read((char*)this,sizeof(*this));
                while(file)
                {
                                flag=1;
                                display4();
                                cout<<"--------------------------------------------------------------------------------"<<endl;
                                cout<<endl;
                                file.read((char*)this,sizeof(*this));
                }
                file.close();
                if(flag==0)
                {
                                cout<<"NO RECORDS HAVE BEEN REGISTERED"<<endl;
                }
}
void InPatient::SearchInPatient()
{
                char tempName[30];
                int flag=0;
                cout<<"ENTER THE PATIENT NAME : ";
                cin>>tempName;
                fstream file;
                file.open("IN PATIENT DETAILS.txt",ios::in|ios::binary);
                if(!file)
                {
                         cout<<"ERROR OPENING THE FILE"<<endl;
                         return;
                }
                file.read((char*)this,sizeof(*this));
                while(file)
                {
                                if(!strcmp(tempName,getName()))
                                {
                                                flag=1;
                                                display4();
                                                cout<<endl;
                                }
                                file.read((char*)this,sizeof(*this));
                }
                file.close();
                if(flag==0)
                {
                                cout<<"NO SUCH PATIENT RECORDED"<<endl;
                }
}
void InPatient::DeleteIPR()
{
                cout<<"ENTER NAME OF PATIENT YOU WANT TO DELETE : ";
                char tempName[30];
                cin>>tempName;
                int flag=0;
                fstream fout,fin;
                fin.open("IN PATIENT DETAILS.txt",ios::in|ios::out|ios::binary);
                if(!fin)
                {
                                cout<<"ERROR OPENING THE FILE"<<endl;
                                return;
                }
                fout.open("TEMP1.txt",ios::out|ios::binary|ios::app);
                if(!fout)
                {
                                cout<<"ERROR OPENING THE FILE"<<endl;
                                return;
                }
                fin.read((char*)this,sizeof(*this));
                while(fin)
                {
                          if(!strcmp(tempName,getName()))
                          {
                                          flag=1;
                          }
                          else
                          {
                                          fout.write((char*)this,sizeof(*this));
                          }
                          fin.read((char*)this,sizeof(*this));
                }
                fin.close();
                fout.close();
                if(flag==0)
                {
                                cout<<endl<<"NO SUCH PATIENT EXISTS"<<endl;
                }
                else
                {
                                cout<<endl<<"THE RECORD HAS BEEN SUCCESFULLY DELETED"<<endl;
                }
                remove("IN PATIENT DETAILS.txt");
                rename("TEMP1.txt","IN PATIENT DETAILS.txt");
}
void InPatient::UpdateIPR()
{
                char tempName[30];
                cout<<"ENTER THE NAME OF THE PATIENT WHOSE RECORD YOU WANT TO UPDATE : ";
                cin>>tempName;
                int flag=0;
                fstream fin,fout;
                fin.open("IN PATIENT DETAILS.txt",ios::in|ios::binary);
                if(!fin)
                {
                                cout<<"ERROR OPENING THE FILE"<<endl;
                                return;
                }
                fout.open("TEMP1.txt",ios::out|ios::binary|ios::app);
                if(!fout)
                {
                                cout<<"ERROR OPENING THE FILE"<<endl;
                                return;
                }
                fin.read((char*)this,sizeof(*this));
                while(fin)
                {
                                if(!strcmp(tempName,getName()))
                                {
                                                flag=1;
                                                int choice;
                                                cout<<"AVAILABLE OPTIONS"<<endl;
                                                cout<<"[1].EDIT NAME"<<endl<<"[2].EDIT AGE"<<endl<<"[3].CHANGE ADDRESS"<<endl<<"[4].CHANGE DISEASE NAME"<<endl<<"[5].CHANGE DATE OF ADMISSION"<<endl<<"[6].UPDATE MEDICINE COST"<<endl<<"[7].UPDATE LAB TEST COST"<<endl<<"[8].CHANGE DATE OF DISCHARGE"<<endl<<"[9].UPDATE NO OF DAYS ADMITTED IN HOSPITAL"<<endl<<"[10].UPDATE NEW ACCOMODATION COST"<<endl<<endl;
                                                cout<<"ENTER YOUR CHOICE : ";
                                                L20:cin>>choice;
                                                if(checkUpdate(choice,10))
                                                {
                                                                cout<<"ENTER VALID OPTION : ";
                                                                goto L20;
                                                }
                                                update(choice);
                                                fout.write((char*)this,sizeof(*this));
                                }
                                else
                                {
                                                fout.write((char*)this,sizeof(*this));
                                }
                                fin.read((char*)this,sizeof(*this));
                }
                fin.close();
                fout.close();
                remove("IN PATIENT DETAILS.txt");
                rename("TEMP1.txt","IN PATIENT DETAILS.txt");
                if(flag==0)
                {
                                cout<<"NO SUCH PATIENT RECORD EXISTS"<<endl;
                }
}
void InPatient::DisplayAdmission()
{
                char Date[15];
                cout<<"ENTER THE DATE OF ADMISSION : ";
                cin>>Date;
                int flag=0;
                fstream file;
                file.open("IN PATIENT DETAILS.txt",ios::in|ios::binary);
                if(!file)
                {
                                cout<<"ERROR OPENING THE FILE"<<endl;
                                return;
                }
                file.read((char*)this,sizeof(*this));
                while(file)
                {
                                if(!strcmp(Date,getAdmission()))
                                {
                                                flag=1;
                                                display4();
                                                cout<<endl;
                                }
                                file.read((char*)this,sizeof(*this));
                }
                file.close();
                if(flag==0)
                {
                                cout<<"NO PATIENTS WERE ADMITTED ON THAT DATE"<<endl;
                }
}
void InPatient::DisplayDischarge()
{
                char date[15];
                cout<<"ENTER THE DATE OF DISCHARGE : ";
                cin>>date;
                int flag=0;
                fstream file;
                file.open("IN PATIENT DETAILS.txt",ios::in|ios::binary);
                if(!file)
                {
                                cout<<"ERROR OPENING THE FILE"<<endl;
                                return;
                }
                file.read((char*)this,sizeof(*this));
                while(file)
                {
                                if(!strcmp(date,date_of_discharge))
                                {
                                                flag=1;
                                                display4();
                                                cout<<"---------------------------------------------------------------------"<<endl;
                                                cout<<endl;
                                }
                                file.read((char*)this,sizeof(*this));
                }
                file.close();
                if(flag==0)
                {
                                cout<<"NO PATIENTS WERE DISCHARGED ON THAT DATE"<<endl;
                }
}
void InPatient::DisplayDisease()
{
                char Disease[50];
                cout<<"ENTER THE DISEASE : ";
                cin>>Disease;
                int flag=0;
                fstream file;
                file.open("IN PATIENT DETAILS.txt",ios::in|ios::binary);
                if(!file)
                {
                                cout<<"ERROR OPENING THE FILE"<<endl;
                                return;
                }
                file.read((char*)this,sizeof(*this));
                while(file)
                {
                                if(!strcmp(Disease,getDisease()))
                                {
                                                flag=1;
                                                display4();
                                                cout<<"----------------------------------------------------------------------"<<endl;
                                                cout<<endl;
                                }
                                file.read((char*)this,sizeof(*this));
                }
                file.close();
                if(flag==0)
                {
                                cout<<"NO PATIENTS WERE ADMITTED WITH THAT DISEASE"<<endl;
                }
}
//DEFINING THE SUBCLASS OF THE PATIENT CLASS
class OutPatient:public Patient
{
private:
                float consultation_fee;
                float bill;
public:
                void newRecord5();
                void display5();
                void update(int);
                float compute_bill();
                void storeOutPatient();
                void readAllOutPatient();
                void SearchOutPatient();
                void DeleteOPR();
                void UpdateOPR();
                void DisplayDate();
                void DisplayDisease();
                //FRIEND FUNCTIONS
                friend int checkFloat(float);
};
//DEFINING THE FUNCTIONS OF THE OUT PATIENT CLASS
void OutPatient::newRecord5()
{
                Patient::newRecord3();
                cout<<"ENTER THE CONSULATION FEE : ";
                L21 : cin>>consultation_fee;
                if(checkFloat(consultation_fee))
                {
                                cout<<"ENTER VALID CONSULTATION FEES : ";
                                goto L21;
                }
                bill = compute_bill();
}
void OutPatient::display5()
{
                Patient::display3();
                cout<<setw(30)<<left<<"CONSULATION FEES"<<" : "<<consultation_fee<<endl<<setw(30)<<left<<"BILL"<<" : "<<bill<<endl;
}
float OutPatient::compute_bill()
{
                float bill=Patient::sum()+consultation_fee;
                return bill;
}
void OutPatient::update(int choice)
{
                if(choice==1||choice==2||choice==3||choice==4||choice==5||choice==6||choice==7)
                {
                                Patient::update(choice);
                                if(choice==6 || choice==7)
                                {
                                                goto L22;
                                }
                }
                else
                {
                                switch(choice)
                                {
                                                case 8 :
                                                {
                                                                cout<<"ENTER THE NEW CONSULATION FEE : ";
                                                                L23 : cin>>consultation_fee;
                                                                if(checkFloat(consultation_fee))
                                                                {
                                                                                cout<<"ENTER VALID CONSULTATION FEE : ";
                                                                                goto L23;
                                                                }
                                                                L22 : bill=compute_bill();
                                                }
                                }
                }
}
void OutPatient::storeOutPatient()
{
                fstream file;
                file.open("OUT PATIENT DETAILS.txt",ios::out|ios::binary|ios::app);
                if(!file)
                {
                                cout<<"ERROR OPENING THE FILE"<<endl;
                                return;
                }
                file.write((char*)this,sizeof(*this));
                file.close();
}
void OutPatient::readAllOutPatient()
{
                fstream file;
                int flag=0;
                file.open("OUT PATIENT DETAILS.txt",ios::in|ios::binary);
                if(!file)
                {
                                cout<<"ERROR OPENING THE FILE"<<endl;
                                return;
                }
                file.read((char*)this,sizeof(*this));
                while(file)
                {
                                flag=1;
                                display5();
                                cout<<"---------------------------------------------------------------------"<<endl;
                                cout<<endl;
                                file.read((char*)this,sizeof(*this));
                }
                file.close();
                if(flag==0)
                {
                                cout<<"NO OUT PATIENT REGISTERED YET"<<endl;
                }
}
void OutPatient::SearchOutPatient()
{
                char tempName[30];
                cout<<"ENTER THE NAME OF THE OUT PATIENT YOU WANT TO SEARCH : ";
                cin>>tempName;
                int flag=0;
                fstream file;
                file.open("OUT PATIENT DETAILS.txt",ios::in|ios::binary);
                if(!file)
                {
                                cout<<"ERROR OPENING THE FILE"<<endl;
                                return;
                }
                file.read((char*)this,sizeof(*this));
                while(file)
                {
                                if(!strcmp(tempName,getName()))
                                {
                                                flag=1;
                                                display5();
                                                cout<<endl;
                                }
                                file.read((char*)this,sizeof(*this));
                }
                file.close();
                if(flag==0)
                {
                                cout<<"NO SUCH OUT PATIENT RECORD EXISTS"<<endl;
                }
}
void OutPatient::DeleteOPR()
{
                fstream fin,fout;
                char tempName[30];
                cout<<"ENTER THE NAME OF THE OUT PATIENT WHOSE RECORD YOU WANT TO DELETE : ";
                cin>>tempName;
                int flag=0;
                fin.open("OUT PATIENT DETAILS.txt",ios::in|ios::binary);
                if(!fin)
                {
                                cout<<"ERROR OPENING THE FILE"<<endl;
                                return;
                }
                fout.open("TEMP.txt",ios::out|ios::binary|ios::app);
                if(!fout)
                {
                                cout<<"ERROR OPENING THE FILE"<<endl;
                                return;
                }
                fin.read((char*)this,sizeof(*this));
                while(fin)
                {
                                if(!strcmp(tempName,getName()))
                                {
                                                flag=1;
                                }
                                else
                                {
                                                fout.write((char*)this,sizeof(*this));
                                }
                                fin.read((char*)this,sizeof(*this));
                }
                fin.close();
                fout.close();
                if(flag==0)
                {
                                cout<<"NO SUCH OUT PATIENT RECORD EXISTS"<<endl;
                }
                remove("OUT PATIENT DETAILS.txt");
                rename("TEMP.txt","OUT PATIENT DETAILS.txt");
}
void OutPatient::UpdateOPR()
{
                char tempName[30];
                cout<<"ENTER THE NAME OF THE PATIENT WHOSE RECORD YOU WANT TO UPDATE : ";
                cin>>tempName;
                int flag=0;
                fstream fin,fout;
                fin.open("OUT PATIENT DETAILS.txt",ios::in|ios::binary);
                if(!fin)
                {
                                cout<<"ERROR OPENING THE FILE"<<endl;
                                return;
                }
                fout.open("TEMP.txt",ios::out|ios::binary|ios::app);
                if(!fout)
                {
                                cout<<"ERROR OPENING THE FILE"<<endl;
                                return;
                }
                fin.read((char*)this,sizeof(*this));
                while(fin)
                {
                                if(!strcmp(tempName,getName()))
                                {
                                                flag=1;
                                                int choice;
                                                cout<<"AVAILABLE OPTIONS"<<endl;
                                                cout<<"[1].EDIT NAME"<<endl<<"[2].EDIT AGE"<<endl<<"[3].CHANGE ADDRESS"<<endl<<"[4].CHANGE DISEASE NAME"<<endl<<"[5].CHANGE DATE OF ADMISSION"<<endl<<"[6].UPDATE MEDICINE COST"<<endl<<"[7].UPDATE LAB TEST COST"<<endl<<"[8].UPDATE THE CONSULATATION FEE"<<endl;
                                                cout<<"ENTER YOUR CHOICE : ";
                                                L24 : cin>>choice;
                                                if(checkUpdate(choice,8))
                                                {
                                                                cout<<"ENTER VALID OPTION : ";
                                                                goto L24;
                                                }
                                                update(choice);
                                                fout.write((char*)this,sizeof(*this));
                                }
                                else
                                {
                                                fout.write((char*)this,sizeof(*this));
                                }
                                fin.read((char*)this,sizeof(*this));
                }
                fin.close();
                fout.close();
                remove("OUT PATIENT DETAILS.txt");
                rename("TEMP.txt","OUT PATIENT DETAILS.txt");
                if(flag==0)
                {
                                cout<<"NO SUCH OUT PATIENT RECORD EXISTS"<<endl;
                }
}
void OutPatient::DisplayDate()
{
                char Date[15];
                cout<<"ENTER THE DATE OF CONSULTATION : ";
                cin>>Date;
                int flag=0;
                fstream file;
                file.open("OUT PATIENT DETAILS.txt",ios::in|ios::binary);
                if(!file)
                {
                                cout<<"ERROR OPENING THE FILE"<<endl;
                                return;
                }
                file.read((char*)this,sizeof(*this));
                while(file)
                {
                                if(!strcmp(Date,getAdmission()))
                                {
                                                flag=1;
                                                display5();
                                                cout<<"---------------------------------------------------------------------"<<endl;
                                                cout<<endl;
                                }
                                file.read((char*)this,sizeof(*this));
                }
                file.close();
                if(flag==0)
                {
                                cout<<"NO PATIENTS WERE CHECKED ON THAT DATE"<<endl;
                }
}
void OutPatient::DisplayDisease()
{
                char Disease[50];
                cout<<"ENTER THE DISEASE : ";
                cin>>Disease;
                int flag=0;
                fstream file;
                file.open("OUT PATIENT DETAILS.txt",ios::in|ios::binary);
                if(!file)
                {
                                cout<<"ERROR OPENING THE FILE"<<endl;
                                return;
                }
                file.read((char*)this,sizeof(*this));
                while(file)
                {
                                if(!strcmp(Disease,getDisease()))
                                {
                                                flag=1;
                                                display5();
                                                cout<<"--------------------------------------------------------------------"<<endl;
                                                cout<<endl;
                                }
                                file.read((char*)this,sizeof(*this));
                }
                file.close();
                if(flag==0)
                {
                                cout<<"NO PATIENTS WERE DIAGNOSED WITH THAT DISEASE"<<endl;
                }
}

//MAIN FUNCTION
int main()
{
                int choice1;
                M1 : system("cls");
                system("color 0A");
                cout<<endl<<endl<<"\t\t\t\t\tWELCOME TO SMILE HOSPITAL!!!!!!!\t\t\t\t\t\t"<<endl;
                cout<<"\t\t\t\t************************************************\t\t\t"<<endl<<endl;
                cout<<setw(20)<<right<<"\t\tAVAILABLE RECORDS"<<endl<<endl<<"[1].DOCTOR"<<endl<<"[2].PATIENTS"<<endl<<"[3].EXIT"<<endl<<endl;
                //GETTING WHOSE RECORD THE USER WANTS TO ACCESS
                cout<<"ENTER WHOSE DETAILS YOU WANT TO MANIPULATE OR CLICK EXIT :  ";
                M2 : cin>>choice1;
                if(checkUpdate(choice1,3))
                {
                                cout<<"ENTER VALID OPTION : ";
                                goto M2;
                }
                switch(choice1)
                {
                                case 1://MANIPULATING THE RECORDS OF THE DOCTOR
                                {
                                                Doctor D;
                                                int choice2;
                                                M3 : system("cls");
                                                system("color 70");
                                                cout<<setw(25)<<right<<"\t\tDOCTOR RECORDS"<<endl<<endl;
                                                cout<<"\t\tAVAILABLE OPTIONS"<<endl<<endl<<"[1].ADD NEW RECORD"<<endl<<"[2].VIEW ALL DOCTOR DETAILS"<<endl<<"[3].SEARCH A DOCTOR"<<endl<<"[4].DELETE RECORD"<<endl<<"[5].UPDATE A RECORD"<<endl<<"[6].DISPLAY ALL DOCTORS OF A PARTICULAR SHIFT"<<endl<<"[7].DISPLAY ALL THE DOCTORS WITH A CERTAIN MINIMAL EXPERIENCE"<<endl<<"[8].DISPLAY ALL DOCTORS OF SPECIAL FIELD"<<endl<<"[9].EXIT"<<endl<<endl;
                                                cout<<"ENTER YOUR CHOICE :  ";
                                                M4 : cin>>choice2;
                                                if(checkUpdate(choice2,9))
                                                {
                                                                cout<<"ENTER VALID OPTION : ";
                                                                goto M4;
                                                }
                                                switch(choice2)
                                                {
                                                                case 1 ://TO ADD NEW DOCTOR RECORD
                                                                {
                                                                                char ask;
                                                                                system("cls");
                                                                                cout<<endl<<endl<<"\t\t\tADD NEW DOCTOR RECORD"<<endl<<endl;
                                                                                M5 : cout<<endl<<"ENTER THE DETAILS OF THE NEW DOCTOR "<<endl<<endl;
                                                                                D.newRecord2();
                                                                                D.storeDoctor();
                                                                                cout<<endl;
                                                                                cout<<"WOULD YOU LIKE TO ADD ANOTHER RECORD : ";
                                                                                cin>>ask;
                                                                                if(ask=='Y'||ask=='y')
                                                                                {
                                                                                                goto M5;
                                                                                }
                                                                                getch();
                                                                                break;
                                                                }
                                                                case 2://TO VIEW ALL DOCTOR RECORDS
                                                                {
                                                                                system("cls");
                                                                                D.readAllDoctor();
                                                                                getch();
                                                                                break;
                                                                }
                                                                case 3://TO SEARCH A DOCTOR
                                                                {
                                                                                char ask;
                                                                                system("cls");
                                                                                cout<<endl<<endl<<"\t\t\tSEARCHING A DOCTOR RECORD"<<endl<<endl;
                                                                                M6 : D.searchDoctor();
                                                                                cout<<endl;
                                                                                cout<<"WOULD YOU LIKE TO SEARCH ANOTHER RECORD : ";
                                                                                cin>>ask;
                                                                                if(ask=='Y'||ask=='y')
                                                                                {
                                                                                                goto M6;
                                                                                }
                                                                                getch();
                                                                                break;
                                                                }
                                                                case 4://DELETE A DOCTOR RECORD
                                                                {
                                                                                char ask;
                                                                                system("cls");
                                                                                cout<<endl<<endl<<"\t\t\tDELETING A DOCTOR RECORD"<<endl<<endl;
                                                                                M7 : D.deleteDoctor();
                                                                                cout<<endl;
                                                                                cout<<"WOULD YOU LIKE TO DELETE ANOTHER RECORD : ";
                                                                                cin>>ask;
                                                                                if(ask=='Y'||ask=='y')
                                                                                {
                                                                                                goto M7;
                                                                                }
                                                                                getch();
                                                                                break;
                                                                }
                                                                case 5://TO UPDATE A DOCTOR RECORD
                                                                {
                                                                                char ask;
                                                                                system("cls");
                                                                                cout<<endl<<endl<<"\t\t\tUPDATING A DOCTOR RECORD"<<endl<<endl;
                                                                                M8 : D.updateDoctor();
                                                                                cout<<endl;
                                                                                cout<<"WOULD YOU LIKE TO UPDATE ANOTHER RECORD : ";
                                                                                cin>>ask;
                                                                                if(ask=='Y'||ask=='y')
                                                                                {
                                                                                                goto M8;
                                                                                }
                                                                                getch();
                                                                                break;
                                                                }
                                                                case 6://TO DISPLAY ALL DOCTORS OF A PARTICULAR SHIFT
                                                                {
                                                                                char ask;
                                                                                system("cls");
                                                                                cout<<endl<<endl<<"\t\t\tDISPLAYING DOCTOR RECORDS SHIFT WISE"<<endl<<endl;
                                                                                M9 : D.DisplayShift();
                                                                                cout<<endl;
                                                                                cout<<"WOULD YOU LIKE TO SEE ANOTHER SHIFT DETAILS : ";
                                                                                cin>>ask;
                                                                                if(ask=='Y'||ask=='y')
                                                                                {
                                                                                                goto M9;
                                                                                }
                                                                                getch();
                                                                                break;
                                                                }
                                                                case 7://TO DISPLAY ALL DOCTORS WITH A MINIMUM EXPERIENCE
                                                                {
                                                                                char ask;
                                                                                system("cls");
                                                                                cout<<endl<<endl<<"\t\t\tDISPLAYING DOCTOR RECORDS WITH A CERTAIN MINIMAL EXPERIENCE"<<endl<<endl;
                                                                                M10 : D.DisplayExperience();
                                                                                cout<<endl;
                                                                                cout<<"WOULD YOU LIKE TO CHECK FOR ANOTHER YEAR : ";
                                                                                cin>>ask;
                                                                                if(ask=='Y'||ask=='y')
                                                                                {
                                                                                                goto M10;
                                                                                }
                                                                                getch();
                                                                                break;
                                                                }
                                                                case 8://TO DISPLAY ALL SPECIALISTS AVAILABLE
                                                                {
                                                                                char ask;
                                                                                system("cls");
                                                                                cout<<endl<<endl<<"\t\t\tDISPLAYING ALL DOCTOR RECORDS OF A SPECIALISATION"<<endl<<endl;
                                                                                M11 : D.DisplaySpecialization();
                                                                                cout<<endl;
                                                                                cout<<"WOULD YOU LIKE TO SEE THE LIST OF SOME OTHER SPECIALIZATION : ";
                                                                                cin>>ask;
                                                                                if(ask=='Y'||ask=='y')
                                                                                {
                                                                                                goto M11;
                                                                                }
                                                                                getch();
                                                                                break;
                                                                }
                                                                case 9://TO EXIT THE DOCTOR MENU
                                                                {
                                                                                goto M1;
                                                                }
                                                }
                                                goto M3;
                                                break;
                                }
                                case 2://MANIPULATING THE RECORDS OF THE PATIENTS
                                {
                                                int choice3;
                                                M12 : system("cls");
                                                system("color 03");
                                                cout<<endl<<"\t\tTYPE"<<endl<<endl;
                                                cout<<"[1].IN PATIENT"<<endl<<"[2].OUT PATIENT"<<endl<<"[3].EXIT"<<endl<<endl;
                                                cout<<"ENTER YOUR CHOICE :  ";
                                                M13 : cin>>choice3;
                                                if(checkUpdate(choice3,3))
                                                {
                                                                cout<<"ENTER VALID OPTION : ";
                                                                goto M13;
                                                }
                                                switch(choice3)
                                                {
                                                                case 1://MANIPULATING IN PATIENT RECORDS
                                                                {
                                                                                InPatient IP;
                                                                                int choice4;
                                                                                M14 : system("cls");
                                                                                system("color b0");
                                                                                cout<<"\t\t\t\tIN PATIENT RECORDS"<<endl<<endl;
                                                                                cout<<endl<<"\t\tAVAILABLE OPTIONS"<<endl<<endl;
                                                                                cout<<"[1].ADD NEW RECORD"<<endl<<"[2].DISPLAY ALL PATIENT RECORDS"<<endl<<"[3].SEARCH PATIENT"<<endl<<"[4].DELETE IN PATIENT RECORD"<<endl<<"[5].UPDATE IN PATIENT RECORD"<<endl<<"[6].DISPLAY ADMISSIONS ON A PARTICULAR DATE"<<endl<<"[7].DISPLAY DISCHARGES ON A PARTICULAR DATE"<<endl<<"[8].DISPLAY ALL RECORDS OF A PARTICULAR DISEASE"<<endl<<"[9].EXIT"<<endl<<endl;
                                                                                cout<<"ENTER YOUR CHOICE :  ";
                                                                                M15 : cin>>choice4;
                                                                                if(checkUpdate(choice4,9))
                                                                                {
                                                                                                cout<<"ENTER A VALID OPTION : ";
                                                                                                goto M15;
                                                                                }
                                                                                switch(choice4)
                                                                                {
                                                                                                case 1://ADD NEW IN PATIENT RECORD
                                                                                                {
                                                                                                                char ask;
                                                                                                                system("cls");
                                                                                                                cout<<endl<<endl<<"\t\t\tADD NEW IN PATIENT RECORD"<<endl<<endl;
                                                                                                                M16 : cout<<endl<<"ENTER THE DETAILS OF THE NEW INPATIENT RECORD"<<endl<<endl;
                                                                                                                IP.newRecord4();
                                                                                                                IP.storeInPatient();
                                                                                                                cout<<endl;
                                                                                                                cout<<"WOULD YOU LIKE TO ADD ANOTHER RECORD : ";
                                                                                                                cin>>ask;
                                                                                                                if(ask=='Y'||ask=='y')
                                                                                                                {
                                                                                                                                goto M16;
                                                                                                                }
                                                                                                                getch();
                                                                                                                break;
                                                                                                }
                                                                                                case 2://DISPLAY ALL IN PATIENT RECORDS
                                                                                                {
                                                                                                                system("cls");
                                                                                                                cout<<endl<<endl<<"\t\t\tDISPLAYNG ALL IN PATIENT RECORD"<<endl<<endl;
                                                                                                                IP.readAllInPatients();
                                                                                                                cout<<endl;
                                                                                                                getch();
                                                                                                                break;
                                                                                                }
                                                                                                case 3://SEARCH A PARTICULAR IN PATIENT
                                                                                                {
                                                                                                                char ask;
                                                                                                                system("cls");
                                                                                                                cout<<endl<<endl<<"\t\t\tSEARCH AN IN PATIENT RECORD"<<endl<<endl;
                                                                                                                M17 : IP.SearchInPatient();
                                                                                                                cout<<endl;
                                                                                                                cout<<"WOULD YOU LIKE TO SEARCH ANOTHER RECORD : ";
                                                                                                                cin>>ask;
                                                                                                                if(ask=='Y'||ask=='y')
                                                                                                                {
                                                                                                                                goto M17;
                                                                                                                }
                                                                                                                getch();
                                                                                                                break;
                                                                                                }
                                                                                                case 4://DELETE IN PATIENT RECORD
                                                                                                {
                                                                                                                char ask;
                                                                                                                system("cls");
                                                                                                                cout<<endl<<endl<<"\t\t\tDELETE AN IN PATIENT RECORD"<<endl<<endl;
                                                                                                                M18 : IP.DeleteIPR();
                                                                                                                cout<<endl;
                                                                                                                cout<<"WOULD YOU LIKE TO DELETE ANOTHER RECORD : ";
                                                                                                                cin>>ask;
                                                                                                                if(ask=='Y'||ask=='y')
                                                                                                                {
                                                                                                                                goto M18;
                                                                                                                }
                                                                                                                getch();
                                                                                                                break;
                                                                                                }
                                                                                                case 5://UPDATE IN PATIENT RECORD
                                                                                                {
                                                                                                                char ask;
                                                                                                                system("cls");
                                                                                                                cout<<endl<<endl<<"\t\t\tUPDATE AN IN PATIENT RECORD"<<endl<<endl;
                                                                                                                M19:IP.UpdateIPR();
                                                                                                                cout<<endl;
                                                                                                                cout<<"WOULD YOU LIKE TO UPDATE ANOTHER RECORD : ";
                                                                                                                cin>>ask;
                                                                                                                if(ask=='Y'||ask=='y')
                                                                                                                {
                                                                                                                                goto M19;
                                                                                                                }
                                                                                                                getch();
                                                                                                                break;
                                                                                                }
                                                                                                case 6://DISPLAY ADMISSIONS ON A PARTICULAR DATE
                                                                                                {
                                                                                                                char ask;
                                                                                                                system("cls");
                                                                                                                cout<<endl<<endl<<"\t\t\tDISPLAYNG ALL IN PATIENT RECORDS ADMITTED ON A PARTICULAR DATE"<<endl<<endl;
                                                                                                                M20:IP.DisplayAdmission();
                                                                                                                cout<<endl;
                                                                                                                cout<<"WOULD YOU LIKE TO SEE ADMISSIONS OF ANOTHER DATE : ";
                                                                                                                cin>>ask;
                                                                                                                if(ask=='Y'||ask=='y')
                                                                                                                {
                                                                                                                                goto M20;
                                                                                                                }
                                                                                                                getch();
                                                                                                                break;
                                                                                                }
                                                                                                case 7://DISPLAY DISCHARGES ON A PARTICULAR DATE
                                                                                                {
                                                                                                                char ask;
                                                                                                                system("cls");
                                                                                                                cout<<endl<<endl<<"\t\t\tDISPLAYNG ALL IN PATIENT RECORDS DISCHARGED ON A PARTICULAR DATE"<<endl<<endl;
                                                                                                                M21:IP.DisplayDischarge();
                                                                                                                cout<<endl;
                                                                                                                cout<<"WOULD YOU LIKE TO SEE DISCHARGES OF ANOTHER DATE : ";
                                                                                                                cin>>ask;
                                                                                                                if(ask=='Y'||ask=='y')
                                                                                                                {
                                                                                                                                goto M21;
                                                                                                                }
                                                                                                                getch();
                                                                                                                break;
                                                                                                }
                                                                                                case 8://DISPLAY IN PATIENT RECORDS OF A PARTICULAR DISEASE
                                                                                                {
                                                                                                                char ask;
                                                                                                                system("cls");
                                                                                                                cout<<endl<<endl<<"\t\t\tDISPLAYNG ALL IN PATIENT RECORDS OF A PARTICULAR DISEASE"<<endl<<endl;
                                                                                                                M22:IP.DisplayDisease();
                                                                                                                cout<<endl;
                                                                                                                cout<<"WOULD YOU LIKE TO SEE IN PATIENT RECORDS OF ANOTHER DISEASE : ";
                                                                                                                cin>>ask;
                                                                                                                if(ask=='Y'||ask=='y')
                                                                                                                {
                                                                                                                                goto M22;
                                                                                                                }
                                                                                                                getch();
                                                                                                                break;
                                                                                                }
                                                                                                case 9://EXIT FROM THE IN PATIENT RECORDS
                                                                                                {
                                                                                                                goto M12;
                                                                                                }
                                                                                }
                                                                                goto M14;
                                                                                break;
                                                                }
                                                                case 2://MANIPULATING OUT PATIENT RECORDS
                                                                {
                                                                                OutPatient OP;
                                                                                int choice5;
                                                                                M23 : system("cls");
                                                                                system("color b0");
                                                                                cout<<endl<<"\t\t\t\t\tOUT PATIENT RECORDS"<<endl;
                                                                                cout<<endl<<"\t\tAVAILABLE OPTIONS"<<endl<<endl;
                                                                                cout<<"[1].ADD NEW RECORD"<<endl<<"[2].DISPLAY ALL PATIENT RECORDS"<<endl<<"[3].SEARCH PATIENT"<<endl<<"[4].DELETE OUT PATIENT RECORD"<<endl<<"[5].UPDATE OUT PATIENT RECORD"<<endl<<"[6].DISPLAY CONSULTATIONS ON A PARTICULAR DATE"<<endl<<"[7].DISPLAY ALL RECORDS OF A PARTICULAR DISEASE"<<endl<<"[8].EXIT"<<endl<<endl;
                                                                                cout<<"ENTER YOUR CHOICE :  ";
                                                                                M24 : cin>>choice5;
                                                                                if(checkUpdate(choice5,8))
                                                                                {
                                                                                                cout<<"ENTER VALID OPTION : ";
                                                                                                goto M24;
                                                                                }
                                                                                switch(choice5)
                                                                                {
                                                                                                case 1://ADD NEW OUT PATIENT RECORD
                                                                                                {
                                                                                                                char ask;
                                                                                                                system("cls");
                                                                                                                cout<<endl<<endl<<"\t\t\tADD NEW OUT PATIENT RECORD"<<endl<<endl;
                                                                                                                M25 : cout<<endl<<"ENTER THE DETAILS OF THE NEW INPATIENT RECORD"<<endl<<endl;
                                                                                                                OP.newRecord5();
                                                                                                                OP.storeOutPatient();
                                                                                                                cout<<endl;
                                                                                                                cout<<"WOULD YOU LIKE TO ADD ANOTHER RECORD : ";
                                                                                                                cin>>ask;
                                                                                                                if(ask=='Y'||ask=='y')
                                                                                                                {
                                                                                                                                goto M25;
                                                                                                                }
                                                                                                                getch();
                                                                                                                break;
                                                                                                }
                                                                                                case 2://DISPLAY ALL OUT PATIENT RECORDS
                                                                                                {
                                                                                                                system("cls");
                                                                                                                cout<<endl<<endl<<"\t\t\t\tOUT PATIENT RECORDS"<<endl<<endl;
                                                                                                                OP.readAllOutPatient();
                                                                                                                cout<<endl;
                                                                                                                getch();
                                                                                                                break;
                                                                                                }
                                                                                                case 3://SEARCH A PARTICULAR OUT PATIENT RECORD
                                                                                                {
                                                                                                                char ask;
                                                                                                                system("cls");
                                                                                                                cout<<endl<<endl<<"\t\t\tSEARCH AN OUT PATIENT RECORD"<<endl<<endl;
                                                                                                                M26 : OP.SearchOutPatient();
                                                                                                                cout<<endl;
                                                                                                                cout<<"WOULD YOU LIKE TO SEARCH ANOTHER RECORD : ";
                                                                                                                cin>>ask;
                                                                                                                if(ask=='Y'||ask=='y')
                                                                                                                {
                                                                                                                                goto M26;
                                                                                                                }
                                                                                                                getch();
                                                                                                                break;
                                                                                                }
                                                                                                case 4://DELETE A PARTICULAR OUTPATIENT RECORD
                                                                                                {
                                                                                                                char ask;
                                                                                                                system("cls");
                                                                                                                cout<<endl<<endl<<"\t\t\tDELETE AN OUT PATIENT RECORD"<<endl<<endl;
                                                                                                                M27 : OP.DeleteOPR();
                                                                                                                cout<<endl;
                                                                                                                cout<<"WOULD YOU LIKE TO DELETE ANOTHER RECORD : ";
                                                                                                                cin>>ask;
                                                                                                                if(ask=='Y'||ask=='y')
                                                                                                                {
                                                                                                                                goto M27;
                                                                                                                }
                                                                                                                getch();
                                                                                                                break;
                                                                                                }
                                                                                                case 5://UPDATE A PARTICULAR RECORD
                                                                                                {
                                                                                                                char ask;
                                                                                                                system("cls");
                                                                                                                cout<<endl<<endl<<"\t\t\tUPDATE AN OUT PATIENT RECORD"<<endl<<endl;
                                                                                                                M28:OP.UpdateOPR();
                                                                                                                cout<<endl;
                                                                                                                cout<<"WOULD YOU LIKE TO UPDATE ANOTHER RECORD : ";
                                                                                                                cin>>ask;
                                                                                                                if(ask=='Y'||ask=='y')
                                                                                                                {
                                                                                                                                goto M28;
                                                                                                                }
                                                                                                                getch();
                                                                                                                break;
                                                                                                }
                                                                                                case 6://DISPLAY ALL OUT PATIENT RECORDS OF A PARTICULAR DATE
                                                                                                {
                                                                                                                char ask;
                                                                                                                system("cls");
                                                                                                                cout<<endl<<endl<<"\t\t\tDISPLAY ALL OUT PATIENT RECORDS OF A PARTICULAR DATE"<<endl<<endl;
                                                                                                                M29:OP.DisplayDate();                                                                                                                cout<<endl;
                                                                                                                cout<<"WOULD YOU LIKE TO SEE THE RECORD OF ANOTHER DATE : ";
                                                                                                                cin>>ask;
                                                                                                                if(ask=='Y'||ask=='y')
                                                                                                                {
                                                                                                                                goto M29;
                                                                                                                }
                                                                                                                getch();
                                                                                                                break;
                                                                                                }
                                                                                                case 7://DISPLAY ALL OUT PATIENT RECORDS WITH SAME DISEASE
                                                                                                {
                                                                                                                char ask;
                                                                                                                system("cls");
                                                                                                                cout<<endl<<endl<<"\t\t\tDISPLAYING ALL OUT PATIENT RECORDS OF A PARTICULAR DISEASE"<<endl<<endl;
                                                                                                                M30:OP.DisplayDisease();
                                                                                                                cout<<endl;
                                                                                                                cout<<"WOULD YOU LIKE TO SEE OUT PATIENT RECORDS OF ANOTHER DISEASE : ";
                                                                                                                cin>>ask;
                                                                                                                if(ask=='Y'||ask=='y')
                                                                                                                {
                                                                                                                                goto M30;
                                                                                                                }
                                                                                                                getch();
                                                                                                                break;
                                                                                                }
                                                                                                case 8://EXIT THE OUT PATIENT RECORD
                                                                                                {
                                                                                                                goto M12;
                                                                                                }
                                                                                }
                                                                                goto M23;
                                                                                break;
                                                                }
                                                                case 3://EXIT FROM PATIENT RECORDS
                                                                {
                                                                                goto M1;
                                                                }
                                                }
                                                goto M12;
                                                break;
                                }
                                case 3://TO EXIT THE PROGRAM
                                {
                                                return 0;
                                }
                }
                goto M1;
}
