#include "hash_table.h"

int main()
{
	Dictionary a(5);
	int array_size = 15;
	string array[] = { "bread","milk","apple","beef","chicken","ham", "butter", "egg", "cherry", "porridge" , "jam" , "noodles" , "carrot" , "avocado" , "potato" };
	for (int i = 0; i < array_size; i++)
	{
		a.insert(array[i]);
	}
	cout << "hash table after inserting 15 items: " << endl;
	a.print();
	a.delete_("egg");
	cout << "hash table after deleting item 'egg': " << endl;
	a.print();
	a.delete_("bread");
	cout << "hash table after deleting item 'bread': " << endl;
	a.print();
	a.delete_("ham");
	cout << "hash table after deleting item 'ham': " << endl;
	a.print();
	a.delete_("minardi");
	cout << "hash table after deleting item 'minardi', that isn`t in the table: " << endl;
	a.print();

	cout << "testing the 'member' function on the example of a word " << array[13] << ": " << endl;
	if (a.member(array[13]))
		cout << array[13] << " is in the hash table" << endl;
	else
		cout << array[13] << " isn't in the hash table" << endl;

	cout << endl << "testing the 'member' function on the example of a word " << array[7] << ": " << endl;
	if (a.member(array[7]))
		cout << array[7] << " is in the hash table" << endl;
	else
		cout << array[7] << " isn't in the hash table" << endl;

	a.clear();
	cout << endl << "hash table after deleting all items: " << endl;
	a.print();
}