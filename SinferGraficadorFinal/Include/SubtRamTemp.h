#if !defined(_SUBTRAMPTEMP_)
#define _SUBTRAMPTEMP_
#pragma once
#include "SubTramaParam.h"
#include "SubTramaMetod.h"
/// <summary>
/// Class SubtRampTemp
/// </summary>
/// <seealso cref="SubTramaParam" />
/// <seealso cref="SubTramaMetod" />
class SubtRamTemp : virtual public SubTramaParam, SubTramaMetod
{
private:
	double T1;
	double T2;
	double TD;
	int val;
public:	

	/// <summary>
	/// Subs the trama ecg.
	/// </summary>
	/// <param name="sub">The sub.</param>
	/// <returns></returns>
	SubtRamTemp( SubTramaParam * sub);

	/// <summary>
	/// Initializes a new instance of the <see cref="SubtRamTemp"/> class.
	/// </summary>
	/// <param name="sub">The sub.</param>
	SubtRamTemp(const SubTramaParam & sub);

	/// <summary>
	/// Initializes a new instance of the <see cref="SubtRamTemp"/> class.
	/// </summary>
	SubtRamTemp();
	
	/// <summary>
	/// Initializes a new instance of the <see cref="SubtRamTemp"/> class.
	/// </summary>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	SubtRamTemp(uint8_t[], uint8_t[], uint8_t[]);

	/// <summary>
	/// Finalizes an instance of the <see cref="SubtRamTemp"/> class.
	/// </summary>
	~SubtRamTemp();
	/// <summary>
	/// Clasficas the sub tra.
	/// </summary>
	void clasficaSubTra(const std::vector<uint8_t> &, int);
	
	/// <summary>
	/// Runs the data.
	/// </summary>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	/// <returns></returns>
	int runData(const std::vector<uint8_t> &, int);
	
	/// <summary>
	/// Loads the t1.
	/// </summary>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	/// <returns></returns>
	int loadT1(const std::vector<uint8_t> &, int);
	
	/// <summary>
	/// Loads the t2.
	/// </summary>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	/// <returns></returns>
	int loadT2(const std::vector<uint8_t> &, int);
	
	/// <summary>
	/// Loads the t3.
	/// </summary>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	/// <returns></returns>
	int loadTD(const std::vector<uint8_t> &, int);


	Temp datTram(Temp &);
	

};

#endif