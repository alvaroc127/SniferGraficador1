#if !defined(_SUBTRAMSPO2_)
#define _SUBTRAMSPO2_
#pragma once
#include "SubTramaParam.h"
#include "SubTramaMetod.h"
/// <summary>
/// Class SubTramSpo2
/// </summary>
/// <seealso cref="SubTramaParam" />
/// <seealso cref="SubTramaMetod" />
class SubTramSpo2 : virtual	public SubTramaParam, SubTramaMetod
{
private:
	int dato1;
	int frecuencia;
	int val;

public:		
	
	/// <summary>
	/// Initializes a new instance of the <see cref="SubTramSpo2"/> class.
	/// </summary>
	/// <param name="sub">The sub.</param>
	SubTramSpo2( SubTramaParam * sub);


	/// <summary>
	/// Initializes a new instance of the <see cref="SubTramSpo2"/> class.
	/// </summary>
	/// <param name="sub">The sub.</param>
	SubTramSpo2(const SubTramaParam & sub);

	SubTramSpo2(uint8_t[],uint8_t[],uint8_t[]);
	/// <summary>
	/// Initializes a new instance of the <see cref="SubTramSpo2"/> class.
	/// </summary>
	SubTramSpo2();

	/// <summary>
	/// Finalizes an instance of the <see cref="SubTramSpo2"/> class.
	/// </summary>
	~SubTramSpo2();
	
	/// <summary>
	/// Clasficas the sub tra.
	/// </summary>
	void clasficaSubTra(const std::vector<uint8_t> &,int);
	
	/// <summary>
	/// Loads the dato1.
	/// </summary>
	/// <param name="datas">The datas.</param>
	/// <param name="">The .</param>
	/// <returns></returns>
	int loadDato1(const std::vector<uint8_t> &, int);

	
	/// <summary>
	/// Loads the frequency.
	/// </summary>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	/// <returns></returns>
	int loadFrequency(const std::vector<uint8_t> &, int);
	
	/// <summary>
	/// Runs the data.
	/// </summary>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	/// <returns></returns>
	int runData(const std::vector<uint8_t> &, int);

	SPO2  datTram(SPO2 &);
	
	/// <summary>
	/// Gets the dato1.
	/// </summary>
	/// <returns></returns>
	float getDato1();

	
	/// <summary>
	/// Gets the frecuencia.
	/// </summary>
	/// <returns></returns>
	float getFrecuencia();
	
};

#endif