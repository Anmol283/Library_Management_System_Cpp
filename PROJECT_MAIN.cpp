//can use files   -
#include<iostream>
#include<string>
using namespace std;

class Book{
    protected:
    string title;
    string author;
    int ISBN;
    bool availability;
    static int count;
    public:
    Book(string title,string author,int ISBN,bool availability){
        this->title=title;
        this->author=author;
        this->ISBN=ISBN;
        this->availability=availability;
        count++;
    }
    ~Book(){
        count--;
    }
    virtual void display_Book(){
        cout << "Title: "<<title<<" Author: "<<author<<" ISBN: "<<ISBN<<" Available: "<<(availability?"Yes":"No")<<endl;
    }
    static void display_count() {
        cout << "Number of physical books in library: " << count << endl;
    }
    bool search_book(int search_ISBN){
        if(search_ISBN==ISBN){
            return true;
        }
        return false;
    }
};

int Book::count=0;

class digital_books:public Book{
    static int count_db;
    public:
    digital_books(string title,string author,int ISBN,bool availability):Book(title,author,ISBN,availability){
        count_db++;
        count--;
    }
    ~digital_books(){
        count_db--;
    }
    void display_Book() override{
        cout << "E-book Title: "<<title<<", E-book Author: "<<author<<", E-book ISBN: "<<ISBN<<", E-book Available: "<<(availability?"Yes":"No")<<endl;
    }
    static void display_count() {
        cout << "Number of digital books: " << count_db << endl;
    }
};
int digital_books::count_db=0;

int main(){
    Book *b1=new Book("C++","abc",123,true);
    Book *b2=new Book("python","xyz",456,true);
    Book *b3=new Book("C","pqr",789,true);

    digital_books *db1=new digital_books("E-book Java","xyz",789,true);
    digital_books *db2=new digital_books("E-book javascript","abc",456,true);

    b1->display_Book();
    b2->display_Book();
    b3->display_Book();

    db1->display_Book();
    db2->display_Book();

    Book::display_count();
    digital_books::display_count();
 

    char function;
    cout<<"what do you want to do?(A for add ,R for remove, S for search):";
    cin>>function;


    if(function=='S'){
    int search_ISBN;
    cout<<"enter the ISBN of the book you want to search:";
    cin>>search_ISBN;
    if(b1->search_book(search_ISBN)){
        cout<<"book found"<<endl;
        b1->display_Book();
    }
    else if(b2->search_book(search_ISBN)){
        cout<<"book found"<<endl;
        b2->display_Book();
    }
    else if(b3->search_book(search_ISBN)){
        cout<<"book found"<<endl;
        b3->display_Book();
    }
    else{
        cout<<"book not found"<<endl;
    }

  }

    else if(function=='A'){
        string title;
        string author;
        int ISBN;
        bool availability;
        cout<<"enter title:";
        cin>>title;
        cout<<"enter author:";
        cin>>author;
        cout<<"enter ISBN:";
        cin>>ISBN;
        cout<<"enter availability:";
        cin>>availability;
        cout<<"BOOK ADDED!"<<endl;
        Book *b4=new Book(title,author,ISBN,availability);

        b1->display_Book();
        b2->display_Book();
        b3->display_Book();
        b4->display_Book();
        b4->display_count();
    }

    else if(function=='R'){
        int remove_ISBN;
        cout<<"Enter the ISBN of the book to be removed:";
        cin>>remove_ISBN;
        if(b1->search_book(remove_ISBN)){
            cout<<"book removed"<<endl;
            delete b1;
            b1->display_count();
            b2->display_Book();
            b3->display_Book();
        }
        else if(b2->search_book(remove_ISBN)){
            cout<<"Book removed"<<endl;
            delete b2;
            b2->display_count();
            b1->display_Book();
            b3->display_Book();
        }
        else if(b3->search_book(remove_ISBN)){
            cout<<"book removed"<<endl;
            delete b3;
            b3->display_count();
            b1->display_Book();
            b2->display_Book();
        }
        else{
            cout<<"BOOK NOT FOUND!"<<endl;
        }
    }

    delete b1;
    delete b2;
    delete b3;
    delete db1;
    delete db2;

    return 0;
}
