// Win32Project9.cpp: определяет точку входа для приложения.
//

#include "stdafx.h"
#include "Win32Project9.h"
#include "stdio.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

												// Отправить объявления функций, включенных в этот модуль кода:
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

	// TODO: разместите код здесь.

	// Инициализация глобальных строк
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_WIN32PROJECT9, szWindowClass, MAX_LOADSTRING);

	// Выполнить инициализацию приложения:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32PROJECT9));

	MSG msg;

	// Цикл основного сообщения:
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
//  ФУНКЦИЯ: MyRegisterClass()
//
//  НАЗНАЧЕНИЕ: регистрирует класс окна.
//


//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   НАЗНАЧЕНИЕ: сохраняет обработку экземпляра и создает главное окно.
//
//   КОММЕНТАРИИ:
//
//        В данной функции дескриптор экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится на экран главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // Сохранить дескриптор экземпляра в глобальной переменной

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
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  НАЗНАЧЕНИЕ:  обрабатывает сообщения в главном окне.
//
//  WM_COMMAND — обработать меню приложения
//  WM_PAINT — отрисовать главное окно
//  WM_DESTROY — отправить сообщение о выходе и вернуться
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
				

				MessageBox(hDlg, "1 значение введено неверно",
					"Error", MB_OK | MB_ICONHAND);
				return TRUE;
			}
			if (sscanf_s(yy, "%lf", &y)<1)
			{

				MessageBox(hDlg, "2 значение введено неверно",
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

				MessageBox(hDlg, "1 значение введено неверно",
					"Error", MB_OK | MB_ICONHAND);
				return TRUE;
			}
			if (sscanf_s(yy, "%lf", &y)<1)
			{

				MessageBox(hDlg, "2 значение введено неверно",
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
		case IDC_BUTTON3: // Обработка сообщения от кнопки "Очистить список"
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

				MessageBox(hDlg, "1 значение введено неверно",
					"Error", MB_OK | MB_ICONHAND);
				return TRUE;
			}
			if (sscanf_s(yy, "%lf", &y)<1)
			{

				MessageBox(hDlg, "2 значение введено неверно",
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

				MessageBox(hDlg, "1 значение введено неверно",
					"Error", MB_OK | MB_ICONHAND);
				return TRUE;
			}
			if (sscanf_s(yy, "%lf", &y)<1)
			{

				MessageBox(hDlg, "2 значение введено неверно",
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


