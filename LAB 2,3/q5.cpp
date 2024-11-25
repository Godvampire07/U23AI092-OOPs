#include<iostream>
#include<string.h>
using namespace std;
class employee{
    private:
    string name;//
     int code;//
     string desig;//
     int years;//
     int age;
     float pay;
    public:
    employee(){
        cout<<"default constructor called."<<endl;
    }
    employee(string name,int code,string desig,int years,int age,float pay){
        this->age = age;
        this->code = code;
        this->name = name;
        this->desig = desig;
        this->years = years;
        this->pay = pay;
        cout<<"parametric constructor called."<<endl;
    }
    employee(employee &t){
        t.age = age;
        t.code = code;
        t.name = name;
        t.desig = desig;
        t.years = years;
        t.pay = pay;
        cout<<"Copy constructor called."<<endl;
    }
    ~employee(){
        cout<<"destructor called."<<endl;
    }
    inline void display(){
        cout << "Employee Name: " << name << endl;
        cout << "Employee Code: " << code << endl;
        cout << "Designation: " << desig << endl;
        cout << "Account Number: " << years << endl;
        cout << "Date of joining: " << age << endl;
        cout << "Fair pay: "<<pay<<endl;
    }
    friend class empdb; 
};
class empdb{
    employee *emp;
    int size;
    public:
    empdb(){
        cout<<"\nemployees database.";
    }
    empdb(int n){
        size = n;
        emp =  new employee[n];
    }
    void displaydata(){
        for (int i = 0; i < size; ++i) {
            cout << "\nDetails of Employee " << i + 1 << ":" << endl;
            emp[i].display();
        }
    }    
    void getdata(){
         string name,desig;
        int years,age,code;
        float pay;
        for (int i = 0; i<size;i++){
            cout<<"Enter details for employee number "<<i+1<<endl;
            cout << "Name: ";
            cin >> name;
            cout << "Code: ";
            cin >> code;
            cout << "Designation: ";
            cin >> desig;
            cout << "Account Number: ";
            cin >> years;
            cout << "Date of joining(ddmmyyyy): ";
            cin >> age;
            cout<<"What is fair pay: ";
            cin>>pay;
            emp[i] = employee(name,code,desig,years,age,pay);
    }
    }

};
int main(){
    int n;
    cout << "Enter the number of employees: ";
    cin >> n;
    empdb* v = new empdb(n);
    v->getdata();
    v->displaydata();
}