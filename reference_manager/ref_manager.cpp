// -------------------------------------------------
// Name: Parth Dadhania
// SID: 1722612
// CCID: pdadhani
// AnonID: 1000330704
// CMPUT 275, Winter 2023
// Assessment: Weekly Exercise #3: Reference Manager
// -------------------------------------------------

#include "ref_manager.h"
#include <cassert>

ReferenceManager::ReferenceManager()
{
  /* initializing "numToDelete" to 0, i.e., initializing the index of the
     "garbage" array to zero to start filling it from the very first element */
  numToDelete = 0;
  /* initializing all the pointers in "pointers" array to NULL */
  for (int i = 0; i < MAX_PTRS; i++)
  {
    pointers[i] = NULL;
  }
}

/*
    Description: This is the Destructor for the class ReferenceManager().
                 It goes through all pointers in the "pointers" array from the
                 first index to the last one and calls method reassignPointer()
                 to reassign all pointers in the array to NULL. Then the 
                 method garbageCollect() is called to free the memory.

    This class method takes NO arguments and returns nothing but prints each
    string of the "garbage" array before deleting it and freeing the memory.
*/
ReferenceManager::~ReferenceManager()
{
  /* reassinging every pointer in the "pointers" array to NULL using the calss
     method reassignPointer() */
  for (int i = 0; i < MAX_PTRS; i++)
  {
    reassignPointer(i, NULL);
  }
  /* calling the class method garbageCollect() in order to print the existing
     pointers in the "garbage" array and deleting them to free up memory */
  garbageCollect();
}

/*
    Description: This method goes through all the strings in the garbage array, 
                 prints each string and then frees the memory using the delete
                 operator.

    This class method takes NO arguments and returns nothing but prints each
    string of the "garbage" array before deleting it and freeing the memory.
*/
void ReferenceManager::garbageCollect()
{
  /* iterating through every pointer currently existing in the "garbage" array
     to print it out before deleting it in order to free up memory */
  for (int i = 0; i < numToDelete; i++)
  {
    cout << garbage[i] << endl;
    delete[] garbage[i];
  }
  /* reassigning the "numToDelete" (index iterating through the "garbage" array)
     to 0 after deletion of every pointer that was existing in it */
  numToDelete = 0;
}

/*
    Description: This method makes the pointer at "ptrIndex" in the "pointers"
                 array reference newAddr. It also supports reassignment to NULL in
                 the case when newAddr is NULL. In addition to doing this, the
                 reference counts are updated in the unordered map "refCount".
                 If this causes a string’s reference count to fall to 0 (i.e.,
                 no pointers in the pointers array reference it) then the string
                 is added to the "garbage" array, to be deleted the next time
                 garbage collection is requested.

    Arguments:
        ptrIndex (unsigned int): the pointer index in the "pointers" array at
                                 which the pointer needs to reassigned.

        newAddr (const char): the new address with which the pointer at index
                              ptrIndex needs to be reassigned with. 

    This class method returns nothing.
*/
void ReferenceManager::reassignPointer(unsigned int ptrIndex, const char *newAddr)
{
  /* checking if the pointer stored at the index "ptrIndex" in the "pointers"
     array is not NULL */
  if (getPtr(ptrIndex) != NULL)
  {
    /* decreasing the reference count (in the "refCount" unordered map) of the
       string previously stored at "ptrIndex" by one in order to store the new
       string if the previous string stored was NOT NULL */
    refCount[getPtr(ptrIndex)]--;
    /* adding the previously stored string to the "garbage" array if the reference
       count of that string falls to 0 in order to delete it when the next garbage
       collection is called */
    if (refCount[getPtr(ptrIndex)] == 0)
    {
      garbage[numToDelete] = getPtr(ptrIndex);
      numToDelete++;
    }
  }
  /* storing the new string "newAddr" at the index "ptrIndex" in the "pointers"
     array after the previous string has been dealt with */
  pointers[ptrIndex] = newAddr;
  /* increasing the reference count (in the "refCount" unordered map) of the
     newly assigned string "newAddr" by one if it is NOT NULL */
  if (newAddr != NULL)
  {
    refCount[newAddr]++;
  }
}

/*
    Description: This method allocates space for a string of size "length" using
                 "new" operator. Then it reads a string of size "length" from the
                 standard input and stores it in the allocated space. Finally it
                 uses the method reassignPointer() to have the pointer at index
                 "ptrIndex" reference the newly allocated string.

    Arguments:
        ptrIndex (unsigned int): the pointer index in the "pointers" array at
                                 which the pointer needs to reassigned.

        length (unsigned int): the size of the string that needs to be read in
                               through standard input.

    This class method returns nothing.
*/
void ReferenceManager::readString(unsigned int ptrIndex, unsigned int length)
{
  /* allocating space for a string ("str") of size "length". Here, the space
     exceeds the "length" by one in order to include space for the terminating
     null character */
  char *str = new char[length + 1];
  /* reading a string of size "length" from the standard input and storing it
     in the allocated space */
  cin >> str;
  /* assigning the last character (found at the index "length") of the string
     ("str") as the terminating null characater */
  str[length] = '\0';
  /* using the class method reassignPointer() to have the pointer at index
     "ptrIndex" reference the newly allocated string "str" */
  reassignPointer(ptrIndex, str);
}

const char *ReferenceManager::getPtr(unsigned int ptrIndex)
{
  /* checking if the index "ptrIndex" is less than "MAX_PTRS". If the condition
     is confirmed, the class method will return the pointer located at the index
     "ptrIndex" in the "pointers" array and if the condition evaluates to false,
     an assertion error is raised */
  assert(ptrIndex < MAX_PTRS);
  return pointers[ptrIndex];
}