#include<iostream>
using namespace std;
class employee{
    private:
    string name;
    int income;
    float amount;
    public:
    void getdata();
    void compute();
    void output();  
};
void employee::getdata(){
    cout<<"Enter the name:";
    cin>>name;
    cout<<"The income paid:";
    cin>>income;
}
void employee::compute(){
    float amount;
    if (income<= 100000){
        amount = 0;
    }
    else if ( 100000 < income <= 150000){
        amount = (income-100000)*(0.10);
    }
    else if ( 150000< income <= 200000){
        amount = (income-100000)*(0.10)+(income-150000)*(0.20);
    }
    else{
        amount = (income-100000)*(0.10)+(income-150000)*(0.20) + (income-200000)*(0.30);
    } 
    this->amount = amount;   
}
void employee::output(){
    cout<<"Name: "<<name<<endl;
    cout<<"Tax to be paid: $"<<amount<<endl;
}
int main(){
    employee a;
    a.getdata();
    a.compute();
    a.output();
}