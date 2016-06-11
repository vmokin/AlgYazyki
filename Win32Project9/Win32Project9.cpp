// Win32Project9.cpp: ���������� ����� ����� ��� ����������.
//

#include "stdafx.h"
#include "Win32Project9.h"
#include "stdio.h"

#define MAX_LOADSTRING 100

// ���������� ����������:
HINSTANCE hInst;                                // ������� ���������
WCHAR szTitle[MAX_LOADSTRING];                  // ����� ������ ���������
WCHAR szWindowClass[MAX_LOADSTRING];            // ��� ������ �������� ����

												// ��������� ���������� �������, ���������� � ���� ������ ����:
BOOL                InitInstance(HINSTANCE, int);
INT_PTR CALLBACK	dialog(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	DialogFun2(HWND, UINT, WPARAM, LPARAM);

//FILE *pF;
//fopen_s(&pF, "My kalkulator.txt", "w");

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: ���������� ��� �����.

	// ������������� ���������� �����
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_WIN32PROJECT9, szWindowClass, MAX_LOADSTRING);

	// ��������� ������������� ����������:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32PROJECT9));

	MSG msg;

	// ���� ��������� ���������:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}



//
//  �������: MyRegisterClass()
//
//  ����������: ������������ ����� ����.
//


//
//   �������: InitInstance(HINSTANCE, int)
//
//   ����������: ��������� ��������� ���������� � ������� ������� ����.
//
//   �����������:
//
//        � ������ ������� ���������� ���������� ����������� � ���������� ����������, � �����
//        ��������� � ��������� �� ����� ������� ���� ���������.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // ��������� ���������� ���������� � ���������� ����������

					   //HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
					   //CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);
	DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), 0, dialog);
	/*if (!hWnd)
	{
	return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	*/

	return 0;
}

char zz[64];

BOOL CALLBACK DialogFun2(HWND hwnd, UINT message,
	WPARAM wParam, LPARAM lParam)
{
	

	switch (message)
	{

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDOK:
		case IDCANCEL:
			EndDialog(hwnd, IDOK);
			return TRUE;
		}

	}
	return FALSE;
}

BOOL CALLBACK DialogFun3(HWND hwnd, UINT message,
	WPARAM wParam, LPARAM lParam)
{
	SendDlgItemMessage(hwnd, IDC_LIST2, LB_RESETCONTENT, 0, 0);
	return TRUE;
}

BOOL CALLBACK DialogFun4(HWND hwnd, UINT message,
	WPARAM wParam, LPARAM lParam)
{
	SendDlgItemMessage(hwnd, IDC_LIST2, LB_ADDSTRING, 0, (LPARAM)zz);
	return TRUE;
}


//return TRUE;
//
//  �������: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ����������:  ������������ ��������� � ������� ����.
//
//  WM_COMMAND � ���������� ���� ����������
//  WM_PAINT � ���������� ������� ����
//  WM_DESTROY � ��������� ��������� � ������ � ���������
//
//
HWND hwnd = CreateDialog(hInst, MAKEINTRESOURCE(IDD_DIALOG2), 0, DialogFun2);

