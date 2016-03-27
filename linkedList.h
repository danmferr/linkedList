#ifndef H_LinkedListType
#define H_LinkedListType

#include <iostream>


using namespace std;
template <class Type>
struct node
{
	Type info;
	node<Type> *z;
};

template<class Type>
class linkedListType
{
public:
	linkedListType(const linkedListType<Type>& subList);
    const linkedListType<Type>& operator=
          			      (const linkedListType<Type>&); //Overload 
    
    virtual bool search(const Type& searchItem) const=0;
    virtual void insertFirst(const Type& newItem)=0;//insert to first
    virtual void inputlast(const Type& newItem);//insert new into last of list
    virtual void deleteNode(const Type& deleteItem)=0;//delete item function
	virtual void divideMid(linkedListType<Type> &sublist);//splits into 2
	virtual void divideAt(linkedListType<Type> &sublist, const Type& item);
    linkedListType(); 
    ~linkedListType();   
    void initializeList(); 
    bool empty() const;
    void print() const;
    int length() const;
    void desList();
    Type front() const; 
    Type back()const; 
protected:
    int count;	
    node<Type> *first; 
    node<Type> *last;  

private: 
    void copyList(const linkedListType<Type>& subList); 
	

};

template<class Type>
bool linkedListType<Type>::empty() const
{
	return(first == NULL);
}

template<class Type>
linkedListType<Type>::linkedListType() //default 
{
	first = NULL;
	last = NULL;
 	count = 0;
}

template<class Type>
void linkedListType<Type>::desList()
{
	node<Type> *minor;   
	while (first != NULL)    
	{
	   minor = first;        
	   first = first->z; 
	   delete minor;       
	}
	last = NULL; 
 	count = 0;
}


	
template<class Type>
void linkedListType<Type>::initializeList()
{
	desList(); //if the list has any nodes, delete them
}

template<class Type>
void linkedListType<Type>::print() const
{
	node<Type> *current; 
	current = first;  
	while (current != NULL) 
	{
	   cout << current->info << " ";
	   current = current->z;
	}
}


template<class Type>
int linkedListType<Type>::length() const
{
    return count;
}  

template<class Type>
Type linkedListType<Type>::front() const
{   
    
    return first->info; //return 
}

template<class Type>
Type linkedListType<Type>::back() const
{   
    
    return last->info; 
}


template<class Type>
bool linkedListType<Type>::search(const Type& item) const
{
   node<Type> *current; 
   bool found = false;
   
   current = first; 

   while (current != NULL && !found) //search
       if (current->info == item)    // is found
           found = true;
       else
           current = current->z; 
   return found; 
}//end search


template<class Type>
void linkedListType<Type>::insertFirst(const Type& newItem)
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
void linkedListType<Type>::inputlast(const Type& newItem)
{
   node<Type> *newNode; 

   newNode = new node<Type>; 


   newNode->info = newItem;     
   newNode->z = NULL;         

   if (first == NULL)  
   {
	  first = newNode;
	  last = newNode;
	  count++;		
   }
   else     
   {
	last->z = newNode; 
	last = newNode;   
      count++;		
   }
}



template<class Type>
void linkedListType<Type>::deleteNode(const Type& deleteItem)
{
    node<Type> *current; 
    node<Type> *trailCurrent; 
    bool found;
    if (first == NULL)    
        cout << "Can not delete "
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
            found = false;
            trailCurrent = first;  
            current = first->z; 

            while (current != NULL &&  !found)
            {
                if (current->info != deleteItem) 
                {
                    trailCurrent = current;
                    current = current-> z;
                }
                else
                    found = true;
            } 

            if (found) 
            {
                trailCurrent->z = current->z;
                count--;

                if (last == current)   
                    last = trailCurrent; 
                delete current;  
            }
            else
                cout << "The item to be deleted is not here"<< endl;
        } 
    } 
} 
template<class Type>
void linkedListType<Type>::copyList
                   (const linkedListType<Type>& subList) 
{
    node<Type> *newNode; 
    node<Type> *current; 

    if (first != NULL) //make it empty
       desList();

    if (subList.first == NULL) //empty
    {
        first = NULL;
        last = NULL;
        count = 0;
    }
    else
    {
        current = subList.first; 
        count = subList.count;
        first = new node<Type>;  


        first->info = current->info; 
        first->z = NULL;       
        last = first;              
        current = current->z;     

           //copy the remaining list
        while (current != NULL)
        {
            newNode = new node<Type>;  //create a node

            
            newNode->info = current->info; //copy 
            newNode->z = NULL;       
            last->z = newNode;  
            last = newNode;        
            current = current->z;   
        }
    }
}

template<class Type>
linkedListType<Type>::~linkedListType() //destructor
{
   desList();
}//end 

template<class Type>
linkedListType<Type>::linkedListType
            	    (const linkedListType<Type>& subList) 
{
   	first = NULL;
    copyList(subList);
}//end

template<class Type>
const linkedListType<Type>& linkedListType<Type>::operator=
                      (const linkedListType<Type>& subList)
{ 
    if (this != &subList) 
    {
        copyList(subList);
    }//end else

     return *this; 
}

template<class Type>
void linkedListType<Type>::divideMid(linkedListType<Type> &sublist)
{
	node<Type> *current; 
	node<Type> *mid; 

	if (first == NULL)
	{

		sublist.first = NULL;
		sublist.last = NULL;
	}
	else
		if (first->z == NULL)
		{
			sublist.first = NULL;
			sublist.last = NULL;
		}
		else
		{
			mid = first;
			current = first->z;

			if (current != NULL)
				current = current->z;
		
			while (current != NULL)
			{
				mid = mid->z;
				current = current->z;

				if (current != NULL)
					current = current->z;
			}

			sublist.first = mid->z;
			sublist.last = last;
			last = mid;
			last->z = NULL;
		}
}

template<class Type>
void linkedListType<Type>::divideAt(linkedListType &sublist, const Type& item)
{
	node<Type> *current; 
	node<Type> *trailCurrent;

	bool found;

	if (first == NULL)
	{
		cout << "is empty." << endl;
		sublist.first = NULL;
		sublist.last = NULL;
	}
	else
	{
		current = first;
		found = false;

		while (current != NULL && !found)
			if (current->info == item)
				found = true;
			else
			{
				trailCurrent = current;
				current = current->z;
			}

		if (found)
		{
			if (first == current)
			{
				sublist.first = first;
				sublist.last = last;
				first = NULL;
				last = NULL;
			}
			else
			{
				sublist.first = current;
				sublist.last = last;
				last = trailCurrent;
				last->z = NULL;
			}
		}
		else
		{
			cout << " not in the list." << endl;
			sublist.first = NULL;
			sublist.last = NULL;
		}
	}
}

#endif
