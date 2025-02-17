#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    string author;
    string title;
    double price;
    string publisher;
    int stock;

public:
    Book(const string& author, const string& title, double price, const string& publisher, int stock)
        : author(author), title(title), price(price), publisher(publisher), stock(stock) {}

    string getAuthor() const {
        return author;
    }

    string getTitle() const {
        return title;
    }

    double getPrice() const {
        return price;
    }

    string getPublisher() const {
        return publisher;
    }

    int getStock() const {
        return stock;
    }

    void displayDetails() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: $" << price << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Stock: " << stock << " copies" << endl;
    }

    bool isAvailable(int requestedCopies) const {
        return stock >= requestedCopies;
    }

    void sellCopies(int copies) {
        stock -= copies;
    }
};

class Bookstore {
private:
    static const int MAX_BOOKS = 100;
    Book* inventory[MAX_BOOKS];
    int bookCount;

public:
    Bookstore() : bookCount(0) {}

    void addBook(const Book& book) {
        if (bookCount < MAX_BOOKS) {
            inventory[bookCount] = new Book(book); 
            bookCount++;
        } else {
            cout << "Inventory full, cannot add more books." << endl;
        }
    }

    void searchAndSellBook(const string& title, const string& author, int requestedCopies) {
        for (int i = 0; i < bookCount; i++) {
            if (inventory[i]->getTitle() == title && inventory[i]->getAuthor() == author) {
                inventory[i]->displayDetails();
                if (inventory[i]->isAvailable(requestedCopies)) {
                    double totalCost = requestedCopies * inventory[i]->getPrice();
                    cout << "Total cost for " << requestedCopies << " copies: $" << totalCost << endl;
                    inventory[i]->sellCopies(requestedCopies); 
                } else {
                    cout << "Required copies not in stock." << endl;
                }
                return;
            }
        }
        cout << "Book not available in the inventory." << endl;
    }

    ~Bookstore() {
        for (int i = 0; i < bookCount; i++) {
            delete inventory[i]; 
        }
    }
};

int main() {
    Bookstore bookstore;
    int numberOfBooks;
    cout << "Enter the number of books to add: ";
    cin >> numberOfBooks;

    for (int i = 0; i < numberOfBooks; i++) {
        string author, title, publisher;
        double price;
        int stock;

        cout << "\nEnter details for book " << (i + 1) << ":\n";
        cin.ignore(); 
        cout << "Author: ";
        getline(cin, author);
        cout << "Title: ";
        getline(cin, title);
        cout << "Price: ";
        cin >> price;
        cout << "Publisher: ";
        cin.ignore(); 
        getline(cin, publisher);
        cout << "Stock: ";
        cin >> stock;

        bookstore.addBook(Book(author, title, price, publisher, stock));
    }
    string title, author;
    int requestedCopies;

    cout << "\nEnter book title to search: ";
    cin.ignore(); 
    getline(cin, title);
    cout << "Enter book author: ";
    getline(cin, author);
    cout << "Enter number of copies required: ";
    cin >> requestedCopies;

    bookstore.searchAndSellBook(title, author, requestedCopies);

    return 0;
}
