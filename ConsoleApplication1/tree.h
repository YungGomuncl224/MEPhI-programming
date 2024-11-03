#ifndef TREE_H
#define TREE_H

#include <iostream>
using namespace std;
#include <format>


template <class T>
class elem
{
public:
    int key;
    T data;
    elem* left;
    elem* right;
    elem(int k, T val)
    {
        left = nullptr;
        right = nullptr;
        data = val;
        key = k;
    }
};

template <class T>
class binary_tree
{
private:
    elem<T>* root;
    int size;

public:

    void garbagge()
    {
        if (root == nullptr) cout << " dcvdcd";
        cout << "[ ";
        if (root == nullptr) cout << "a";
        print_tree(root);
        cout << " ] ";
        cout << " after print_tree" << endl;
        cout << endl;

    }

    binary_tree() {
        root = NULL;
        size = 0;
    }

    binary_tree(int key, T data)
    {
        root = new elem<T>(key, data);
        size = 1;
    }

    void print()
    {
        cout << "[ ";
        print_tree(root);
        cout << "] ";
        cout << endl;


    }

    void print_tree(elem<T>* curr)
    {
        //cout << " from print_tree " << endl;
        if (curr) {
            //cout << " curr is not null" << endl;
           // if (curr->left) cout << "lala" << endl;
            print_tree(curr->left);
            cout << "{ ";
            cout << curr->key << ", ";
            cout << curr->data << "} ";
            print_tree(curr->right);
        }
        //else cout << " curr is null " << endl;

    }

    int age = 0;
    void print_tree_gis(elem<T>* curr)
    {
        //cout << " from print_tree " << endl;
        if (curr) {
            //cout << " curr is not null" << endl;
           // if (curr->left) cout << "lala" << endl;
            print_tree_gis(curr->left);
            printf("{ %d to ", age );
            cout << curr->key << ", ";
            cout << curr->data << "} ";
            age += 30;
            print_tree_gis(curr->right);
        }
        //else cout << " curr is null " << endl;
        //age = 0;

    }

    void print_gis()
    {
        cout << "[ ";
        print_tree_gis(root);
        cout << "] ";
        cout << endl;


    }

    void show(int key)
    {
        elem<T>* curr = root;
        while (curr && curr->key != key)
        {
            if (curr->key > key)
                curr = curr->left;
            else
                curr = curr->right;
        }
        if (curr->left) {
            cout << "left: ";
            cout << curr->left->data << "\n";
        }
        else {
            cout << "left: ";
            cout << "not exist" << "\n";
        }

        if (curr->right) {
            cout << "right: " << "\n";
            cout << curr->right->data << "\n";
        }
        else {
            cout << "right: ";
            cout << "not exist" << "\n";
        }

    }

    T find(int key)
    {
        elem<T>* curr = root;
        while (curr && curr->key != key)
        {
            if (curr->key > key)
                curr = curr->left;
            else
                curr = curr->right;
        }
        if (curr != NULL) {
            return curr->data;

        }
        else return -1;
    }

    void insert(int key, T value)
    {
        elem<T>* curr = root;
        if (root == NULL) {
            root = new elem<T>(key, value);
            size++;
        }
        else {
            while (curr && curr->key != key)
            {
                if (curr->key > key && curr->left == NULL)
                {
                    curr->left = new elem<T>(key, value);
                    ++size;
                    return;
                }
                if (curr->key < key && curr->right == NULL)
                {
                    curr->right = new elem<T>(key, value);
                    ++size;
                    return;
                }
                if (curr->key > key)
                    curr = curr->left;
                else
                    curr = curr->right;
            }
        }
        // size++;
    }

    void erase(int key)
    {
        if (root->left && root->right == NULL) {
            root = nullptr;
            size--;
        }
        else {
            elem<T>* curr = root;
            elem<T>* parent = NULL;
            while (curr && curr->key != key)
            {
                parent = curr;
                if (curr->key > key)
                {
                    curr = curr->left;
                }
                else
                {
                    curr = curr->right;
                }
            }
            if (!curr)
                return;
            if (curr->left == NULL)
            {

                if (parent && parent->left == curr)
                    parent->left = curr->right;
                if (parent && parent->right == curr)
                    parent->right = curr->right;
                --size;
                delete curr;
                return;
            }
            if (curr->right == NULL)
            {

                if (parent && parent->left == curr)
                    parent->left = curr->left;
                if (parent && parent->right == curr)
                    parent->right = curr->left;
                --size;
                delete curr;
                return;
            }

            elem<T>* replace = curr->right;
            while (replace->left)
                replace = replace->left;
            T replace_value = replace->key;
            erase(replace_value);
            curr->key = replace_value;
        }
    }

    elem<T>* Get_root()
    {
        return this->root;
    }

    int isSubtree(elem<T>* S, elem<T>* T)
    {
        if (S == NULL)
            return 0;
        return (isEqual(S, T) || isSubtree(S->left, T) || isSubtree(S->right, T));
    }

    int isEqual(elem<T>* S, elem<T>* T)
    {
        if (S == NULL && T == NULL)
            return 1;
        if (S == NULL || T == NULL)
            return 1;
        if (S->data == T->data)
            return isEqual(S->left, T->left) && isEqual(S->right, T->right);
        else
            return 0;
    }

    int Get_size()
    {
        return size;
    }

    bool InTree(int key)
    {
        elem<T>* curr = root;
        while (curr && curr->key != key)
        {
            if (curr->key > key)
                curr = curr->left;
            else
                curr = curr->right;
        }
        return curr != NULL;
    }


};

#endif;
