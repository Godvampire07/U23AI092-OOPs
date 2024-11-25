#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;
class info{
       string name;
       string Sname;
       int code;
       int rollno;
       int inter;
       int exter;
       public:
       info();
       info(string name,string Sname,int code,int rollno,int inter,int exter){
        cout<<"\t<<Student INFO>>\t"<<endl;
        this->code = code;
        this->inter = inter;
        this->exter = exter;
        this->name = name;
        this->Sname = Sname;
        this->rollno = rollno;
       }
       ~info(){
        cout<<"Thanks.";
       }
       inline void display(){
           cout<<"\n\nStudent DETAILS GIVEN:"<<endl;
           cout<<"Student's name: "<<name<<endl;
           cout<<"Sunject's name: "<<Sname<<endl;
           cout<<"Student code: "<<code<<endl;
           cout<<"Internal Marks: "<<inter<<endl;
           cout<<"External marks: "<<exter<<endl;
       } 
       void get(){
         cout<<"Enter name:";
         cin>>name;
         cout<<"Subject name:";
         cin>>Sname;
         cout<<"Student code:";
         cin>>code;
         cout<<"Internal marks:";
         cin>>inter;
         cout<<"Give Roll number:";
         cin>>rollno;
         cout<<"External Marks:";
         cin>>exter;
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
        cout<<"Student DETAILS:-"<<endl;
        cout<<"Enter Data:"<<endl;
        x.get();
      }
      ~db(){
        cout<<"Details completed.\t\t(Destructor called)"<<endl;
      }
      
};
info::info(){
    cout<<"\t\t<<Student INFO>>\t(default constructor is called)"<<endl;
}
int main(){
      db a;
      a.displaydata();
}