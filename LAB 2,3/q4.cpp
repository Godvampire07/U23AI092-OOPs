#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;
class info{
       string name;
       string sex;
       int age;
       int wardno;
       int bedno;
       string disease;
       string doa;
       public:
       info();
       info(string name,string sex,int age,int wardno,int bedno,string disease,string doa){
        cout<<"\t<<Patient INFO>>\t"<<endl;
        this->age = age;
        this->bedno = bedno;
        this->disease = disease;
        this->doa = doa;
        this->name = name;
        this->sex = sex;
        this->wardno = wardno;
       }
       ~info(){
        cout<<"Thanks.";
       }
       inline void display(){
           cout<<"\n\nPATIENT DETAILS GIVEN:"<<endl;
           cout<<"Patient's name: "<<name<<endl;
           cout<<"sex: "<<sex<<endl;
           cout<<"Age: "<<age<<endl;
           cout<<"Ward Number: "<<wardno<<endl;
           cout<<"Bed number: "<<bedno<<endl;
           cout<<"Disease: "<<disease<<endl;
           cout<<"Day of admission: "<<doa<<endl;
       } 
       void get(){
         cout<<"Enter name:";
         cin>>name;
         cout<<"Sex:(MALE/FEMALE):";
         cin>>sex;
         cout<<"AGE:";
         cin>>age;
         cout<<"Day of admission:";
         cin>>doa;
         cout<<"Give Ward number:";
         cin>>wardno;
         cout<<"Give Bed number:";
         cin>>bedno;
         cout<<"Disease:";
         cin>>disease;
      }   
       friend class db;
};
class db{
    info x;
      public:
      void displaydata(){
        x.display();
      }
      db(){
        cout<<"PATIENT DETAILS:-"<<endl;
        cout<<"Enter Data:"<<endl;
        x.get();
      }
      ~db(){
        cout<<"Details completed.\t\t(Destructor called)"<<endl;
      }
      
};
info::info(){
    cout<<"\t\t<<Patient INFO>>\t(default constructor is called)"<<endl;
}
int main(){
      db a;
      a.displaydata();
}