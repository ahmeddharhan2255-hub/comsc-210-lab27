//COMSC-210 | Lab 27 | Ahmad Dharhan

#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <string>
using namespace std;


//Function Prototypes
void range_display(map<string, tuple<int,string,string>> &villagerColors);
void iterator_display(map<string, tuple<int,string,string>> &villagerColors);
void search(map<string, tuple<int,string,string>> &villagerColors, string searchKey);
void addFriendship(map<string, tuple<int,string,string>> &villagerColors, string name);
void deleteFriendship(map<string, tuple<int,string,string>> &villagerColors, string name);
void clear(map<string, tuple<int,string,string>> &villagerColors);
void addVillager(map<string, tuple<int,string,string>> &villagerColors);
void deleteVillager(map<string, tuple<int,string,string>> &villagerColors, string name);

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

    //Driver Code
    while(choice != 6){
        cout << "1. Add Villager" << endl;
        cout << "2. Delete Villager" << endl;
        cout << "3. Increase Friendship" << endl;
        cout << "4. Decrease Friendship" << endl;
        cout << "5. Search For Villager" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice here: ";
        cin >> choice;
        cout << endl;
        iterator_display(villagerColors);
        cout << endl;

        switch(choice){
            case 1:
                addVillager(villagerColors);
                iterator_display(villagerColors);
                break;
            case 2:
                cout << "Enter name of villager you want to delete" << endl;
                cin >> name;
                deleteVillager(villagerColors, name);
                range_display(villagerColors);
                break;
        
            case 3:
                cout << "Enter name of villager to increase their friendship point" << endl;
                cin >> name;
                addFriendship(villagerColors, name);
                range_display(villagerColors);
                break;

            case 4:
                cout << "Enter name of villager to decrease their friendship point" << endl;
                cin >> name;
                deleteFriendship(villagerColors, name);
                range_display(villagerColors);
                break;

            case 5:
                cout << "Enter name of villager you want to search" << endl;
                cin >> name;
                search(villagerColors, name);
                range_display(villagerColors);
                break;

            case 6:
                cout << "Exiting Program" << endl;
                clear(villagerColors);
                return 0;
        }
    }
}

void clear(map<string, tuple<int,string,string>> &villagerColors){
    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerColors.size() << endl;
    villagerColors.clear();
    cout << "Size after clear: " << villagerColors.size() << endl; 
}

void range_display(map<string, tuple<int,string,string>> &villagerColors){
    // access the map using a range-based for loop
    cout << "Villagers and their favorite traits (range-based for loop):" << endl;
    for (auto villager : villagerColors) {
        cout << villager.first << ": ";
        cout << get<0>(villager.second) << ", ";
        cout << get<1>(villager.second) << ", ";
        cout << get<2>(villager.second) << " " << endl;
    }
    cout << endl;
}

void iterator_display(map<string, tuple<int,string,string>> &villagerColors){
    // access the map using iterators
    cout << "\nVillagers and their favorite traits (iterators):" << endl;
    for (map<string, tuple<int,string,string>>::iterator it = villagerColors.begin(); 
                                               it != villagerColors.end(); ++it) {
        cout << it->first << ": ";
        cout << get<0>(it->second) << ", ";
        cout << get<1>(it->second) << ", ";
        cout << get<2>(it->second) << " " << endl;
    }
    cout << endl;
}

void search(map<string, tuple<int,string,string>> &villagerColors, string searchKey){
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

void addFriendship(map<string, tuple<int,string,string>> &villagerColors, string name){
    auto it = villagerColors.find(name);

    if(it != villagerColors.end()){
        if(get<0>(it->second) < 10 && get<0>(it->second) >= 0){
            get<0>(it->second) += 1;
        }
        else{
            cout << "Max Friendship Reached" << endl;
        }

    }
}

void deleteFriendship(map<string, tuple<int,string,string>> &villagerColors, string name){
    auto it = villagerColors.find(name);

    if(it != villagerColors.end()){
        if(get<0>(it->second) <= 10 && get<0>(it->second) > 0){
            get<0>(it->second) -= 1;
        }
        else{
            cout << "Lowest Friendship Reached" << endl;
        }

    }
}

void addVillager(map<string, tuple<int,string,string>> &villagerColors){
    string name;
    int friendship;
    string species;
    string phrase;

    cout << "Enter Name: ";
    cin >> name;

    cout << "Enter Friendship Level: ";
    cin >> friendship;

    while(friendship > 10 || friendship < 0){
        cout << "Try Again. Must be between 0 and 10: ";
        cin >> friendship;
    }

    cin.ignore();

    cout << "Enter Catchphrase: ";
    getline(cin, phrase);

    cout << "Enter Species: ";
    getline(cin,species);

    villagerColors.insert({name,{friendship,species,phrase}});
}

void deleteVillager(map<string, tuple<int,string,string>> &villagerColors, string name){
    auto it = villagerColors.find(name);

    if(it != villagerColors.end()){
        villagerColors.erase(name);
    }
    else{
        cout << "Name couldn't be found. Cannot erase" << endl;
    }
}