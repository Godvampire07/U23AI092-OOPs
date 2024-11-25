#include<iostream>
#include<string.h>
using namespace std;
class employee{
    private:
    string name;
     int code;
     string desig;
     int years;
     int age;
    public:
    employee(){
        cout<<"default constructor called."<<endl;
    }
    employee(string name,int code,string desig,int years,int age){
        this->age = age;
        this->code = code;
        this->name = name;
        this->desig = desig;
        this->years = years;
        cout<<"parametric constructor called."<<endl;
    }
    ~employee(){
        cout<<"destructor called."<<endl;
    }
    inline void display(){
        cout << "Employee Name: " << name << endl;
        cout << "Employee Code: " << code << endl;
        cout << "Designation: " << desig << endl;
        cout << "Years of Experience: " << years << endl;
        cout << "Age: " << age << endl;
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
        for (int i = 0; i<size;i++){
            cout<<"Enter details for employee number "<<i+1<<endl;
            cout << "Name: ";
            cin >> name;
            cout << "Code: ";
            cin >> code;
            cout << "Designation: ";
            cin >> desig;
            cout << "Years of Experience: ";
            cin >> years;
            cout << "Age: ";
            cin >> age;
            emp[i] = employee(name,code,desig,years,age);
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