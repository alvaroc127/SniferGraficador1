#include "..\Include\Senal_Roja_Amarilla.h"

Senal_Roja_Amarilla::Senal_Roja_Amarilla(SQLHANDLE envi, SQLHANDLE con, SQLHANDLE  state) {
	this->sqlenvirot = envi;
	this->sqlCon = con;
	this->sqlstate = state;
}


Senal_Roja_Amarilla::Senal_Roja_Amarilla()
{
}


Senal_Roja_Amarilla::~Senal_Roja_Amarilla()
{


}


void Senal_Roja_Amarilla::loadSrA(Store &s, SubTramaArt_AP *ap, Monitor1 * mon) {
	Signal sig;
	this->dateTime = s.mpp.getDataTime().c_str();
	this->id = mon->getId();
	if (ap->isBand()) {
		this->senial = 1;//amarilla 
	}
	else {
		this->senial = 2;//roja
	}
	this->max = ap->getAlto();
	this->min = ap->getBajo();
	this->parentesis = ap->getParentesis();
	for (int i = 0; i < s.mp.getSubTra().size(); i++) {
		sig = s.mp.getSubTra().at(i)->datTram(sig);
		if (sig.tipo == "ROJASign.txt" || sig.tipo == "AMARILLASign.txt") {
			this->sig = sig.sign1;
		}
	}
}

void Senal_Roja_Amarilla::setHandeEnv(SQLHANDLE envir) {
	this->sqlenvirot = envir;
}


void Senal_Roja_Amarilla::setHandeCon(SQLHANDLE con) {
	this->sqlCon = con;
}



void Senal_Roja_Amarilla::setHandeState(SQLHANDLE stat) {
	this->sqlstate = stat;
}


void Senal_Roja_Amarilla::setTimeStruc(const TIMESTAMP_STRUCT &st) {
	this->st = st;
}



void Senal_Roja_Amarilla::show_Error(unsigned int handle, const SQLHANDLE &han) {
	SQLCHAR sqlstate[1024];
	SQLCHAR sqlmessag[1024];
	if (SQL_SUCCESS == SQLGetDiagRec(handle, han, 1, sqlstate, NULL, sqlmessag, 1024, NULL))
		std::cout << "Mensaje " << sqlmessag << "Estado " << sqlstate << std::endl;
}

void Senal_Roja_Amarilla::Close() {
	SQLFreeHandle(SQL_HANDLE_STMT, sqlstate);
	SQLDisconnect(sqlCon);
	SQLFreeHandle(SQL_HANDLE_DBC, sqlenvirot);
	SQLFreeHandle(SQL_HANDLE_ENV, sqlenvirot);
}

void Senal_Roja_Amarilla::insertTabSignalRed_Yell() {
	RETCODE rc;
	char senten[100];
	char sqlupda[100];
	std::string aux = SQLUPDATE;
	SQLLEN a = 0, b = 0, c = 0, d = 0, e = 0;
	sprintf_s(senten, "INSERT INTO Senal_Roja_Amarilla (id , HoraSenal ) values (%i,'%i/%i/%i %i:%i:%i.%i')", id , st.year, st.month, st.day, st.hour, st.minute, st.second, st.fraction);
	if (SQL_SUCCESS != SQLExecDirect(sqlstate, (SQLCHAR *)senten, SQL_NTS)) {
		show_Error(SQL_HANDLE_STMT, sqlstate);
		Close();
	}
	sprintf_s(sqlupda, "id = %i AND HoraSenal = '%i/%i/%i %i:%i:%i.%i';", id, st.year, st.month, st.day, st.hour, st.minute, st.second, st.fraction);
	rc = SQLBindParameter(sqlstate, 1, SQL_PARAM_INPUT, SQL_C_ULONG, SQL_INTEGER, sizeof(int), 0, &this->senial, sizeof(int), &a);
	if (rc != SQL_SUCCESS) {
		show_Error(SQL_HANDLE_STMT, sqlstate);
		std::cout << "aqui  entro 1" << std::endl;
	}
	rc = SQLBindParameter(sqlstate, 2, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 2, &this->max, sizeof(float), &b);
	if (rc != SQL_SUCCESS) {
		show_Error(SQL_HANDLE_STMT, sqlstate);
		std::cout << "aqui  entro 1" << std::endl;
	}

	rc = SQLBindParameter(sqlstate, 3, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 2, &this->min, sizeof(float), &c);
	if (rc != SQL_SUCCESS) {
		show_Error(SQL_HANDLE_STMT, sqlstate);
		std::cout << "aqui  entro 1" << std::endl;
	}

	rc = SQLBindParameter(sqlstate, 4, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 2, &this->parentesis, sizeof(float), &d);
	if (rc != SQL_SUCCESS) {
		show_Error(SQL_HANDLE_STMT, sqlstate);
		std::cout << "aqui  entro 1" << std::endl;
	}
	if (sig.empty() == false) {
		d = sig.size() - 1;
		rc = SQLBindParameter(sqlstate, 5, SQL_PARAM_INPUT, SQL_C_BINARY, SQL_VARBINARY, 8000, 0, &sig[0], sig.size() - 1, &d);
		if (SQL_SUCCESS != rc) {
			show_Error(SQL_HANDLE_STMT, sqlstate);
			std::cout << "aqui  entro 4" << std::endl;
		}
	}
	else {
		rc = SQLBindParameter(sqlstate, 5, SQL_PARAM_INPUT, SQL_C_BINARY, SQL_VARBINARY, 8000, 0, NULL, 0, &d);
		if (SQL_SUCCESS != rc) {
			show_Error(SQL_HANDLE_STMT, sqlstate);
			std::cout << "aqui  entro 4" << std::endl;
		}
	}
	aux.append(sqlupda);
	if (SQL_SUCCESS != SQLExecDirect(sqlstate, (SQLCHAR *)aux.c_str(), SQL_NTS)) {
		show_Error(SQL_HANDLE_STMT, sqlstate);
		std::cout << "aqui  entro 5" << std::endl;
		Close();
	}

}

void Senal_Roja_Amarilla::loadParam(SubTramaArt_AP *ap,Monitor1 *mon ) {
	this->id = mon->getId();
	if (ap->isBand()) {
		this->senial = 1;//amarilla 
	}
	else {
		this->senial = 2;//roja
	}
	this->max = ap->getAlto();
	this->min = ap->getBajo();
	this->parentesis = ap->getParentesis();
	this->bandPara = true;
}


void Senal_Roja_Amarilla::loadSignal(Signal &sig, Monitor1 *mon) {
	this->sig = sig.sign1;
	bandSig = true;
}

bool Senal_Roja_Amarilla::isLoad() {
	bool retur = false;
	if (bandPara == true && bandSig == true) {
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
				if (false == bandPara && bandSig == true) {
					retur = true;
				}
			}
		}
	}
	return retur;
}

void Senal_Roja_Amarilla::backEstad() {
	bandPara = false;
	bandSig = false;
	sig.clear();
	sig.erase(sig.begin(), sig.end());
}