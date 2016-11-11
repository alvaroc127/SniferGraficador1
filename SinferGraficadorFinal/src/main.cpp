#define TINS_STATIC
#define _AFXDLL
#include <iostream>
#include <vector>
#include <tins\tins.h>
#include <sql.h>
#include <sqlext.h>
#include "..\Include\CapturaDeRed.h"
using std::cin;
using std::cout;
using std::endl;






//========================================================================
int main( ){
	RETCODE rc;        // ODBC return code
	HENV henv;         // Environment
	HDBC hdbc;         // Connection handle
	HSTMT hstmt;       // Statement handle
	SDWORD cbData;     // Output length of data

					   // attempt to connect to the ODBC database
	char db[] = "FUCS"; // ODBC database name
	cout << "Attempting to open database " << db << "..." << endl;
	SQLAllocEnv(&henv);
	SQLAllocConnect(henv, &hdbc);
	rc = SQLConnect(hdbc, (SQLCHAR*) "FUCS", SQL_NTS, (SQLCHAR*)NULL, 0, NULL, 0);
	//rc = SQLConnect(hdbc, (SQLCHAR *)"JAVIERCASASUC",SQL_NTS, (SQLCHAR *)"pasante1", 8, (SQLCHAR *)"sebastian1", 11);
	// if not successful, quit
	if ((rc != SQL_SUCCESS) && (rc != SQL_SUCCESS_WITH_INFO))
	{
		cout << "Cannot open database -- make sure ODBC is configured properly." << endl;
		SQLFreeConnect(hdbc);
		SQLFreeEnv(henv);
		
		cout << "Press ENTER to continue." << endl;
		cin.get();
		return 1;
	}
	else {
		cout << "ABIO" << endl;
	}


	CapturaDeRed ca;
	ca.startCapture();
}
