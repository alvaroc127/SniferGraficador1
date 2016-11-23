#include "..\Include\Ecg.h"



Ecg::Ecg(SQLHANDLE envi, SQLHANDLE con, SQLHANDLE  state) {
	this->sqlenvirot = envi;
	this->sqlCon = con;
	this->sqlstate = state;
}


Ecg::Ecg() {


}


Ecg::~Ecg() {


}


void Ecg::loadECG(Store  &st, Monitor1 *mon) {
	Signal sig;
	ECG ecg;
	this->id = mon->getId();
	date_sig = st.mpp.getDataTime().c_str();
	std::cout << "catnidad de subtramas" <<st.mp.getSubTra().size() << std::endl;
	for (int i = 0; i < st.mp.getSubTra().size(); i++) {
		sig = st.mp.getSubTra().at(i)->datTram(sig);
		std::cout << sig.tipo << std::endl;
		if (sig.tipo == "ECG1.txt") {
			std::cout << "cargo una senial" << std::endl;
			this->ECG1 = sig.sign1;
		}
		else if (sig.tipo == "ECG2.txt") {
			std::cout << "cargo una senial" << std::endl;
			this->ECG2 = sig.sign1;
		}
		else if (sig.tipo == "ECG3.txt") {
			std::cout << "cargo una senial" << std::endl;
			this->ECG3 = sig.sign1;
		}
	}
	for (int a = 0; a < st.mpp.getSubTra().size(); a++) {
		SubTramaECG * sue = dynamic_cast<SubTramaECG *> (st.mpp.getSubTra().at(a));
		if (sue != NULL) {
			std::cout << "esta aqui"<<std::endl;
			ecg = sue->datTram(ecg);
			this->aVR = ecg.aVR;
			this->aVL = ecg.aVL;
			this->fre_Card = ecg.frecuencia;
			this->I = ecg.I;
			this->II = ecg.II;
			this->III = ecg.III;
			this->V = ecg.V;
			this->CVP = ecg.CVP;
			this->aVF = ecg.aVF;
			std::cout << "se cargaraon" << aVR <<" "<< aVL<<" "<< fre_Card<<" "<< I <<" "<< II <<" "<< III <<" "<< V <<" "<< CVP <<" "<< aVF <<" "<< std::endl;
		}
	}

}


void Ecg::show_Error(unsigned int handle, const SQLHANDLE &han) {
	SQLCHAR sqlstate[1024];
	SQLCHAR sqlmessag[1024];
	if (SQL_SUCCESS == SQLGetDiagRec(handle, han, 1, sqlstate, NULL, sqlmessag, 1024, NULL))
		std::cout << "Mensaje " << sqlmessag << "Estado " << sqlstate << std::endl;
}

void Ecg::Close() {
	SQLFreeHandle(SQL_HANDLE_STMT, sqlstate);
	SQLDisconnect(sqlCon);
	SQLFreeHandle(SQL_HANDLE_DBC, sqlenvirot);
	SQLFreeHandle(SQL_HANDLE_ENV, sqlenvirot);
}


void Ecg::setHandeEnv(SQLHANDLE envir) {
	this->sqlenvirot = envir;
}


void Ecg::setHandeCon(SQLHANDLE con) {
	this->sqlCon = con;
}



void Ecg::setHandeState(SQLHANDLE stat) {
	this->sqlstate = stat;
}