INT_PTR CALLBACK dialog(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	double x = 0;
	double y = 0;
	double z = 0;
	char xx[64];
	char yy[64];
	
	//char text[25];
	switch (message)
	{
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_BUTTON1:
			x = 0;
			y = 0;
			z = 0;
			SendDlgItemMessage(hDlg, IDC_EDIT1, WM_GETTEXT, 63, (LPARAM)xx);
			SendDlgItemMessage(hDlg, IDC_EDIT2, WM_GETTEXT, 63, (LPARAM)yy);
			if (sscanf_s(xx, "%lf", &x)<1)
			{
				

				MessageBox(hDlg, "1 �������� ������� �������",
					"Error", MB_OK | MB_ICONHAND);
				return TRUE;
			}
			if (sscanf_s(yy, "%lf", &y)<1)
			{

				MessageBox(hDlg, "2 �������� ������� �������",
					"Error", MB_OK | MB_ICONHAND);
				return TRUE;
			}
			z = x + y;
			sprintf_s(zz, "%lf", z);
			SendDlgItemMessage(hDlg, IDC_EDIT3, WM_SETTEXT, 63, (LPARAM)zz);
			if (IsDlgButtonChecked(hDlg, IDC_RADIO3))
			{
					sprintf_s(zz, "%f + %f = %f", x, y, z);
				SendDlgItemMessage(hDlg, IDC_LIST1, LB_ADDSTRING, 63, (LPARAM)zz);
				DialogFun4(hwnd, message, wParam, lParam);
			};
			
			break;
		case IDC_BUTTON2:
			x = 0;
			y = 0;
			z = 0;
			SendDlgItemMessage(hDlg, IDC_EDIT1, WM_GETTEXT, 63, (LPARAM)xx);
			SendDlgItemMessage(hDlg, IDC_EDIT2, WM_GETTEXT, 63, (LPARAM)yy);
			if (sscanf_s(xx, "%lf", &x)<1)
			{

				MessageBox(hDlg, "1 �������� ������� �������",
					"Error", MB_OK | MB_ICONHAND);
				return TRUE;
			}
			if (sscanf_s(yy, "%lf", &y)<1)
			{

				MessageBox(hDlg, "2 �������� ������� �������",
					"Error", MB_OK | MB_ICONHAND);
				return TRUE;
			}
			z = x - y;
			sprintf_s(zz, "%lf", z);
			SendDlgItemMessage(hDlg, IDC_EDIT3, WM_SETTEXT, 63, (LPARAM)zz);
			if (IsDlgButtonChecked(hDlg, IDC_RADIO3))
			{
				sprintf_s(zz, "%f - %f = %f", x, y, z);
				SendDlgItemMessage(hDlg, IDC_LIST1, LB_ADDSTRING, 63, (LPARAM)zz);
			
				DialogFun4(hwnd, message, wParam, lParam);
			};
			
			break;
		case IDC_BUTTON3: // ��������� ��������� �� ������ "�������� ������"
			DialogFun3(hwnd, message, wParam, lParam);
			return TRUE;

		case IDC_BUTTON4:
			x = 0;
			y = 0;
			z = 0;
			SendDlgItemMessage(hDlg, IDC_EDIT1, WM_GETTEXT, 63, (LPARAM)xx);
			SendDlgItemMessage(hDlg, IDC_EDIT2, WM_GETTEXT, 63, (LPARAM)yy);
			if (sscanf_s(xx, "%lf", &x)<1)
			{

				MessageBox(hDlg, "1 �������� ������� �������",
					"Error", MB_OK | MB_ICONHAND);
				return TRUE;
			}
			if (sscanf_s(yy, "%lf", &y)<1)
			{

				MessageBox(hDlg, "2 �������� ������� �������",
					"Error", MB_OK | MB_ICONHAND);
				return TRUE;
			}
			z = x * y;
			sprintf_s(zz, "%lf", z);
			SendDlgItemMessage(hDlg, IDC_EDIT3, WM_SETTEXT, 63, (LPARAM)zz);
			if (IsDlgButtonChecked(hDlg, IDC_RADIO3))
			{
				sprintf_s(zz, "%f * %f = %f", x, y, z);
				SendDlgItemMessage(hDlg, IDC_LIST1, LB_ADDSTRING, 63, (LPARAM)zz);
				DialogFun4(hwnd, message, wParam, lParam);
			};
			
			break;

		case IDC_BUTTON5:
			x = 0;
			y = 0;
			z = 0;
			SendDlgItemMessage(hDlg, IDC_EDIT1, WM_GETTEXT, 63, (LPARAM)xx);
			SendDlgItemMessage(hDlg, IDC_EDIT2, WM_GETTEXT, 63, (LPARAM)yy);
			if (sscanf_s(xx, "%lf", &x)<1)
			{

				MessageBox(hDlg, "1 �������� ������� �������",
					"Error", MB_OK | MB_ICONHAND);
				return TRUE;
			}
			if (sscanf_s(yy, "%lf", &y)<1)
			{

				MessageBox(hDlg, "2 �������� ������� �������",
					"Error", MB_OK | MB_ICONHAND);
				return TRUE;
			}
			z = x / y;
			sprintf_s(zz, "%lf", z);
			SendDlgItemMessage(hDlg, IDC_EDIT3, WM_SETTEXT, 63, (LPARAM)zz);
			if (IsDlgButtonChecked(hDlg, IDC_RADIO3))
			{
				sprintf_s(zz, "%f / %f = %f", x, y, z);
				SendDlgItemMessage(hDlg, IDC_LIST1, LB_ADDSTRING, 63, (LPARAM)zz);
				DialogFun4(hwnd, message, wParam, lParam);
			};
			//DialogFun4(hwnd, message, wParam, lParam);
			break;

		case IDC_BUTTON6:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG3), hDlg, DialogFun2);
			return TRUE;
			break;
			
		case IDC_BUTTON7:
			ShowWindow(hwnd, 1);
			//DialogFun4(hwnd, message, wParam, lParam);
			return TRUE;
			break;
		}

		if (LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	default:
		break;

	}
	return (INT_PTR)FALSE;
}


