#if !defined(_ECG_)
#define _ECG_
#pragma once
#include <vector>
#include <afxdb.h>
#include <string>
#include "MindrayPacket.h"

class Ecg : CRecordset
{
private:
	int id;
	std::string date_sig;
	double aVR;
	double aVL;
	double fre_Card;
	double I;
	double II;
	double III;
	double V;
	std::vector<uint8_t> ECG1;
	std::vector<uint8_t> ECG2;
	std::vector<uint8_t> ECG3;
	double aVF;
	double CVP;

public:		
	/// <summary>
	/// Initializes a new instance of the <see cref="ecg"/> class.
	///	overload
	/// </summary>
	/// <param name="bd">The bd.</param>
	Ecg(CDatabase * bd);

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
	void loadECG( MindrayPacket &);

};

#endif