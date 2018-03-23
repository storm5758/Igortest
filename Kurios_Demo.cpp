// Kurios_Demo.cpp
//

//#include "stdafx.h"
#include "Kurios_Api.h"
//#include "stdafx.h"
#include <string.h>
#include <assert.h>

/// <summary>
/// <p>Returns a new string in which all occurrences of a specified Unicode character.</p>
/// </summary>
/// <param name="src">The original string. </param>
/// <param name="oldChar">The Unicode character to be replaced.</param>
/// <param name="newChar">The Unicode character to replace all occurrences of oldChar.</param>
/// <returns> A string that is equivalent to this instance except that all instances of oldChar are replaced with newChar.</returns>
char * ReplaceChar(char * src,char oldChar,char newChar)
{
	char * head=src;
	while(*src!='\0')
	{
		if(*src==oldChar) *src=newChar;
		src++;
	}
	return head;
}

/// <summary>
/// <p>Returns a value indicating whether the string occurs within this string.</p>
/// </summary>
/// <param name="src">The string. </param>
/// <param name="value">The string to seek.</param>
/// <returns> true if the value parameter occurs within this string; otherwise, false.</returns>
bool ContainsChar(char * src,char * value)
{
	size_t length=strlen(value);
	while(*src!='\0')
	{
		if(strncmp(src,value,length)==0) return true;
		src++;
	}
	return false;
}

/// <summary>
/// <p>Set wavelength.</p>
/// </summary>
void Test_SetWavelength()
{
	int ret,hdl;
	char sn[256];
	char a='e';
	char c[256];
	memset(c,0,sizeof(c));
	fnKurios_List(c);
	printf("%s.\n",c);
	printf("Please input com port number.\n");	
	scanf_s("%s",sn,256);
	hdl=fnKurios_Open(sn);
	if(hdl < 0 ) { 
		printf("com port fails, plese check the driver installed correctly.\n");
	}
	else {
		memset(c,0,sizeof(c));
		fnKurios_GetID(hdl,c);	
		ReplaceChar(c,'>','\n');
		printf("%s",c);
		if(ContainsChar(c,"WB1")) 
		{
			ret = fnKurios_SetWavelength(hdl,530);
			assert(ret==0);

			memset(c,0,sizeof(c));
			fnKurios_GetWavelength(hdl,c);	
			ReplaceChar(c,'>','\n');
			printf("%s",c);
		}
		else if(ContainsChar(c,"VB1"))
		{
			ret = fnKurios_SetWavelength(hdl,530);
			assert(ret==0);
			ret = fnKurios_SetBandwidthMode(hdl,2);
			assert(ret==0);		

			memset(c,0,sizeof(c));
			fnKurios_GetWavelength(hdl,c);	
			ReplaceChar(c,'>','\n');
			printf("%s",c);
			memset(c,0,sizeof(c));
			fnKurios_GetBandwidthMode(hdl,c);	
			ReplaceChar(c,'>','\n');
			printf("%s",c);
	}
		fnKurios_Close(hdl);
	}
	printf("press 'x' to quit.\n");
	while(a != 'x') {
		a = getchar();
	}
}

/// <summary>
/// <p>Set sequence mode.</p>
/// </summary>
void Test_SetSequenceMode()
{
	int ret,hdl;
	char sn[256];
	char a='e';
	char c[256];
	memset(c,0,sizeof(c));
	fnKurios_List(c);
	printf("%s.\n",c);
	printf("Please input com port number.\n");	
	scanf_s("%s",sn,256);
	hdl=fnKurios_Open(sn);
	if(hdl < 0 ) { 
		printf("com port fails, plese check the driver installed correctly.\n");
	}
	else {
		memset(c,0,sizeof(c));
		fnKurios_GetID(hdl,c);	
		ReplaceChar(c,'>','\n');
		printf("%s",c);
		if(ContainsChar(c,"WB1")) 
		{
			ret = fnKurios_DeleteSequence(hdl,0);
			assert(ret==0);
			ret = fnKurios_InsertSequence(hdl,1,450,1000,2);
			assert(ret==0);
			ret = fnKurios_InsertSequence(hdl,2,550,1000,2);
			assert(ret==0);
			ret = fnKurios_InsertSequence(hdl,3,650,1000,2);
			assert(ret==0);
			ret = fnKurios_SetOutputMode(hdl,2);
			assert(ret==0);
			memset(c,0,sizeof(c));
			fnKurios_GetAllSequence(hdl,c);
			ReplaceChar(c,'\r','\n');
			ReplaceChar(c,'>','\n');
			printf("%s",c);
		}
		else if(ContainsChar(c,"VB1"))
		{
			ret = fnKurios_DeleteSequence(hdl,0);
			assert(ret==0);
			ret = fnKurios_InsertSequence(hdl,1,450,1000,2);
			assert(ret==0);
			ret = fnKurios_InsertSequence(hdl,2,550,1000,4);
			assert(ret==0);
			ret = fnKurios_InsertSequence(hdl,3,650,1000,8);
			assert(ret==0);
			ret = fnKurios_SetOutputMode(hdl,2);
			assert(ret==0);
			memset(c,0,sizeof(c));
			fnKurios_GetAllSequence(hdl,c);
			ReplaceChar(c,'\r','\n');
			ReplaceChar(c,'>','\n');
			printf("%s",c);
		}
		fnKurios_Close(hdl);
	}
	printf("press 'x' to quit.\n");
	while(a != 'x') {
		a = getchar();
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int ret=Init();
	if(ret!=0)
	{
		printf("Load uart library fail,please check.\n");	
		printf("press 'x' to quit.\n");
		char a='e';
		while(a != 'x') 
			a = getchar();
		return 0;
	}
	printf("0: Set Wavelength.\n");	
	printf("1: Set Sequence Mode.\n");	
	printf("Please select to continue.\n");	
	char a = getchar();
	switch (a)
	{
		case '0':Test_SetWavelength();
			break;
		case '1':Test_SetSequenceMode();
			break;
		default:
			break;
	}
	return 0;
}

