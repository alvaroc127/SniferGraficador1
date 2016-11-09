# if !defined (_FRECRESP_)
#define _FRECRESP_
#pragma once
#include <afxdb.h>
#include <vector>
#include "SubTramaImpedancia.h"
#include "Monitor1.h"
#include "StructDB.h"


class frec_respiratoriDB :public CRecordset
{
private:
	CString dat_Sig;
	float impedancia;
	int id;
	std::vector<uint8_t> sig;


public:	
		
	/// <summary>
	/// Initializes a new instance of the <see cref="frec_respiratoriDB"/> class.
	/// </summary>
	/// <param name="">The .</param>
	frec_respiratoriDB(CDatabase *);

	/// <summary>
	/// Initializes a new instance of the <see cref="frec_respiratoriDB"/> class.
	/// </summary>
	frec_respiratoriDB();	

	/// <summary>
	/// Finalizes an instance of the <see cref="frec_respiratoriDB"/> class.
	/// </summary>
	virtual ~frec_respiratoriDB();
	
	/// <summary>
	/// Gets the default sq.
	/// </summary>
	/// <returns></returns>
	virtual CString GetDefaultSQL();
	
	/// <summary>
	/// Loads the frec resource.
	/// </summary>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	void loadFrecRes(Store, SubTramaImpedancia *, Monitor1 *);
};

#endif

