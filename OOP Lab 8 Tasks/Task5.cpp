#include <iostream>
#include <string>

using namespace std;

class Media {
protected:
    string title;
    string uniqueId;
    string publisher;

public:
    Media(string t, string id, string pub)
        : title(t), uniqueId(id), publisher(pub) {}

    virtual void displayInfo() {
        cout << "Title: " << title << "\nUnique ID: " << uniqueId
             << "\nPublisher: " << publisher << endl;
    }

    virtual void checkOut() {
        cout << "Checking out: " << title << endl;
    }

    virtual void returnMedia() {
        cout << "Returning: " << title << endl;
    }

    virtual ~Media() {}
};

class Book : public Media {
private:
    string author;
    int numberOfPages;
    string isbn;

public:
    Book(string t, string id, string pub, string auth, int pages, string isbn)
        : Media(t, id, pub), author(auth), numberOfPages(pages), isbn(isbn) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Author: " << author << "\nISBN: " << isbn 
             << "\nNumber of Pages: " << numberOfPages << endl;
    }
};

class DVD : public Media {
private:
    string director;
    int duration; 
    string rating;

public:
    DVD(string t, string id, string pub, string dir, int dur, string rat)
        : Media(t, id, pub), director(dir), duration(dur), rating(rat) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Director: " << director << "\nDuration: " << duration 
             << " minutes\nRating: " << rating << endl;
    }
};


class Magazine : public Media {
private:
    int numberOfIssues;
    string frequency; 

public:
    Magazine(string t, string id, string pub, int issues, string freq)
        : Media(t, id, pub), numberOfIssues(issues), frequency(freq) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Number of Issues: " << numberOfIssues 
             << "\nFrequency: " << frequency << endl;
    }
};

int main() {
    Book book("C++ Programming", "B001", "Pakistan Publications", "Ali Khan", 350, "978-3-16-148410-0");
    DVD dvd("Bollywood Hits", "D001", "Shalimar Video", "Saeed Anwar", 120, "PG-13");
    Magazine magazine("Pakistan Today", "M001", "Jang Publications", 12, "Monthly");

    cout << "\nBook Info:\n";
    book.displayInfo();
    book.checkOut();

    cout << "\nDVD Info:\n";
    dvd.displayInfo();
    dvd.checkOut();

    cout << "\nMagazine Info:\n";
    magazine.displayInfo();
    magazine.checkOut();

    // Return media
    cout << "\nReturning Media:\n";
    book.returnMedia();
    dvd.returnMedia();
    magazine.returnMedia();

    return 0;
}
