#include "TemperaturaDB.h"



TemperaturaDB::TemperaturaDB()
{
}


TemperaturaDB::~TemperaturaDB()
{
}


TemperaturaDB::TemperaturaDB(SQLHANDLE envi, SQLHANDLE con, SQLHANDLE  state) {
	this->sqlenvirot = envi;
	this->sqlCon = con;
	this->sqlstate = state;

}


void TemperaturaDB::loadTemp(Store &st, SubtRamTemp *sun, Monitor1 *mon) {
	this->id = mon->getId();
	this->dat_Sig = st.mpp.getDataTime();
	this->T1 = sun->getT1();
	this->T2 = sun->getT2();
	this->T3 = sun->getTD();
}

void TemperaturaDB::setHandeEnv(SQLHANDLE envir) {
	this->sqlenvirot = envir;
}


void TemperaturaDB::setHandeCon(SQLHANDLE con) {
	this->sqlCon = con;
}



void TemperaturaDB::setHandeState(SQLHANDLE stat) {
	this->sqlstate = stat;
}


void TemperaturaDB::setTimeStruc(const TIMESTAMP_STRUCT &st) {
	this->st = st;
}



void TemperaturaDB::show_Error(unsigned int handle, const SQLHANDLE &han) {
	SQLCHAR sqlstate[1024];
	SQLCHAR sqlmessag[1024];
	if (SQL_SUCCESS == SQLGetDiagRec(handle, han, 1, sqlstate, NULL, sqlmessag, 1024, NULL))
		std::cout << "Mensaje " << sqlmessag << "Estado " << sqlstate << std::endl;
}

void TemperaturaDB::Close() {
	SQLFreeHandle(SQL_HANDLE_STMT, sqlstate);
	SQLDisconnect(sqlCon);
	SQLFreeHandle(SQL_HANDLE_DBC, sqlenvirot);
	SQLFreeHandle(SQL_HANDLE_ENV, sqlenvirot);
}


void TemperaturaDB::insetTableTempe() {
	RETCODE rc;
	char senten[100];
	char sqlupda[100];
	std::string aux = SQLUPDATE;
	SQLLEN a = 0, b = 0, c = 0;
	sprintf_s(senten, "INSERT INTO Temperatura (id , HoraSenal ) values (%i,'%i/%i/%i %i:%i:%i.%i')", id, st.year, st.month, st.day, st.hour, st.minute, st.second, st.fraction);
	if (SQL_SUCCESS != SQLExecDirect(sqlstate, (SQLCHAR *)senten, SQL_NTS)) {
		show_Error(SQL_HANDLE_STMT, sqlstate);
		Close();
	}
	sprintf_s(sqlupda, "id = %i AND HoraSenal = '%i/%i/%i %i:%i:%i.%i';", id, st.year, st.month, st.day, st.hour, st.minute, st.second, st.fraction);
	rc = SQLBindParameter(sqlstate, 1, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 2, &this->T1, sizeof(float), &a);
	if (rc != SQL_SUCCESS) {
		show_Error(SQL_HANDLE_STMT, sqlstate);
		std::cout << "aqui  entro 1" << std::endl;
	}
	rc = SQLBindParameter(sqlstate, 2, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 2, &this->T2, sizeof(float), &b);
	if (rc != SQL_SUCCESS) {
		show_Error(SQL_HANDLE_STMT, sqlstate);
		std::cout << "aqui  entro 2" << std::endl;
	}
	rc = SQLBindParameter(sqlstate, 3, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 2, &this->T3, sizeof(float), &c);
	if (rc != SQL_SUCCESS) {
		show_Error(SQL_HANDLE_STMT, sqlstate);
		std::cout << "aqui  entro 3" << std::endl;
	}

	aux.append(sqlupda);
	if (SQL_SUCCESS != SQLExecDirect(sqlstate, (SQLCHAR *)aux.c_str(), SQL_NTS)) {
		show_Error(SQL_HANDLE_STMT, sqlstate);
		std::cout << "aqui  entro 4" << std::endl;
		Close();
	}
}




void TemperaturaDB::loadParam(SubtRamTemp  *sub, Monitor1 *mon) {
	this->id = mon->getId();
	this->T1 = sub->getT1();
	this->T2 = sub->getT2();
	this->T3 = sub->getTD();

}


void TemperaturaDB::loadSignal(Signal &sig, Monitor1 *mon) {
	this->id = mon->getId();
}