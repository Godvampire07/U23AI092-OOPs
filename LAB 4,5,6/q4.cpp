#include<iostream>
using namespace std;
class acc{
    private:
    string name;
    long int accno;
    string type;
    float balance;
    public:
    void getdata(){
        cout<<"Enter the name of account holder: ";
        cin>>name;
        cout<<"Enter the account number:";
        cin>>accno;
        cout<<"Type of the banking account:";
        cin>>type;
        cout<<"Input balance:";
        cin>>balance;
    }
    void deposit(){
        int accno;
        float d;
        cout<<"Enter the account number:";
        cin>>accno;
        if ( this->accno = accno){
            cout<<"Enter the amount to be deposited: ";
            cin>>d;
            balance += d;
            cout<<"Current balancee is :"<<balance<<endl;
        }
        else{
            cout<<"Wrong credentials";
        }
    }
    void withdraw(){
        int accno;
        float d;
        cout<<"Enter the account number:";
        cin>>accno;
        if ( this->accno = accno){
            cout<<"Enter the amount to be withdrawn: ";
            cin>>d;
            balance -= d;
            cout<<"Current balancee is :"<<balance<<endl;
        }
        else{
            cout<<"Wrong credentials";
        }
    }
    void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"Type:"<<type<<endl;
        cout<<"Balance: $"<<balance<<endl;
    }
};
int main(){
    acc a;
    char x;
    a.getdata();
    cout<<"Deposit ? (Y/N)"<<endl;
    cin>>x;
    if (x == 'Y'){
        a.deposit();
    }
    cout<<"Withdraw ? (Y/N)"<<endl;
    cin>>x;
    if (x == 'Y'){
        a.withdraw();
    }
    char y;
    cout<<"Transactions completed,Want to check balance(Y/N)";
    cin>>y;
    if (y == 'Y'){
        a.display();
    }
}