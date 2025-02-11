#include<iostream>
#include<string>
using namespace std;

class Glass {
private:
int liquidLevel;
public:
Glass() : liquidLevel(200){}
void setLiquidLevel(int level){
liquidLevel= level;
}
int getLiquidLevel(){
return liquidLevel;
}
void Drink(int millimeters){
liquidLevel-= millimeters;
if(liquidLevel < 100){
Refill();
}
}
void Refill(){
liquidLevel=200;
cout << "Glass Refilled to 200ml. " <<endl;
}
};
int main(int argc, char*argv[]){
Glass glass;
for(int i=1; i<argc; ++i){
int command = atoi(argv[i]);
if(command>=0){
glass.Drink(command);
cout << "Current Liquid level: " << glass.getLiquidLevel() << "ml." << endl;
}else {
cout << "Invalid input. please enter a non-negative amount." << endl;
}
}
return 0;
}

