/*File: unsorted.c
 *
 * Name: Khondakar Marzouq Mujtaba
 *
 * This program provides many ways to create, search, and manipulate a set datastructure */




#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
typedef struct set{
	char** data; //address of the array
	int length; //length of array
	int count;//number of elements
}SET;

static int search(SET *sp, char *tar){ //searching through sequential method, tar is the target for the search
	assert(sp!=NULL);
	int ser = sp->count;//finding the number of elements in the set
	int x; //throwaway for loop variable
	for (x=0;x<ser;x++){ //looping sequentially through set's data
		if (strcmp(sp->data[x],tar)==0){ //looking if the strings match
			return x; //returns index of matched string
		}
		}
	return (-1); // returns a variable outside what is possible for an index of an array.
}

SET *createSet(int maxElts){ //creates a set
	SET* sp;
	sp = malloc(sizeof(SET)); //allocating space for set
	assert(sp!=NULL); //asserting that the set is not empty
	sp->count =0; //setting count is set to zero
	sp->length = maxElts; //setting length of set to zero 
	sp->data= malloc(sizeof(char*)*sp->length); // allocation space for strings
	assert(sp->data!=NULL); //asserting that said space for the strings is not empty
	return (sp); //returning the data type
	
}

void destroySet(SET *sp){ // destroying and freeing up the memory of the set
	assert(sp!=NULL);//checking if pointer points to set <- ignore assert issue for now
	int i;//throwaway for loop variable
	for (i=0; i< sp->count; i++){ //for loop going through every element
		free(sp->data[i]); // dellocating the memory from the set element
	}
	free(sp->data); //freeing set and its variables
	free(sp);
	
}

int numElements(SET *sp){
	assert (sp!=NULL);
	return sp->count;
}
void addElement(SET *sp, char *elt){ //adding an element <-figure out how to add to latest null space
	if (sp->length==sp->count){ //checking if the array is full
		printf("array full");
		exit(1);
		}
	int sind = search(sp,elt); //index of element if element is aleady is set
	if (sind!=(-1)){ // chekcing if element is already in set
		return;
	}
	else{ //adding element
		sp->data[sp->count]=strdup(elt); // adding the element to the set <- fix adding
		assert(sp->data[sp->count]!=NULL);
		sp->count++; //increasing the number of elements in the set
	}
}

void removeElement(SET *sp, char *elt){ //removes an element from a set
	assert(sp!=NULL);
	int ind = search(sp, elt); // finds target index of the element
	if (ind != -1){
		free(sp->data[ind]);//removes element
		sp->count--;
		sp->data[ind]=sp->data[sp->count];
		}
}

char *findElement(SET *sp, char *elt){ //finds and returns element in set
	assert(sp!=NULL);
	int ind = search(sp, elt); //searches for index of element
	if (ind!=(-1)){ //if scenario when search function finds the index of the function
		return sp->data[ind];// returns element
	}
	else{ //for the scenario when the index is -1 so the target element is not found
		return NULL; // notifies client that the element cannot be found
	}
}
char **getElements(SET *sp){ // creates an array of all the elements in the data
	assert(sp!=NULL);
	char** arrstr; // defining a pointer for the string array
	int totnum = numElements(sp); // finding the number of elements in the array
	arrstr = malloc(sizeof(char*)*totnum); // allocating the memory for the array
	int i;// throwaway for loop variable
	memcpy(arrstr,sp->data, sizeof(char*)*sp->count);
	return arrstr; //returning array	
}
