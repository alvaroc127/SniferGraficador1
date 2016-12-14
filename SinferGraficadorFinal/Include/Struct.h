#if !defined(_STRUCT_)
#define _STRUCT_
#pragma once
#include <string>
#include <vector>




/// <summary>
/// structura impedancia
/// </summary>
struct Impedancia {
	int impedanciaX2;
	std::string tipo;
	void asignarTipo(std::string tip){
		this->tipo = tip;
	}
};



/// <summary>
/// arterial struct
/// </summary>
struct Art {
	int alto;
	int bajo;
	int parentesis;
	bool band;
	std::string tipo;
	void asignarTipo(std::string tip) {
		this->tipo = tip;
	}
};

/// <summary>
/// ap struct
/// </summary>
struct Ap {
	int alto;
	int bajo;
	int parentesis;
	bool band;
	std::string tipo;
	void asignarTipo(std::string tip) {
		this->tipo = tip;
	}
};


/// <summary>
/// ECG struct
/// </summary>
struct ECG {
	double aVF;
	double aVL;
	double aVR;
	double CVP;
	int frecuencia;
	double I;
	double V;
	double II;
	double III;
	std::string tipo;
	void asignarTipo(std::string tip) {
		this->tipo = tip;
	}
};

/// <summary>
/// Spo2 struct
/// </summary>
struct SPO2 {
	int dato1;
	int frecuencia;
	std::string tipo;
	void asignarTipo(std::string tip) {
		this->tipo = tip;
	}
};

/// <summary>
/// temp struct
/// </summary>
struct Temp {
	double T1;
	double T2;
	double TD;
	std::string tipo;
	void asignarTipo(std::string tip) {
		this->tipo = tip;
	}
};

/// <summary>
/// represent signal of 
/// </summary>
struct Signal {
	std::vector<uint8_t> sign1;
	std::string tipo;
	void asignarTipo(std::string tip) {
		this->tipo = tip;
	}
};





#endif
