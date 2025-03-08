#include <iostream>
using namespace std;

// Base class: Books
class Books {
protected:
    string genre;
public:
    Books(string bookGenre) : genre(bookGenre) {}
    virtual void displayDetails() {
        cout << "Genre: " << genre << endl;
    }
};

// Derived class: Novel
class Novel : public Books {
private:
    string title;
    string author;
public:
    Novel(string bookTitle, string bookAuthor)
        : Books("Novel"), title(bookTitle), author(bookAuthor) {}
    
    void displayDetails() override {
        cout << "Genre: " << genre << "\nTitle: " << title << "\nAuthor: " << author << endl;
    }
};

// Derived class: Mystery
class Mystery : public Books {
private:
    string title;
    string author;
public:
    Mystery(string bookTitle, string bookAuthor)
        : Books("Mystery"), title(bookTitle), author(bookAuthor) {}
    
    void displayDetails() override {
        cout << "Genre: " << genre << "\nTitle: " << title << "\nAuthor: " << author << endl;
    }
};

int main() {
    Novel novel1("Pride and Prejudice", "Jane Austen");
    Mystery mystery1("Sherlock Holmes", "Arthur Conan Doyle");
    
    cout << "Library Books:\n";
    novel1.displayDetails();
    cout << "\n";
    mystery1.displayDetails();
    
    return 0;
}

