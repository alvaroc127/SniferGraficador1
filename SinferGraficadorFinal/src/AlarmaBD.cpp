#include "..\Include\AlarmaBD.h"


AlarmaBD::AlarmaBD(SQLHANDLE envi, SQLHANDLE con, SQLHANDLE  state){
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


void AlarmaBD::loadAlarm(Store &s, Monitor1 *mon, std::string ms, Ecg *ecg) {
	this->num_cam = mon->getNumCam();
	this->dateTime = s.mpp.getDataTime().c_str();
	this->alarmSeverity = contChar(ms);
	this->description = ms;
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

int AlarmaBD::contChar(std::string mens) {
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
	char senten[100];
	char sqlupda[100];
	std::string aux = SQLUPdate;
	SQLLEN a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, i = 0, j = 0, k = 0, l = 0, m = 0, n = 0;
	sprintf_s(senten, "INSERT INTO Alarm (id , HoraSenal ) values (%i,'%i/%i/%i %i:%i:%i.%i')", num_cam, st.year, st.month, st.day, st.hour, st.minute, st.second, st.fraction);
	if (SQL_SUCCESS != SQLExecDirect(sqlstate, (SQLCHAR *)senten, SQL_NTS)) {
		show_Error(SQL_HANDLE_STMT, sqlstate);
		Close();
	}
	sprintf_s(sqlupda, "id = %i AND HoraSenal = '%i/%i/%i %i:%i:%i.%i';", num_cam, st.year, st.month, st.day, st.hour, st.minute, st.second, st.fraction);
	rc = SQLBindParameter(sqlstate, 1, SQL_PARAM_INPUT, SQL_C_ULONG, SQL_INTEGER, sizeof(int), 0, &alarmSeverity, sizeof(int), &a);
	if (SQL_SUCCESS != rc) {
		show_Error(SQL_HANDLE_STMT, sqlstate);
		std::cout << "aqui  entro 1" << std::endl;
	}
	if (description.empty()== false) {
		b = description.size() - 1;
	rc = SQLBindParameter(sqlstate, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 255, 0,&description, description.size()-1, &b);
	if (SQL_SUCCESS != rc) {
		show_Error(SQL_HANDLE_STMT, sqlstate);
		std::cout << "aqui  entro 2" << std::endl;
		}
	}
	else {
		rc = SQLBindParameter(sqlstate, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 255, 0, NULL, 0, NULL);
		if (SQL_SUCCESS != rc) {
			show_Error(SQL_HANDLE_STMT, sqlstate);
			std::cout << "aqui  entro 2" << std::endl;
		}
	
	}

	if (ECG1.empty() == false) {
		c = ECG1.size() - 1;
		rc = SQLBindParameter(sqlstate, 3, SQL_PARAM_INPUT, SQL_C_BINARY, SQL_VARBINARY, 8000, 0, &ECG1[0], ECG1.size() - 1, &c);
		if (SQL_SUCCESS != rc) {
			show_Error(SQL_HANDLE_STMT, sqlstate);
			std::cout << "aqui  entro 3" << std::endl;
		}
	}
	else {
		rc = SQLBindParameter(sqlstate, 3, SQL_PARAM_INPUT, SQL_C_BINARY, SQL_VARBINARY, 8000, 0, NULL, 0, &c);
		if (SQL_SUCCESS != rc) {
			show_Error(SQL_HANDLE_STMT, sqlstate);
			std::cout << "aqui  entro 3" << std::endl;
		}
	}
	
	if (ECG2.empty() == false) {
		d = ECG2.size() - 1;
		rc = SQLBindParameter(sqlstate,4, SQL_PARAM_INPUT, SQL_C_BINARY, SQL_VARBINARY, 8000, 0, &ECG2[0], ECG2.size() - 1, &d);
		if (SQL_SUCCESS != rc) {
			show_Error(SQL_HANDLE_STMT, sqlstate);
			std::cout << "aqui  entro 4" << std::endl;
		}
	}
	else {
		rc = SQLBindParameter(sqlstate, 4, SQL_PARAM_INPUT, SQL_C_BINARY, SQL_VARBINARY, 8000, 0, NULL, 0, &d);
		if (SQL_SUCCESS != rc) {
			show_Error(SQL_HANDLE_STMT, sqlstate);
			std::cout << "aqui  entro 4" << std::endl;
		}
	}
	if (ECG3.empty() == false) {
		e = ECG3.size() - 1;
		rc = SQLBindParameter(sqlstate, 5, SQL_PARAM_INPUT, SQL_C_BINARY, SQL_VARBINARY, 8000, 0, &ECG3[0], ECG3.size() - 1, &e);
		if (SQL_SUCCESS != rc) {
			show_Error(SQL_HANDLE_STMT, sqlstate);
			std::cout << "aqui  entro 5" << std::endl;
		}
	}
	else {
		rc = SQLBindParameter(sqlstate, 5, SQL_PARAM_INPUT, SQL_C_BINARY, SQL_VARBINARY, 8000, 0, NULL, 0, &e);
		if (SQL_SUCCESS != rc) {
			show_Error(SQL_HANDLE_STMT, sqlstate);
			std::cout << "aqui  entro 5" << std::endl;
		}
	}

	if (aVR!=0) {
		rc = SQLBindParameter(sqlstate, 6, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 2, &aVR, sizeof(float), &f);
		if (SQL_SUCCESS != rc) {
			show_Error(SQL_HANDLE_STMT, sqlstate);
			std::cout << "aqui  entro 6" << std::endl;
		}
	}
	else {
		rc = SQLBindParameter(sqlstate, 6, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 2, NULL, sizeof(float), &f);
		if (SQL_SUCCESS != rc) {
			show_Error(SQL_HANDLE_STMT, sqlstate);
			std::cout << "aqui  entro 6" << std::endl;
		}
	}
	if (aVl!=0) {
		rc = SQLBindParameter(sqlstate, 7, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 2, &this->aVl, sizeof(float), &g);
		if (SQL_SUCCESS != rc) {
			show_Error(SQL_HANDLE_STMT, sqlstate);
			std::cout << "aqui  entro 7" << std::endl;
		}
	}else{
		rc = SQLBindParameter(sqlstate, 7, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 2, NULL, sizeof(float), &g);
		if (SQL_SUCCESS != rc) {
			show_Error(SQL_HANDLE_STMT, sqlstate);
			std::cout << "aqui  entro 7" << std::endl;
		}
	}
	if (frec_Card != 0) {
		rc = SQLBindParameter(sqlstate, 8, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 2, &frec_Card, sizeof(float), &h);
		if (SQL_SUCCESS != rc) {
			show_Error(SQL_HANDLE_STMT, sqlstate);
			std::cout << "aqui  entro 8" << std::endl;
		}
	}
	else {
		rc = SQLBindParameter(sqlstate, 8, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 2, NULL, sizeof(float), &h);
		if (SQL_SUCCESS != rc) {
			show_Error(SQL_HANDLE_STMT, sqlstate);
			std::cout << "aqui  entro 8" << std::endl;
		}
	}

	if (I != 0) {
		rc = SQLBindParameter(sqlstate, 9, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 3, &I, sizeof(float), &i);
		if (SQL_SUCCESS != rc) {
			show_Error(SQL_HANDLE_STMT, sqlstate);
			std::cout << "aqui  entro 9" << std::endl;
		}
	}
	else {
		rc = SQLBindParameter(sqlstate, 9, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 3, NULL, sizeof(float), &i);
		if (SQL_SUCCESS != rc) {
			show_Error(SQL_HANDLE_STMT, sqlstate);
			std::cout << "aqui  entro 9" << std::endl;
		}
	}

	if (II != 0) {
		rc = SQLBindParameter(sqlstate, 10, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 3, &II, sizeof(float), &j);
		if (SQL_SUCCESS != rc) {
			show_Error(SQL_HANDLE_STMT, sqlstate);
			std::cout << "aqui  entro 10" << std::endl;
		}
	}
	else {
		rc = SQLBindParameter(sqlstate, 10, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 3, NULL, sizeof(float), &j);
		if (SQL_SUCCESS != rc) {
			show_Error(SQL_HANDLE_STMT, sqlstate);
			std::cout << "aqui  entro 10" << std::endl;
		}
	}

	if (III != 0) {
		rc = SQLBindParameter(sqlstate, 11, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 3, &III, sizeof(float), &k);
		if (SQL_SUCCESS != rc) {
			show_Error(SQL_HANDLE_STMT, sqlstate);
			std::cout << "aqui  entro 11" << std::endl;
		}
	}
	else {
		rc = SQLBindParameter(sqlstate, 11, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 3, NULL, sizeof(float), &k);
		if (SQL_SUCCESS != rc) {
			show_Error(SQL_HANDLE_STMT, sqlstate);
			std::cout << "aqui  entro 11" << std::endl;
		}
	
	}

	if (V != 0) {
		rc = SQLBindParameter(sqlstate, 12, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 3, &V, sizeof(float), &l);
		if (SQL_SUCCESS != rc) {
			show_Error(SQL_HANDLE_STMT, sqlstate);
			std::cout << "aqui  entro 12" << std::endl;
		}
	}
	else {
		rc = SQLBindParameter(sqlstate, 12, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 3, NULL, sizeof(float), &l);
		if (SQL_SUCCESS != rc) {
			show_Error(SQL_HANDLE_STMT, sqlstate);
			std::cout << "aqui  entro 12" << std::endl;
		}
	
	}

	if (aVF != 0) {
		rc = SQLBindParameter(sqlstate, 13, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 3, &aVF, sizeof(float), &m);
		if (SQL_SUCCESS != rc) {
			show_Error(SQL_HANDLE_STMT, sqlstate);
			std::cout << "aqui  entro 13" << std::endl;
		}
	}
	else {
		rc = SQLBindParameter(sqlstate, 12, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 3, NULL, sizeof(float), &m);
		if (SQL_SUCCESS != rc) {
			show_Error(SQL_HANDLE_STMT, sqlstate);
			std::cout << "aqui  entro 12" << std::endl;
		}
	
	}

	if (CVP != 0) {
		rc = SQLBindParameter(sqlstate, 14, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 3, &CVP, sizeof(float), &n);
		if (SQL_SUCCESS != rc) {
			show_Error(SQL_HANDLE_STMT, sqlstate);
			std::cout << "aqui  entro 14" << std::endl;
		}
	}
	else {
		rc = SQLBindParameter(sqlstate, 14, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 3, NULL, sizeof(float), &n);
		if (SQL_SUCCESS != rc) {
			show_Error(SQL_HANDLE_STMT, sqlstate);
			std::cout << "aqui  entro 14" << std::endl;
		}
	}

	aux.append(sqlupda);
	if (SQL_SUCCESS != SQLExecDirect(sqlstate, (SQLCHAR *)aux.c_str(), SQL_NTS)) {
		show_Error(SQL_HANDLE_STMT, sqlstate);
		std::cout << "aqui  entro 15" << std::endl;
		Close();
	}

}

void AlarmaBD::setHandeEnv(SQLHANDLE envir) {
	this->sqlenvirot = envir;
}


void AlarmaBD::setHandeCon(SQLHANDLE con) {
	this->sqlCon = con;
}



void AlarmaBD::setHandeState(SQLHANDLE stat) {
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
	SQLDisconnect(sqlCon);
	SQLFreeHandle(SQL_HANDLE_DBC, sqlenvirot);
	SQLFreeHandle(SQL_HANDLE_ENV, sqlenvirot);
}

