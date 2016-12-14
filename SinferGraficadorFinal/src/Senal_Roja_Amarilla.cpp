#include "..\Include\Senal_Roja_Amarilla.h"

Senal_Roja_Amarilla::Senal_Roja_Amarilla(const SQLHANDLE  & envi,const  SQLHANDLE & con,const  SQLHANDLE &state) {
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


void Senal_Roja_Amarilla::loadSArt(Monitor1 * mon) {
	this->id = mon->getId();
	readFileParam(mon->getIp()+"\\ART.txt");
	this->sig=readFileSig(mon->getIp()+"\\ROJASign.bin");
	this->senial = 2;
}

void Senal_Roja_Amarilla::loadSAP(Monitor1 *mon) {
	this->id = mon->getId();
	readFileParam(mon->getIp() + "\\AP.txt");
	this->sig = readFileSig(mon->getIp() + "\\AMARILLASign.bin");
	this->senial = 1;
}

void Senal_Roja_Amarilla::setHandeEnv(const SQLHANDLE  & envir) {
	this->sqlenvirot = envir;
}


void Senal_Roja_Amarilla::setHandeCon(const SQLHANDLE & con) {
	this->sqlCon = con;
}



void Senal_Roja_Amarilla::setHandeState(const SQLHANDLE  & stat) {
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
	sqlstate = NULL;
}

void Senal_Roja_Amarilla::insertTabSignalRed_Yell() {
	RETCODE rc;
	char senten[150];
	char sqlupda[150];
	std::string aux = SQLUPDATE;
	SQLLEN a = 0, b = 0, c = 0, d = 0, e = 0;
	sprintf_s(senten, "INSERT INTO Senal_Roja_Amarilla (id , HoraSenal, TipoSenal ) values (%i ,'%i/%i/%i %i:%i:%i.%i', %i)", id , st.year, st.month, st.day, st.hour, st.minute, st.second, st.fraction, senial);
	if (SQL_SUCCESS != SQLExecDirect(sqlstate, (SQLCHAR *)senten, SQL_NTS)) {
		show_Error(SQL_HANDLE_STMT, sqlstate);
		Close();
	}
	sprintf_s(sqlupda, "id = %i AND HoraSenal = '%i/%i/%i %i:%i:%i.%i' AND TipoSenal = %i;", id, st.year, st.month, st.day, st.hour, st.minute, st.second, st.fraction,senial);
	

	rc = SQLBindParameter(sqlstate, 1, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 2, &this->max, sizeof(float), &b);
	if (rc != SQL_SUCCESS) {
		show_Error(SQL_HANDLE_STMT, sqlstate);
		std::cout << "aqui  entro 1" << std::endl;
	}

	rc = SQLBindParameter(sqlstate, 2, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 2, &this->min, sizeof(float), &c);
	if (rc != SQL_SUCCESS) {
		show_Error(SQL_HANDLE_STMT, sqlstate);
		std::cout << "aqui  entro 1" << std::endl;
	}

	rc = SQLBindParameter(sqlstate, 3, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(float), 2, &this->parentesis, sizeof(float), &d);
	if (rc != SQL_SUCCESS) {
		show_Error(SQL_HANDLE_STMT, sqlstate);
		std::cout << "aqui  entro 1" << std::endl;
	}
	if (sig.empty() == false) {
		d = sig.size() - 1;
		rc = SQLBindParameter(sqlstate, 4, SQL_PARAM_INPUT, SQL_C_BINARY, SQL_VARBINARY, 8000, 0, &sig[0], sig.size() - 1, &d);
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
	this->max = 0;
	this->min = 0;
	this->parentesis = 0;
	this->senial = NULL;
	sig.clear();
}


std::vector<uint8_t> Senal_Roja_Amarilla::readFileSig(const std::string &ip) {
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

void Senal_Roja_Amarilla::readFileParam(const std::string  &ip) {
	std::string max;
	std::string min;
	std::string parentesis;
	std::string tipo;
	inFile.open(direcc + ip, std::ifstream::in | std::ifstream::_Nocreate);
	if (!inFile.is_open()) {
		std::cout << "no se pudo abrir" << direcc + ip << std::endl;
	}
	else {
		while (!inFile.eof()) {
			inFile >> max;
			if (max != "") {
				inFile >> min >> parentesis >> tipo;
			}
		}
		if (max != "") {
			this->max = atof(max.c_str());
			this->min = atof(min.c_str());
			this->parentesis = atof(parentesis.c_str());
			this->senial = atoi(tipo.c_str());
		}
	}
	inFile.close();
}


