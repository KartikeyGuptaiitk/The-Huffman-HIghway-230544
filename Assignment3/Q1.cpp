#include <iostream>
#include <string>

using namespace std;

struct Student {
    string name;
    int rollNumber;
    string course;
    int totalMarks;
};

struct Node {
    Student student;
    Node* left;
    Node* right;

    Node(Student s) : student(s), left(nullptr), right(nullptr) {}
};

class StudentRecordBST {
private:
    Node* root;

    Node* insert(Node* node, Student s) {
        if (!node)
            return new Node(s);

        if (s.rollNumber < node->student.rollNumber)
            node->left = insert(node->left, s);
        else if (s.rollNumber > node->student.rollNumber)
            node->right = insert(node->right, s);

        return node;
    }

    Node* minNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }

    Node* deleteNode(Node* root, int rollNumber) {
        if (root == nullptr)
            return root;

        if (rollNumber < root->student.rollNumber)
            root->left = deleteNode(root->left, rollNumber);
        else if (rollNumber > root->student.rollNumber)
            root->right = deleteNode(root->right, rollNumber);
        else {
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            Node* temp = minNode(root->right);
            root->student = temp->student;
            root->right = deleteNode(root->right, temp->student.rollNumber);
        }
        return root;
    }

    void inorder(Node* root) {
        if (root != nullptr) {
            inorder(root->left);
            cout << "Roll Number: " << root->student.rollNumber << ", Name: " << root->student.name
                 << ", Course: " << root->student.course << ", Total Marks: " << root->student.totalMarks << endl;
            inorder(root->right);
        }
    }

    Node* search(Node* root, int rollNumber) {
        if (root == nullptr || root->student.rollNumber == rollNumber)
            return root;

        if (root->student.rollNumber < rollNumber)
            return search(root->right, rollNumber);

        return search(root->left, rollNumber);
    }

public:
    StudentRecordBST() : root(nullptr) {}

    void insert(Student s) {
        root = insert(root, s);
    }

    void deleteRecord(int rollNumber) {
        root = deleteNode(root, rollNumber);
    }

    void showRecords() {
        inorder(root);
    }

    void searchRecord(int rollNumber) {
        Node* result = search(root, rollNumber);
        if (result != nullptr) {
            cout << "Record Found: Roll Number: " << result->student.rollNumber << ", Name: " << result->student.name
                 << ", Course: " << result->student.course << ", Total Marks: " << result->student.totalMarks << endl;
        } else {
            cout << "Record not found." << endl;
        }
    }
};

int main() {
    StudentRecordBST bst;

    Student s1 = {"Alice", 1, "Computer Science", 95};
    Student s2 = {"Bob", 2, "Electrical Engineering", 88};
    Student s3 = {"Charlie", 3, "Mechanical Engineering", 90};
    Student s4 = {"David", 4, "Civil Engineering", 85};

    bst.insert(s1);
    bst.insert(s2);
    bst.insert(s3);
    bst.insert(s4);

    cout << "All Student Records:" << endl;
    bst.showRecords();

    cout << "\nSearching for student with Roll Number 2:" << endl;
    bst.searchRecord(2);

    cout << "\nDeleting student with Roll Number 3:" << endl;
    bst.deleteRecord(3);

    cout << "\nAll Student Records after deletion:" << endl;
    bst.showRecords();

    return 0;
}
