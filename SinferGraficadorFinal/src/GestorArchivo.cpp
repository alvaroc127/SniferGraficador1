#include "..\Include\GestorArchivo.h"
#include <iostream>


GestorArchivo::GestorArchivo()
{


}


GestorArchivo::~GestorArchivo()
{


}


bool GestorArchivo::searchIp(const std::string & ip) {
	bool band = true;
	bool stop = false;
	std::string ipArch;
	this->inEN.open(direcc1,std::ios::_Nocreate);
	if (!inEN)band = false;
	while (!inEN.eof()&& false == stop) {
		this->inEN >> ipArch;
		stop = band = ip == ipArch ? true : false;
	}
	this->inEN.close();
	return band;
}




bool GestorArchivo::crearArchivo(const std::string  &ip) {
	bool resul=0;
	std::string dir = direcc +"\\"+ip;
	_mkdir(dir.c_str());
	std::ofstream creatArch;

	creatArch.open(dir +"\\"  + "ECGSig1.txt");
	resul = !creatArch ? true : false ;
	creatArch.close();

	creatArch.open(dir + "\\" + "ECGSig2.txt");
	resul = !creatArch ? true : false;
	creatArch.close();

	creatArch.open(dir + "\\" + "ECGSig3.txt");
	resul = !creatArch ? true : false;
	creatArch.close();

	creatArch.open(dir + "\\" + "RESPSign.txt");
	resul = !creatArch ? true : false;
	creatArch.close();

	creatArch.open(dir + "\\" + "SPO2Sign.txt");
	resul = !creatArch ? true : false;
	creatArch.close();

	creatArch.open(dir + "\\" + "ROJASign.txt");
	resul = !creatArch ? true : false;
	creatArch.close();

	creatArch.open(dir + "\\" + "AMARILLASign.txt");
	resul = !creatArch ? true : false;
	creatArch.close();

	creatArch.open(dir + "\\" + "ECGPARAM.txt");
	resul = !creatArch ? true : false;
	creatArch.close();

	creatArch.open(dir + "\\" + "IMPEPARAM.txt");
	resul = !creatArch ? true : false;
	creatArch.close();

	creatArch.open(dir + "\\" + "ART.txt");
	resul = !creatArch ? true : false;
	creatArch.close();

	creatArch.open(dir + "\\" + "AP.txt");
	resul = !creatArch ? true : false;
	creatArch.close();

	creatArch.open(dir + "\\" + "SPO2PARAM.txt");
	resul = !creatArch ? true : false;
	creatArch.close();
	

	creatArch.open(dir + "\\" + "TEMPPARAM.txt");
	resul = !creatArch ? true : false;
	creatArch.close();

	creatArch.open(dir + "\\" + "AlARMAMEN.txt");
	resul = !creatArch ? true : false;
	creatArch.close();
	

	//faltan archivos por crear
	this->outSA.open(direcc1, std::ios::app | std::ios::_Nocreate);
	this->outSA << ip;
	this->outSA << std::endl;
	this->outSA.close();

	return resul;
}

/*
ECG GestorArchivo::getECG() {
	return this->ecg;
}

void GestorArchivo::setEcg(const ECG & ec) {
	this->ecg = ec;
}

void GestorArchivo::setSignal(const Signal &sig) {
	this->sig = sig;

}

Signal GestorArchivo::getSignal() {
	return this->sig;
}
*/

void GestorArchivo::EscribirDatSig(const Signal & sig, MindrayPacket & mp) {
	std::ofstream outArc(direcc+"\\"+mp.getFuente()+"\\"+sig.tipo, std::ios::app | std::ios::_Nocreate);
	if (!outArc) {
		std::cout << direcc + "\\" + mp.getFuente() +"\\" + sig.tipo << std::endl;
		getchar();
	}
	for (int i = 0; i < sig.sign1.size();i++) {
		outArc <<sig.sign1.at(i);
	}
	outArc << std::endl;
	outArc.close();
}



