#if !defined(_CAPTURADERED_)
#define _CAPTURADERED_
#define TINS_STATIC
#pragma once
#include <vector>
#include <tins\tins.h>
#include "Trama.h"
#include "MindrayPacket.h"
#include "MindrayAlarma.h"
#include "MindrayParametros.h"
#include "SubTramaECG.h"
#include "SubTramaAlarma.h"
#include "SubTramaArt_AP.h"
#include "SubTramaImpedancia.h"
#include "SubtRamTemp.h"
#include "SubTramSpo2.h"
#include "GestorArchivo.h"
#include "Coneccion.h"




/// <summary>
/// Class CapturaDeRed
/// </summary>



typedef struct MyData {
	Tins::SnifferConfiguration s1;
	Tins::NetworkInterface ifaceName;
};




class CapturaDeRed
{
	
private:
	MindrayAlarma ma;
	MindrayPacket mp;
	MindrayParametros mpp;
	std::vector<uint8_t> datWait;
	std::string dat_time;
	bool wait =true;
	int posG=0;
	GestorArchivo ga;
	Conection co;

public:
	/// <summary>
	/// Initializes a new instance of the <see cref="CapturaDeRed"/> class.
	/// </summary>
	CapturaDeRed();


	/// <summary>
	/// Finalizes an instance of the <see cref="CapturaDeRed"/> class.
	/// </summary>
	virtual ~CapturaDeRed();


	

	/// <summary>
	/// sort the packet of networck for save in the arch
	/// </summary>
	 std::string clasificarPacket(const  std::vector<uint8_t> & , int );
	
	/// <summary>
	/// Configurations the capture.
	/// </summary>
	/// <returns></returns>
	Tins::NetworkInterface  configCapture();
		
	/// <summary>
	/// Confingrations the sniffer.
	/// </summary>
	/// <returns></returns>
	Tins::SnifferConfiguration  configSniffer();
	
	/// <summary>
	/// Starts the capture.
	/// </summary>
	void startCapture();
		
	/// <summary>
	/// Capturars the packet1.
	/// </summary>
	void CapturarPacket1();

	
	/// <summary>
	/// Confs the head.
	/// </summary>
	/// <returns></returns>
	int confHead(const std::string  &head,const  std::string &ip,const std::vector<uint8_t>&, int);
	
	/// <summary>
	/// Capture the data time.
	/// </summary>
	/// <returns></returns>
	std::string  captDta_time();
		

		
	/// <summary>
	/// Sets the vector.
	/// </summary>
	/// <param name="">The .</param>
	void setVector(const std::vector<uint8_t> &);
	
	/// <summary>
	/// Gets the data wait.
	/// </summary>
	/// <returns></returns>
	std::vector<std::uint8_t>  getDataWait();
		
	/// <summary>
	/// Buscars the head.
	/// </summary>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	/// <returns></returns>
	int searchHead(const std::vector<uint8_t> &, int);
	
	/// <summary>
	/// Guardars the mp.
	/// </summary>
	bool guardarMP(MindrayPacket &);	

	/// <summary>
	/// Guardars the MPP.
	/// </summary>
	bool guardarMPP(MindrayParametros &);	

	/// <summary>
	/// Guardars the ma.
	/// </summary>
	bool guardarMA(MindrayAlarma &);
	
	/// <summary>
	/// Iniciars the base dat.
	/// </summary>
	void iniciarBaseDat();
};


#endif

