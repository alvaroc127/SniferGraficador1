#include "..\Include\SPO2BD.h"



SPO2BD::SPO2BD()
{
}


SPO2BD::~SPO2BD()
{

}


SPO2BD::SPO2BD(SQLHANDLE envi, SQLHANDLE con, SQLHANDLE  state) {
	this->sqlenvirot = envi;
	this->sqlCon = con;
	this->sqlstate = state;
}

void SPO2BD::setHandeEnv(SQLHANDLE envir) {
	this->sqlenvirot = envir;
}


void SPO2BD::setHandeCon(SQLHANDLE con) {
	this->sqlCon = con;
}



void SPO2BD::setHandeState(SQLHANDLE stat) {
	this->sqlstate = stat;
}


void SPO2BD::setTimeStruc(const TIMESTAMP_STRUCT &st) {
	this->st = st;
}



void SPO2BD::show_Error(unsigned int handle, const SQLHANDLE &han) {
	SQLCHAR sqlstate[1024];
	SQLCHAR sqlmessag[1024];
	if (SQL_SUCCESS == SQLGetDiagRec(handle, han, 1, sqlstate, NULL, sqlmessag, 1024, NULL))
		std::cout << "Mensaje " << sqlmessag << "Estado " << sqlstate << std::endl;
}

void SPO2BD::Close() {
	SQLFreeHandle(SQL_HANDLE_STMT, sqlstate);
	SQLDisconnect(sqlCon);
	SQLFreeHandle(SQL_HANDLE_DBC, sqlenvirot);
	SQLFreeHandle(SQL_HANDLE_ENV, sqlenvirot);
}


void SPO2BD::loadSPO2(Store &s,SubTramSpo2 *spo, Monitor1 *mon){
	Signal sig;
	this->id = mon->getId();
	this->frec_encia = spo->getFrecuencia();
	this->desconocido = spo->getDato1();
	for (int i = 0; i < s.mp.getSubTra().size(); i++) {
		sig = s.mp.getSubTra().at(i)->datTram(sig);
		std::cout <<"en ESPO2/////////////////"<<sig.tipo << std::endl;
		if (sig.tipo == "SPO2Sign.txt") {
			this->signa = sig.sign1;
		}
	}
}


void SPO2BD::insertarTablSPO2() {
	RETCODE rc;
	char senten[100];
	char sqlupda[100];
	std::string aux = SQLUPDATE;
	SQLLEN a = 0, b = 0, c = 0, d = 0, e = 0;
	std::cout << "el ID" << id << std::endl;
	sprintf_s(senten, "INSERT INTO  SPO2 (id , HoraSenal ) values (%i,'%i/%i/%i %i:%i:%i.%i')", id, st.year, st.month, st.day, st.hour, st.minute, st.second, st.fraction);
	if (SQL_SUCCESS != SQLExecDirect(sqlstate, (SQLCHAR *)senten, SQL_NTS)) {
		show_Error(SQL_HANDLE_STMT, sqlstate);
		std::cout << "aqui  entro 000" << std::endl;
		Close();
	}
	sprintf_s(sqlupda, "id = %i AND HoraSenal = '%i/%i/%i %i:%i:%i.%i';", id, st.year, st.month, st.day, st.hour, st.minute, st.second, st.fraction);
	if (signa.empty()==false) {
		a = signa.size() - 1;
		rc = SQLBindParameter(sqlstate, 1, SQL_PARAM_INPUT, SQL_C_BINARY, SQL_VARBINARY, 8000, 0, &signa[0], signa.size()-1, &a);
		if (rc!=SQL_SUCCESS) {
			show_Error(SQL_HANDLE_STMT, sqlstate);
			std::cout << "aqui  entro 1" << std::endl;
		}
	}
	else {
		rc = SQLBindParameter(sqlstate, 1, SQL_PARAM_INPUT, SQL_C_BINARY, SQL_VARBINARY, 8000, 0,NULL, 0, NULL);
		if (rc != SQL_SUCCESS) {
			show_Error(SQL_HANDLE_STMT, sqlstate);
			std::cout << "aqui  entro 1" << std::endl;
		}
	}
	
		rc = SQLBindParameter(sqlstate, 2, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 2, &desconocido, sizeof(float), &b);
		if (rc != SQL_SUCCESS) {
			show_Error(SQL_HANDLE_STMT, sqlstate);
			std::cout << "aqui  entro 2" << std::endl;
		}
	
		rc = SQLBindParameter(sqlstate, 3, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 2, &frec_encia, sizeof(float), &c);
		if (rc != SQL_SUCCESS) {
			show_Error(SQL_HANDLE_STMT, sqlstate);
			std::cout << "aqui  entro 3-+++++" << std::endl;
		}
	
	

	aux.append(sqlupda);
	if (SQL_SUCCESS != SQLExecDirect(sqlstate, (SQLCHAR *)aux.c_str(), SQL_NTS)) {
		show_Error(SQL_HANDLE_STMT, sqlstate);
		std::cout << "aqui  entro 4" << std::endl;
		Close();
	}

}


void SPO2BD::loadSignal(Signal &s, Monitor1 * mon) {
	this->id = mon->getId();
	std::cout << " VALOR De ID" << mon->getId() << std::endl;
	if (s.tipo == "SPO2Sign.txt") {
		this->signa = s.sign1;
	}
	bandSig = true;
}


void SPO2BD::loadParametros(SubTramSpo2 * spo2, Monitor1 * mon) {
	this->id = mon->getId();
	std::cout <<" VALOR DE ID"<<mon->getId () << std::endl;
	this->desconocido = spo2->getDato1();
	this->frec_encia = spo2->getFrecuencia();
	bandPara = true;
}

bool SPO2BD::isLoad() {
	bool retur=false;
	if (bandPara==true && bandSig == true) {
		retur = true;
	}
	else {
		if (true == bandPara && bandSig == false) {
			retur = true;
		}
		else {
			if (false == bandPara && bandSig == false) {
				retur = false;
			}
			else {
				if (false == bandPara && bandSig ==true) {
					retur = true;
				}
			}
		}
	}
	return retur;
}

void SPO2BD::backEstad() {
	bandPara = false;
	bandSig = false;
	signa.clear();
	signa.erase(signa.begin(), signa.end());
}