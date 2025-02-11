#include<iostream>
#include<string>
using namespace std;

class User{
private:
int Age;
string Name;
public:
void setAge(int a){
Age=a;
}
void setName(string n){
Name=n;
}
int getAge(){
return Age;
}
string getName(){
return Name;
}

};

int main(int argc, char* argv[]){
if(argc!=3){
cout << "Usage: " << argv[0] << "<Name> <Age> " <<endl;
return 1;

}
User user;
user.setName(argv[1]);
user.setAge(stoi(argv[2]));
cout<< "My Name is " << user.getName() << " and I am " << user.getAge() << " years old." << endl;
return 0;
}
