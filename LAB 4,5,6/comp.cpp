#include<iostream>
using namespace std;
class complex{
    private :
    int r;
    int i;
    public:
    void inline getdata();
    friend void mul(complex &a , complex&b);
};
void complex::getdata(){
     cout<<"Enter the real part of the complex number:"<<endl;
     cin>>r;
     cout<<"Enter the imaginary part of the complex number:"<<endl;
     cin>>i;
}
void mul(complex &a , complex&b){
    cout<<"The multiplication of the 2 complex numbers is:"<<endl;
    cout<<"Real Part:"<<(a.r*b.r)-(a.i*b.i)<<endl;
    cout<<"Imaginary Part:"<<(a.r*b.i)+(a.i*b.r)<<"i"<<endl;
}
int main(){
    complex a;
    complex b;
    a.getdata();
    b.getdata();
    mul(a,b);
    return 0;
}