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
	int num_cam;
	std::string dateTime;
	int alarmSeverity;
	std::string description;
	std::vector<uint8_t> ECG1;
	std::vector<uint8_t> ECG2;
	std::vector<uint8_t> ECG3;
	float aVR;
	float aVl;
	float frec_Card;
	float I;
	float II;
	float III;
	float V;
	float aVF;
	float CVP;


public:	
	
	/// <summary>
	/// Initializes a new instance of the <see cref="AlarmaBD"/> class.
	/// </summary>
	/// <param name="">The .</param>
	

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
	

	void loadAlarm(Store , Monitor1 *, std::string, Ecg *ecg );

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

};
#endif
