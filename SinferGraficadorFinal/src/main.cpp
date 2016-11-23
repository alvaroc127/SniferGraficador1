#define TINS_STATIC
#include <iostream>
#include <vector>
#include <tins\tins.h>
#include "..\Include\CapturaDeRed.h"




/*
void show_error(unsigned int handletype, const SQLHANDLE& handle) {
SQLCHAR sqlstate[1024];
SQLCHAR message[1024];
if (SQL_SUCCESS == SQLGetDiagRec(handletype, handle, 1, sqlstate, NULL, message, 1024, NULL))
cout << "Message Error: " << message << "\nSQLSTATE: " << sqlstate << endl;
}

SQLHANDLE sqlenvhandle;
SQLHANDLE sqlconnectionhandle;
SQLHANDLE sqlstatementhandle;
SQLRETURN retcode;

if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &sqlenvhandle))
goto FINISHED;

if (SQL_SUCCESS != SQLSetEnvAttr(sqlenvhandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0))
goto FINISHED;

if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, sqlenvhandle, &sqlconnectionhandle))
goto FINISHED;

SQLCHAR retconstring[1024];
SQLSMALLINT outconstring;

switch (SQLDriverConnect(sqlconnectionhandle,
NULL,
(SQLCHAR*)TEXT("DSN=FUCS;UID=pasante1;PWD=sebastian1;"),
SQL_NTS,
retconstring,
1024,
&outconstring,
SQL_DRIVER_NOPROMPT)) {
case SQL_SUCCESS_WITH_INFO:
show_error(SQL_HANDLE_DBC, sqlconnectionhandle);
break;
case SQL_INVALID_HANDLE:
case SQL_ERROR:
show_error(SQL_HANDLE_DBC, sqlconnectionhandle);
goto FINISHED;
default:
break;
}

if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, sqlconnectionhandle, &sqlstatementhandle))
goto FINISHED;

if (SQL_SUCCESS != SQLExecDirect(sqlstatementhandle, (SQLCHAR*)"select * from Alarm", SQL_NTS)) {
show_error(SQL_HANDLE_STMT, sqlstatementhandle);
goto FINISHED;
}
else {
char name[64];
char address[64];
int id;
while (SQLFetch(sqlstatementhandle) == SQL_SUCCESS) {
SQLGetData(sqlstatementhandle, 1, SQL_C_ULONG, &id, 0, NULL);
SQLGetData(sqlstatementhandle, 2, SQL_C_CHAR, name, 64, NULL);
SQLGetData(sqlstatementhandle, 3, SQL_C_CHAR, address, 64, NULL);
cout << id << " " << name << " " << address << endl;
}
}

FINISHED:
//SQLFreeHandle(SQL_HANDLE_STMT, sqlstatementhandle);
//SQLDisconnect(sqlconnectionhandle);
//SQLFreeHandle(SQL_HANDLE_DBC, sqlconnectionhandle);
SQLFreeHandle(SQL_HANDLE_ENV, sqlenvhandle);
cout << "Press ENTER to continue." << endl;
cin.get();

*/


//========================================================================
int main( ){
	

	CapturaDeRed ca;
	ca.startCapture();
};