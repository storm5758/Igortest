#include "stdafx.h"
#include <Windows.h>

typedef int 	(*fnUART_open	)(char *sn, int nBaud, int timeout);
typedef int 	(*fnUART_isOpen	)(int hdl);
typedef int 	(*fnUART_list		)(char *nPort, int var);
typedef int 	(*fnUART_close	)(int hdl);
typedef int 	(*fnUART_write	)(int hdl, char *b, int size);
typedef int 	(*fnUART_read		)(int hdl, char *b, int limit);
typedef int 	(*fnUART_Set		)(int hdl, char *c,int var);
typedef int 	(*fnUART_Get		)(int hdl, char *c,char *d);
typedef int 	(*fnUART_Req		)(int hdl, char *c,char *d);
typedef void 	(*fnUART_timeout)(int hdl, int time);
typedef int 	(*fnUART_Purge	)(int hdl, int flag);
    fnUART_open open;
    fnUART_isOpen isOpen;
    fnUART_list list;
    fnUART_close close;
    fnUART_write write;
    fnUART_read read;
    fnUART_Set Set;
    fnUART_Get Get;
    fnUART_Req Req;
    fnUART_timeout timeout;
    fnUART_Purge Purge;

int Init()
{
#ifdef WIN32
		HMODULE dll_handle=LoadLibrary(TEXT("uart_library_ftdi32.dll"));
#else
		HMODULE dll_handle=LoadLibrary(TEXT("uart_library_ftdi64.dll"));
#endif 
		if(!dll_handle)
			return -1;

        open=(fnUART_open)GetProcAddress(dll_handle,("fnUART_LIBRARY_open"));
        isOpen=(fnUART_isOpen)GetProcAddress(dll_handle, ("fnUART_LIBRARY_isOpen"));
        list=(fnUART_list)GetProcAddress(dll_handle, ("fnUART_LIBRARY_list"));
        close=(fnUART_close)GetProcAddress(dll_handle, ("fnUART_LIBRARY_close"));
        write=(fnUART_write)GetProcAddress(dll_handle, ("fnUART_LIBRARY_write"));
        read=(fnUART_read)GetProcAddress(dll_handle, ("fnUART_LIBRARY_read"));
        Set=(fnUART_Set)GetProcAddress(dll_handle, ("fnUART_LIBRARY_Set"));
        Get=(fnUART_Get)GetProcAddress(dll_handle, ("fnUART_LIBRARY_Get"));
        Req=(fnUART_Req)GetProcAddress(dll_handle, ("fnUART_LIBRARY_Req"));
        timeout=(fnUART_timeout)GetProcAddress(dll_handle, ("fnUART_LIBRARY_timeout"));
        Purge=(fnUART_Purge)GetProcAddress(dll_handle, ("fnUART_LIBRARY_Purge"));
		if(!open||!isOpen||!list||!close||!write||!read||!Set||!Get||!Req||!timeout||!Purge)
			return -2;
		return 0;
}

int fnKurios_List(char* c)
{
	int ret=0;
	ret=list(c,255);
	return ret;
}

int fnKurios_Open(char* sn)
{
	int ret=0;
    int	hdl=open(sn, 115200,3);
	return hdl;
}

int fnKurios_Close(int hdl)
{
	int ret=0;
	ret=	close(hdl);
	return ret;
}
int fnKurios_GetID(int hdl,char *c)
{
	int ret=0;
	char b[256]={0};
	sprintf_s(b,"*idn?\r");
	ret = Get(hdl,b,c);
	return ret;

}
int fnKurios_SetBandwidthMode(int hdl,int n)
{
	int ret=0;
	char b[256]={0};
	if(n>=1 && n<=4) {
		sprintf_s(b,"BW=%d\r",n);
		ret = Set(hdl,b,0);
	}
	else ret = 0xEA;
	return ret;
}

int fnKurios_SetOutputMode(int hdl,int n)
{
	int ret=0;
	char b[256]={0};
	if(n>=1 && n<=5) {
		sprintf_s(b,"OM=%d\r",n);
		ret = Set(hdl,b,0);
	}
	else ret = 0xEA;
	return ret;
}

int fnKurios_SetWavelength(int hdl,int n)
{
	int ret=0;
	char b[256]={0};
	sprintf_s(b,"WL=%d\r",n);
	ret = Set(hdl,b,0);
	return ret;
}

int fnKurios_GetWavelength(int hdl,char *c)
{
	int ret=0;
	char b[256]={0};
	sprintf_s(b,"WL?\r");
	ret = Get(hdl,b,c);
	return ret;
}

int fnKurios_GetOutputMode(int hdl,char *c)
{
	int ret=0;
	char b[256]={0};
	sprintf_s(b,"OM?\r");
	ret = Get(hdl,b,c);
	return ret;
}

int fnKurios_GetBandwidthMode(int hdl,char *c)
{
	int ret=0;
	char b[256]={0};
	sprintf_s(b,"BW?\r");
	ret = Get(hdl,b,c);
	return ret;
}

int fnKurios_SetSequence(int hdl,int n,int wl,int interval, int bandwidth)
{
	int ret=0;
	char b[256]={0};
	if(n>=0 && n<=1024) {
		sprintf_s(b,"SS=%d %d %d %d\r",n,wl,interval,bandwidth);
		ret = Set(hdl,b,0);

	}
	else ret = 0xEA;
	return ret;
}

int fnKurios_GetSequence(int hdl,int n,char *c)
{
	int ret=0;
	char b[256]={0};

	sprintf_s(b,"SS%d?\r",n);
	ret = Get(hdl,b,c);
	return ret;
}

int fnKurios_GetAllSequence(int hdl,char *c)
{
	int ret=0;
	char b[256]={0};

	sprintf_s(b,"SS?\r");
	ret = Get(hdl,b,c);
	return ret;
}

int fnKurios_InsertSequence(int hdl,int n,int wl,int interval, int bandwidth)
{
	int ret=0;
	char b[256]={0};
	if(n>=0 && n<=1024) {
		sprintf_s(b,"SS=%d %d %d %d\r",n,wl,interval,bandwidth);
		ret = Set(hdl,b,0);

	}
	else ret = 0xEA;
	return ret;
}

int fnKurios_DeleteSequence(int hdl,int n)
{
	int ret=0;
	char b[256]={0};

	sprintf_s(b,"DS=%d?\r",n);
	ret = Set(hdl,b,0);
	return ret;
}
