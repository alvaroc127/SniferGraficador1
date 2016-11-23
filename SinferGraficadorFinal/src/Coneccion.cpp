#include "..\Include\Coneccion.h"


Conection::Conection()
{
	
}


Conection::~Conection()
{
}


void Conection::OpenCo() {
	SQLCHAR retconstring[1024];
	SQLSMALLINT outconstring;
	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV,SQL_NULL_HANDLE,&sqlenvirot)){
		Close();
	}
	else if (SQL_SUCCESS != SQLSetEnvAttr(sqlenvirot,SQL_ATTR_ODBC_VERSION,(SQLPOINTER)SQL_OV_ODBC3,0)) {
		Close();
	}
	else if (SQL_SUCCESS!= SQLAllocHandle(SQL_HANDLE_DBC,sqlenvirot,&sqlCon)) {
		Close();
	}
	switch (SQLDriverConnect(sqlCon, NULL, (SQLCHAR *)TEXT("DSN=FUCS;UID=pasante1;PWD=sebastian1;"),SQL_NTS,retconstring,1024,&outconstring,SQL_DRIVER_NOPROMPT)) {
	
	case SQL_SUCCESS_WITH_INFO:
		show_Error(SQL_HANDLE_DBC, sqlCon);
		break;

	case SQL_INVALID_HANDLE:


	break;
	
	case SQL_ERROR:
		show_Error(SQL_HANDLE_DBC, sqlCon);
		Close();
		break;

	default:
		
		break;
	
	}
 if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, sqlCon, &sqlstate)) {
		Close();
	}
	open = true;
}


void Conection::setIp(const std::string  & ip) {
	this->Ip = ip;
}


void Conection::setDate(const std::string   & date) {
	this->date = date;
}

void Conection::loadDatTableMon() {
	if (mon==NULL) {
		mon = new Monitor1(sqlenvirot, sqlCon, sqlstate);
	}
	else {
		mon->setHandeEnv(sqlenvirot);
		mon->setHandeCon(sqlCon);
		mon->setHandeState(sqlstate);
	}
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
	if (al.ma.getDataTime().empty() ==  false && al.mp.getDataTime().empty() == false && al.mpp.getDataTime().empty() == false) {
		band = true;
	}
	else {
		band = false;
	}
	return band;
}

void Conection::insertaDatTab() {
	QueryMon();
	if (open==false) {
		OpenCo();
	}
	if (ecg==NULL) {
		ecg = new Ecg(sqlenvirot,sqlCon,sqlstate);
	}
	else {
		ecg->setHandeEnv(sqlenvirot);
		ecg->setHandeCon(sqlCon);
		ecg->setHandeState(sqlstate);
	}
	ecg->setTimeStruc(st);
	ecg->loadECG(al, mon);
	ecg->insertECG();
	ecg->Close();
	/*
	
	sacar los paquetes y comenzar a relacionar
	*/
	
	
}

void Conection::QueryMon() {
	mon->queryMonitor();
	std::cout << mon->getIp() << std::endl;
	std::cout << mon->getId() << std::endl;
	std::cout << mon->getNumCam() << std::endl;
	std::cout << mon->getDate() << std::endl;
	mon->Close();
	open = false;
}

void Conection::loadDate_Ip() {
	this->date = al.mpp.getDataTime();
	this->Ip = al.mpp.getFuente();
}

void Conection::Close() {
	SQLFreeHandle(SQL_HANDLE_STMT, sqlstate);
	SQLDisconnect(sqlCon);
	SQLFreeHandle(SQL_HANDLE_DBC, sqlenvirot);
	SQLFreeHandle(SQL_HANDLE_ENV,sqlenvirot);
}

void Conection::show_Error(unsigned int handle,const SQLHANDLE &han) {
	SQLCHAR sqlstate[1024];
	SQLCHAR sqlmessag[1024];
	if (SQL_SUCCESS == SQLGetDiagRec(handle, han, 1, sqlstate, NULL, sqlmessag, 1024, NULL))
		std::cout << "Mensaje " << sqlmessag << "Estado " << sqlstate << std::endl;
}

void Conection::setStore(const Store & st) {
	this->al = st;
}

void Conection::insertSinAlarm() {
	QueryMon();
	if (open == false) {
		OpenCo();
	}
	if (ecg == NULL) {
		ecg = new Ecg(sqlenvirot, sqlCon, sqlstate);
	}
	else {
		ecg->setHandeEnv(sqlenvirot);
		ecg->setHandeCon(sqlCon);
		ecg->setHandeState(sqlstate);
	}
	std::cout << "load ecg" << std::endl;
	std::cout << "cantidad de subtramas "<< al.mp.getSubTra().size()<< std::endl;
	ecg->setTimeStruc(st);
	ecg->loadECG(al, mon);
	std::cout << "load terminado" << std::endl;
	ecg->insertECG();
	ecg->Close();

	/*
	sacar paqute y relacionar
	*/
	


}

std::string Conection::getDataTime() {
	return date;
}

std::string Conection::getFuente() {
	return this->Ip;
}



bool Conection::isOpen() {
	return open;
}

void Conection::setTimeStruc(const TIMESTAMP_STRUCT &st) {
	this->st = st;
	std::cout << "se captura" << st.year << std::endl;
}