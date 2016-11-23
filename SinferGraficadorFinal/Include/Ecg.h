#if !defined(_ECGBD_)
#define _ECGBD_
#pragma once

#include <Windows.h>
#include <sqltypes.h>
#include <sql.h>
#include <sqlext.h>
#include <vector>
#include <string>
#include "StructDB.h"
#include "Monitor1.h"
#include "SubTramaECG.h"



class Ecg 
{
private:
	SQLHANDLE sqlenvirot;
	SQLHANDLE sqlCon;
	SQLHANDLE sqlstate;
	int id;
	std::string date_sig;
	float aVR;
	float aVL;
	float fre_Card;
	float I;
	float II;
	float III;
	float V;
	std::vector<uint8_t> ECG1;
	std::vector<uint8_t> ECG2;
	std::vector<uint8_t> ECG3;
	float aVF;
	float CVP;
	TIMESTAMP_STRUCT st;
	std::string SQLUPDATE = "update ECG SET ( aVR = ?, aVL = ?, Frec_Cardi = ?, I = ?, II = ?, III = ? , ECG1 = ?, ECG2  = ?, ECG3 = ?, aVF = ?, CVPs = ?) WHERE id = ? AND HoraSenal = ?";

public:
		
	/// <summary>
	/// Initializes a new instance of the <see cref="Ecg"/> class.
	/// </summary>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	Ecg(SQLHANDLE, SQLHANDLE, SQLHANDLE);
	

	/// <summary>
	/// Initializes a new instance of the <see cref="ecg"/> class.
	/// </summary>
	Ecg();

	/// <summary>
	/// Finalizes an instance of the <see cref="ecg"/> class.
	/// </summary>
	virtual ~Ecg();


	/// <summary>
	/// Loads the ecg.
	/// </summary>
	/// <param name="">The .</param>
	/// <returns></returns>
	void loadECG(Store &s, Monitor1 *);


	/// <summary>
	/// Gets the default connect.
	/// </summary>
	/// <returns></returns>
	

	/// <summary>
	/// Opens the tab.
	/// </summary>
	/// <returns></returns>
	bool openTab();


	/// <summary>
	/// Determines whether this instance is load.
	/// </summary>
	/// <returns>
	///   <c>true</c> if this instance is load; otherwise, <c>false</c>.
	/// </returns>
	bool  isLoad();


	/// <summary>
	/// Gets the ecg1.
	/// </summary>
	/// <returns></returns>
	std::vector<uint8_t> getEcg1();

	/// <summary>
	/// Gets the ecg2.
	/// </summary>
	/// <returns></returns>
	std::vector<uint8_t> getEcg2();

	/// <summary>
	/// Gets the ecg2.
	/// </summary>
	/// <returns></returns>
	std::vector<uint8_t> getEcg3();

	/// <summary>
	/// Gets the avr.
	/// </summary>
	/// <returns></returns>
	float getAvr();

	/// <summary>
	/// Gets the av l.
	/// </summary>
	/// <returns></returns>
	float getAvl();

	/// <summary>
	/// Gets the i.
	/// </summary>
	/// <returns></returns
	float getI();


	/// <summary>
	/// Gets the ii.
	/// </summary>
	/// <returns></returns>
	float getII();

	/// <summary>
	/// Gets the iii.
	/// </summary>
	/// <returns></returns>
	float getIII();

	/// <summary>
	/// Gets the v.
	/// </summary>
	/// <returns></returns>
	float getV();
	
	/// <summary>
	/// Getas the vf.
	/// </summary>
	/// <returns></returns>
	float getaVF();
	
	/// <summary>
	/// Gets the CVP.
	/// </summary>
	/// <returns></returns>
	float getCVP();
	
	/// <summary>
	/// Frecs the cardi.
	/// </summary>
	/// <returns></returns>
	float getFrec_Cardi();
	
	/// <summary>
	/// Gets the date time.
	/// </summary>
	/// <returns></returns>
	std::string getDateTime();
	
	/// <summary>
	/// Inserts the ecg.
	/// </summary>
	void insertECG();

	/// <summary>
	/// Sets the hande env.
	/// </summary>
	/// <param name="sql">The SQL.</param>
	void setHandeEnv(SQLHANDLE);

	/// <summary>
	/// Sets the hande con.
	/// </summary>
	/// <param name="">The .</param>
	void setHandeCon(SQLHANDLE);


	/// <summary>
	/// Sets the hande con.
	/// </summary>
	/// <param name="">The .</param>
	void setHandeState(SQLHANDLE);


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
	/// Sets the time struc.
	/// </summary>
	/// <param name="st">The st.</param>
	void setTimeStruc(const TIMESTAMP_STRUCT &st);

	


};

#endif