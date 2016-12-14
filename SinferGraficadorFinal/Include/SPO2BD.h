#if !defined(_SPO2BD_)
#define _SPOD2BD_
#pragma once
#include <vector>
#include <sstream>
#include <fstream>
#include "StructDB.h"
#include "SubTramSpo2.h"
#include "Monitor1.h"


class SPO2BD
{
private:
	SQLHANDLE sqlenvirot;
	SQLHANDLE sqlCon;
	SQLHANDLE sqlstate;
	TIMESTAMP_STRUCT st;
	std::string SQLUPDATE = "UPDATE SPO2 SET  SenalSPO2 = ? , Desconocido = ?, frecuencia = ? WHERE ";
	int id;
	std::vector<uint8_t> signa;
	float frec_encia = 0;
	float desconocido = 0;
	bool bandPara = false;
	bool bandSig = false;
	std::string direcc = "C:\\ArchivosSignal\\";
	std::fstream inFile;

public:	
	
	/// <summary>
	/// Initializes a new instance of the <see cref="SPO2BD"/> class.
	/// </summary>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	SPO2BD(const SQLHANDLE &,const  SQLHANDLE &,const  SQLHANDLE &);

	/// <summary>
	/// Initializes a new instance of the <see cref="SPO2BD"/> class.
	/// </summary>
	SPO2BD();
	
	/// <summary>
	/// Finalizes an instance of the <see cref="SPO2BD"/> class.
	/// </summary>
	virtual ~SPO2BD();


	/// <summary>
	/// Sets the hande env.
	/// </summary>
	/// <param name="envir">The envir.</param>
	void setHandeEnv(const SQLHANDLE  & envir);

	/// <summary>
	/// Sets the hande con.
	/// </summary>
	/// <param name="con">The con.</param>
	void setHandeCon(const SQLHANDLE & con);


	/// <summary>
	/// Sets the state of the hande.
	/// </summary>
	/// <param name="stat">The stat.</param>
	void setHandeState(const SQLHANDLE  &stat);

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
	/// Loads the sp o2.
	/// </summary>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	void loadSPO2(Monitor1 *);
	
	/// <summary>
	/// Insertars the sp o2.
	/// </summary>
	void insertarTablSPO2();
	
	/// <summary>
	/// Loads the signal.
	/// </summary>
	/// <param name="sig">The sig.</param>
	void loadSignal(Signal &sig, Monitor1 *);
	
	/// <summary>
	/// Loads the parametros.
	/// </summary>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	void loadParametros(SubTramSpo2 *, Monitor1 *);
	
	/// <summary>
	/// Determines whether this instance is load.
	/// </summary>
	/// <returns>
	///   <c>true</c> if this instance is load; otherwise, <c>false</c>.
	/// </returns>
	bool isLoad();
	
	/// <summary>
	/// Backs the estad.
	/// </summary>
	void backEstad();

	/// <summary>
	/// Reads the file.
	/// </summary>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	/// <returns>vector</returns>
	std::vector<uint8_t> readFileSig(const std::string &);

	/// <summary>
	/// Reads the file parameter.
	/// </summary>
	/// <param name="">The IP.</param>
	void readFileParam(const std::string &);



};

#endif