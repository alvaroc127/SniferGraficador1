#include "..\Include\AlarmaIDBD.h"



AlarmaIDBD::AlarmaIDBD()
{
}


AlarmaIDBD::~AlarmaIDBD()
{
}


AlarmaIDBD::AlarmaIDBD(const SQLHANDLE & envi, const  SQLHANDLE & con, const  SQLHANDLE & state) {
	this->sqlenvirot = envi;
	this->sqlCon = con;
	this->sqlstate = state;
}

bool AlarmaIDBD::queryAlarmaIDBD() {
	bool band=false;
	RETCODE rc;
	SQLLEN a = 0, b = 0;
	std::string sente = "SELECT * FROM ALARMABDID WHERE Descripcion = ";
	sente += +"'"+descrip+"'";
	sente += " AND Severidad = ";
	sente += std::to_string(serveri);
	if (SQL_SUCCESS != SQLExecDirect(sqlstate, (SQLCHAR *)sente.c_str(), SQL_NTS)) {
		show_Error(SQL_HANDLE_STMT, sqlstate);
		std::cout << "aqui entro execute" << std::endl;
		Close();
	}
	else {
		char descrip[150];
		if (SQLFetch(sqlstate) == SQL_SUCCESS) {
			band = true;//existe el registro
			while (SQLFetch(sqlstate) == SQL_SUCCESS) {
				SQLGetData(sqlstate, 1, SQL_C_ULONG, &this->id, sizeof(int), NULL);
				SQLGetData(sqlstate, 2, SQL_C_CHAR, &this->descrip, sizeof(descrip), NULL);
				SQLGetData(sqlstate, 4, SQL_C_ULONG, &this->serveri, sizeof(int), NULL);
				this->descrip = descrip;
			}
		}
		else {
			if (SQLFetch(sqlstate) == SQL_NO_DATA) {
				band = false;//no existe
			}
		}
	}
	return band;
}



int AlarmaIDBD::getId() {
	return this->id;
}

std::string AlarmaIDBD::getDescription() {
	return this->descrip;
}



int AlarmaIDBD::getSeverity() {
	return this->serveri;
}

void AlarmaIDBD::setIp(const std::string & ip) {
	this->Ip = ip;
}

void AlarmaIDBD::show_Error(unsigned int handle, const SQLHANDLE &han) {
	SQLCHAR sqlstate[1024];
	SQLCHAR sqlmessag[1024];
	if (SQL_SUCCESS == SQLGetDiagRec(handle, han, 1, sqlstate, NULL, sqlmessag, 1024, NULL))
		std::cout << "Mensaje " << sqlmessag << "Estado " << sqlstate << std::endl;
}

void AlarmaIDBD::Close() {
	SQLFreeHandle(SQL_HANDLE_STMT, sqlstate);
	sqlstate = NULL;
}


void AlarmaIDBD::setHandeEnv(const SQLHANDLE  &envir) {
	this->sqlenvirot = envir;
}


void AlarmaIDBD::setHandeCon(const SQLHANDLE &con) {
	this->sqlCon = con;
}

void AlarmaIDBD::setDescrip(const std::string & des) {
	this->descrip = des;
}

void AlarmaIDBD::setSeveri(int seve) {
	this->serveri = seve;
}

void AlarmaIDBD::setHandeState(const SQLHANDLE &stat) {
	this->sqlstate = stat;
}

void AlarmaIDBD::insertAlarmaID() {
	RETCODE rc;
	SQLLEN b = 0;
	std::string sente = "INSERT INTO ALARMABDID (Descripcion,Severidad) values (";
	sente +="'"+ descrip+"'";
	sente += " , " + std::to_string(this->serveri)+" )";
	
	if (SQL_SUCCESS != SQLExecDirect(sqlstate, (SQLCHAR *)sente.c_str(), SQL_NTS)) {
		show_Error(SQL_HANDLE_STMT, sqlstate);
		std::cout << "aqui  entro +++3++" << std::endl;
		Close();
	}
}

void AlarmaIDBD::loadOtherDat() {
	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, sqlCon, &sqlstate)) {
		Close();
	}
}