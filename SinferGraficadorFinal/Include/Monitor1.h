#if !defined(_MONITOR1_)
#define _MONITOR1_
#define _AFXDLL
#pragma once

#include <iostream>
#include <string>
#include <Windows.h>
#include <sqltypes.h>
#include <sql.h>
#include <sqlext.h>


class Monitor1 
{
private:
	SQLHANDLE sqlenvirot;
	SQLHANDLE sqlCon;
	SQLHANDLE sqlstate;
	int id;
	std::string IP;
	int numCam;
	std::string date_reg;
	std::string  SQLOpen = "SELECT * FROM Monitor WHERE  ip = '";
	


public:	

	Monitor1(const SQLHANDLE &,const SQLHANDLE &, const SQLHANDLE &);
	/// <summary>
	/// Monitors the specified .
	/// </summary>
	/// <param name="">The .</param>
	/// <returns></returns>
	

	/// <summary>
	/// Initializes a new instance of the <see cref="Monitor1"/> class.
	/// </summary>
	Monitor1();	
	
	/// <summary>
	/// Opens the tab mo.
	/// </summary>
	/// <returns></returns>
	bool openTabMo();
	
	/// <summary>
	/// Sets the ip.
	/// </summary>
	/// <param name="">The .</param>
	


	/// <summary>
	/// Finalizes an instance of the <see cref="Monitor1"/> class.
	/// </summary>
	virtual ~Monitor1();
	

	/// <summary>
	/// Gets the default SQL.
	/// </summary>
	/// <returns></returns>
	
	
	/// <summary>
	/// Does the field exchange.
	/// </summary>
	
	
	/// <summary>
	/// Gets the identifier.
	/// </summary>
	/// <returns></returns>
	int getId();
	
	/// <summary>
	/// Numbers the cam.
	/// </summary>
	/// <returns></returns>
	int getNumCam();
	
	
	
	/// <summary>
	/// Loads the mon.
	/// </summary>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	///void loadMon(CString, CString, int);
	
	/// <summary>
	/// Queries the monitor.
	/// </summary>
	void queryMonitor();
	
	/// <summary>
	/// Sets the ip.
	/// </summary>
	/// <param name="ip">The ip.</param>
	void setIp(const std::string  & ip);
	
	/// <summary>
	/// Shows the error.
	/// </summary>
	/// <param name="handle">The handle.</param>
	/// <param name="han">The han.</param>
	void show_Error(unsigned int handle, const SQLHANDLE &han);

	
	/// <summary>
	/// Closes this instance.
	/// </summary>
	void Close();
	
	/// <summary>
	/// Gets the ip.
	/// </summary>
	/// <returns></returns>
	std::string getIp();
	

	
	/// <summary>
	/// Gets the SQL seten.
	/// </summary>
	/// <returns></returns>
	std::string getSQLSeten();

	
	/// <summary>
	/// Gets the date.
	/// </summary>
	/// <returns></returns>
	std::string getDate();
	
	/// <summary>
	/// Sets the hande env.
	/// </summary>
	/// <param name="sql">The SQL.</param>
	void setHandeEnv(const SQLHANDLE  &);
	
	/// <summary>
	/// Sets the hande con.
	/// </summary>
	/// <param name="">The .</param>
	void setHandeCon(const SQLHANDLE &);

	
	/// <summary>
	/// Sets the hande con.
	/// </summary>
	/// <param name="">The .</param>
	void setHandeState(const SQLHANDLE &);
};

#endif
