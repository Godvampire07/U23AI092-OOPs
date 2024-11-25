#include<iostream>
using namespace std;
class Class_2;
class Class_1{
    private:
    int a;
    public:
    void getdata(){
        cout<<"Enter a:";
        cin>>a;
    }
    friend void exchange(Class_1 & , Class_2 &);
};
class Class_2{
    private:
    int b;
    public:
    void getdata(){
        cout<<"Enter b:";
        cin>>b;
    }
    friend void exchange(Class_1 & , Class_2 &);
};
void exchange(Class_1 &a , Class_2 &b){
    int temp = a.a;
    a.a = b.b;
    b.b = temp;
    cout<<"a ="<<a.a<<" and b ="<<b.b<<endl;
}
int main(){
    Class_1 a;
    Class_2 b;
    a.getdata();
    b.getdata();
    exchange(a,b);
    return 0;
}