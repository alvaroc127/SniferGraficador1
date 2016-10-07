#if !defined(_HEADERTRAM_)
#define _HEADERTRAM_
#pragma once
#include <iostream>
#include <vector>
#include "Header.h"
/// <summary>
/// Class of HeaderTrama
/// </summary>
/// <seealso cref="Header" />
class HeaderTram : public Header
{
private:
	uint8_t start[6];
	uint8_t size[2];
	uint8_t hi_ze[8];
	uint8_t crc[2];
	uint8_t low_ser[6];
	int siz = 6 + 2 + 8 + 2 + 6;
public:		
	/// <summary>
	/// Initializes a new instance of the <see cref="HeaderTram"/> class.
	/// </summary>
	/// <param name="">The .</param>
	HeaderTram(const HeaderTram &);

	/// <summary>
	/// Initializes a new instance of the <see cref="HeaderTram"/> class.
	/// </summary>
	HeaderTram();
	/// <summary>
	/// Finalizes an instance of the <see cref="HeaderTram"/> class.
	/// </summary>
	virtual ~HeaderTram();	
	/// <summary>
	/// Sizes the packet.
	/// </summary>
	/// <returns></returns>
	int sizePacket();
	
	/// <summary>
	/// Loads the head.
	/// </summary>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	/// <returns></returns>
	int loadHead(const std::vector<uint8_t> &, int);
	
	/// <summary>
	/// Cants the packet.
	/// </summary>
	/// <returns></returns>
	int cantPacket(int);
	
	
	
};

#endif