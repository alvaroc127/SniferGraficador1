#if !defined(_GESTARCH_)
#define _GESTARCH_
#pragma once
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <direct.h>
#include "Struct.h"
#include "MindrayPacket.h"
#include "MindrayAlarma.h"
#include "MindrayParametros.h"


static const std::string direcc = "C:\\ArchivosSignal\\";
static const std::string direcc1 = "C:\\ArchivosSignal\\IP.txt";

class GestorArchivo
{
private :
	/*
	Impedancia  imp;
	ECG ecg;
	Art art;
	SPO2 spo2;
	Ap ap;
	Temp tem;
	Signal sig;
	std::vector<std::string>mensajes;
	*/
	std::ofstream outSA;
	std::ifstream inEN;

public:	
	//
	/// <summary>
	/// Initializes a new instance of the <see cref="GestorArchivo"/> class.
	/// </summary>
	GestorArchivo();
	
	/// <summary>
	/// Finalizes an instance of the <see cref="GestorArchivo"/> class.
	/// </summary>
	virtual ~GestorArchivo();

	/// <summary>
	/// Searches the ip.
	/// </summary>
	/// <param name="">The .</param>
	/// <returns></returns>
	bool searchIp(const std::string &);

	/// <summary>
	/// Crears the archivo.
	/// </summary>
	/// <param name="">The .</param>
	bool crearArchivo(const std::string &);


	/// <summary>
	/// Escribirs the dat.
	/// </summary>
	void EscribirDatSig(const Signal &, MindrayPacket &);
	
	/// <summary>
	/// Escribirs the dat impedancia.
	/// </summary>
	/// <param name="">The .</param>
	void EscribirDatImpedancia(const Impedancia &, MindrayParametros &);
	
	/// <summary>
	/// Escribirs the dat ecg.
	/// </summary>
	/// <param name="">The .</param>
	void EscribirDatECG(const ECG & , MindrayParametros &);
	
	/// <summary>
	/// Escribirs the dat art.
	/// </summary>
	/// <param name="">The .</param>
	void EscribirDatArt(const Art &, MindrayParametros &);

	
	/// <summary>
	/// Escribirs the dat sig.
	/// </summary>
	/// <param name="">The .</param>
	void EscribirDatSpo2(const SPO2 &, MindrayParametros &);	

	/// <summary>
	/// Escribirs the dat sig.
	/// </summary>
	/// <param name="">The .</param>
	void EscribirDatAp(const Ap &, MindrayParametros &);
	
	/// <summary>
	/// Escribirs the dat sig.
	/// </summary>
	/// <param name="">The .</param>
	void EscribirDatTemp(const Temp &, MindrayParametros &);
	
	
	/// <summary>
	/// Escribirs the dat a larma.
	/// </summary>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	void EscribirDatALarma(std::vector<std::string>, MindrayAlarma &);
	



	/// <summary>
	/// Sets the ecg.
	/// </summary>
	/// <param name="">The .</param>
	void setEcg(const ECG &);

	/// <summary>
	/// Sets the art.
	/// </summary>
	/// <param name="">The .</param>
	void setArt(const Art &);

	/// <summary>
	/// Sets the spo2.
	/// </summary>
	/// <param name="">The .</param>
	void setSpo2(const SPO2 &);

	/// <summary>
	/// Sets the ap.
	/// </summary>
	/// <param name="">The .</param>
	void setAp(const Ap &);

	/// <summary>
	/// Sets the tem.
	/// </summary>
	/// <param name="">The .</param>
	void setTem(const Temp &);
	
	/// <summary>
	/// Gets the ecg.
	/// </summary>
	/// <returns></returns>
	ECG getECG();
	
	/// <summary>
	/// Sets the signal.
	/// </summary>
	void setSignal(const Signal &);
	
	/// <summary>
	/// Gets the signal.
	/// </summary>
	/// <returns></returns>
	Signal getSignal();


	int sizeFile();

	void Delete();

};


#endif