// Pruebas.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "misc/gammae_misc.h"

class MyClass
{
public:
	int a;
};

int main(int argc, char* argv[])
{
	MyClass C;
	CDynArray <MyClass> MiArray;	
	
	C.a = 1;	MiArray.iAdd(C);
	C.a = 2;	MiArray.iAdd(C);
	C.a = 3;	MiArray.iAdd(C);
	C.a = 4;	MiArray.iAdd(C);
	C.a = 5;	MiArray.iAdd(C);

	for (int i=0;i<MiArray.iNumElems();i++)
	{
		printf("%d\n",MiArray[i].a);
	}

	MiArray.Del(2);
	for (i=0;i<MiArray.iNumElems();i++)
	{
		printf("%d\n",MiArray[i].a);
	}

	MiArray.Del(2);
	for (i=0;i<MiArray.iNumElems();i++)
	{
		printf("%d\n",MiArray[i].a);
	}

	return 0; 
}

