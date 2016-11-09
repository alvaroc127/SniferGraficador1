#if !defined(_TEMPERATURABD_)
#define _TEMPERATURABD_
#pragma once

#include<afxdb.h>
#include <vector>
#include "StructDB.h"
#include "SubtRamTemp.h"
#include "Monitor1.h"


class TemperaturaDB: public CRecordset
{
private:
	CString dat_Sig;
	float T1;
	float T2;
	float T3;
	int id;

public:	
	
	/// <summary>
	/// Initializes a new instance of the <see cref="TemperaturaDB"/> class.
	/// </summary>
	/// <param name="cb">The cb.</param>
	TemperaturaDB(CDatabase *cb);

	/// <summary>
	/// Initializes a new instance of the <see cref="TemperaturaDB"/> class.
	/// </summary>
	TemperaturaDB();
	
	/// <summary>
	/// Finalizes an instance of the <see cref="TemperaturaDB"/> class.
	/// </summary>
	virtual ~TemperaturaDB();

	
	/// <summary>
	/// Gets the default SQL.
	/// </summary>
	/// <returns></returns>
	virtual  CString GetDefaultSQL();
	
	/// <summary>
	/// Loads the temporary.
	/// </summary>
	void loadTemp(Store s, SubtRamTemp *imp, Monitor1 *mon);

};

#endif