#include<iostream>
using namespace std;
class emp{
    private:
    string name;
    float bonus;
    float sal;
    public:
    void getinfo();
    void check(){
         if(sal>2000){
            cout<<"The salary exceeds 2000. The increment in  salary is:"<<sal*(0.1)<<endl;
            this->bonus = sal*(0.1);
         }
         else{
            cout<<"The salary doesn't exceed 2000. Sorry no increment"<<endl;
         }
    }
    void display(){
        cout<<"Employee Data:"<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Salary(after bonus): "<<sal+bonus<<endl;
        cout<<"Bonus: "<<bonus<<endl;
    }
};
void emp::getinfo(){
    cout<<"Enter the name of the employee:"<<endl;
    cin>>name;
    cout<<"Enter the salary of the employee:"<<endl;
    cin>>sal;
}
int main(){
    emp a;
    a.getinfo();
    a.check();
    a.display();
}