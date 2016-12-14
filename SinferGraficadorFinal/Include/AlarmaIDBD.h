#if !defined(_ALARMAIDDB_)
#define _ALARMAIDDB_
#pragma once
#include <vector>
#include "StructDB.h"
#include "Ecg.h"
#include "Monitor1.h"

/// <summary>
/// Classs ALARMAIDBD
/// </summary>

class AlarmaIDBD
{
private:

	SQLHANDLE sqlenvirot;
	SQLHANDLE sqlCon;
	SQLHANDLE sqlstate;
	int id;
	std::string descrip;
	int serveri;
	std::string Ip;
	std::string  SQLQuery = "SELECT * FROM ALARMABDID WHERE Descripcion = ? AND Severidad = ?;";
	std::string SQLinsert = "INSERT INTO ALRAMABDID ( Descripcion, Severidad )?,?;";

public:	

	/// <summary>
	/// Initializes a new instance of the <see cref="AlarmaBD"/> class.
	/// </summary>
	/// <param name= "sqlCon">The  sqlCon the representatio conection whith BD .</param>
	/// <param name= "sqlState">The  sqlState the representation state whith state .</param>
	/// <param name= "sqlEnvirot">The Envirot the envirot conection whitch BD.</param>
	AlarmaIDBD(const SQLHANDLE &, const  SQLHANDLE &, const  SQLHANDLE &);

	/// <summary>
	/// Initializes a new instance of the <see cref="AlarmaIDBD"/> class.
	/// </summary>
	AlarmaIDBD();
	
	/// <summary>
	/// Finalizes an instance of the <see cref="AlarmaIDBD"/> class.
	/// </summary>
	virtual ~AlarmaIDBD();
	
	/// <summary>
	/// Loads the alarma idbd.
	/// </summary>
	bool queryAlarmaIDBD();
	
	/// <summary>
	/// Gets the identifier.
	/// </summary>
	/// <returns></returns>
	int getId();
	
	/// <summary>
	/// Gets the description.
	/// </summary>
	/// <returns></returns>
	std::string getDescription();

	
	/// <summary>
	/// Gets the sever.
	/// </summary>
	/// <returns></returns>
	int getSeverity();	

	/// <summary>
	/// Sets the ip.
	/// </summary>
	/// <param name="ip">The ip.</param>
	/// <returns></returns>
	void setIp(const std::string & );


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
	
	/// <summary>
	/// Loads the alarm.
	/// </summary>
	/// <param name="">The .</param>
	/// <param name="ecg">The ecg.</param>
	void loadAlarm(std::string , int severi);

	
	/// <summary>
	/// Inserts the alarma identifier.
	/// </summary>
	void insertAlarmaID();
		
	/// <summary>
	/// Prepares the query.
	/// </summary>
	void PrepareQuery();
	
	/// <summary>
	/// Loads the other dat.
	/// </summary>
	void loadOtherDat();
	
	/// <summary>
	/// Sets the descrip.
	/// </summary>
	/// <param name="">The .</param>
	void setDescrip(const std::string &);
	
	/// <summary>
	/// Sets the severi.
	/// </summary>
	/// <param name="sev">The sev.</param>
	void setSeveri(int sev);


};



#endif