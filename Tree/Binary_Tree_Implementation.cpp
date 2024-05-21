#include <bits/stdc++.h>
#include "gtest/gtest.h"

// Node class representing a single node of a binary tree
class node {
public:
    int data;
    node *left;
    node *right;

    // Constructor to initialize the node with data and set left and right pointers to nullptr
    node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Tree class representing the binary tree and its operations
class Tree {
public:
    // Function to create a binary tree from user input
    node* createTree() {
        int data;
        std::cout << "Enter the data" << std::endl;
        std::cin >> data;
        if (data == -1)
            return nullptr;

        node *root = new node(data);
        
        std::cout << "Enter the left of tree" << std::endl;
        root->left = createTree();
        
        std::cout << "Enter the right of tree" << std::endl;
        root->right = createTree();
        
        return root;
    }

    // Function to perform pre-order traversal of the binary tree
    void preOrder(node *root, std::vector<int> &result) {
        if (root == nullptr)
            return;

        result.push_back(root->data);
        preOrder(root->left, result);
        preOrder(root->right, result);
    }

    // Function to perform in-order traversal of the binary tree
    void inOrder(node *root, std::vector<int> &result) {
        if (root == nullptr) {
            return;
        }

        inOrder(root->left, result);
        result.push_back(root->data);
        inOrder(root->right, result);
    }

    // Function to perform level-order traversal of the binary tree
    void LevelOrder(node *root, std::vector<int> &result) {
        if (root == nullptr) {
            return;
        }

        std::queue<node *> q;
        q.push(root); // Initial push of root node into the queue

        // Iterate while the queue is not empty
        while (!q.empty()) {
            node *front = q.front();
            q.pop();
            result.push_back(front->data);

            if (front->left != nullptr) {
                q.push(front->left);
            }
            if (front->right != nullptr) {
                q.push(front->right);
            }
        }
    }
};

// Helper function to create a simple tree for testing
node* createTestTree() {
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    return root;
}

// Test the preOrder function
TEST(TreeTest, PreOrderTraversal) {
    Tree t;
    node* root = createTestTree();
    std::vector<int> result;
    t.preOrder(root, result);

    std::vector<int> expected = {1, 2, 4, 5, 3, 6, 7};
    EXPECT_EQ(result, expected);
}

// Test the inOrder function
TEST(TreeTest, InOrderTraversal) {
    Tree t;
    node* root = createTestTree();
    std::vector<int> result;
    t.inOrder(root, result);

    std::vector<int> expected = {4, 2, 5, 1, 6, 3, 7};
    EXPECT_EQ(result, expected);
}

// Test the LevelOrder function
TEST(TreeTest, LevelOrderTraversal) {
    Tree t;
    node* root = createTestTree();
    std::vector<int> result;
    t.LevelOrder(root, result);

    std::vector<int> expected = {1, 2, 3, 4, 5, 6, 7};
    EXPECT_EQ(result, expected);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
