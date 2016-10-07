#if !defined(_SUBTRAMA_)
#define _SUBTRAMA_
#pragma once
#define lenght(x)  (sizeof(x)/sizeof(x[0]))
#include <string>
/// <summary>
/// Interface of SubTrama
/// </summary>

class SubTrama
{
public:	

	/// <summary>
	/// Initializes a new instance of the <see cref="SubTrama"/> class.
	/// </summary>
	/// <param name="">The .</param>
	SubTrama(const SubTrama &) {}
	
	/// <summary>
	/// Initializes a new instance of the <see cref="SubTrama"/> class.
	/// </summary>
	SubTrama() {}

	/// <summary>
	/// Finalizes an instance of the <see cref="SubTrama"/> class.
	/// </summary>
	 virtual ~SubTrama() {}	

	/// <summary>
	/// Sizes the p subtrama.
	/// </summary>
	/// <returns>sizePsubtram</returns>
	virtual int sizePSubtrama() = 0;	

	/// <summary>
	/// Sizes the sub.
	/// </summary>
	/// <returns> teh size of subTrama</returns>
	virtual int sizeSub() = 0;	


	/// <summary>
	/// Joins the header.
	/// </summary>
	/// <returns>tehe string of join header</returns>
	virtual std::string joinHeader() = 0;

	
	
};

#endif