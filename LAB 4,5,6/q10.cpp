#include<iostream>
using namespace std;
class Vector{
    private:
    int v[3]; 
    public:
    friend ostream& operator<<(ostream &os, Vector &v){
        os<<v;
    }
    friend istream& operator>>(istream &is, Vector &A){
        cout<<"Enter the values (size = 3):";
        for(int i = 0 ; i < 3 ;i++){
           is>>A.v[i]; 
        }
    }
    friend void operator+(Vector &A,Vector &B){
        int i,j;
        cout<<"Enter the indices for addition in vector";
        cin>>i>>j;
        cout<<"The addition is :"<<A.v[i] <<"+j" <<A.v[j]<<endl;
    }
    friend void operator-(Vector &A , Vector &B){
        int x,y;
        cout<<"Enter the indices for substraction in vector:";
        cin>>x>>y;
        cout<<"The substraction is: "<<A.v[x] - B.v[y]<<endl;
    }
    
};
int main(){
    Vector A,B;
    cin>>A>>B;
    A+A;
    A-B;
}  