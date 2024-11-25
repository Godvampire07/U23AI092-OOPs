#include<iostream>
using namespace std;
class Integer{
    int a,b;
    public:
    friend istream& operator >>(istream& ci , Integer &A ){
        cout<<"Enter the value for a,b:";
        ci>>A.a>>A.b;
    }
    friend ostream& operator <<(ostream& co ,Integer &A ){
       co<<"The values for the a,b are :"<<A.a<<" "<<A.b<<endl;
       co<<"Sum of these :"<<A.a+A.b;
    }
};
int main(){
    Integer A;
    cin>>A;
    cout<<A;
}