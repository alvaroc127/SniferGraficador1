#include "..\Include\AlarmaBD.h"


AlarmaBD::AlarmaBD(const SQLHANDLE & envi,const  SQLHANDLE & con,const  SQLHANDLE & state){
	this->sqlenvirot = envi;
	this->sqlCon = con;
	this->sqlstate = state;
}


AlarmaBD::AlarmaBD()
{
}


AlarmaBD::~AlarmaBD()
{
}




void AlarmaBD::loadAlarm( Monitor1 *mon, Ecg *ecg, AlarmaIDBD * aidbd ) {
	this->idMon = mon->getId();
	this->description = aidbd->getDescription();
	this->alarmSeverity = aidbd->getSeverity();
	this->ECG1 = ecg->getEcg1();
	this->ECG2 = ecg->getEcg2();
	this->ECG3 = ecg->getEcg3();
	this->aVR = ecg->getAvr();
	this->aVl = ecg->getAvl();
	this->frec_Card = ecg->getFrec_Cardi();
	this->I = ecg->getI();
	this->II = ecg->getII();
	this->III = ecg->getIII();
	this->V = ecg->getV();
	this->aVF = ecg->getaVF();
	this->CVP = ecg->getCVP();

}

int AlarmaBD::contChar( std::string mens) {
	int con = 0;
	for (int i = 0; i < mens.size(); i++) {
		if (mens.at(i) == '*') {
			con++;
		}
	}
	return con;
}


void AlarmaBD::insertarTbaAlarma() {
	RETCODE rc;
	char senten[200];
	char sqlupda[100];
	std::string aux = SQLUPdate;
	std::string upda="INSERT INTO Alarm (id , HoraAlarma,Severidad,Descripcion) values (%i,'%i/%i/%i %i:%i:%i.%i', %i , ";
	SQLLEN a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, i = 0, j = 0, k = 0, l = 0, m = 0, n = 0;
	upda += "'"+description+"'"+ " ) ;";
	sprintf_s(senten, upda.c_str() , idMon, st.year, st.month, st.day, st.hour, st.minute, st.second, st.fraction,alarmSeverity);
	if (SQL_SUCCESS != SQLExecDirect(sqlstate, (SQLCHAR *)senten, SQL_NTS)) {
		show_Error(SQL_HANDLE_STMT, sqlstate);
		std::cout << "entro AQUIIIIOOOOOO" << std::endl;
		Close();
	}
	sprintf_s(sqlupda, "id = %i AND HoraAlarma = '%i/%i/%i %i:%i:%i.%i';", idMon, st.year, st.month, st.day, st.hour, st.minute, st.second, st.fraction);
	
	if (ECG1.empty() == false) {
		c = ECG1.size() - 1;
		rc = SQLBindParameter(sqlstate, 1, SQL_PARAM_INPUT, SQL_C_BINARY, SQL_VARBINARY, 8000, 0, &ECG1[0], ECG1.size() - 1, &c);
		if (SQL_SUCCESS != rc) {
			show_Error(SQL_HANDLE_STMT, sqlstate);
			std::cout << "aqui  entro 3" << std::endl;
		}
	}
	else {
		rc = SQLBindParameter(sqlstate, 1, SQL_PARAM_INPUT, SQL_C_BINARY, SQL_VARBINARY, 8000, 0, NULL, 0, &c);
		if (SQL_SUCCESS != rc) {
			show_Error(SQL_HANDLE_STMT, sqlstate);
			std::cout << "aqui  entro 3" << std::endl;
		}
	}
	
	if (ECG2.empty() == false) {
		d = ECG2.size() - 1;
		rc = SQLBindParameter(sqlstate,2, SQL_PARAM_INPUT, SQL_C_BINARY, SQL_VARBINARY, 8000, 0, &ECG2[0], ECG2.size() - 1, &d);
		if (SQL_SUCCESS != rc) {
			show_Error(SQL_HANDLE_STMT, sqlstate);
			std::cout << "aqui  entro 4" << std::endl;
		}
	}
	else {
		rc = SQLBindParameter(sqlstate, 2, SQL_PARAM_INPUT, SQL_C_BINARY, SQL_VARBINARY, 8000, 0, NULL, 0, &d);
		if (SQL_SUCCESS != rc) {
			show_Error(SQL_HANDLE_STMT, sqlstate);
			std::cout << "aqui  entro 4" << std::endl;
		}
	}
	if (ECG3.empty() == false) {
		e = ECG3.size() - 1;
		rc = SQLBindParameter(sqlstate, 3, SQL_PARAM_INPUT, SQL_C_BINARY, SQL_VARBINARY, 8000, 0, &ECG3[0], ECG3.size() - 1, &e);
		if (SQL_SUCCESS != rc) {
			show_Error(SQL_HANDLE_STMT, sqlstate);
			std::cout << "aqui  entro 5" << std::endl;
		}
	}
	else {
		rc = SQLBindParameter(sqlstate, 3, SQL_PARAM_INPUT, SQL_C_BINARY, SQL_VARBINARY, 8000, 0, NULL, 0, &e);
		if (SQL_SUCCESS != rc) {
			show_Error(SQL_HANDLE_STMT, sqlstate);
			std::cout << "aqui  entro 5" << std::endl;
		}
	}

	
		rc = SQLBindParameter(sqlstate, 4, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 2, &aVR, sizeof(float), &f);
		if (SQL_SUCCESS != rc) {
			show_Error(SQL_HANDLE_STMT, sqlstate);
			std::cout << "aqui  entro 6" << std::endl;
		}

		rc = SQLBindParameter(sqlstate, 5, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 2, &this->aVl, sizeof(float), &g);
		if (SQL_SUCCESS != rc) {
			show_Error(SQL_HANDLE_STMT, sqlstate);
			std::cout << "aqui  entro 7" << std::endl;
		}
	
		
	
		rc = SQLBindParameter(sqlstate, 6, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 2, &frec_Card, sizeof(float), &h);
		if (SQL_SUCCESS != rc) {
			show_Error(SQL_HANDLE_STMT, sqlstate);
			std::cout << "aqui  entro 8" << std::endl;
		}

		rc = SQLBindParameter(sqlstate, 7, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 3, &I, sizeof(float), &i);
		if (SQL_SUCCESS != rc) {
			show_Error(SQL_HANDLE_STMT, sqlstate);
			std::cout << "aqui  entro 9" << std::endl;
		}

	


		rc = SQLBindParameter(sqlstate, 8, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 3, &II, sizeof(float), &j);
		if (SQL_SUCCESS != rc) {
			show_Error(SQL_HANDLE_STMT, sqlstate);
			std::cout << "aqui  entro 10" << std::endl;
		}
	
	
		rc = SQLBindParameter(sqlstate, 9, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 3, &III, sizeof(float), &k);
		if (SQL_SUCCESS != rc) {
			show_Error(SQL_HANDLE_STMT, sqlstate);
			std::cout << "aqui  entro 11" << std::endl;
		}
	
	


	
		rc = SQLBindParameter(sqlstate, 10, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 3, &V, sizeof(float), &l);
		if (SQL_SUCCESS != rc) {
			show_Error(SQL_HANDLE_STMT, sqlstate);
			std::cout << "aqui  entro 12" << std::endl;
		}
	
	

	
		rc = SQLBindParameter(sqlstate, 11, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 3, &aVF, sizeof(float), &m);
		if (SQL_SUCCESS != rc) {
			show_Error(SQL_HANDLE_STMT, sqlstate);
			std::cout << "aqui  entro 13" << std::endl;
		}
	

	
		rc = SQLBindParameter(sqlstate, 12, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 3, &CVP, sizeof(float), &n);
		if (SQL_SUCCESS != rc) {
			show_Error(SQL_HANDLE_STMT, sqlstate);
			std::cout << "aqui  entro 14" << std::endl;
		}

	aux.append(sqlupda);
	if (SQL_SUCCESS != SQLExecDirect(sqlstate, (SQLCHAR *)aux.c_str(), SQL_NTS)) {
		show_Error(SQL_HANDLE_STMT, sqlstate);
		std::cout << "aqui  entro 15" << std::endl;
		Close();
	}

}

