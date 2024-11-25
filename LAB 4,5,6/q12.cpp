#include<iostream>
using namespace std;
class Str{
    private:
    string s;
    public:
    void gets(){
        cout<<"Enter the string : ";
        cin>>s;
    }
    friend bool operator ==(Str const&x,Str const&y){
        return x.s == y.s;
    }
};

int main(){
     Str s,t;
     s.gets();
     t.gets();
     if (s == t){
        cout<<"The strings are equal.";
     }
     else{
        cout<<"The string are different.";
     }
}