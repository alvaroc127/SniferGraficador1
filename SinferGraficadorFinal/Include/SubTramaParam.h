	#if !defined (_SUBTRAMAPARAM_)
#define _SUBTRAMAPARAM_
#pragma once
#include <vector>
#include <sstream>
#include "SubTrama.h"
#include "Struct.h"


/// <summary>
/// Class SubtramaParam
/// </summary>
/// <seealso cref="SubTrama" />
 class SubTramaParam : virtual  public SubTrama
{
private:
	uint8_t start[2];
	uint8_t size[3];
	uint8_t vodi[2];
	std::vector<uint8_t>datas;
	int siz=2+3+2;
		
public:	
	
	/// <summary>
	/// Initializes a new instance of the <see cref="SubTramaParam"/> class.
	/// </summary>
	/// <param name="p">The p.</param>
	SubTramaParam(SubTramaParam *);


	/// <summary>
	/// Initializes a new instance of the <see cref="SubTramaParam"/> class.
	/// </summary>
	/// <param name="siz">The siz.</param>
	SubTramaParam(const SubTramaParam &);


	/// <summary>
	/// Runs the data.
	/// </summary>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	/// <returns></returns>
	 int runData(const std::vector<uint8_t> &, int);

	/// <summary>
	/// Initializes a new instance of the <see cref="SubTramaParam"/> class.
	/// </summary>
	 SubTramaParam();


	
	/// <summary>
	/// Initializes a new instance of the <see cref="SubTramaParam"/> class.
	/// </summary>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	SubTramaParam(uint8_t[], uint8_t[], uint8_t[]);

	/// <summary>
	/// Finalizes an instance of the <see cref="SubTramaParam"/> class.
	/// </summary>
	virtual ~SubTramaParam();	

	/// <summary>
	/// Joins the header.
	/// </summary>
	/// <returns></returns>
	std::string joinHeader();
		
	/// <summary>
	/// Sizes the sub.
	/// </summary>
	/// <returns></returns>
	int sizeSub();
	
	/// <summary>
	/// Sizes the p subtrama.
	/// </summary>
	/// <returns></returns>
	int sizePSubtrama();
	

	
	/// <summary>
	/// Seleccions the metod.
	/// </summary>
	int seleccionMetod(int);

	
	/// <summary>
	/// Loads the head.
	/// </summary>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	/// <returns></returns>
	int loadHead(const std::vector<uint8_t> &, int);
		
	/// <summary>
	/// Adds the data.
	/// </summary>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	/// <returns></returns>
	int addData(const std::vector<uint8_t> &, int, int);

	
	/// <summary>
	/// Getstarts this instance.
	/// </summary>
	/// <returns></returns>
	uint8_t * getstart();

	/// <summary>
	/// Getsizes this instance.
	/// </summary>
	/// <returns></returns>
	uint8_t * getsize();


	
	/// <summary>
	/// Getends this instance.
	/// </summary>
	/// <returns></returns>
	uint8_t * getvodi();

	
	/// <summary>
	/// Sets the siz.
	/// </summary>
	void setSiz(int);





};
#endif