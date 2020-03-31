//
// Created by Daniil Yefimov on 31.03.2020.
//
#pragma once

class StackL {
public:
    StackL();
    StackL(const StackL&);
    StackL& operator=(const StackL&);
    ~StackL();
    void pop();
    void push(const float v);
    bool is_empty() const;
    float& top();
    float& at(int at);

    void insertAt(int at,float value);
    void deleteAt(int at);

    const float& top() const;

    struct Node {
        float value{ 0.0 };
        Node* next{ nullptr };
    };

    int current {0};

    Node* head{ nullptr };

};