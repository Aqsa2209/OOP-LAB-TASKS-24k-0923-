#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Book {
private:
    string bookName;
    string isbn;
    string authorName;
    string publisher;

public:
    Book(const string &bookName, const string &isbn, const string &authorName, const string &publisher) {
        this->bookName = bookName;
        this->isbn = isbn;
        this->authorName = authorName;
        this->publisher = publisher;
    }
    string getBookName() const {
        return this->bookName;
    }

    string getISBN() const {
        return this->isbn;
    }

    string getAuthorName() const {
        return this->authorName;
    }

    string getPublisher() const {
        return this->publisher;
    }
    string getBookInfo() const {
        return "Book Name: " + this->bookName + "\n" +
               "ISBN: " + this->isbn + "\n" +
               "Author: " + this->authorName + "\n" +
               "Publisher: " + this->publisher + "\n";
    }
};

class BookTest {
public:
    static void main(int argc, char *argv[]) {
        if (argc < 21) {
            cerr << "Please provide information for 5 books (4 arguments each)." << endl;
            return;
        }

        vector<Book> books;

        for (int i = 1; i < argc; i += 4) {
            books.emplace_back(argv[i], argv[i + 1], argv[i + 2], argv[i + 3]);
        }
        for (const auto &book : books) {
            cout << book.getBookInfo() << endl;
        }
    }
};

int main(int argc, char *argv[]) {
    BookTest::main(argc, argv);
    return 0;
}
