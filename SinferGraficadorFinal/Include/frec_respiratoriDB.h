# if !defined (_FRECRESP_)
#define _FRECRESP_
#pragma once

#include <vector>
#include "SubTramaImpedancia.h"
#include "Monitor1.h"
#include "StructDB.h"


class frec_respiratoriDB
{
private:

	SQLHANDLE sqlenvirot;
	SQLHANDLE sqlCon;
	SQLHANDLE sqlstate;
	TIMESTAMP_STRUCT st;
	std::string dat_Sig;
	float impedancia=0;
	int id;
	std::vector<uint8_t> sig;
	std::string SQLUpda = "UPDATE Frec_Respiratoria SET Impedancia = ? , Senal = ? WHERE ";
	bool bandPara = false;
	bool bandSig = false;

public:	
	
	/// <summary>
	/// Initializes a new instance of the <see cref="Ecg"/> class.
	/// </summary>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	frec_respiratoriDB(SQLHANDLE, SQLHANDLE, SQLHANDLE);
	

	/// <summary>
	/// Initializes a new instance of the <see cref="frec_respiratoriDB"/> class.
	/// </summary>
	frec_respiratoriDB();	

	/// <summary>
	/// Finalizes an instance of the <see cref="frec_respiratoriDB"/> class.
	/// </summary>
	virtual ~frec_respiratoriDB();
	
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
	/// Loads the frec resource.
	/// </summary>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	void loadFrecRes(Store &, SubTramaImpedancia *, Monitor1 *);

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

	
	/// <summary>
	/// Inserts the table alarma.
	/// </summary>
	void insertTableFrec_Resp();

	
	/// <summary>
	/// Loads the signal.
	/// </summary>
	/// <param name="">The .</param>
	/// <param name="mon">The mon.</param>
	void loadSignal(Signal &, Monitor1 *mon);

	
	/// <summary>
	/// Loads the parameter.
	/// </summary>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	void LoadParam(SubTramaImpedancia *, Monitor1 *);
	
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

};

#endif

