#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
        char* data;
        vector<Node*> children;
        bool isLocked;
        char* lockedBy;
        Node(char* data){
            this->data = data;
            isLocked = false;
        }
};
bool lock(Node* node, char* lockedBy){
    if(node->isLocked){
        return false;
    }
    else{
        node->isLocked = true;
        node->lockedBy = lockedBy;
        return true;
    }
}
bool unlock(Node* node, char* lockedBy){
    if(node->isLocked && node->lockedBy == lockedBy){
        node->isLocked = false;
        return true;
    }
    else{
        return false;
    }
}

bool areDescendentsLockedBySameUser(Node* node, char* lockedBy){
    if(node->isLocked && node->lockedBy == lockedBy){
        return true;
    }
    else{
        for(int i = 0; i < node->children.size(); i++){
            if(areDescendentsLockedBySameUser(node->children[i], lockedBy)){
                return true;
            }
        }
        return false;
    }
}

bool upgradeLockToAncestor(Node* node, char* lockedBy){
    if(node->isLocked && node->lockedBy != lockedBy){
        return false;
    }
    else{
        node->isLocked = true;
        node->lockedBy = lockedBy;
        for(int i = 0; i < node->children.size(); i++){
            upgradeLockToAncestor(node->children[i], lockedBy);
        }
        return true;
    }
}
int main(int argc, char const *argv[])
{
    int numberOfNodes, numberOfQueries, numberOfChildren;
    cin >> numberOfNodes >> numberOfChildren>> numberOfQueries;
    Node* root;
    for (int i = 0;i<numberOfNodes;i++){
        char* data = new char[100];
        cin >> data;
        Node* node = new Node(data);
        // Node* node = new Node(i);
        if(i == 0){
            root = node;
        }
        for(int j = 0; j < numberOfChildren; j++, i++){
            char* data = new char[100];
            cin >> data;
            Node* child = new Node(data);
            node->children.push_back(child);
        }
    }
    return 0;
}
