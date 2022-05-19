#pragma once
#include <iostream>
#include <string.h>
using namespace std;

struct Node
{
	string data;
	Node* next;
};

class Dictionary
{
	Node** dictionary;
	int dict_size;
	int hash(string data);
public:
	Dictionary(int size);

	void insert(string data);
	void delete_(string data);
	bool member(string data);
	void clear();
	void print();
};