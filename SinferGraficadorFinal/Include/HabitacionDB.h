#if !defined(_HABITACIONBD_)
#define _HABITACIONBD_
#pragma once
#include <afxdb.h>
#include "StructDB.h"
class HabitacionDB: public CRecordset
{
private:

	int id;
	int cedPaciente;
	
public:	
	
	/// <summary>
	/// Initializes a new instance of the <see cref="HabitacionDB"/> class.
	/// </summary>
	/// <param name="db">The database.</param>
	HabitacionDB(CDatabase *db);

	/// <summary>
	/// Initializes a new instance of the <see cref="HabitacionDB"/> class.
	/// </summary>
	HabitacionDB();	

	/// <summary>
	/// Finalizes an instance of the <see cref="HabitacionDB"/> class.
	/// </summary>
	virtual ~HabitacionDB();
};

#endif
