#include<iostream>
using namespace std;
class Integer{
    int a,b;
    public:
    friend istream& operator>>(istream &in , Integer &A){
           in>>A.a>>A.b;
    }
   friend ostream& operator<<(ostream &os , Integer &A){
          os<<A.a+A.b;   
   }    

};
int main(){
    Integer A;
    cin>>A;
    cout<<A;
}