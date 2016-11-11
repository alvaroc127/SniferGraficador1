#include "..\Include\Monitor1.h"



Monitor1::Monitor1(odbc::Connection *co) {
	this->co = co;
}

Monitor1::Monitor1()
{
}


Monitor1::~Monitor1()
{

}



void Monitor1::queryMonitor() {
	odbc::ResultSet *RS;
	odbc::PreparedStatement *pr;
	pr=this->co->prepareStatement(this->SQLOpen);
	RS = pr->executeQuery();
	while (RS->next()) {
		this->id=RS->getInt("ID");
		this->IP=RS->getString("IP");
		this->date_reg = RS->getTimestamp("FechaRegistro").toString();
		this->numCam = RS->getInt("Num_Cama");
	}
	delete RS;
	delete pr;
}


void Monitor1::setIp(const std::string & ip) {
	this->IP = ip;
}


int Monitor1::getId() {
	return this->id;
}


int Monitor1::getNumCam(){
	return this->numCam;
}


