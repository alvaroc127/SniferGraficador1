#include "..\Include\frec_respiratoriDB.h"


frec_respiratoriDB::frec_respiratoriDB(const SQLHANDLE  &envi,const  SQLHANDLE & con, const SQLHANDLE & state) {
	this->sqlenvirot = envi;
	this->sqlCon = con;
	this->sqlstate = state;
}


frec_respiratoriDB::frec_respiratoriDB()
{
}


frec_respiratoriDB::~frec_respiratoriDB()
{
}



void frec_respiratoriDB::setTimeStruc(const TIMESTAMP_STRUCT &st) {
	this->st = st;
}



void frec_respiratoriDB::show_Error(unsigned int handle, const SQLHANDLE &han) {
	SQLCHAR sqlstate[1024];
	SQLCHAR sqlmessag[1024];
	if (SQL_SUCCESS == SQLGetDiagRec(handle, han, 1, sqlstate, NULL, sqlmessag, 1024, NULL))
		std::cout << "Mensaje " << sqlmessag << "Estado " << sqlstate << std::endl;
}

void frec_respiratoriDB::Close() {
	SQLFreeHandle(SQL_HANDLE_STMT, sqlstate);
	sqlstate = NULL;
}


void frec_respiratoriDB::setHandeEnv(const SQLHANDLE & envir) {
	this->sqlenvirot = envir;
}


void frec_respiratoriDB::setHandeCon(const SQLHANDLE  & con) {
	this->sqlCon = con;
}



void frec_respiratoriDB::setHandeState(const SQLHANDLE & stat) {
	this->sqlstate = stat;
}


void frec_respiratoriDB::loadFrecRes(Monitor1 *mon) {
	this->id = mon->getId();
	this->sig = readFileSig(mon->getIp()+"\\RESPSign.bin");
	readFileParam(mon->getIp()+"\\IMPEPARAM.txt");
}

void frec_respiratoriDB::insertTableFrec_Resp() {
	RETCODE rc;
	char senten[100];
	char sqlupda[100];
	std::string aux = SQLUpda;
	SQLLEN a = 0, b = 0;
	sprintf_s(senten, "INSERT INTO Frec_Respiratoria (id , HoraSenal ) values (%i,'%i/%i/%i %i:%i:%i.%i')", id, st.year, st.month, st.day, st.hour, st.minute, st.second, st.fraction);
	if (SQL_SUCCESS != SQLExecDirect(sqlstate, (SQLCHAR *)senten, SQL_NTS)) {
		show_Error(SQL_HANDLE_STMT, sqlstate);
		Close();
	}
	sprintf_s(sqlupda, "id = %i AND HoraSenal = '%i/%i/%i %i:%i:%i.%i';", id, st.year, st.month, st.day, st.hour, st.minute, st.second, st.fraction);
		rc = SQLBindParameter(sqlstate, 1, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 2, &impedancia, sizeof(float), &a);
		if (rc != SQL_SUCCESS) {
			std::cout << "entro aqui" << std::endl;
			show_Error(SQL_HANDLE_STMT, sqlstate);
			std::cout << "aqui  entro 1" << std::endl;
		}
	


	if (sig.empty()==false) {
		b = sig.size() - 1;
		rc = SQLBindParameter(sqlstate, 2, SQL_PARAM_INPUT, SQL_C_BINARY, SQL_VARBINARY, 8000, 0, &sig[0], sig.size()-1, &b);
		if (rc != SQL_SUCCESS) {
			show_Error(SQL_HANDLE_STMT, sqlstate);
			std::cout << "aqui  entro NO null 2" << std::endl;
		}
	}
	else {
		rc = SQLBindParameter(sqlstate, 2, SQL_PARAM_INPUT, SQL_C_BINARY, SQL_VARBINARY, 8000, 0, NULL, 0,&b);
		if (rc != SQL_SUCCESS) {
			show_Error(SQL_HANDLE_STMT, sqlstate);
			std::cout << "aqui  entro  NULL 2" << std::endl;
		}
	}
	aux.append(sqlupda);
	if (SQL_SUCCESS != SQLExecDirect(sqlstate, (SQLCHAR *)aux.c_str(), SQL_NTS)) {
		show_Error(SQL_HANDLE_STMT, sqlstate);
		std::cout << "aqui  entro 3" << std::endl;
		Close();
	}
}

void frec_respiratoriDB::loadSignal(Signal &sig, Monitor1 *mon) {
	this->id = mon->getId();
	this->sig = sig.sign1;
	
}


void frec_respiratoriDB::LoadParam(SubTramaImpedancia *im, Monitor1 * mon) {
	this->impedancia = im->getimpe();
}

bool frec_respiratoriDB::isLoad() {
	return bandLoad;
}

void frec_respiratoriDB::backEstad() {
	impedancia = 0;
	sig.clear();
}


std::vector<uint8_t> frec_respiratoriDB::readFileSig(const std::string &ip) {
	std::vector<uint8_t> let;
	char byte = 0;
	inFile.open(direcc + ip, std::ifstream::in | std::ios::binary | std::ios::_Nocreate);
	if (!inFile.is_open()) {
		std::cout << "no se pudo abrir" << direcc + ip << std::endl;
	}
	else {
		while (!inFile.eof()) {
			inFile.get(byte);
			let.push_back(byte);
		}
	}
	inFile.close();
	return let;
}


void frec_respiratoriDB::readFileParam(const std::string &ip) {
	std::string imp;
	inFile.open(direcc + ip, std::ifstream::in | std::ifstream::_Nocreate);
	if (!inFile.is_open()) {
		std::cout << "no se pudo abrir" << direcc + ip << std::endl;
	}
	else {
		while (!inFile.eof()) {
			inFile >> imp;
		}
		if (imp != "") {
			this->impedancia = atof(imp.c_str());
		}
	}
	inFile.close();
}