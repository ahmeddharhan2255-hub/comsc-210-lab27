//COMSC-210 | Lab 27 | Ahmad Dharhan

#include <iostream>
#include <map>
#include <vector>
using namespace std;

void range_display(map<string, tuple<int,string,string>> villagerColors);
void iterator_display(map<string, tuple<int,string,string>> villagerColors);
void search(map<string, tuple<int,string,string>> villagerColors, string searchKey);

int main() {
    // declarations
    int choice = 0;
    string name;
    map<string, tuple<int,string,string>> villagerColors;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagerColors["Audie"] = {9, "Forest Species", "Kachow!"};
    villagerColors["Raymond"] = {3, "Water Species", "6-7"};
    villagerColors.insert({"Marshal", {7, "Mountain Species", "I love pizza!"}});

    while(choice != 4){
        cout << "1. Increase Friendship" << endl;
        cout << "2. Decrease Friendship" << endl;
        cout << "3. Search for Villager" << endl;
        cout << "4. Exit" << endl;
        cin >> choice;

        switch(choice){
            case 1:

            case 2:

            case 3:
                cout << "Enter name of villager you want to search" << endl;
                cin >> name;
                search(villagerColors, name);

            case 4:
                cout << "Exiting Program" << endl;
                break;
        }
    }

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerColors.size() << endl;
    villagerColors.clear();
    cout << "Size after clear: " << villagerColors.size() << endl;

    return 0;
}

void range_display(map<string, tuple<int,string,string>> villagerColors){
    // access the map using a range-based for loop
    cout << "Villagers and their favorite colors (range-based for loop):" << endl;
    for (auto villager : villagerColors) {
        cout << villager.first << ": ";
        cout << get<0>(villager.second) << ", ";
        cout << get<1>(villager.second) << ", ";
        cout << get<2>(villager.second) << " " << endl;
    }
}

void iterator_display(map<string, tuple<int,string,string>> villagerColors){
    // access the map using iterators
    cout << "\nVillagers and their favorite colors (iterators):" << endl;
    for (map<string, tuple<int,string,string>>::iterator it = villagerColors.begin(); 
                                               it != villagerColors.end(); ++it) {
        cout << it->first << ": ";
        cout << get<0>(it->second) << ", ";
        cout << get<1>(it->second) << ", ";
        cout << get<2>(it->second) << " " << endl;
    }
}

void search(map<string, tuple<int,string,string>> villagerColors, string searchKey){
    // search for an element using .find() to avoid errors
    auto it = villagerColors.find(searchKey);
    if (it != villagerColors.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s favorite colors: ";
        cout << get<0>(it->second) << ", ";
        cout << get<1>(it->second) << ", ";
        cout << get<2>(it->second) << " " <<endl;
        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;    
}
