#include<iostream>
using namespace std;
class B;
class A{
    private:
    float a;
    public:
    A(){
        cout<<"Input a:"<<endl;
        cin>>a;
    }
    friend void mean(A&,B&);
};
class B{
    private:
    float b;
    public:
    B(){
        cout<<"Input b:"<<endl;
        cin>>b;
    }
    friend void mean(A&,B&);
};
void mean(A&a,B&b){
      cout<<"The mean of 2 number is :"<<endl;
      float x =(a.a+b.b)/2;
      cout<<x<<endl;
}

int main(){
    A a;
    B b;
    mean(a,b);
    
}