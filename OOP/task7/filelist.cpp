/**
* @file		filelist.cpp
* @brief	All the following crap is a modified MSDN example
* @see		http://msdn.microsoft.com/en-us/library/windows/desktop/aa365200(v=vs.85).aspx
**/
#include <windows.h>
#include <tchar.h> 
#include <iostream>
#include <strsafe.h>
#pragma comment(lib, "User32.lib")

using namespace std;

void DisplayErrorBox(LPTSTR lpszFunction);

void PrintTxtFiles()
{
	WIN32_FIND_DATA ffd;
	//LARGE_INTEGER filesize;
	TCHAR szDir[MAX_PATH];
	size_t length_of_arg;
	HANDLE hFind = INVALID_HANDLE_VALUE;
	DWORD dwError = 0;

	// If the directory is not specified as a command-line argument,
	// print usage.


	// Check that the input path plus 3 is not longer than MAX_PATH.
	// Three characters are for the "\*" plus NULL appended below.

	StringCchLength(".//", MAX_PATH, &length_of_arg);


	// Prepare string for use with FindFile functions.  First, copy the
	// string to a buffer, then append '\*' to the directory name.

	StringCchCopy(szDir, MAX_PATH, ".//");
	StringCchCat(szDir, MAX_PATH, TEXT("\\*"));

	// Find the first file in the directory.

	hFind = FindFirstFile(szDir, &ffd);

	if (INVALID_HANDLE_VALUE == hFind)
	{
		cout << "ERROR!" << endl;
	}

	// List all the files in the directory with some info about them.
	cout << "\nText files in current directory:\n\n";
	do
	{
		if (!(ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
		{
			if (strstr(ffd.cFileName, ".txt") && (*(strstr(ffd.cFileName, ".txt") + 4) == '\0'))
				cout << "\t" << ffd.cFileName << endl;
		}
	} while (FindNextFile(hFind, &ffd) != 0);
	cout << endl;
	dwError = GetLastError();
	if (dwError != ERROR_NO_MORE_FILES)
	{
		cout << "ERROR!" << endl;
	}

	FindClose(hFind);
}

