#include <iostream>
#include <cstring>

using namespace std;

class Book {
public:
    Book(const char* title, const char* author, const char* isbn)
        : title(title), author(author), isbn(isbn) {}

    const char* getTitle() const {
        return title;
    }

    const char* getAuthor() const {
        return author;
    }

    const char* getISBN() const {
        return isbn;
    }

private:
    const char* title;
    const char* author;
    const char* isbn;
};

class Catalog {
public:
    void addBook(Book* book) {
        if (bookCount < 10) {
            catalog[bookCount++] = book;
        }
    }

    Book* findBook(const char* isbn) const {
        for (int i = 0; i < bookCount; ++i) {
            if (strcmp(catalog[i]->getISBN(), isbn) == 0) {
                return catalog[i];
            }
        }
        return nullptr;
    }

private:
    Book* catalog[10];
    int bookCount = 0;
};

class Library {
public:
    Library(const char* name, const char* address)
        : name(name), address(address) {}

    void addBook(Book* book) {
        books[bookCount++] = book;
        catalog.addBook(book);
    }

    Book* findBookInCatalog(const char* isbn) {
        return catalog.findBook(isbn);
    }

    void displayBooks() const {
        cout << "Books in " << name << " Library:\n";
        for (int i = 0; i < bookCount; ++i) {
            cout << " - " << books[i]->getTitle() << " by " << books[i]->getAuthor() << " (ISBN: " << books[i]->getISBN() << ")\n";
        }
    }

private:
    const char* name;
    const char* address;
    Catalog catalog;
    Book* books[10];
    int bookCount = 0;
};

int main() {
    Library myLibrary("City Library", "123 Main St");

    Book book1("Harry Potter", "J.K. Rowling", "9780747532743");
    Book book2("My Fault", "Mercedes Ron", "9781234567890");
    Book book3("Alchemist", "Paulo Coelho", "9780061122415");

    myLibrary.addBook(&book1);
    myLibrary.addBook(&book2);
    myLibrary.addBook(&book3);

    myLibrary.displayBooks();

    const char* isbnToFind = "9781234567890";
    Book* foundBook = myLibrary.findBookInCatalog(isbnToFind);
    if (foundBook) {
        cout << "Found book: " << foundBook->getTitle() << " by " << foundBook->getAuthor() << endl;
    } else {
        cout << "Book with ISBN " << isbnToFind << " not found in catalog." << endl;
    }

    return 0;
}
