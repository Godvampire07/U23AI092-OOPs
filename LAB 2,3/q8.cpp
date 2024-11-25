#include<iostream>
#include<string.h>
using namespace std;
class employee{
    private:
    string name;
    string code;
     string desig;
     int years;
     int age;
     float height;
     float weight;
    public:
    employee(){
        cout<<"default constructor called."<<endl;
    }
    employee(employee &t){
        t.age = age;
        t.code = code;
        t.name = name;
        t.desig = desig;
        t.years = years;
        t.height = height;
        t.weight = weight;
        cout<<"Copy constructor called."<<endl;
    }
    employee(string name,string code,string desig,int years,int age,float height,float weight){
        this->age = age;
        this->code = code;
        this->name = name;
        this->desig = desig;
        this->years = years;
        this->height = height;
        this->weight = weight;
        cout<<"parametric constructor called."<<endl;
    }
    ~employee(){
        cout<<"destructor called."<<endl;
    }
    inline void display(){
        cout << "Person Name: " << name << endl;
        cout << "Blood Group: " << code << endl;
        cout << "Address: " << desig << endl;
        cout << "Contact number: " << years << endl;
        cout << "Date of Birth: " << age << endl;
        cout << "body weight:"<<weight<<endl;
        cout << "body height:"<<height<<endl;
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
            cout << "\nDetails of Recipient" << i + 1 << ":" << endl;
            emp[i].display();
        }
    }    
    void getdata(){
         string name,desig,code;
        int years,age;
        float weight,height;
        for (int i = 0; i<size;i++){
            cout<<"Enter details for Patient"<<i+1<<endl;
            cout << "Name: ";
            cin >> name;
            cout << "Blood Group: ";
            cin >> code;
            cout << "Address: ";
            cin >> desig;
            cout << "Contact number: ";
            cin >> years;
            cout << "Date of Birth: ";
            cin >> age;
            cout<<"Height :(in cm)";
            cin>>height;
            cout<<"Weight:(in kg)";
            cin>>weight;
            emp[i] = employee(name,code,desig,years,age,height,weight);
    }
    }

};
int main(){
    int n;
    cout << "Enter the number of People: ";
    cin >> n;
    empdb* v = new empdb(n);
    v->getdata();
    v->displaydata();
    delete v;
}