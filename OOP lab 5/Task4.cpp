#include <iostream>
#include <string>

using namespace std;

class Blend {
public:
    void blendJuice() {
        cout << "Blending juice..." << endl;
        for (int i = 0; i < 5; ++i) {
            cout << "."; 
            for (int j = 0; j < 100000000; ++j);
        }
        cout << "\nJuice blended!" << endl;
    }
};

class Grind {
public:
    void grindJuice() {
        cout << "Grinding juice..." << endl;
        for (int i = 0; i < 5; ++i) {
            cout << "."; 
            for (int j = 0; j < 100000000; ++j);
        }
        cout << "\nJuice ground!" << endl;
    }
};

class JuiceMaker {
public:
    void makeJuice() {
        Blend blender;
        Grind grinder;
        blender.blendJuice();
        grinder.grindJuice();
    }
};

int main() {
    JuiceMaker juiceMaker;
    juiceMaker.makeJuice();
    return 0;
}
