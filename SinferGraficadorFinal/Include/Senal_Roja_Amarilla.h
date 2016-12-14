#if !defined(_AMARILLAROJA_)
#define _AMARILLAROJA_
#pragma once
#include <vector>
#include <sstream>
#include <fstream>
#include "StructDB.h"
#include "SubTramaArt_AP.h"
#include "Monitor1.h"

class Senal_Roja_Amarilla
{
private:

	SQLHANDLE sqlenvirot;
	SQLHANDLE sqlCon;
	SQLHANDLE sqlstate;
	TIMESTAMP_STRUCT st;
	int senial;
	std::string dateTime;
	float max;
	float min;
	float parentesis;
	int id;
	std::vector<uint8_t> sig;
	std::string SQLUPDATE = "UPDATE Senal_Roja_Amarilla SET  Maximo = ?, Minimo = ?, Parentesis = ? , Senal = ? WHERE ";
	bool bandPara = false;
	bool bandSig = false;
	std::string direcc = "C:\\ArchivosSignal\\";
	std::fstream inFile;


public:

	/// <summary>
	/// Initializes a new instance of the <see cref="Senal_Roja_Amarilla"/> class.
	/// </summary>
	/// <param name="db">The database.</param>
	Senal_Roja_Amarilla(const SQLHANDLE &,const  SQLHANDLE &,const  SQLHANDLE &);

	/// <summary>
	/// Initializes a new instance of the <see cref="Senal_Roja_Amarilla"/> class.
	/// </summary>
	Senal_Roja_Amarilla();
		
	/// <summary>
	/// Loads the sr a.
	/// </summary>
	void loadSArt( Monitor1 *);
	
	/// <summary>
	/// Loads the sap.
	/// </summary>
	/// <param name="">The .</param>
	void loadSAP(Monitor1 *);

	/// <summary>
	/// Finalizes an instance of the <see cref="Senal_Roja_Amarilla"/> class.
	/// </summary>
	virtual ~Senal_Roja_Amarilla();
	
	/// <summary>
	/// Gets the default SQL.
	/// </summary>
	/// <returns></returns>
	
	/// <summary>
	/// Sets the hande env.
	/// </summary>
	/// <param name="envir">The envir.</param>
	void setHandeEnv(const SQLHANDLE &);

	/// <summary>
	/// Sets the hande con.
	/// </summary>
	/// <param name="con">The con.</param>
	void setHandeCon(const SQLHANDLE &);


	/// <summary>
	/// Sets the state of the hande.
	/// </summary>
	/// <param name="stat">The stat.</param>
	void setHandeState(const SQLHANDLE &);

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
	
	/// <summary>
	/// Inserts the tab signal red yell.
	/// </summary>
	void insertTabSignalRed_Yell();
	
	/// <summary>
	/// Loads the parameter.
	/// </summary>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	void loadParam(SubTramaArt_AP *, Monitor1 *);

	
	/// <summary>
	/// Loads the signal.
	/// </summary>
	/// <param name="si">The si.</param>
	/// <param name="">The .</param>
	void loadSignal(Signal &si, Monitor1 *);
	
	/// <summary>
	/// Determines whether this instance is load.
	/// </summary>
	/// <returns>
	///   <c>true</c> if this instance is load; otherwise, <c>false</c>.
	/// </returns>
	bool isLoad();
	
	/// <summary>
	/// Reads the file.
	/// </summary>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	/// <returns>vector</returns>
	std::vector<uint8_t> readFileSig(const std::string &);

	/// <summary>
	/// Reads the file parameter.
	/// </summary>
	/// <param name="">The IP.</param>
	void readFileParam(const std::string &);

	/// <summary>
	/// Backs the estad.
	/// </summary>
	void backEstad();

};

#endif