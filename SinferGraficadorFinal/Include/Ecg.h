#if !defined(_ECGBD_)
#define _ECGBD_
#pragma once
#include <vector>
#include <afxdb.h>
#include <string>
#include "StructDB.h"
#include "Monitor1.h"
#include "SubTramaECG.h"

class Ecg : public  CRecordset
{
private:
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

public:
	/// <summary>
	/// Initializes a new instance of the <see cref="ecg"/> class.
	///	overload
	/// </summary>
	/// <param name="bd">The bd.</param>
	Ecg(CDatabase *);

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
	void loadECG(Store s, Monitor1 *);


	/// <summary>
	/// Gets the default connect.
	/// </summary>
	/// <returns></returns>
	virtual CString GetDefaultSQL();

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
};

#endif