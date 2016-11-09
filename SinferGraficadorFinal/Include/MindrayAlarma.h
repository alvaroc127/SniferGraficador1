#if !defined(_MINDRAYALARMA_)
#define _MINDRAYALARMA_
#pragma once
#include "Trama.h"
#include "HeaderTram.h"
#include "SubTramaAlarma.h"

/// <summary>
/// Class Mindray Alarma
/// </summary>
/// <seealso cref="Trama" />
class MindrayAlarma : public Trama
{
private:
	std::vector<SubTramaAlarma *> subtra;
	HeaderTram head;
	int tam=0;
	int tip=0;
	std::string fuente;
	std::string date_time;
	

public:	

	MindrayAlarma(const MindrayAlarma &);

	/// <summary>
	/// Initializes a new instance of the <see cref="MindrayAlarma"/> class.
	/// </summary>
	MindrayAlarma();	


	/// <summary>
	/// Finalizes an instance of the <see cref="MindrayAlarma"/> class.
	/// </summary>
	virtual ~MindrayAlarma();	


	/// <summary>
	/// Clasifies the data.
	/// </summary>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	/// <returns></returns>
	int clasifyData(const std::vector<uint8_t> &, int);


	/// <summary>
	/// Carfars the sub tram.
	/// </summary>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	/// <returns></returns>
	int carfarSubTram(const std::vector<uint8_t> &, int);
	
	/// <summary>
	/// Gets the tipo.
	/// </summary>
	/// <param name="">The .</param>
	/// <returns></returns>
	int getTipo() const;
	
	/// <summary>
	/// Gets the fuente.
	/// </summary>
	/// <returns></returns>
	std::string getFuente();

	/// <summary>
	/// Sets the fuente.
	/// </summary>
	/// <param name="">The .</param>
	void setFuente(const std::string);

	
	/// <summary>
	/// Sets the dta time.
	/// </summary>
	/// <param name="">The .</param>
	void setDtaTime(const std::string);
	
	/// <summary>
	/// Gets the head.
	/// </summary>
	/// <returns></returns>
	HeaderTram getHead();
	
	/// <summary>
	/// Gets the data time.
	/// </summary>
	/// <returns></returns>
	std::string getDataTime();
	
	/// <summary>
	/// Sets the head.
	/// </summary>
	/// <param name="">The .</param>
	void setHead(const HeaderTram &);
	
	/// <summary>
	/// Sets the tipo.
	/// </summary>
	/// <param name="">The .</param>
	void setTipo(int);	

	/// <summary>
	/// Gets the sub tra.
	/// </summary>
	/// <returns></returns>
	std::vector<SubTramaAlarma *> getSubTra();
	
	
};
#endif