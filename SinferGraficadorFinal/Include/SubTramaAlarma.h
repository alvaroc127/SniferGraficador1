#if !defined(_SUBTRAMALARMA_)
#define _SUBTRAMALARMA_
#pragma once
#include "SubTramaParam.h"
#include "SubTramaMetod.h"
/// <summary>
/// Class SubTramaAlarma
/// </summary>
/// <seealso cref="SubTramaParam" />
/// <seealso cref="SubTramaMetod" />
class SubTramaAlarma : virtual public SubTramaParam
{
private:
		uint8_t cant[2];
		uint8_t tam[2];
		std::vector<std::string> mensajes;
public:

	/// <summary>
	/// Initializes a new instance of the <see cref="SubTramaAlarma"/> class.
	/// </summary>
	/// <param name="">The .</param>
	SubTramaAlarma(const SubTramaAlarma &);

	
	/// <summary>
	/// Initializes a new instance of the <see cref="SubTramaAlarma"/> class.
	/// </summary>
	/// <param name="">The .</param>
	SubTramaAlarma(const SubTramaParam &);


	/// <summary>
	/// Initializes a new instance of the <see cref="SubTramaAlarma"/> class.
	/// </summary>
	SubTramaAlarma();


	/// <summary>
	/// Finalizes an instance of the <see cref="SubTramaAlarma"/> class.
	/// </summary>
	~SubTramaAlarma();
	
	/// <summary>
	/// Clasficas the sub tra.
	/// </summary>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	void cargarMensaje(const std::vector<uint8_t>&, int, int);

	
	/// <summary>
	/// Loads the cant.
	/// </summary>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	/// <returns></returns>
	int loadCant(const std::vector<uint8_t> &, int);

	
	/// <summary>
	/// Loads the tam.
	/// </summary>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	/// <returns></returns>
	int loadTam(const std::vector<uint8_t> &, int);
	
	
	/// <summary>
	/// Gets the cant.
	/// </summary>
	/// <returns></returns>
	int getCant();
	
	/// <summary>
	/// Gets the tam.
	/// </summary>
	/// <returns></returns>
	int getTam();
	
	/// <summary>
	/// Gets the mensaje.
	/// </summary>
	/// <returns></returns>
	std::vector<std::string> getMensajes();
	
};

#endif

