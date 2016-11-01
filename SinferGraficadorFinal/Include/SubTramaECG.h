#if !defined(_SUBTRAECG_)
#define _SUBTRAECG_
#pragma once
#include "SubTramaParam.h"
#include "SubTramaMetod.h"
/// <summary>
/// Class SubtramaECG
/// </summary>
/// <seealso cref="SubTramaParam" />
class SubTramaECG : virtual public SubTramaParam, SubTramaMetod
{
private:
	int val;
	double aVF;
	double aVL;
	double aVR;
	double CVP;
	int frecuencia;
	double I;
	double V;
	double II;
	double III;
public:
		
	
	/// <summary>
	/// Initializes a new instance of the <see cref="SubTramaECG"/> class.
	/// </summary>
	/// <param name="">The .</param>
	SubTramaECG(SubTramaParam *);


	/// <summary>
	/// Subs the trama parameter.
	/// </summary>
	/// <param name="">The .</param>
	/// <returns></returns>
	SubTramaECG(const SubTramaParam &);

	/// <summary>
	/// Initializes a new instance of the <see cref="SubTramaECG"/> class.
	/// </summary>
	/// <param name="">The .</param>
	SubTramaECG(const SubTramaECG &);
	
	/// <summary>
	/// Initializes a new instance of the <see cref="SubTramaECG"/> class.
	/// </summary>
	SubTramaECG();
	

	/// <summary>
	/// Initializes a new instance of the <see cref="SubTramaECG"/> class.
	/// </summary>
	SubTramaECG(uint8_t[], uint8_t[], uint8_t[]);
	
	/// <summary>
	/// Finalizes an instance of the <see cref="SubTramaECG"/> class.
	/// </summary>
	~SubTramaECG();
	
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
	/// Loas the frecuencia.
	/// </summary>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	/// <returns></returns>
	int loadFrecu(const std::vector<uint8_t> &, int);
	
	/// <summary>
	/// Loads the CVP.
	/// </summary>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	/// <returns></returns>
	int loadCVP(const std::vector<uint8_t> &, int);
	
	/// <summary>
	/// Loads the avr.
	/// </summary>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	/// <returns></returns>
	int loadAVR(const std::vector<uint8_t> &, int);
	
	/// <summary>
	/// Laods the avl.
	/// </summary>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	/// <returns></returns>
	int loadAVL(const std::vector<uint8_t> &, int);

	
	/// <summary>
	/// Loads the average.
	/// </summary>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	/// <returns></returns>
	int loadAVF(const std::vector<uint8_t> &, int);
	
	/// <summary>
	/// Loads the v.
	/// </summary>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	/// <returns></returns>
	int loadV(const std::vector<uint8_t> &, int);
	
	/// <summary>
	/// Loads the i.
	/// </summary>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	/// <returns></returns>
	int loadI(const std::vector<uint8_t> &, int);
	
	/// <summary>
	/// Loads the ii.
	/// </summary>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	/// <returns></returns>
	int loadII(const std::vector<uint8_t> &, int);

	
	/// <summary>
	/// Loads the iii.
	/// </summary>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	/// <returns></returns>
	int loadIII(const std::vector<uint8_t> &, int);
	
	/// <summary>
	/// Dats the tram.
	/// </summary>
	/// <param name="">The .</param>
	/// <returns></returns>
	ECG datTram(ECG &);
	
	/// <summary>
	/// Gets the avf.
	/// </summary>
	/// <returns></returns>
	double getAVF();
	
	/// <summary>
	/// Gets the avl.
	/// </summary>
	/// <returns></returns>
	double getAVL();
	
	/// <summary>
	/// Gets the avr.
	/// </summary>
	/// <returns></returns>
	double getAVR();

	
	/// <summary>
	/// Gets the CVP.
	/// </summary>
	/// <returns></returns>
	double getCVP();
	
	/// <summary>
	/// Gets the frecuen.
	/// </summary>
	/// <returns></returns>
	double getFrecuen();
	
	/// <summary>
	/// Gets the i.
	/// </summary>
	/// <returns></returns>
	double getI();

	
	/// <summary>
	/// Gets the v.
	/// </summary>
	/// <returns></returns>
	double getV();
	
	/// <summary>
	/// Gets the ii.
	/// </summary>
	/// <returns></returns>
	double getII();
	
	/// <summary>
	/// Gets the iii.
	/// </summary>
	/// <returns></returns>
	double getIII();

};


#endif

