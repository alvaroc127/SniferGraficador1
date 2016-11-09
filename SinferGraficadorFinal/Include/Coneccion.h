#if !defined (_CONECCION_)
#define _CONECCION_
#pragma once


#include <stdio.h>
#include <string>
#include <afxdb.h>
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
	CDatabase *con;
	Ecg *ecg;
	Monitor1 *mon;
	AlarmaBD *alar;
	frec_respiratoriDB *frec;
	TemperaturaDB *tem;
	Senal_Roja_Amarilla *sRa;
	HabitacionDB *hB;
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
	/// Conectars this instance.
	/// </summary>
	void conectar();
	
	/// <summary>
	/// Gets the conection.
	/// </summary>
	/// <returns></returns>
	CDatabase * getConection();
	
	/// <summary>
	/// Gets the insert.
	/// </summary>
	/// <returns></returns>
	CString getInsert();
		
	/// <summary>
	/// Opens the ecg.
	/// </summary>
	/// <returns></returns>
	bool openECG();
	
	/// <summary>
	/// Opens the monitor.
	/// </summary>
	/// <returns></returns>
	bool openMonitor();

	/// <summary>
	/// Inserts the regis mp.
	/// </summary>
	/// <returns></returns>
	void insertRegisMP(MindrayPacket );
	
	/// <summary>
	/// Inserts the regis ma.
	/// </summary>
	/// <returns></returns>
	void insertRegisMA( MindrayAlarma );

	
	/// <summary>
	/// Insers the regis MPP.
	/// </summary>
	/// <returns></returns>
	void inserRegisMPP(MindrayParametros );
	
	/// <summary>
	/// Checks the store.
	/// </summary>
	/// <returns></returns>
	bool checkStore();
	
	/// <summary>
	/// Sets the date.
	/// </summary>
	/// <param name="">The .</param>
	void setDate(const std::string &);
		
	/// <summary>
	/// Sets the ip.
	/// </summary>
	/// <param name="">The .</param>
	void setIp(const std::string &);

	/// <summary>
	/// Insers the t dat bas.
	/// </summary>
	void inserTDatBas();
	
	
	/// <summary>
	/// Loads the dat table.
	/// </summary>
	void loadDatTableMon();
	
	/// <summary>
	/// Loads the dat talbe ecg.
	/// </summary>
	void loadDatTalbeECG();

};

#endif