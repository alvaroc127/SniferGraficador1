#if !defined(_MINDRAYPARAMETROS_)
#define _MINDRAYPARAMETROS_
#pragma once
#include "Trama.h"
#include "HeaderTram.h"
#include "SubTramaParam.h"

class MindrayParametros: public Trama
{
private:
	std::string fuente;
	HeaderTram head;
	int tam =0;
	std::vector<SubTramaParam *>subtrmas;
	std::string data_time;
	

public:	
	/// <summary>
	/// Initializes a new instance of the <see cref="MindrayParametros"/> class.
	/// </summary>
	MindrayParametros();	

	/// <summary>
	/// Initializes a new instance of the <see cref="MindrayParametros"/> class.
	/// </summary>
	MindrayParametros(const MindrayParametros &);

	/// <summary>
	/// Finalizes an instance of the <see cref="MindrayParametros"/> class.
	/// </summary>
	~MindrayParametros();		


	/// <summary>
	/// Cargars the sub tram.
	/// </summary>
	/// <returns></returns>
	int carfarSubTram(const std::vector<uint8_t> &, int);

	/// <summary>
	/// Clasifies the data.
	/// </summary>
	/// <returns></returns>
	int clasifyData(const std::vector<uint8_t> &, int);	



	 
	 /// <summary>
	 /// Gets the fuente.
	 /// </summary>
	 /// <returns></returns>
	 std::string getFuente();

	 
	 /// <summary>
	 /// Sets the fuente.
	 /// </summary>
	 /// <param name="">The .</param>
	 void setFuente(const std::string &);

	 
	 /// <summary>
	 /// Sets the dta time.
	 /// </summary>
	 /// <param name="">The .</param>
	 void setDtaTime(const std::string &);

	 
	 /// <summary>
	 /// Gets the data time.
	 /// </summary>
	 /// <returns></returns>
	std::string  getDataTime();
	 
	 /// <summary>
	 /// Gets the head.
	 /// </summary>
	 /// <returns></returns>
	  HeaderTram  getHead();
	 
	 /// <summary>
	 /// Sets the head.
	 /// </summary>
	 /// <param name="">The .</param>
	 void setHead(const HeaderTram &);
	 
	 /// <summary>
	 /// Codes the type.
	 /// </summary>
	 /// <param name="">The .</param>
	 /// <returns></returns>
	 int codeType(const std::vector<uint8_t> &,int);
	 
	 /// <summary>
	 /// Gets the sub tra.
	 /// </summary>
	 /// <returns></returns>
	 std::vector<SubTramaParam *> getSubTra();
	 
	 /// <summary>
	 /// Clones this instance.
	 /// </summary>
	 /// <returns></returns>
	 MindrayParametros * clone();
	 
	
};

#endif