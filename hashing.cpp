#include <iostream>
#include <vector>
#include <list>

using namespace std;

class HashTable {
public:
    vector<list<int>> table;
    int size;

 HashTable(int tableSize)  {
        this->size=tableSize;
        table.resize(size);
    }

    int hashFunction(int key) 
     {
        return key % size;
    }

   

    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    void display()
     {
        for (int i = 0; i < size; ++i) {
            cout << i << ": ";
            for (int key : table[i]) {
                cout << key << " -> ";
            }
            cout << "NULL" << endl;
        }
    }
};

int main() {
    int tableSize;
    cout << "Enter the size of the hash table: ";
    cin >> tableSize;

    HashTable hashTable(tableSize);

    int numKeys;
    cout << "Enter the number of keys to insert: ";
    cin >> numKeys;

    cout << "Enter the keys to insert:" << endl;
    for (int i = 0; i < numKeys; ++i) {
        int key;
        cin >> key;
        hashTable.insert(key);
    }

    cout << "\nHash Table with Chaining:" << endl;
    hashTable.display();

    return 0;
}
