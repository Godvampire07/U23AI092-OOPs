#include<iostream>
using namespace std;
class bill{
    private:
    string name;
    int calls;
    float amount;
    public:
    void getdata();
    void compute();
    void output();  
};
void bill::getdata(){
    cout<<"Enter the name:";
    cin>>name;
    cout<<"The number of calls:";
    cin>>calls;
}
void bill::compute(){
    float amount;
    if (calls <= 100){
        amount = 200;
    }
    else if ( 100<calls <= 150){
        amount = 200 + (calls-100)*(0.60);
    }
    else if ( 150<calls <= 200){
        amount = 200 + (calls-100)*(0.60)+(calls-150)*(0.50);
    }
    else{
        amount = 200 + (calls-100)*(0.60)+(calls-150)*(0.50)+ (calls-200)*(0.40);
    } 
    this->amount = amount;   
}
void bill::output(){
    cout<<"Name: "<<name<<endl;
    cout<<"Bill to be paid: $"<<amount<<endl;
}
int main(){
    bill a;
    a.getdata();
    a.compute();
    a.output();
}