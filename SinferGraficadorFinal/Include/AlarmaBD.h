#if !defined(_ALARMADB_)
#define _ALARMADB_
#pragma once
#include <vector>
#include "StructDB.h"
#include "Ecg.h"
#include "Monitor1.h"
class AlarmaBD
{

private:
	SQLHANDLE sqlenvirot;
	SQLHANDLE sqlCon;
	SQLHANDLE sqlstate;
	int num_cam;
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
	std::string  SQLUPdate = "UPDATE alarm SET alarmaSeverity  = ? , Description1 = ? , ECG1 = ?, ECG2 = ?, ECG3 = ?, aVR = ?, aVL = ?, Frec_Cardi = ?, I = ?, II = ? , III = ?, V = ?, aVF = ?, CVPs = ? WHERE ";

public:	
	
	/// <summary>
	/// Initializes a new instance of the <see cref="AlarmaBD"/> class.
	/// </summary>
	/// <param name="">The .</param>
	AlarmaBD(SQLHANDLE, SQLHANDLE, SQLHANDLE);

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
	/// <returns></returns>
	bool openTab();
	

	void loadAlarm(Store &, Monitor1 *, std::string, Ecg *ecg );

	/// <summary>
	/// Gets the default SQL.
	/// </summary>
	/// <returns></returns>
	
	
	/// <summary>
	/// Conts the character.
	/// </summary>
	/// <param name="">The .</param>
	/// <returns></returns>
	int contChar(std::string);

	
	/// <summary>
	/// Insertars the alarma.
	/// </summary>
	void insertarTbaAlarma();
	
	/// <summary>
	/// Sets the hande env.
	/// </summary>
	/// <param name="envir">The envir.</param>
	void setHandeEnv(SQLHANDLE envir);
	
	/// <summary>
	/// Sets the hande con.
	/// </summary>
	/// <param name="con">The con.</param>
	void setHandeCon(SQLHANDLE con);

	
	/// <summary>
	/// Sets the state of the hande.
	/// </summary>
	/// <param name="stat">The stat.</param>
	void setHandeState(SQLHANDLE stat);
	
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


	
};
#endif
