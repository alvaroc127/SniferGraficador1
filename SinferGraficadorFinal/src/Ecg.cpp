#include "..\Include\Ecg.h"



Ecg::Ecg(const SQLHANDLE &envi,const  SQLHANDLE  &con, const SQLHANDLE  &state) {
	this->sqlenvirot = envi;
	this->sqlCon = con;
	this->sqlstate = state;
}


Ecg::Ecg() {


}


Ecg::~Ecg() {


}


void Ecg::loadECG(Monitor1 *mon) {
	this->id = mon->getId();
	ECG1.clear();
	this->ECG1 = readFileSig(mon->getIp()+"\\ECGSig1.bin");
	ECG2.clear();
	this->ECG2 = readFileSig(mon->getIp()+"\\ECGSig2.bin");
	ECG3.clear();
	this->ECG3 = readFileSig(mon->getIp()+"\\ECGSig3.bin");
	readFileParam(mon->getIp() + "\\ECGPARAM.txt");
}


void Ecg::show_Error(unsigned int handle, const SQLHANDLE &han) {
	SQLCHAR sqlstate[1024];
	SQLCHAR sqlmessag[1024];
	if (SQL_SUCCESS == SQLGetDiagRec(handle, han, 1, sqlstate, NULL, sqlmessag, 1024, NULL))
		std::cout << "Mensaje " << sqlmessag << "Estado " << sqlstate << std::endl;
}

void Ecg::Close() {
	SQLFreeHandle(SQL_HANDLE_STMT,sqlstate);
	sqlstate = NULL;
	/*
	SQLDisconnect(sqlCon);
	SQLFreeHandle(SQL_HANDLE_DBC, sqlCon);
	sqlCon = NULL;
	SQLFreeHandle(SQL_HANDLE_ENV, sqlenvirot);
		sqlenvirot = NULL;
	*/
	/*
	RETCODE tc;
	SQLFreeHandle(SQL_HANDLE_STMT, sqlstate);
	sqlstate = NULL;
	SQLFreeStmt(sqlstate,SQL_CLOSE);
	SQLFreeStmt(sqlstate, SQL_DROP);
	SQLDisconnect(sqlCon);
	SQLFreeConnect(sqlCon);
	SQLFreeEnv(sqlenvirot);
	tc=SQLFreeHandle(SQL_HANDLE_ENV, sqlenvirot);
	sqlenvirot = NULL;
	*/
}


void Ecg::setHandeEnv(const SQLHANDLE &envir) {
	this->sqlenvirot = envir;
}


void Ecg::setHandeCon(const SQLHANDLE &con) {
	this->sqlCon = con;
}



void Ecg::setHandeState(const SQLHANDLE &stat) {
	this->sqlstate = stat;
}