void Ecg::insertECG() {
	RETCODE rc;
	char senten[100];
		SQLLEN a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, i = 0, j = 0, k = 0, l = 0, m = 0, n = 0;
		sprintf_s(senten,"INSERT INTO ECG (id , HoraSenal ) values (%i,'%i/%i/%i %i:%i:%i.%i')",id,st.year,st.month,st.day,st.hour,st.minute,st.second,st.fraction);
			if (SQL_SUCCESS != SQLExecDirect(sqlstate, (SQLCHAR *)senten , SQL_NTS)) {
				show_Error(SQL_HANDLE_STMT, sqlstate);
				Close();
			}
			rc = SQLBindParameter(sqlstate, 1, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 2, &aVR, sizeof(float), &a);
			if (SQL_SUCCESS != rc) {
				show_Error(SQL_HANDLE_STMT, sqlstate);
				std::cout << "aqui  entro 1" << std::endl;
			}
			rc = SQLBindParameter(sqlstate, 2, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 2, &aVL, sizeof(float), &b);
			if (SQL_SUCCESS != rc) {
			show_Error(SQL_HANDLE_STMT, sqlstate);
			std::cout << "aqui  entro 2" << std::endl;
			}
			rc = SQLBindParameter(sqlstate, 3, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 2, &fre_Card, sizeof(float), &c);
			if (SQL_SUCCESS != rc) {
				show_Error(SQL_HANDLE_STMT, sqlstate);
				std::cout << "aqui  entro 3" << std::endl;
			}
			rc = SQLBindParameter(sqlstate, 4, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 2, &I, sizeof(float), &d);
			if (SQL_SUCCESS != rc) {
				show_Error(SQL_HANDLE_STMT, sqlstate);
				std::cout << "aqui  entro 4" << std::endl;
			}
			rc = SQLBindParameter(sqlstate, 5, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 2, &II, sizeof(float), &e);
			if (SQL_SUCCESS != rc) {
				show_Error(SQL_HANDLE_STMT, sqlstate);
				std::cout << "aqui  entro 5" << std::endl;
			}
			rc = SQLBindParameter(sqlstate, 6, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 2, &III, sizeof(float), &f);
			if (SQL_SUCCESS != rc) {
				show_Error(SQL_HANDLE_STMT, sqlstate);
				std::cout << "aqui  entro 6" << std::endl;
			}
			rc = SQLBindParameter(sqlstate, 7, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 2, &V, sizeof(float), &g);
			if (SQL_SUCCESS != rc) {
				show_Error(SQL_HANDLE_STMT, sqlstate);
				std::cout << "aqui  entro 7" << std::endl;
			}
			h = ECG1.size() - 1;
			rc = SQLBindParameter(sqlstate, 8, SQL_PARAM_INPUT, SQL_C_BINARY, SQL_VARBINARY,8000, 0, &ECG1[0], ECG1.size(), &h);
			if (SQL_SUCCESS != rc) {
				show_Error(SQL_HANDLE_STMT, sqlstate);
				std::cout << "aqui  entro 8" << std::endl;
			}
			h = ECG2.size() - 1;
			rc = SQLBindParameter(sqlstate, 9, SQL_PARAM_INPUT, SQL_C_BINARY, SQL_VARBINARY, ECG2.size(), 0, &ECG2[0], ECG2.size(), &i);
			if (SQL_SUCCESS != rc) {
				show_Error(SQL_HANDLE_STMT, sqlstate);
				std::cout << "aqui  entro 9" << std::endl;
			}
			h = ECG3.size() - 1;
			rc = SQLBindParameter(sqlstate, 10, SQL_PARAM_INPUT, SQL_C_BINARY, SQL_VARBINARY, ECG3.size(), 0, &ECG3[0], ECG3.size(), &j);
			if (SQL_SUCCESS != rc) {
				show_Error(SQL_HANDLE_STMT, sqlstate);
				std::cout << "aqui  entro 10" << std::endl;
			}
			rc = SQLBindParameter(sqlstate, 11, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 2, &aVF, sizeof(float), &k);
			if (SQL_SUCCESS != rc) {
				show_Error(SQL_HANDLE_STMT, sqlstate);
				std::cout << "aqui  entro 11" << std::endl;
			}
			rc = SQLBindParameter(sqlstate, 12, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 2, &CVP, sizeof(float), &l);
			if (SQL_SUCCESS != rc) {
				show_Error(SQL_HANDLE_STMT, sqlstate);
				std::cout << "aqui  entro 12" << std::endl;
			}
			if (SQL_SUCCESS != SQLExecDirect(sqlstate, (SQLCHAR *)this->SQLUPDATE.c_str(), SQL_NTS)) {
				show_Error(SQL_HANDLE_STMT, sqlstate);
				std::cout << "aqui  entro 13" << std::endl;
				Close();
			}
}


float Ecg::getaVF() {
	return aVF;
}


float Ecg::getAvr() {
	return aVR;
}


float Ecg::getCVP() {
	return CVP;
}


float Ecg::getFrec_Cardi() {
	return this->fre_Card;
}

std::string Ecg::getDateTime(){
	return this->date_sig;
}



float Ecg::getAvl() {
	return this->aVL;
}

float Ecg::getI() {
	return this->I;
}

float Ecg::getII() {
	return this->II;
}


float  Ecg::getIII() {
	return this->III;
}


float Ecg::getV(){
	return this->V;
}

void Ecg::setTimeStruc(const TIMESTAMP_STRUCT &st) {
	this->st = st;
}