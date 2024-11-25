#include<iostream>
using namespace std;
class Integer{
    private:
    int x;
    public:
    void getx(){
        cout<<"Enter the Integer:";
        cin>>x;
    }
    friend void operator+(Integer const&,Integer const&);
};
void operator+(Integer const&a,Integer const&b){
    cout<<"Addition of 2 integers: "<<a.x<<" and "<<b.x<<" is "<<a.x+b.x<<endl;
}
int main(){
  Integer a,b;
  a.getx();
  b.getx();
  a+b;
}