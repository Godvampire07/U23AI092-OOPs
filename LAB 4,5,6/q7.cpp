#include<iostream>
#include<string.h>
using namespace std;
class employee{
    private:
    string name;
    string code;   
     int age;
    public:
    employee(){}
    employee(string name,string code,int age){
        this->age = age;
        this->code = code;
        this->name = name;
    }
    inline void display(){
        cout << "Person Name: " << name << endl;
        cout << "Code: " << code << endl;
        cout << "Age: " << age << endl;
    }
    friend class empdb; 
};
class empdb{
    employee *emp;
    int size;
    public:
    empdb(){
        cout<<"\nGeneral database.";
    }
    empdb(int n){
        size = n;
        emp =  new employee[n];
    }
    void displaydata(){
        for (int i = 0; i < size; ++i) {
            cout << "\nDetails of Employee: " << i + 1 << ":" << endl;
            emp[i].display();
        }
    }    
    void getdata(){
         string name,code;
        int age;
        float weight,height;
        for (int i = 0; i<size;i++){
            cout<<"Enter details for Employee"<<i+1<<endl;
            cout << "Name: ";
            cin >> name;
            cout << "Code: ";
            cin >> code;
            cout << "Age: ";
            cin >> age;
            emp[i] = employee(name,code,age);
    }
    }
    void getid(){
    string code;
      cout<<"Give the employee id:(valid only)"<<endl;
      cin>>code;
      for (int i = 0;i< 3 ; i++){
          if (code == emp[i].code){
            emp[i].display();
          }
      }
    };

};

int main(){
    empdb* v = new empdb(3);
    v->getdata();
    v->displaydata();
    v->getid();
    delete v;
}