void AlarmaBD::setHandeEnv(const SQLHANDLE &envir) {
	this->sqlenvirot = envir;
}


void AlarmaBD::setHandeCon(const SQLHANDLE  &con) {
	this->sqlCon = con;
}



void AlarmaBD::setHandeState(const SQLHANDLE &stat) {
	this->sqlstate = stat;
}


void AlarmaBD::setTimeStruc(const TIMESTAMP_STRUCT &st) {
	this->st = st;
}



void AlarmaBD::show_Error(unsigned int handle, const SQLHANDLE &han) {
	SQLCHAR sqlstate[1024];
	SQLCHAR sqlmessag[1024];
	if (SQL_SUCCESS == SQLGetDiagRec(handle, han, 1, sqlstate, NULL, sqlmessag, 1024, NULL))
		std::cout << "Mensaje " << sqlmessag << "Estado " << sqlstate << std::endl;
}

void AlarmaBD::Close() {
	SQLFreeHandle(SQL_HANDLE_STMT, sqlstate);
	sqlstate = NULL;
}

std::string AlarmaBD::readFileMens(const std::string & ip) {
	std::string ms;
	inFile.open(direcc + ip, std::ifstream::in | std::ifstream::_Nocreate);
	if (!inFile.is_open()) {
		std::cout << "no se pudo abrir" << direcc + ip << std::endl;
	}
	else {
		while (!inFile.eof()) {
			inFile >> ms;
		}
	}
	if (ms!="") {
		this->alarmSeverity = contChar(ms);
	}
	inFile.close();
	return ms;
}

void AlarmaBD::loadMens(const std::string &ip) {
	std::string ms;
	inFile.open(direcc + ip, std::ifstream::in | std::ifstream::_Nocreate);
	if (!inFile.is_open()) {
		std::cout << "no se pudo abrir" << direcc + ip << std::endl;
	}
	else {
		for (std::string line; std::getline(inFile, line);) {
			mensajes.push_back(line);
		}
	}
	inFile.close();
}



std::vector<std::string> AlarmaBD::getMensajes() {
	return mensajes;
}

void AlarmaBD::clearMensajes() {
		mensajes.clear();
}