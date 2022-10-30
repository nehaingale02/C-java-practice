#include<iostream>
using namespace std;

class Books
{
    private :
        string author, title, pub;
        int price, pos, i, q ;
    public :

void get_data()
{
    cout<<"Enter author name :"<<endl;
    cin>>author;
    cout<<"Enter book title :"<<endl;
    cin>>title;
    cout<<"Enter publication name :"<<endl;
    cin>>pub;
    cout<<"Enter book price :"<<endl;
    cin>>price;
    cout<<"Enter stock position :"<<endl;
    cin>>pos;
}

void display_data()
{
    cout<<"author name :"<<author<<endl;
    cout<<"book title :"<<title<<endl;
    cout<<"publication name :"<<pub<<endl;
    cout<<"book price :"<<price<<endl;
    cout<<"stock position :"<<pos<<endl;
}

int search_book()
{
    string s_title, s_author;
    cout<<"Enter author name: ";
    cin>>s_author;
    cout<<"Enter the title: ";
    cin>>s_title;
if(title==s_title && author==s_author)
{
    cout<<"Book found!"<<endl;
    return 1;
}
else
{
    cout<<"Book not found!"<<endl;
    return 0;
}
}

void buy_book()
{
    if(search_book() == 1)
    {
        cout<<"Book price : "<<price<<endl;
        cout<<"Enter quantity : ";
        cin>>q;
        if(q < pos)
        {
            cout<<"Total price : "<<q<<"*"<<"Rs."<<price<<"= Rs."<<q*price<<endl;
        }
        else
            cout<<"Book out of stock!"<<endl;
    }
    else
        cout<<"Try another book"<<endl;
}

void edit_data()
{
    cout<<"Enter author name :";
    cin>>author;
    cout<<"Enter book title :";
    cin>>title;
    cout<<"Enter publication name :";
    cin>>pub;
    cout<<"Enter book price :";
    cin>>price;
    cout<<"Enter stock position :";
    cin>>pos;
}
};

int main()
{
    int n;
    char ch = 'y';
    Books b[10];
    while(ch == 'y')
    {
    cout<<"Select from following menu : "<<endl<<"1. Enter book data"<<endl<<"2. Search Book"<<endl<<"3. Buy book"<<endl<<"4. Edit book data"<<endl;
    cin>>n;
    switch(n)
    {
    case 1 :
         b[0].get_data();
    break;
    case 2:
         b[0].search_book();
    break;
    case 3:
         b[0].buy_book();
    break;
    case 4:
         b[0].edit_data();
    break;
    }
    cout<<"Do you wish to proceed?(y/n)";
    cin>>ch;
    }
}
