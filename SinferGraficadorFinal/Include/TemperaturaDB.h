#if !defined(_TEMPERATURABD_)
#define _TEMPERATURABD_
#pragma once

#include <sstream>
#include <fstream>
#include <vector>
#include "StructDB.h"
#include "SubtRamTemp.h"
#include "Monitor1.h"


class TemperaturaDB
{
private:
	SQLHANDLE sqlenvirot;
	SQLHANDLE sqlCon;
	SQLHANDLE sqlstate;
	TIMESTAMP_STRUCT st;
	std::string dat_Sig;
	float T1;
	float T2;
	float T3;
	int id;
	std::string SQLUPDATE = "UPDATE Temperatura SET T1 = ? , T2  = ?, TD = ? WHERE ";
	std::string direcc = "C:\\ArchivosSignal\\";
	std::fstream inFile;
public:	
	
	/// <summary>
	/// Initializes a new instance of the <see cref="TemperaturaDB"/> class.
	/// </summary>
	/// <param name="cb">The cb.</param>
	TemperaturaDB(const SQLHANDLE &,const  SQLHANDLE &,const  SQLHANDLE &);

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
	void loadTemp( Monitor1 *);


	/// <summary>
	/// Sets the hande env.
	/// </summary>
	/// <param name="envir">The envir.</param>
	void setHandeEnv(const SQLHANDLE &);

	/// <summary>
	/// Sets the hande con.
	/// </summary>
	/// <param name="con">The con.</param>
	void setHandeCon(const SQLHANDLE &);


	/// <summary>
	/// Sets the state of the hande.
	/// </summary>
	/// <param name="stat">The stat.</param>
	void setHandeState(const SQLHANDLE &);

	/// <summary>
	/// Sets the time struc.
	/// </summary>
	/// <param name="">The .</param>
	void setTimeStruc(const TIMESTAMP_STRUCT &);


	/// <summary>
	/// Shows the error.
	/// </summary>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	void show_Error(unsigned int, const SQLHANDLE &);


	/// <summary>
	/// Closes this instance.
	/// </summary>
	void Close();
	
	
	/// <summary>
	/// Insets the table tempe.
	/// </summary>
	void insetTableTempe();

	/// <summary>
	/// The load parameter
	/// </summary>
	void loadParam(SubtRamTemp *, Monitor1 *);

	///<sumary>
	///The load signal
	///</sumary>
	void loadSignal(Signal &, Monitor1 *);

	

	/// <summary>
	/// Reads the file parameter.
	/// </summary>
	/// <param name="">The IP.</param>
	void readFileParam(const std::string &);

	/// <summary>
	/// Backs the estad.
	/// </summary>
	void backEstad();
	

};

#endif