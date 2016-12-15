#include "..\Include\Monitor1.h"



Monitor1::Monitor1(const SQLHANDLE  &envi ,const SQLHANDLE &con,const SQLHANDLE  &state) {
	this->sqlenvirot = envi;
	this->sqlCon = con;
	this->sqlstate = state;
}

Monitor1::Monitor1()
{
}


Monitor1::~Monitor1()
{

}



void Monitor1::queryMonitor() {
	if (SQL_SUCCESS != SQLExecDirect(sqlstate,(SQLCHAR *)(SQLOpen + IP + "'").c_str(),SQL_NTS)) {
		show_Error(SQL_HANDLE_STMT, sqlstate);
		Close();
	}
	else {
		char IP[64];
		char Dat[64];
		while (SQLFetch(sqlstate)==SQL_SUCCESS) {
			SQLGetData(sqlstate,1,SQL_C_ULONG,&this->id,sizeof(int),NULL);
			SQLGetData(sqlstate,2,SQL_C_CHAR,IP,sizeof(IP),NULL);
			SQLGetData(sqlstate,3, SQL_C_ULONG, &this->numCam, sizeof(int), NULL);
			SQLGetData(sqlstate,4,SQL_C_CHAR,Dat,64,NULL);
			this->IP = IP;
			this->date_reg = Dat;
		}
	}
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


void Monitor1::show_Error(unsigned int handle, const SQLHANDLE &han) {
	SQLCHAR sqlstate[1024];
	SQLCHAR sqlmessag[1024];
	if (SQL_SUCCESS == SQLGetDiagRec(handle, han, 1, sqlstate, NULL, sqlmessag, 1024, NULL))
		std::cout << "Mensaje " << sqlmessag << "Estado " << sqlstate << std::endl;
}

void Monitor1::Close() {
	SQLFreeHandle(SQL_HANDLE_STMT, sqlstate);
	sqlstate = NULL;
}



std::string Monitor1::getIp() {
	return this->IP;
}





std::string Monitor1::getSQLSeten() {
	return this->SQLOpen;
}

std::string Monitor1::getDate(){
	return this->date_reg;
}


void Monitor1::setHandeEnv(const SQLHANDLE  &envir) {
	this->sqlenvirot = envir;
}


void Monitor1::setHandeCon(const SQLHANDLE &con) {
	this->sqlCon = con;
}



void Monitor1::setHandeState(const SQLHANDLE &stat) {
	this->sqlstate = stat;
}