#if !defined(_HEADER_)
#define _HEADER_
#pragma once

/// <summary>
/// Interface of  Header
/// </summary>
class Header
{
public:	
	
	/// <summary>
	/// Initializes a new instance of the <see cref="Header"/> class.
	/// </summary>
	Header() {}
	
	/// <summary>
	/// Initializes a new instance of the <see cref="Header"/> class.
	/// </summary>
	/// <param name="">The .</param>
	Header(const Header &) {};


	/// <summary>
	/// Finalizes an instance of the <see cref="Header"/> Header.
	/// </summary>
	virtual ~Header() {}		
	/// <summary>
	/// Sizes the packet.
	/// </summary>
	/// <returns>the size of packet</returns>
	virtual int sizePacket() = 0;
	
	/// <summary>
	/// Cants the packet.
	/// </summary>
	/// <returns></returns>
	virtual int cantPacket( int) = 0;

};
#endif
