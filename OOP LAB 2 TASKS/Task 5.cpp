#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Entity {
    int id;
    string name;
};
bool compare(const Entity &a, const Entity &b) {
    if (a.id == b.id) {
        return a.name < b.name; 
    }
    return a.id < b.id; 
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        cout << "Usage: " << argv[0] << " <id1> <name1> [<id2> <name2> ...]" << endl;
        return 1;
    }

    vector<Entity> entities;
    for (int i = 1; i < argc; i += 2) {
        if (i + 1 < argc) {
            Entity entity;
            entity.id = stoi(argv[i]);
            entity.name = argv[i + 1];
            entities.push_back(entity);
        }
    }
    sort(entities.begin(), entities.end(), compare);
    cout << "Sorted entities (by ID and Name):" << endl;
    for (const auto &entity : entities) {
        cout << "ID: " << entity.id << ", Name: " << entity.name << endl;
    }

    return 0;
}
