#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

#define HASHSIZE 11
#define NULLKEY -32768

typedef struct {
    int* elem; // 数据元素基址，动态分配数组
    int count; // 当前数据元素个数
} HashTable;

int InitHashTable(HashTable &H) {
    H.count = 0;
    H.elem = (int*)malloc(HASHSIZE * sizeof(int));
    if (!H.elem) return -1;
    for (int i = 0; i < HASHSIZE; i++) {
        H.elem[i] = NULLKEY;
    }
    return 0;
}

// 除留余数法
int Hash(int key) {
    return key % HASHSIZE;
}

bool SearchHash(HashTable H, int key, int& addr) {
    addr = Hash(key);
    while (H.elem[addr] != key) {
        addr = (addr + 1) % HASHSIZE;
        if (H.elem[addr] == NULLKEY || addr == Hash(key))
            return false;
    }
    return true; // 返回 true 表示找到了 key
}

void InsertHash(HashTable& H, int key) {
    if(H.count == HASHSIZE) {
        cout << "哈希表已满，" << key << "插入失败" <<endl;
        return;
    }
    int addr;
    if(SearchHash(H,key,addr)) {
        cout << key << "已经存在" <<endl;
        return;
    }
    addr = Hash(key);
    while (H.elem[addr] != NULLKEY) // 若不为空，则冲突出现
        addr = (addr + 1) % HASHSIZE; // 线性探测再散列法
    H.elem[addr] = key;
    H.count++;
}

bool DeleteHash(HashTable& H, int key) {
    int addr,nextaddr;
    if (!SearchHash(H, key, addr)) {
        return false;
    }
    H.elem[addr] = NULLKEY;
    H.count--;
    nextaddr = (addr + 1)%HASHSIZE;
    while(nextaddr != addr && H.elem[nextaddr] != NULLKEY) {
        if(Hash(H.elem[nextaddr]) != nextaddr) {
            int temp = H.elem[nextaddr];
            H.elem[nextaddr] = NULLKEY;
            H.count--;
            InsertHash(H,temp);
        }//先删除可被前移的元素，然后重新插入该元素，自动完成前移
        nextaddr = (nextaddr + 1)%HASHSIZE;
    }
    return true;
}//如果同义词之间夹的有非同义词，就必须轮一遍才知道谁可以前移，(如果前移后出现了空位，即使是与被删除元素非同义的元素也要前移)如果不使用先删除后插入就无法知道应该前移到哪里

void PrintHashTable(const HashTable& H) {
    cout << "HashTable: ";
    for (int i = 0; i < HASHSIZE; i++) {
        if (H.elem[i] != NULLKEY) {
            cout << H.elem[i] << " ";
        } else {
            cout << "#" << " ";
        }
    }
    cout << endl;
}

int main() {
    HashTable myHashTable;
    if (InitHashTable(myHashTable) == -1) {
        cout << "哈希表初始化失败." << endl;
        return 1;
    }

    // 从用户输入中构建散列表
    cout << "请输入以,分隔的元素序列 (例如1,2,4,5,8,0,1): ";
    string input;
    getline(cin, input);
    stringstream ss(input);
    vector<int> elements;
    string element;
    while (getline(ss, element, ',')) {
        elements.push_back(stoi(element));
    }

    for (int i = 0; i < elements.size(); i++) {
        InsertHash(myHashTable, elements[i]);
    }
    PrintHashTable(myHashTable);

    while (true) {
        cout << "请选择操作: " << endl;
        cout << "1. 插入元素" << endl;
        cout << "2. 删除元素" << endl;
        cout << "3. 查找元素" << endl;
        cout << "4. 退出" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            int insertKey;
            cout << "请输入要插入的值: ";
            cin >> insertKey;
            InsertHash(myHashTable, insertKey);
            break;
        }
        case 2: {
            int deleteKey;
            cout << "请输入要删除的值: ";
            cin >> deleteKey;
            if (DeleteHash(myHashTable, deleteKey)) {
                cout << "Key " << deleteKey << " 删除成功" << endl;
            } else {
                cout << "Key " << deleteKey << " 未找到" << endl;
            }
            break;
        }
        case 3: {
            int searchKey;
            cout << "请输入要查找的值: ";
            cin >> searchKey;
            int addr;
            if (SearchHash(myHashTable, searchKey, addr)) {
                cout << "Key " << searchKey << " 的下标为 " << addr << endl;
            } else {
                cout << "Key " << searchKey << " 未找到" << endl;
            }
            break;
        }
        case 4: {
            free(myHashTable.elem);
            return 0;
        }
        default:
            cout << "无效选择，请重新选择操作." << endl;
        }
        PrintHashTable(myHashTable);
    }
    free(myHashTable.elem);
    return 0;
}
