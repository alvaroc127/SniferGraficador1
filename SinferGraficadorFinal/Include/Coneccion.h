#if !defined (_CONECCION_)
#define _CONECCION_
#pragma once


#include <odbc++\drivermanager.h>
#include <odbc++\connection.h>
#include <odbc++\resultsetmetadata.h>
#include <odbc++\callablestatement.h>
#include <odbc++\databasemetadata.h>
#include <stdio.h>
#include <string>
#include "Ecg.h"
#include "AlarmaBD.h"
#include "frec_respiratoriDB.h"
#include "HabitacionDB.h"
#include "TemperaturaDB.h"
#include "Senal_Roja_Amarilla.h"
#include "Monitor1.h"
#include "StructDB.h"
#include "SubtRamTemp.h"


class Conection
{

private:
	/*
	Ecg *ecg;
	Monitor1 *mon;
	AlarmaBD *alar;
	frec_respiratoriDB *frec;
	TemperaturaDB *tem;
	Senal_Roja_Amarilla *sRa;
	HabitacionDB *hB;
	*/
	Monitor1 *mon;
	odbc::Connection *co;
	Store al;
	std::string date;
	std::string Ip;
public:	
	


	/// <summary>
	/// Initializes a new instance of the <see cref="Conection"/> class.
	/// </summary>
	Conection();	

	/// <summary>
	/// Finalizes an instance of the <see cref="Conection"/> class.
	/// </summary>
	~Conection();
		
	/// <summary>
	/// Checks the monitor.
	/// </summary>
	void OpenCo();

	/// <summary>
	/// Gets the conection.
	/// </summary>
	/// <returns></returns>
	void insertaDatTab();

	
	/// <summary>
	/// Sets the ip.
	/// </summary>
	/// <param name="">The .</param>
	void setIp(const std::string &);

	
	/// <summary>
	/// Sets the date.
	/// </summary>
	/// <param name="">The .</param>
	void setDate(const std::string &);
	
	/// <summary>
	/// Loads the dat table mon.
	/// </summary>
	void loadDatTableMon();
	
	/// <summary>
	/// Inserts the regis mp.
	/// </summary>
	/// <param name="">The .</param>
	void insertRegisMP(MindrayPacket);
	
	/// <summary>
	/// Inserts the regis ma.
	/// </summary>
	/// <param name="">The .</param>
	void insertRegisMA(MindrayAlarma);
	
	/// <summary>
	/// Insers the regis MPP.
	/// </summary>
	/// <param name="">The .</param>
	void inserRegisMPP(MindrayParametros);
	
	/// <summary>
	/// Checks the store.
	/// </summary>
	/// <returns></returns>
	bool checkStore();

	
	/// <summary>
	/// Queries the mon.
	/// </summary>
	void QueryMon();

	
	/// <summary>
	/// Loads the date ip.
	/// </summary>
	void loadDate_Ip();
	};

#endif