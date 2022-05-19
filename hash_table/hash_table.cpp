#include "hash_table.h"


Dictionary::Dictionary(int size)
{
	dict_size = size;
	dictionary = new Node * [dict_size];
	for (int i = 0; i < dict_size; i++)
	{
		dictionary[i] = nullptr;
	}
}

void Dictionary::insert(string data)
{
	if (member(data)) return;

	int index = hash(data);

	if (dictionary[index] == nullptr)
	{
		dictionary[index] = new Node;
		dictionary[index]->data = data;
		dictionary[index]->next = nullptr;
	}
	else
	{
		Node* current = dictionary[index];
		while (current->next != nullptr)
		{
			current = current->next;
		}
		Node* temp = new Node;
		temp->data = data;
		temp->next = nullptr;
		current->next = temp;
	}
}

void Dictionary::delete_(string data)
{
	if (!member(data)) return;

	int index = hash(data);

	Node* current = dictionary[index];

	if (data == dictionary[index]->data)
	{
		dictionary[index] = dictionary[index]->next;
		return;
	}

	while (current->next->data != data)
	{
		current = current->next;
	}

	current->next = current->next->next;
	current = current->next;
}

bool Dictionary::member(string data)
{
	Node* current = dictionary[hash(data)];

	if (current == nullptr)
	{
		return false;
	}

	while (current != nullptr)
	{
		if (current->data == data)
			return true;
		else
			current = current->next;
	}

	return false;
}

void Dictionary::clear()
{
	for (int i = 0; i < dict_size; i++)
	{
		dictionary[i] = nullptr;
	}
}

void Dictionary::print()
{
	Node* current;

	for (int i = 0; i < dict_size; i++)
	{
		cout << "[" << i << "]  ";

		current = dictionary[i];

		while (current != nullptr)
		{
			cout << current->data << "  ";
			current = current->next;
		}
		cout << endl;
	}
	cout << endl;
}

int Dictionary::hash(string data)
{
	int hash = 0;

	for (int i = 0; i < data.size(); i++)
	{
		hash += (int)data[i];
	}

	return hash % dict_size;
}