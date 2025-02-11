#include<iostream>
using namespace std;
class Date{
private:
int month;
int day;
int year;

    public:
    void setMonth(int m){
    month=m;
    }
    void setDay(int d){
    day=d;
    }
    void setYear(int y){
    year=y;
    }
    int getMonth(){
    return month;
    }
    int getDay(){
    return day;
    }
    int getYear(){
    return year;
    }
    void displayDate(){
    cout << month << "/" << day << "/" << year << endl;
    }
};
int main(int argc, char* argv[]){
Date dateTest;
dateTest.setMonth(stoi(argv[1]));
dateTest.setDay(stoi(argv[2]));
dateTest.setYear(stoi(argv[3]));

dateTest.displayDate();
return 0;
}
