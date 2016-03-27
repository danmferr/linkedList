#ifndef H_UnorderedLinkedList
#define H_UnorderedLinkedList

#include "linkedList.h"
 
using namespace std;

template <class Type>
class unorderedLinkedList: public linkedListType<Type>
{
public:
    bool search(const Type& searchItem) const;
    void insertFirst(const Type& newItem);
    void inputlast(const Type& newItem);
    void deleteNode(const Type& deleteItem);
    

private:
 
    void divideList(node<Type>* first1, 
                    node<Type>* &first2);
};


template<class Type>
bool unorderedLinkedList<Type>::
                   search(const Type& searchItem) const
{
    node<Type> *current; 
    bool yes = false;
    current = first; 
  while (current != NULL && !yes)    
        if (current->info == searchItem) //searchItem is yes
            yes = true;
        else
            current = current->z; 
    return yes; 
}

template<class Type>
void unorderedLinkedList<Type>::insertFirst(const Type& newItem)
{
   node<Type> *newNode; //pointer 
   newNode = new node<Type>; 
   newNode->info = newItem; 	  
   newNode->z = first;        
   first = newNode;             
   count++; 			   
   if (last == NULL)   
      last = newNode;
}

template<class Type>
void unorderedLinkedList<Type>::inputlast(const Type& newItem)
{
    node<Type> *newNode; //pointer to create the new node

    newNode = new node<Type>; //create the new node

    
    newNode->info = newItem;   //store the new item in the node
    newNode->z = NULL;   
    if (first == NULL)  
    {
        first = newNode;
        last = newNode;
        count++;        //increment count
    }
    else   
    {
        last->z = newNode; 
        last = newNode; 
        count++;        //increment 
    }
}


template<class Type>
void unorderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
    node<Type> *current; 
    node<Type> *Current; 
    bool yes;
    if (first == NULL)   
        cout << "Cannot delete."
             << endl;
    else
    {
        if (first->info == deleteItem) 
        {
            current = first;
            first = first->z;
            count--;
            if (first == NULL)    
                last = NULL;
            delete current;
        }
        else 
        {
            yes = false;
			Current = first;  
            current = first->z; 

            while (current != NULL && !yes)
            {
                if (current->info != deleteItem) 
                {
                    Current = current;
                    current = current-> z;
                }
                else
                    yes = true;
            }

            if (yes) 
            {
                Current->z = current->z;
                count--;

                if (last == current)   
                    last = Current; 
                delete current;  
            }
            else
                cout << "The item to be deleted is not in "
                     << "the list." << endl;
        }
    }
}
template <class Type>
void unorderedLinkedList<Type>::
               divideList(node<Type>* first1, 
                          node<Type>* &first2)
{
    node<Type>* middle;
    node<Type>* current;

    if (first1 == NULL)   
        first2 = NULL;
    else if (first1->z == NULL)  
        first2 = NULL;
    else
    {
        middle = first1;
        current = first1->z;

        if (current != NULL)    
            current = current->z;
        while (current != NULL)
        {
            middle = middle->z;
            current = current->z;
            if (current != NULL)
                current = current->z;
        } 
        first2 = middle->z; 
        middle->z = NULL;   
    } 
} 



#endif
