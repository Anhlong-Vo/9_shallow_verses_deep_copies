//============================================================================
// Name        : 9_shallow_verses_deep_copies.cpp
// Author      : 
// Version     :
// Copyright   : Steal this code!
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#include <iostream>

using namespace std;


void do_shallow_copy_VERY_BAD_DONT_DO_THIS(char *pData, char *&pSC){
	//shallow copy, p1 and p2 both point to same memory
	pSC=pData;	
}

void do_deep_copy_GOOD(char *pData, char *&pDC){
	int iLen = strlen(pData);
	
	//pointer with enough memory 
	//to hold a COPY of pData (+ null)
	pDC = new char[iLen +1];	
	
	//make the deep copy
	strncpy(pDC, pData, iLen);	
}

int main() {
	//step thru this program in debug, look at Variables window
	std::cout<<"step thru this program in debug, look at Variables window"<<std::endl;

	//allocate a string of chars	
	char *p2 = new char [5];
	strncpy(p2,"abcde",5);
	
	//these will hold shallow and deep copies
	char *pSC = 0;
	char *pDC = 0;

	do_shallow_copy_VERY_BAD_DONT_DO_THIS(p2, pSC);
	do_deep_copy_GOOD(p2, pDC);
	
	//now look at address of pSC, p2, they point to the same memory
	//while pDC points to different memory
	
	//now change the original string
	*(p2+0)	='1';
	*(p2+1)	='2';
	
	//and note that pSC changes as well! 
	//while pDC stays the same, in other
	//words pDC is independent
		
	//tidy the pointers
	if(p2)
		delete [] p2;
	
	if(pDC)
		delete [] pDC;
}
