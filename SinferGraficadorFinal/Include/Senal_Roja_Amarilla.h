#if !defined(_AMARILLAROJA_)
#define _AMARILLAROJA_
#pragma once
#include <vector>
#include "StructDB.h"
#include "SubTramaArt_AP.h"
#include "Monitor1.h"
class Senal_Roja_Amarilla
{
private:
	int senial;
	std::string dateTime;
	float max;
	float min;
	float parentesis;
	int id;
	std::vector<uint8_t> sig;


public:

	/// <summary>
	/// Initializes a new instance of the <see cref="Senal_Roja_Amarilla"/> class.
	/// </summary>
	/// <param name="db">The database.</param>
	

	/// <summary>
	/// Initializes a new instance of the <see cref="Senal_Roja_Amarilla"/> class.
	/// </summary>
	Senal_Roja_Amarilla();
		
	/// <summary>
	/// Loads the sr a.
	/// </summary>
	void loadSrA(Store ,SubTramaArt_AP *, Monitor1 *);

	/// <summary>
	/// Finalizes an instance of the <see cref="Senal_Roja_Amarilla"/> class.
	/// </summary>
	virtual ~Senal_Roja_Amarilla();
	
	/// <summary>
	/// Gets the default SQL.
	/// </summary>
	/// <returns></returns>
	
};

#endif