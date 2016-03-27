/* Danielle Ferriola

Linked lists
csc 161
ch 16
*/

#include <iostream>
#include "unorderedLinkedList.h"

using namespace std;
 
int main()
{
	unorderedLinkedList<int> list, subList;
				
	int num;										 

	cout << "Enter numbers ending with -999" << endl;										 
	cin >> num;									 

	while (num != -999)								 
	{
		list.inputlast(num);						 
		cin >> num;									 
	}

	cout << endl;									 

	cout << "List: ";					 
	list.print();									 
	cout << endl;										 
	cout << "Length of the list: " << list.length() << endl;									 


	list.divideMid(subList);

	cout << "Lists after splitting list" << endl;

	cout << "list: ";
	list.print();									 
	cout << endl;										 
	cout << "Length of the list: " << list.length() << endl;		

	cout << "sublist: ";
	subList.print();									 
	cout << endl;										 
	cout << "Length of subList: " << subList.length() << endl;
	system("pause");
	return 0;					
}



