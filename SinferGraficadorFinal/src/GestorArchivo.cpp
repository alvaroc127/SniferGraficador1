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

	creatArch.open(dir +"\\"  + "ECGSig1.bin");
	resul = !creatArch ? true : false ;
	creatArch.close();

	creatArch.open(dir + "\\" + "ECGSig2.bin");
	resul = !creatArch ? true : false;
	creatArch.close();

	creatArch.open(dir + "\\" + "ECGSig3.bin");
	resul = !creatArch ? true : false;
	creatArch.close();

	creatArch.open(dir + "\\" + "RESPSign.bin");
	resul = !creatArch ? true : false;
	creatArch.close();

	creatArch.open(dir + "\\" + "SPO2Sign.bin");
	resul = !creatArch ? true : false;
	creatArch.close();

	creatArch.open(dir + "\\" + "ROJASign.bin");
	resul = !creatArch ? true : false;
	creatArch.close();

	creatArch.open(dir + "\\" + "AMARILLASign.bin");
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
	
	if (sizeFile() == 0) {
		this->outSA.open(direcc1, std::ios::app | std::ios::_Nocreate);
		this->outSA << ip;
	}
	else {
		this->outSA.open(direcc1, std::ios::app | std::ios::_Nocreate);
		this->outSA << std::endl;
		this->outSA << ip;
		//std::cout << "escribiendo" << std::endl;
	}
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
	std::fstream outArc(direcc + "\\" + mp.getFuente() + "\\" + sig.tipo, std::ios::app | std::ios::binary | std::ios::_Nocreate);
	if (!outArc) {
		std::cout << direcc + "\\" + mp.getFuente() +"\\1" + sig.tipo << std::endl;
		//getchar();
	}
	for (int i = 0; i < sig.sign1.size();i++) {
		outArc.put(sig.sign1.at(i));
	}
	outArc.close();
}



void GestorArchivo::EscribirDatImpedancia(const Impedancia & imp , MindrayParametros & mpp) {
	std::ofstream outArc(direcc + "\\" + mpp.getFuente() + "\\" + imp.tipo, std::ios::app | std::ios::_Nocreate);
	if (!outArc) {
		std::cout << direcc + "\\" + mpp.getFuente() + "\\2" + imp.tipo << std::endl;
	//	getchar();
	}
	outArc << imp.impedanciaX2;
	outArc << std::endl;
	outArc.close();
}



void GestorArchivo::EscribirDatECG(const ECG & ecg ,MindrayParametros & mpp) {
	std::ofstream outArc(direcc + "\\" + mpp.getFuente() + "\\" + ecg.tipo, std::ios::app | std::ios::_Nocreate);
	if (!outArc) {
		std::cout << direcc + "\\" + mpp.getFuente() + "\\3" + ecg.tipo << std::endl;
		//getchar();
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
	outArc << " ";
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
		std::cout << direcc + "\\" + mpp.getFuente() + "\\4" + art.tipo << std::endl;
		//getchar();
	}
	outArc << art.alto;
	outArc << " ";
	outArc << art.bajo;
	outArc << " ";
	outArc << art.parentesis;
	outArc << " ";
	outArc << art.band;
	outArc << std::endl;
	outArc.close();

}


void GestorArchivo::EscribirDatSpo2(const SPO2 &spo2, MindrayParametros &mpp) {
	std::ofstream outArc(direcc + "\\" + mpp.getFuente() + "\\" + spo2.tipo, std::ios::app | std::ios::_Nocreate);
	if (!outArc) {
		std::cout << direcc + "\\" + mpp.getFuente() + "\\5" + spo2.tipo << std::endl;
		//getchar();
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
		std::cout << direcc + "\\" + mpp.getFuente() + "\\6" + ap.tipo << std::endl;
		//getchar();
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
		std::cout << direcc + "\\" + mpp.getFuente() + "\\7" + tem.tipo << std::endl;
		//getchar();
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
		std::cout << direcc + "\\" + ma.getFuente() + "\\8"  << std::endl;
		//getchar();
	}
	for (int i = 0; i < mensajes.size() ; i++) {
		outArc << mensajes.at(i);
		outArc << std::endl;
	}
	outArc.close();
}

int GestorArchivo::sizeFile() {
	int tam = 0;
	this->inEN.open(direcc1, std::ifstream::in);
	if (!inEN.is_open()) {

	}
	else {
		tam = int(inEN.tellg());
		inEN.seekg(0, std::ios::end);
		tam = (int(inEN.tellg()) - tam);
	}
	inEN.close();
	return tam;
}



void GestorArchivo::clearFiles(const std::string & ip) {
	if (searchIp(ip)) {
		std::fstream File;
		File.open(direcc + ip + "\\" + "ECGSig1.bin",std::ios::out |std::ios::trunc);
		File.close();

		File.open(direcc + ip + "\\" + "ECGSig2.bin", std::ios::out |std::ios::trunc);
		File.close();

		File.open(direcc + ip + "\\" + "ECGSig3.bin", std::ios::out | std::ios::trunc);
		File.close();

		File.open(direcc + ip + "\\" + "RESPSign.bin", std::ios::out | std::ios::trunc);
		File.close();
		
		File.open(direcc + ip + "\\" + "SPO2Sign.bin", std::ios::out |std::ios::trunc );
		File.close();

		File.open(direcc + ip + "\\" + "ROJASign.bin", std::ios::out |std::ios::trunc);
		File.close();

		File.open(direcc + ip + "\\" + "AMARILLASign.bin", std::ios::out | std::ios::trunc);
		File.close();

		File.open(direcc + ip + "\\" + "ECGPARAM.txt", std::ios::out | std::ios::trunc);
		File.close();

		File.open(direcc + ip + "\\" + "IMPEPARAM.txt", std::ios::out | std::ios::trunc);
		File.close();

		File.open(direcc + ip + "\\" + "ART.txt", std::ios::out | std::ios::trunc);
		File.close();

		File.open(direcc + ip +"\\" + "AP.txt", std::ios::out | std::ios::trunc);
		File.close();

		File.open(direcc + ip + "\\" + "SPO2PARAM.txt", std::ios::out | std::ios::trunc);
		File.close();


		File.open(direcc + ip + "\\" + "TEMPPARAM.txt", std::ios::out | std::ios::trunc);
		File.close();

		File.open(direcc + ip + "\\" + "AlARMAMEN.txt", std::ios::out |std::ios::trunc);
		File.close();
	}
}

int GestorArchivo::sizeFile1(const std::string & filena) {
	int tam = 0;
	this->inEN.open(filena, std::ifstream::in);
	if (!inEN.is_open()) {

	}
	else {
		tam = int(inEN.tellg());
		inEN.seekg(0, std::ios::end);
		tam = (int(inEN.tellg()) - tam);
	}
	inEN.close();
	return tam;
}