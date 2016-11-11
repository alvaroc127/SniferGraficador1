#if !defined(_HABITACIONBD_)
#define _HABITACIONBD_
#pragma once

#include "StructDB.h"
class HabitacionDB
{
private:

	int id;
	int cedPaciente;
	
public:	
	
	/// <summary>
	/// Initializes a new instance of the <see cref="HabitacionDB"/> class.
	/// </summary>
	/// <param name="db">The database.</param>
	

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
