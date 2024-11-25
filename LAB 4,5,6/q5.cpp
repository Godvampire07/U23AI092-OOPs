#include<iostream>
using namespace std;
class Publication{
    private:
    string title;
    float price;
    string Aname;
    public:
    void getdata(){
        cout<<"Enter the book name:";
        cin>>title;
        cout<<"Enter the book price:";
        cin>>price;
        cout<<"Enter the author's name:";
        cin>>Aname;
    }
    void display(){
        cout<<"The book name:"<<title<<endl;
        cout<<"Price: $"<<price<<endl;
        cout<<"Author's name: "<<Aname<<endl;
    }

};
class Book : public Publication{
      int pcount;
      public:
        void getdata(){
        Publication::getdata();
        cout<<"Enter the number of page completed:";
        cin>>pcount;
    }
    void display(){
        Publication::display();
        cout<<"Number of page's completed:"<<pcount;
    }
};
class Ebook : public Publication{
    float ptime;
    public:
    void getdata(){
        Publication::getdata();
        cout<<"Enter number of hours spent reading Ebook:";
        cin>>ptime;
    }
    void display(){
        Publication::display();
        cout<<"Hours spent reading Ebook:"<<ptime;
    }
};
int main(){
    Book a;
    a.getdata();
    a.display();
}