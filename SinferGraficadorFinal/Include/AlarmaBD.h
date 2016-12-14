#if !defined(_ALARMADB_)
#define _ALARMADB_
#pragma once
#include <vector>
#include "StructDB.h"
#include "Ecg.h"
#include "AlarmaIDBD.h"
#include "Monitor1.h"


/// <summary>
/// Class of represent AlarmaBD
/// </summary>
class AlarmaBD
{

private:
	SQLHANDLE sqlenvirot;
	SQLHANDLE sqlCon;
	SQLHANDLE sqlstate;
	int idMon;
	std::string dateTime;
	int alarmSeverity=0;
	std::string description;
	std::vector<uint8_t> ECG1;
	std::vector<uint8_t> ECG2;
	std::vector<uint8_t> ECG3;
	TIMESTAMP_STRUCT st;
	float aVR=0;
	float aVl=0;
	float frec_Card=0;
	float I=0;
	float II=0;
	float III=0;
	float V=0;
	float aVF=0;
	float CVP=0;
	std::string  SQLUPdate = "UPDATE alarm SET   ECG1 = ?, ECG2 = ?, ECG3 = ?, aVR = ?, aVL = ?, Frec_Cardi = ?, I = ?, II = ? , III = ?, V = ?, aVF = ?, CVPs = ? WHERE ";
	std::string direcc = "C:\\ArchivosSignal\\";
	std::fstream inFile;
	std::vector<std::string> mensajes;
	
public:	


	/// <summary>
	/// Initializes a new instance of the <see cref="AlarmaBD"/> class.
	/// </summary>
	/// <param name= "sqlCon">The  sqlCon the representatio conection whith BD .</param>
	/// <param name= "sqlState">The  sqlState the representation state whith state .</param>
	/// <param name= "sqlEnvirot">The Envirot the envirot conection whitch BD.</param>
	AlarmaBD(const SQLHANDLE &,const  SQLHANDLE &,const  SQLHANDLE &);

	
	/// <summary>
	/// Initializes a new instance of the <see cref="AlarmaBD"/> class.
	/// </summary>
	AlarmaBD();


	/// <summary>
	/// Finalizes an instance of the <see cref="AlarmaBD"/> class.
	/// </summary>
	virtual ~AlarmaBD();
	
	
	/// <summary>
	/// Opens the tab.
	/// </summary>
	/// <returns> bool of represent efect openTab</returns>
	bool openTab();
	
	
	/// <summary>
	/// Loads the alarm.
	/// </summary>
	/// <param name="">The .</param>
	/// <param name="ecg">The ecg.</param>
	void loadAlarm(Monitor1 *, Ecg *ecg, AlarmaIDBD *);

	
	
	

	/// <summary>
	/// Conts the character.
	/// </summary>
	/// <param name="ms">The string of alarm .</param>
	/// <returns> number of parameter</returns>
	int contChar(std::string);

	
	
	/// <summary>
	/// Insertars the alarma.
	/// </summary>
	void insertarTbaAlarma();
	


	/// <summary>
	/// Sets the hande env.
	/// </summary>
	/// <param name="envir">The envir.</param>
	void setHandeEnv(const SQLHANDLE  &envir);
	


	/// <summary>
	/// Sets the hande con.
	/// </summary>
	/// <param name="con">The connection of BD.</param>
	void setHandeCon(const SQLHANDLE & con);


	/// <summary>
	/// Sets the state of the hande.
	/// </summary>
	/// <param name="stat">The handle stat.</param>
	void setHandeState(const SQLHANDLE &stat);
	
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
	/// Reads the file mens.
	/// </summary>
	/// <param name="">The .</param>
	/// <returns></returns>
	std::string readFileMens(const std::string &);

	
	/// <summary>
	/// Loads the mens.
	/// </summary>
	/// <param name="">The .</param>
	void loadMens(const std::string &);

	
	/// <summary>
	/// Gets the mensaje.
	/// </summary>
	/// <returns></returns>
	std::vector<std::string> getMensajes();
	
	/// <summary>
	/// Clears the mensajes.
	/// </summary>
	void clearMensajes();

	
};
#endif
