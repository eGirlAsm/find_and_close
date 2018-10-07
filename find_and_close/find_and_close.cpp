// find_and_close.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>

 //const int WM_SYSCOMMAND = 0x0112;
 //const int SC_CLOSE = 0xF060;

//private void closeWindow()
//{
//	// retrieve the handler of the window  
//	int iHandle = FindWindow("Notepad", "Untitled - Notepad");
//	if (iHandle > 0)
//	{
//		// close the window using API        
//		SendMessage(iHandle, WM_SYSCOMMAND, SC_CLOSE, 0);
//	}  
//}	

void clickControl(HWND hWnd, int x, int y)
{
	POINT p;
	p.x = x; p.y = y;
	ClientToScreen(hWnd, &p);
	SetCursorPos(p.x, p.y);
	PostMessage(hWnd, WM_MOUSEMOVE, 0, MAKELPARAM(x, y));
	PostMessage(hWnd, WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(x, y));
	PostMessage(hWnd, WM_LBUTTONUP, MK_LBUTTON, MAKELPARAM(x, y));
}


BOOL CALLBACK EnumChildProc(HWND hWnd,LPARAM lParam) {     
	TCHAR temp1[256],temp2[256];    
	::GetWindowText(hWnd,temp1,255);    
	wsprintf(temp2,L"hwnd:%x text: %s",hWnd,temp1);   
	if(wcsstr(temp2,L"OK")){
		//MessageBox(NULL,L"i found you mother fucker",L"yes",MB_ICONINFORMATION);
		SendMessage(hWnd,BM_CLICK,0,0);
		return false;
	}
	//if(wcsstr(temp2,L"대화")){
	//	MessageBox(NULL,L" i show you mother fucker",L"yes",MB_ICONINFORMATION);
	//	ShowWindow(hWnd,SW_SHOW);
	//	return false;
	//}
	//MessageBox(NULL,temp2,L"ok",MB_OK);     
	return true;
}
int _tmain(int argc, _TCHAR* argv[])
{
	while (true)
	{
		HWND hWnd = FindWindow(NULL,L"후원 세션");
		SendMessage(hWnd,WM_SYSCOMMAND,SC_CLOSE,0);
		::EnumChildWindows(hWnd,EnumChildProc,0);
		//if(hWnd){
		//	HWND after =NULL;
		//	FindWindowEx(hWnd,after,NULL,L"OK");
		//	if(after){
		//		SendMessage(after,BM_CLICK,0,0);
		//	}
		//	
		//	//SendMessage(hWnd, WM_COMMAND, 1, NULL);
		//	//SendMessage(hWnd,WM_SYSCOMMAND,SC_CLOSE,0);
		//	//clickControl(hWnd,470,150);

		//}
		Sleep(1000);
	}

	return 0;
}

