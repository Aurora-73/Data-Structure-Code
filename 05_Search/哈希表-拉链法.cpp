#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

#define TABLESIZE 11

// 定义哈希表的节点结构
struct Node {
    int data;
    struct Node* next;
};

// 定义哈希表结构
struct HashTable {
    int count;
    struct Node* *head;
};

// 哈希函数：计算关键字的哈希值
int Hash(int key) {
    return key % TABLESIZE;
}

// 初始化哈希表
int InitHashTable(HashTable& H) {
    H.count = 0;
    H.head = new Node*[TABLESIZE];
    for (int i = 0; i < TABLESIZE; i++) {
        H.head[i] = nullptr;
    }
    return 0;
}

// 查找一个关键字是否在哈希表中，并返回对应的指针
Node* SearchHash(const HashTable &H, int key) {
    int index = Hash(key);
    Node* p = H.head[index];

    while (p != nullptr) {
        if (p->data == key) {
            return p;
        }
        p = p->next;
    }

    return nullptr;
}


// 插入一个关键字到哈希表中
void InsertHash(HashTable &H, int key) {
    if(SearchHash(H,key)){
        cout << key << "已经存在" << endl;
        return;
    } 
    int index = Hash(key);
    Node* p = new Node;
    p->data = key;
    p->next = H.head[index];
    H.head[index] = p;
    H.count++;
}

// 删除一个关键字从哈希表中
bool DeleteHash(HashTable& H, int key){
    int index = Hash(key);
    Node* p = H.head[index];
    Node* pre = nullptr;

    while (p != nullptr && p->data != key) {
        pre = p;
        p = p->next;
    }

    if (p == nullptr) {
        return false; // 未找到关键字
    }

    if (pre == nullptr) {
        H.head[index] = p->next;
    } else {
        pre->next = p->next;
    }

    delete p;
    H.count--;
    return true;
}

// 打印哈希表
void PrintHashTable(const HashTable& H) {
    for (int i = 0; i < TABLESIZE; i++) {
        cout << "Bucket " << i << ": ";
        Node* p = H.head[i];
        while (p != nullptr) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
}

int main() {
    HashTable H;
    if (InitHashTable(H) == -1) {
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
        InsertHash(H, elements[i]);
    }
    PrintHashTable(H);

    while (true) {
        cout << "\n请选择操作: " << endl;
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
            InsertHash(H, insertKey);
            PrintHashTable(H);
            break;
        }
        case 2: {
            int deleteKey;
            cout << "请输入要删除的值: ";
            cin >> deleteKey;
            if (DeleteHash(H, deleteKey)) {
                cout << "Key " << deleteKey << " 删除成功" << endl;
            } else {
                cout << "Key " << deleteKey << " 未找到" << endl;
            }
            PrintHashTable(H);
            break;
        }
        case 3: {
            int searchKey;
            cout << "请输入要查找的值: ";
            cin >> searchKey;
            Node* result = SearchHash(H, searchKey);
            if (result != nullptr) {
                cout << "Key " << searchKey << " 的地址为 " << result << endl;
            } else {
                cout << "Key " << searchKey << " 未找到" << endl;
            }
            break;
        }
        case 4: {
            for (int i = 0; i < TABLESIZE; i++) {
                Node* p = H.head[i];
                while (p != nullptr) {
                    Node* temp = p;
                    p = p->next;
                    delete temp;
                }
            }
            delete[] H.head;
            return 0;
        }
        default:
            cout << "无效选择，请重新选择操作." << endl;
        }
    }
}