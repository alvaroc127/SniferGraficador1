#if !defined (_CONECCION_)
#define _CONECCION_
#pragma once


#include <stdio.h>
#include <string>
#include <afxwin.h>


static const  std::string db = "FUCS";

class Conection
{
private:
	
	
public:	
	/// <summary>
	/// Initializes a new instance of the <see cref="Conection"/> class.
	/// </summary>
	Conection();	

	/// <summary>
	/// Finalizes an instance of the <see cref="Conection"/> class.
	/// </summary>
	~Conection();


};

#endif