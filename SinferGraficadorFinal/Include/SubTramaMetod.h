#if !defined(_SUBTRAMETOD_)
#define _SUBTRAMETOD_
#pragma once
#include<vector> 

/// <summary>
/// interface SubtraMetod
/// </summary>
class SubTramaMetod
{
public:
	/// <summary>
	/// Finalizes an instance of the <see cref="SubTramaMetod"/> class.
	/// </summary>
	virtual ~SubTramaMetod() {};
	
	/// <summary>
	/// Clasficas the sub tra.
	/// </summary>
	virtual  void clasficaSubTra(const std::vector<uint8_t> &, int) = 0;
};

#endif