#if !defined (_CONECCION_)
#define _CONECCION_
#pragma once


#include <stdio.h>
#include <string>
#include <afxdb.h>
#include "MindrayPacket.h"
#include "MindrayAlarma.h"
#include "MindrayParametros.h"




class Conection
{
private:
	CDatabase *con;
	CString insert;
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
	/// Inserts the regis mp.
	/// </summary>
	/// <returns></returns>
	bool insertRegisMP(const  MindrayPacket &);
	
	/// <summary>
	/// Inserts the regis ma.
	/// </summary>
	/// <returns></returns>
	bool insertRegisMA(const MindrayAlarma &);

	
	/// <summary>
	/// Insers the regis MPP.
	/// </summary>
	/// <returns></returns>
	bool inserRegisMPP(const MindrayParametros &);

};

#endif