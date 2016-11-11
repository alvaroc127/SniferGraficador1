#if !defined(_MONITOR1_)
#define _MONITOR1_
#pragma once

#include <odbc++\drivermanager.h>
#include <odbc++\connection.h>
#include <odbc++\preparedstatement.h>
#include <odbc++\resultset.h>
#include <string>

class Monitor1 
{
private:
	int id;
	std::string IP;
	int numCam;
	std::string date_reg;
	std::string  SQLOpen = "SELECT * FROM Monitor WHERE  ip = "+IP;
	odbc::Connection *co;


public:	

	Monitor1(odbc::Connection *mo);
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

};

#endif
