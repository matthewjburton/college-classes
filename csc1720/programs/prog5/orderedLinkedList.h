/*
Matt Burton
csc1720
04/07/21

Class for ordered linked lists of nodeType connections.
*/

#ifndef UNORDEREDLINKEDLIST
#define UNORDEREDLINKEDLIST

#include "linkedList.h"

using namespace std;


//***************** derived ordered linked list type definition **************************
template <class Type>
class orderedLinkedList:public linkedListType<Type>
{
public:
    bool search(const Type& searchItem) const;
      //Function to determine whether searchItem is in the list.
      //Postcondition: Returns true if searchItem is in the list, 
      //               otherwise the value false is returned.

    void insert(const Type& newItem);
      //Function to insert newItem in the list.
      //Postcondition: first points to the new list, newItem 
      //               is inserted at the proper place in the
      //               list, and count is incremented by 1.

    void insertFirst(const Type& newItem);
      //Function to insert newItem at the beginning of the list.
      //Postcondition: first points to the new list, newItem is
      //               inserted at the proper place in the list,
      //               last points to the last node in the  
      //               list, and count is incremented by 1.

    void insertLast(const Type& newItem);
      //Function to insert newItem at the end of the list.
      //Postcondition: first points to the new list, newItem is 
      //               inserted at the proper place in the list,
      //               last points to the last node in the 
      //               list, and count is incremented by 1.

    void deleteNode(const Type& deleteItem);
      //Function to delete deleteItem from the list.
      //Postcondition: If found, the node containing 
      //               deleteItem is deleted from the list;
      //               first points to the first node of the 
      //               new list, and count is decremented by 1.
      //               If deleteItem is not in the list, an
      //               appropriate message is printed.

	 void deleteLargest();
		//Function to delete the largest number from the list.
		//Postcondition: The last node is deleted from the list.

	 void merge(orderedLinkedList<Type>& listB);
	 	//Function to merge two orderedLinkedLists into one orderedLinkedList
		//Precondition: two lists exist with data in them
		//Postcondition: this calling list is now a merged ordered list 
		// 				  containing all elements from both lists and the listB
		//					  has its first and last = nullptr and count = 0;
};
//***************** ordered linked list type implementation **************************

template <class Type>
bool orderedLinkedList<Type>::search(const Type& searchItem) const
{
   nodeType<Type> *curPtr = this->first;
   //items in the list are in ascending order.
   //stop when you find it and return true.
   //stop when you know it's not in the list because
   //we have advanced to info larger than the searchItem
   while(curPtr != nullptr) {
      if(curPtr->info == searchItem)
         return true;  
      else if(curPtr->info > searchItem)
         return false;  
      curPtr = curPtr->link;
   }
   //at the end of the list so not present.
   return false;
}

template <class Type>
void orderedLinkedList<Type>::insert(const Type& newItem)
{
   nodeType<Type> *curPtr;
   nodeType<Type> *prevPtr;
   nodeType<Type> *newNode;

   newNode = new nodeType<Type>;
   newNode->info = newItem;
   newNode->link = nullptr;
   this->count++;

   if(this->isEmpty()) {
      this->first = this->last = newNode;
   } else {
      prevPtr = nullptr;
      curPtr = this->first;
      while(curPtr != nullptr && curPtr->info < newItem) {
         prevPtr = curPtr;
         curPtr = curPtr->link;
      }
      if(curPtr == this->first) {
         //add as a new first node
         newNode->link = this->first;
         this->first = newNode;
      } else {
         //found after the first node 
         prevPtr->link = newNode;
         newNode->link = curPtr;
         if(prevPtr == this->last) {
            this->last = newNode;
         }
      }
   }
   this->count++;
}

template <class Type>
void orderedLinkedList<Type>::insertFirst(const Type & newItem)
{
   insert(newItem);
}

template <class Type>
void orderedLinkedList<Type>::insertLast(const Type & newItem)
{
   insert(newItem);
}

template <class Type>
void orderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
   nodeType<Type> *curPtr;
   nodeType<Type> *prevPtr;
   
   if(this->isEmpty())
      cerr << "List is empty, can't delete from empty list!" << endl;
   else {
      prevPtr = nullptr;
      curPtr = this->first;
      //move down list until you find it or the info is
      //larger than deleteItem and it's not in the list.
      while(curPtr != nullptr && curPtr->info < deleteItem) {
         prevPtr = curPtr;
         curPtr = curPtr->link;
      }
      if(curPtr->info != deleteItem) {
         cerr << deleteItem << " is not in the list" << endl;
      } else {
         if(curPtr == this->first) {
            //found in the first node
            this->first = this->first->link;
         } else {
            //found after the first node 
            prevPtr->link = curPtr->link;
         }
         if(curPtr == this->last) {
            //if curPtr = last pointer then one of two items are true;
            //only one node in the list and deleteItem is in the first node
            //more than one node in the list and deleteItem is the last node
            this->last = prevPtr;
         }
         delete curPtr; 
         this->count--;
      }
   }
}

template <class Type>
void orderedLinkedList<Type>::deleteLargest()
{
	if (this->count < 1)
	{
		cerr << "The list is already empty." << endl;
	}

	if (this->count >= 1)
	{
		deleteNode(this->last->info);
	}
}

template <class Type>
void orderedLinkedList<Type>::merge(orderedLinkedList<Type>& listB)
{
	nodeType<Type> *ptrOne;
	nodeType<Type> *ptrTwo;
	nodeType<Type> *nFirst;
	nodeType<Type> *nCur;

	if (this != &listB)
	{
		if (this->isEmpty() == false && listB.isEmpty() == false)
		{
			ptrOne = this->first;
			ptrTwo = listB.first;

			if (ptrOne->info < ptrTwo->info)
			{
			nFirst = ptrOne;
			ptrOne = ptrOne->link;
			}
			else
			{
			nFirst = ptrTwo;
			ptrTwo = ptrTwo->link;
			}

			nCur = nFirst;

			while (ptrOne != nullptr && ptrTwo != nullptr)
			{
			if (ptrOne->info < ptrTwo->info)
			{
				nCur->link = ptrOne;
				nCur = nCur->link;
				ptrOne = ptrOne->link;
			}
			else if (ptrTwo->info < ptrOne->info)
			{
				nCur->link = ptrTwo;
				nCur = nCur->link;
				ptrTwo = ptrTwo->link;
			}
			else if (ptrOne->info == ptrTwo->info)
			{
				nCur->link = ptrOne;
				nCur = nCur->link;
				ptrOne = ptrOne->link;

				nCur->link = ptrTwo;
				nCur = nCur->link;
				ptrTwo = ptrTwo->link;
			}
			}

			if (ptrOne == nullptr)
			{
			nCur->link = ptrTwo;
			this->last = listB.last;
			}
			else if (ptrTwo == nullptr)
			{
			nCur->link = ptrOne;
			}

			this->first = nFirst;
			this->count += listB.count;

			listB.first = nullptr;
			listB.last = nullptr;
			listB.count = 0;
		}
		else if (this->isEmpty() == true && listB.isEmpty() == false)
		{
			this->first = listB.first;
			this->last = listB.last;
			this->count = listB.count;

			listB.first = nullptr;
			listB.last = nullptr;
			listB.count = 0;
		}
		else if (listB.isEmpty() == true) 
		{
			cerr << "The second list is empty" << endl;
		}
	}
}

#endif
