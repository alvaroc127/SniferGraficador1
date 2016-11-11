#include "..\Include\Coneccion.h"


Conection::Conection()
{
	
}


Conection::~Conection()
{
}


void Conection::OpenCo() {
	try {
		co = odbc::DriverManager::getConnection("FUCS","pasante1","sebastian1");
		//mon = new Monitor1(co);
	}
	catch (const odbc::SQLException & a) {
		std::cout << a.what()<< std::endl;
		std::cout << "errores" << std::endl;
	}
}


void Conection::setIp(const std::string  & ip) {
	this->Ip = ip;
}


void Conection::setDate(const std::string   & date) {
	this->date = date;
}

void Conection::loadDatTableMon() {
	this->mon->setIp(this->Ip);
}


void Conection::insertRegisMP(MindrayPacket   mp) {
	if (mp.getDataTime() == this->date) {
		al.mp = mp;
	}
}

void Conection::insertRegisMA(MindrayAlarma  ma) {
	if (ma.getDataTime() == this->date) {
		al.ma = ma;
	}
}


void Conection::inserRegisMPP(MindrayParametros   mpp) {
	this->date = mpp.getDataTime();
	this->Ip = mpp.getFuente();
	al.mpp = mpp;
}

bool Conection::checkStore() {
	bool band = false;
	if (al.ma.getFuente().empty() == false && al.mp.getFuente().empty() == false && al.mpp.getFuente().empty() == false) {
		band = true;
	}
	else {
		band = false;
	}
	return band;
}

void Conection::insertaDatTab() {
	QueryMon();
	this->al.ma.setDtaTime("");
	this->al.mp.setDtaTime("");
	this->al.mpp.setDtaTime("");
	this->al.ma.setFuente("");
	this->al.mp.setFuente("");
	this->al.mpp.setFuente("");
}

void Conection::QueryMon() {
	mon->setIp(Ip);
	mon->queryMonitor();
	std::cout << mon->getId() << std::endl;
	std::cout << mon->getNumCam() << std::endl;
}

void Conection::loadDate_Ip() {
	this->date = al.mpp.getDataTime();
	this->Ip = al.mpp.getFuente();
}