void Ecg::insertECG() {
	RETCODE rc;
	char senten[100];
	char sqlupda[100];
	std::string aux = SQLUPDATE;
	SQLLEN a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, i = 0, j = 0, k = 0, l = 0, m = 0, n = 0;
		sprintf_s(senten,"INSERT INTO ECG (id , HoraSenal ) values (%i,'%i/%i/%i %i:%i:%i.%i')",id,st.year,st.month,st.day,st.hour,st.minute,st.second,st.fraction);
			if (SQL_SUCCESS != SQLExecDirect(sqlstate, (SQLCHAR *)senten , SQL_NTS)) {
				show_Error(SQL_HANDLE_STMT, sqlstate);
				Close();
			}
			sprintf_s(sqlupda, "id = %i AND HoraSenal = '%i/%i/%i %i:%i:%i.%i';", id, st.year, st.month, st.day, st.hour, st.minute, st.second, st.fraction);
			
			//if (aVR != 0) {
				rc = SQLBindParameter(sqlstate, 1, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 2, &aVR, sizeof(float), &a);
				if (SQL_SUCCESS != rc) {
					show_Error(SQL_HANDLE_STMT, sqlstate);
					std::cout << "aqui  entro 1" << std::endl;
				}
			//}
		//	else {
		//		rc = SQLBindParameter(sqlstate, 1, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 2, NULL, 0, &a);
			//	if (SQL_SUCCESS != rc) {
			//		show_Error(SQL_HANDLE_STMT, sqlstate);
				//	std::cout << "aqui  entro 1" << std::endl;
			//	}
			//}

		//	if (aVL != 0) {
				rc = SQLBindParameter(sqlstate, 2, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 2, &aVL, sizeof(float), &b);
				if (SQL_SUCCESS != rc) {
					show_Error(SQL_HANDLE_STMT, sqlstate);
					std::cout << "aqui  entro 2" << std::endl;
				}
		//	}
			//else {
			//	rc = SQLBindParameter(sqlstate, 2, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 2, NULL, 0, &b);
		//	//	if (SQL_SUCCESS != rc) {
			//		show_Error(SQL_HANDLE_STMT, sqlstate);
				//	std::cout << "aqui  entro 2" << std::endl;
			//	}
			//}

			//if (fre_Card != 0) {
				rc = SQLBindParameter(sqlstate, 3, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 2, &fre_Card, sizeof(float), &c);
				if (SQL_SUCCESS != rc) {
					show_Error(SQL_HANDLE_STMT, sqlstate);
					std::cout << "aqui  entro 3" << std::endl;
				}
			//}
			//else {
		//	//	rc = SQLBindParameter(sqlstate, 3, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 2, NULL, 0, &c);
			//	if (SQL_SUCCESS != rc) {
				//	show_Error(SQL_HANDLE_STMT, sqlstate);
				//	std::cout << "aqui  entro 3" << std::endl;
				//}
			//}

		//	if (I != 0) {
				rc = SQLBindParameter(sqlstate, 4, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 2, &I, sizeof(float), &d);
				if (SQL_SUCCESS != rc) {
					show_Error(SQL_HANDLE_STMT, sqlstate);
					std::cout << "aqui  entro 4" << std::endl;
				}
			//}
			//else {
				//rc = SQLBindParameter(sqlstate, 4, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 2, NULL, 0, &d);
				//if (SQL_SUCCESS != rc) {
				//	show_Error(SQL_HANDLE_STMT, sqlstate);
				//	std::cout << "aqui  entro 4" << std::endl;
				//}
			//}

		//	if ( II != 0) {
				rc = SQLBindParameter(sqlstate, 5, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 2, &II, sizeof(float), &e);
				if (SQL_SUCCESS != rc) {
					show_Error(SQL_HANDLE_STMT, sqlstate);
					std::cout << "aqui  entro 5" << std::endl;
				}
			//}
			//else {
			///	rc = SQLBindParameter(sqlstate, 5, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 2, NULL, 0, &e);
			//	if (SQL_SUCCESS != rc) {
			//		show_Error(SQL_HANDLE_STMT, sqlstate);
			//		std::cout << "aqui  entro 5" << std::endl;
				//}
			
			//}

		//	if (III  != 0) {
				rc = SQLBindParameter(sqlstate, 6, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 2, &III, sizeof(float), &f);
				if (SQL_SUCCESS != rc) {
					show_Error(SQL_HANDLE_STMT, sqlstate);
					std::cout << "aqui  entro 6" << std::endl;
				}
			//}
		//	else {
			//	rc = SQLBindParameter(sqlstate, 6, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 2, NULL, 0, &f);
			//	if (SQL_SUCCESS != rc) {
				//	show_Error(SQL_HANDLE_STMT, sqlstate);
			//		std::cout << "aqui  entro 6" << std::endl;
			//	}
			
			
			//}

		//	if (V != 0) {
				rc = SQLBindParameter(sqlstate, 7, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 2, &V, sizeof(float), &g);
				if (SQL_SUCCESS != rc) {
					show_Error(SQL_HANDLE_STMT, sqlstate);
					std::cout << "aqui  entro 7" << std::endl;
				}
			//}
		//	else {
			//	rc = SQLBindParameter(sqlstate, 7, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 2, NULL, 0, &g);
				//if (SQL_SUCCESS != rc) {
				//	show_Error(SQL_HANDLE_STMT, sqlstate);
				//	std::cout << "aqui  entro 7" << std::endl;
			//	}
			
			//}
			if (ECG1.empty()==false) {
				h = ECG1.size() - 1;
				rc = SQLBindParameter(sqlstate, 8, SQL_PARAM_INPUT, SQL_C_BINARY, SQL_VARBINARY, 8000, 0, &ECG1[0], ECG1.size()-1, &h);
				if (SQL_SUCCESS != rc) {
					show_Error(SQL_HANDLE_STMT, sqlstate);
					std::cout << "aqui  entro 8" << std::endl;
				}
			}
			else {
				rc = SQLBindParameter(sqlstate, 8, SQL_PARAM_INPUT, SQL_C_BINARY, SQL_VARBINARY, 8000, 0, NULL, 0,&h);
				if (SQL_SUCCESS != rc) {
					show_Error(SQL_HANDLE_STMT, sqlstate);
					std::cout << "aqui  entro 8" << std::endl;
				}
			}
			if (ECG2.empty()==false) {
				i = ECG2.size() - 1;
				rc = SQLBindParameter(sqlstate, 9, SQL_PARAM_INPUT, SQL_C_BINARY, SQL_VARBINARY, 8000, 0, &ECG2[0], ECG2.size()-1, &i);
				if (SQL_SUCCESS != rc) {
					show_Error(SQL_HANDLE_STMT, sqlstate);
					std::cout << "aqui  entro 9" << std::endl;
				}
			}
			else {
				rc = SQLBindParameter(sqlstate, 9, SQL_PARAM_INPUT, SQL_C_BINARY, SQL_VARBINARY, 8000, 0, NULL, 0, &i);
				if (SQL_SUCCESS != rc) {
					show_Error(SQL_HANDLE_STMT, sqlstate);
					std::cout << "aqui  entro 9" << std::endl;
				}
			}
			if (ECG3.empty()==false) {
				j = ECG3.size() - 1;
				rc = SQLBindParameter(sqlstate, 10, SQL_PARAM_INPUT, SQL_C_BINARY, SQL_VARBINARY, 8000, 0, &ECG3[0], ECG3.size()-1, &j);
				if (SQL_SUCCESS != rc) {
					show_Error(SQL_HANDLE_STMT, sqlstate);
					std::cout << "aqui  entro 10" << std::endl;
				}
			}
			else {
				rc = SQLBindParameter(sqlstate, 10, SQL_PARAM_INPUT, SQL_C_BINARY, SQL_VARBINARY, 8000, 0, NULL, 0, &j);
				if (SQL_SUCCESS != rc) {
					show_Error(SQL_HANDLE_STMT, sqlstate);
					std::cout << "aqui  entro 10" << std::endl;
				}
			}

		///	if (aVF != 0) {
				rc = SQLBindParameter(sqlstate, 11, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 3, &aVF, sizeof(float), &k);
				if (SQL_SUCCESS != rc) {
					show_Error(SQL_HANDLE_STMT, sqlstate);
					std::cout << "aqui  entro 11" << std::endl;
				}
			//}
		//	else {
			//	rc = SQLBindParameter(sqlstate, 11, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 3, NULL,0, &k);
				//if (SQL_SUCCESS != rc) {
					//show_Error(SQL_HANDLE_STMT, sqlstate);
					//std::cout << "aqui  entro 11" << std::endl;
				//}
			
			//}

			//if (CVP != 0) {
				rc = SQLBindParameter(sqlstate, 12, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 3, &CVP, sizeof(float), &l);
				if (SQL_SUCCESS != rc) {
					show_Error(SQL_HANDLE_STMT, sqlstate);
					std::cout << "aqui  entro 12" << std::endl;
				}
			//}
			//else {
				//std::cout << "ALMACENA null" << std::endl;
				//rc = SQLBindParameter(sqlstate, 12, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 3, NULL, 0, &l);
				//if (SQL_SUCCESS != rc) {
				//	show_Error(SQL_HANDLE_STMT, sqlstate);
				//	std::cout << "aqui  entro 12" << std::endl;
				//}
			
			//}

			aux.append(sqlupda);
		if (SQL_SUCCESS != SQLExecDirect(sqlstate, (SQLCHAR *)aux.c_str(), SQL_NTS)) {
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

std::vector<uint8_t> Ecg::getEcg1() {
	return ECG1;
}

std::vector<uint8_t> Ecg::getEcg2(){
	return ECG2;
}

std::vector<uint8_t> Ecg::getEcg3() {
	return ECG3;
}

std::vector<uint8_t> Ecg::readFileSig(const std::string &ip) {
	std::vector<uint8_t> let;
	char byte=0;
	inFile.open(direcc + ip, std::ifstream::in | std::ios::binary | std::ios::_Nocreate);
	if (!inFile.is_open()) {
		std::cout << "no se pudo abrir" << direcc + ip << std::endl;
	}
	else {
		while (!inFile.eof()) {
			inFile.get(byte);
				let.push_back((uint8_t)byte);
		}
	}
	inFile.close();
	return let;
}

void Ecg::readFileParam(const std::string  &ip) {
	std::string lin;
	std::string aVR;
	std::string aVL;
	std::string frecuencia;
	std::string I;
	std::string II;
	std::string III;
	std::string V;
	std::string CVP;
	std::string  aVF;
	inFile.open(direcc + ip, std::ifstream::in | std::ifstream::_Nocreate);
	if (!inFile.is_open()) {
		std::cout << "no se pudo abrir" << direcc + ip << std::endl;
	}
	else {
		while (!inFile.eof()) {
			inFile >> aVR;
				if (aVR != "") {
					inFile >> aVL >> frecuencia >> I >> II >> III >> V >> CVP >> aVF;
				}
		}
		this->aVR = atof(aVR.c_str());
		this->aVL = atof(aVL.c_str());
		this->fre_Card = atof(frecuencia.c_str());
		this->I = atof(I.c_str());
		this->II = atof(II.c_str());
		this->III = atof(III.c_str());
		this->V = atof(V.c_str());
		this->CVP = atof(CVP.c_str());
		this->aVF = atof(aVF.c_str());
	}
	inFile.close();
}


void Ecg::backEstad() {
	ECG1.clear();
	ECG2.clear();
	ECG3.clear();
	this->aVR = 0;
	this->aVL = 0;
	this->fre_Card = 0;
	this->I = 0;
	this->II = 0;
	this->III = 0;
	this->V = 0;
	this->CVP = 0;
	this->aVF = 0;
}