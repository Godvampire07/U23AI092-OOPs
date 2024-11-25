#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;
class info{
       string author;
       string title;
       int code;
       int inter;
       float cost;
       public:
       info();
       info(string author,string title,int code,int inter,float cost){
        cout<<"\t<<BOOK PUBLISHER AND MORE INFO>>\t"<<endl;
        this->code = code;
        this->inter = inter;
        this->cost = cost;
        this->author = author;
        this->title = title;
        cout<<"Parametric Constructor called.";
       }
       info(info &t){
        t.code = code;
        t.inter = inter;
        t.cost = cost;
        t.author = author;
        t.title = title;
        cout<<"Copy constructor called.";
       }
       ~info(){
        cout<<"Thanks.";
       }
       inline void display(){
           cout<<"\n\nStudent DETAILS GIVEN:"<<endl;
           cout<<"Author: "<<author<<endl;
           cout<<"Book Title: "<<title<<endl;
           cout<<"Accession Number: "<<code<<endl;
           cout<<"Year of publishment: "<<inter<<endl;
           cout<<"Cost of the BOOK: "<<cost<<endl;
       } 
       inline void get(){
         cout<<"Enter author's name:";
         cin>>author;
         cout<<"Book title:";
         cin>>title;
         cout<<"Accession Number:";
         cin>>code;
         cout<<"Year of publishment:";
         cin>>inter;
         cout<<"Book cost:";
         cin>>cost;
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
        cout<<"BOOK AND PUBLISHER DETAILS:-"<<endl;
        cout<<"Enter Data:"<<endl;
        x.get();
      }
      ~db(){
        cout<<"Details completed.\t\t(Destructor called)"<<endl;
      }
      
};
info::info(){
    cout<<"\t\t<<BOOK  INFO>>\t(default constructor is called)"<<endl;
}
int main(){
      db a;
      a.displaydata();
}