void GestorArchivo::EscribirDatImpedancia(const Impedancia & imp , MindrayParametros & mpp) {
	std::ofstream outArc(direcc + "\\" + mpp.getFuente() + "\\" + imp.tipo, std::ios::app | std::ios::_Nocreate);
	if (!outArc) {
		std::cout << direcc + "\\" + mpp.getFuente() + "\\" + imp.tipo << std::endl;
		getchar();
	}
	outArc << imp.impedanciaX2;
	outArc << std::endl;
	outArc.close();
}



void GestorArchivo::EscribirDatECG(const ECG & ecg ,MindrayParametros & mpp) {
	std::ofstream outArc(direcc + "\\" + mpp.getFuente() + "\\" + ecg.tipo, std::ios::app | std::ios::_Nocreate);
	if (!outArc) {
		std::cout << direcc + "\\" + mpp.getFuente() + "\\" + ecg.tipo << std::endl;
		getchar();
	}
	outArc << ecg.aVF;
	outArc << " ";
	outArc << ecg.aVL;
	outArc << " ";
	outArc << ecg.aVR;
	outArc << " ";
	outArc << ecg.CVP;
	outArc << " ";
	outArc << ecg.frecuencia;
	outArc << " ";
	outArc << ecg.I;
	outArc << ecg.II;
	outArc << " ";
	outArc << ecg.III;
	outArc << " ";
	outArc << ecg.V;
	outArc << std::endl;
	outArc.close();



}


void GestorArchivo::EscribirDatArt(const Art &art, MindrayParametros & mpp) {
	std::ofstream outArc(direcc + "\\" + mpp.getFuente() + "\\" + art.tipo, std::ios::app | std::ios::_Nocreate);
	if (!outArc) {
		std::cout << direcc + "\\" + mpp
			.getFuente() + "\\" + art.tipo << std::endl;
		getchar();
	}


	outArc << std::endl;
	outArc.close();

}


void GestorArchivo::EscribirDatSpo2(const SPO2 &spo2, MindrayParametros &mpp) {
	std::ofstream outArc(direcc + "\\" + mpp.getFuente() + "\\" + spo2.tipo, std::ios::app | std::ios::_Nocreate);
	if (!outArc) {
		std::cout << direcc + "\\" + mpp.getFuente() + "\\" + spo2.tipo << std::endl;
		getchar();
	}
	outArc << spo2.frecuencia;
	outArc << " ";
	outArc << spo2.dato1;
	outArc << std::endl;
	outArc.close();


}

void  GestorArchivo::EscribirDatAp(const Ap & ap, MindrayParametros &mpp) {
	std::ofstream outArc(direcc + "\\" + mpp.getFuente() + "\\" + ap.tipo, std::ios::app | std::ios::_Nocreate);
	if (!outArc) {
		std::cout << direcc + "\\" + mpp.getFuente() + "\\" + ap.tipo << std::endl;
		getchar();
	}
	
	outArc << ap.alto;
	outArc << " ";
	outArc << ap.bajo;
	outArc << " ";
	outArc << ap.parentesis;
	outArc << " ";
	outArc << ap.band;
	outArc << std::endl;
	outArc.close();
}

void GestorArchivo::EscribirDatTemp(const Temp & tem, MindrayParametros & mpp) {
	std::ofstream outArc(direcc + "\\" + mpp.getFuente() + "\\" + tem.tipo, std::ios::app | std::ios::_Nocreate);
	if (!outArc) {
		std::cout << direcc + "\\" + mpp.getFuente() + "\\" + tem.tipo << std::endl;
		getchar();
	}
	outArc << tem.T1;
	outArc << " ";
	outArc << tem.T2;
	outArc << " ";
	outArc << tem.TD;
	outArc << std::endl;
	outArc.close();
}


void GestorArchivo::EscribirDatALarma(std::vector<std::string> mensajes, MindrayAlarma &ma) {
	std::ofstream outArc(direcc + "\\" + ma.getFuente() + "\\" + "AlARMAMEN.txt" , std::ios::app | std::ios::_Nocreate);
	if (!outArc) {
		std::cout << direcc + "\\" + ma.getFuente() + "\\" + "AlARMAMEN.txt" << std::endl;
		getchar();
	}
	for (int i = 0; i < mensajes.size() ; i++) {
		outArc << mensajes.at(i);
		outArc << std::endl;
	}
	outArc.close();
}