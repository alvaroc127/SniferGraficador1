#if !defined(_MONITOR1_)
#define _MONITOR1_
#pragma once
#include <string>
#include <afxdb.h>
class Monitor1 : public   CRecordset
{
private:
	int id;
	CString IP;
	int numCam;
	CString date_reg;
	std::string  SQLOpen = "SELECT * FROM Monitor WHERE  ip = "+IP;


public:		
	/// <summary>
	/// Monitors the specified .
	/// </summary>
	/// <param name="">The .</param>
	/// <returns></returns>
	Monitor1(CDatabase *);

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
	void setIp(const CString &);


	/// <summary>
	/// Finalizes an instance of the <see cref="Monitor1"/> class.
	/// </summary>
	virtual ~Monitor1();
	

	/// <summary>
	/// Gets the default SQL.
	/// </summary>
	/// <returns></returns>
	virtual CString GetDefaultSQL();
	
	/// <summary>
	/// Does the field exchange.
	/// </summary>
	virtual void DoFieldExchange(CFieldExchange *);
	
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
	/// Gets the ip.
	/// </summary>
	/// <returns></returns>
	CString getIp();

	
	/// <summary>
	/// Gets the date range.
	/// </summary>
	/// <returns></returns>
	CString getDateRag();
	
	
	/// <summary>
	/// Loads the mon.
	/// </summary>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	void loadMon(CString, CString, int);

};

#endif
