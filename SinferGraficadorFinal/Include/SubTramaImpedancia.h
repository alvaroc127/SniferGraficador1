#if !defined(_SUBTRAMAIMPEDANCIA_)
#define _SUBTRAMAIMPEDANCIA_
#pragma once
#include "SubTramaParam.h"
#include "SubTramaMetod.h"
/// <summary>
/// Class SubtramaImpedancia
/// </summary>
/// <seealso cref="SubTramaParam" />
class SubTramaImpedancia : virtual  public SubTramaParam , SubTramaMetod
{
private:
	int impedanciaX2;
	int val;

public:	
	
	/// <summary>
	/// Initializes a new instance of the <see cref="SubTramaImpedancia"/> class.
	/// </summary>
	/// <param name="a">a.</param>
	SubTramaImpedancia(SubTramaParam *);

	/// <summary>
	/// Initializes a new instance of the <see cref="SubTramaImpedancia"/> class.
	/// </summary>
	/// <param name="a">a.</param>
	SubTramaImpedancia(const SubTramaParam &);

	/// <summary>
	/// Initializes a new instance of the <see cref="SubTramaImpedancia"/> class.
	/// </summary>
	/// <param name="a">a.</param>
	SubTramaImpedancia(const SubTramaImpedancia &);


	/// <summary>
	/// Initializes a new instance of the <see cref="SubTramaImpedancia"/> class.
	/// </summary>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	SubTramaImpedancia(uint8_t[], uint8_t[], uint8_t[]);

	/// <summary>
	/// Initializes a new instance of the <see cref="SubTramaImpedancia"/> class.
	/// </summary>
	SubTramaImpedancia();
	
	/// <summary>
	/// Finalizes an instance of the <see cref="SubTramaImpedancia"/> class.
	/// </summary>
	~SubTramaImpedancia();
	

	
	/// <summary>
	/// Clasficas the sub tra.
	/// </summary>
	void clasficaSubTra(const std::vector<uint8_t>&, int);

	
	/// <summary>
	/// Runs the data.
	/// </summary>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	/// <returns></returns>
	int runData(const std::vector<uint8_t> &, int);
	
	/// <summary>
	/// Cargas the impedancia.
	/// </summary>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	/// <returns></returns>
	int loadImpedancia(const std::vector<uint8_t>&, int);


	
	Impedancia datTram(Impedancia &);



};
#endif
