#include "..\Include\Coneccion.h"


Conection::Conection()
{
	
}


Conection::~Conection()
{
}


void Conection::OpenCo() {
	SQLCHAR retconstring[1024];
	SQLSMALLINT outconstring;
	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV,SQL_NULL_HANDLE,&sqlenvirot)){
		Close();
	}
	else if (SQL_SUCCESS != SQLSetEnvAttr(sqlenvirot,SQL_ATTR_ODBC_VERSION,(SQLPOINTER)SQL_OV_ODBC3,0)) {
		Close();
	}
	else if (SQL_SUCCESS!= SQLAllocHandle(SQL_HANDLE_DBC,sqlenvirot,&sqlCon)) {
		Close();
	}
	switch (SQLDriverConnect(sqlCon, NULL, (SQLCHAR *)TEXT("DSN=FUCS;UID=pasante1;PWD=sebastian1;"),SQL_NTS,retconstring,1024,&outconstring,SQL_DRIVER_NOPROMPT)) {
	
	case SQL_SUCCESS_WITH_INFO:
		show_Error(SQL_HANDLE_DBC, sqlCon);
		break;

	case SQL_INVALID_HANDLE:


	break;
	
	case SQL_ERROR:
		show_Error(SQL_HANDLE_DBC, sqlCon);
		Close();
		break;

	default:
		
		break;
	
	}
 if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, sqlCon, &sqlstate)) {
		Close();
	}
	open = true;
}


void Conection::setIp(const std::string  & ip) {
	this->Ip = ip;
}


void Conection::setDate(const std::string   & date) {
	this->date = date;
}

void Conection::loadDatTableMon() {
	if (mon==NULL) {
		mon = new Monitor1(sqlenvirot, sqlCon, sqlstate);
	}
	else {
		mon->setHandeEnv(sqlenvirot);
		mon->setHandeCon(sqlCon);
		mon->setHandeState(sqlstate);
	}
	this->mon->setIp(this->Ip);
}


void Conection::insertRegisMP(MindrayPacket   mp) {
	if (mp.getDataTime() == this->date) {
		al.mp = mp;
	}
}

void Conection::insertRegisMA(MindrayAlarma  ma) {
	if (ma.getDataTime() == this->date) {
		al.ma = ma;
	}
}


void Conection::inserRegisMPP(MindrayParametros   mpp) {
	this->date = mpp.getDataTime();
	this->Ip = mpp.getFuente();
	al.mpp = mpp;
}

bool Conection::checkStore() {
	bool band = false;
	if (al.ma.getDataTime().empty() ==  false && al.mp.getDataTime().empty() == false && al.mpp.getDataTime().empty() == false) {
		band = true;
	}
	else {
		band = false;
	}
	return band;
}

void Conection::insertaDatTab() {
	QueryMon();
	if (open==false) {
		OpenCo();
	}
	loadTable();
	ecg->setTimeStruc(st);
	ecg->loadECG(al, mon);
	ecg->insertECG();
	ecg->Close();
	open = false;
	std::cout << "has aqui inserto ECG" << std::endl;
	if (al.ma.getSubTra().empty() == false && al.ma.getFuente().empty() == false && al.ma.getTipo() == 1) {
		if (open == false)OpenCo();
		abd->setHandeEnv(sqlenvirot);
		abd->setHandeCon(sqlCon);
		abd->setHandeState(sqlstate);
		abd->setTimeStruc(st);
		for (int i = 0; i < al.ma.getSubTra().size(); i++) {
			for (int j = 0; j < al.ma.getSubTra().at(i)->getMensajes().size(); j++) {
				std::string ms = al.ma.getSubTra().at(i)->getMensajes().at(j);
				abd->loadAlarm(al, mon, ms, ecg);
				abd->insertarTbaAlarma();
			}
		}
		abd->Close();
		open = false;
	}
	std::cout << "esta aqui============" << std::endl;
	if (open == false)OpenCo();
	spoBD->setHandeEnv(sqlenvirot);
	spoBD->setHandeCon(sqlCon);
	spoBD->setHandeState(sqlstate);
	spoBD->setTimeStruc(st);
	std::cout << "cantidad de subtramas en MP! " <<al.mpp.getSubTra().size() << std::endl;
	if (al.mpp.getSubTra().empty() == false) {
		std::cout << "entro SPO2 !!!!!!!!!!!" << std::endl;
		for (int j = 0; j < al.mpp.getSubTra().size(); j++) {
			SubTramSpo2 *spo = dynamic_cast<SubTramSpo2 *>(al.mpp.getSubTra().at(j));
			if (spo != NULL) {
				spoBD->loadSPO2(al, spo, mon);
				spoBD->insertarTablSPO2();
			}
			
		}
		spoBD->Close();
		open = false;
	}
	if (open == false)OpenCo();
	sr->setHandeEnv(sqlenvirot);
	sr->setHandeCon(sqlCon);
	sr->setHandeState(sqlstate);
	sr->setTimeStruc(st);
	if (al.mpp.getSubTra().empty() == false) {
		std::cout << "entro Señal rOJA !!!!! " << std::endl;
		for (int x = 0; x < al.mpp.getSubTra().size(); x++) {
			SubTramaArt_AP *AP = dynamic_cast<SubTramaArt_AP *>(al.mpp.getSubTra().at(x));
			if (AP != NULL) {
				sr->loadSrA(al, AP, mon);
				sr->insertTabSignalRed_Yell();
				//señasl roja amarilla
			}
		}
		sr->Close();
		open = false;
	}
	if (open == false) OpenCo();
	Fres->setHandeEnv(sqlenvirot);
	Fres->setHandeCon(sqlCon);
	Fres->setHandeState(sqlstate);
	Fres->setTimeStruc(st);
	if (al.mpp.getSubTra().empty() == false) {
		std::cout << "entro fRECUENCIA Respit !!!!! " << std::endl;
		for (int c = 0; c < al.mpp.getSubTra().size(); c++) {
			SubTramaImpedancia *IM = dynamic_cast<SubTramaImpedancia *>(al.mpp.getSubTra().at(c));
			if (IM != NULL) {
				Fres->loadFrecRes(al, IM, mon);
				Fres->insertTableFrec_Resp();
			}
		}
		Fres->Close();
		open = false;
	}
	if (open == false) OpenCo();
	tbd->setTimeStruc(st);
	tbd->setHandeEnv(sqlenvirot);
	tbd->setHandeCon(sqlCon);
	tbd->setHandeState(sqlstate);
	if (al.mpp.getSubTra().empty() == false) {
		std::cout << "entro sUBTrMAAtEMP !!!!! " << std::endl;
		for (int j = 0; j < al.mpp.getSubTra().size(); j++) {
			SubtRamTemp * sue3 = dynamic_cast<SubtRamTemp *> (al.mpp.getSubTra().at(j));
			if (sue3 != NULL) {
				tbd->loadTemp(al, sue3, mon);
				tbd->insetTableTempe();
			}
		}
		tbd->Close();
		open = false;
	}
	Close();
}

void Conection::QueryMon() {
	mon->queryMonitor();
	std::cout << mon->getDate() <<"REGISTRO mON"<< std::endl;
	std::cout << mon->getIp()<<"IP MON"<< std::endl;
	std::cout << mon->getNumCam() << "num cam MOn" << std::endl;
	mon->Close();
	open = false;
}

void Conection::loadDate_Ip() {
	this->date = al.mpp.getDataTime();
	this->Ip = al.mpp.getFuente();
}

void Conection::Close() {
	SQLFreeHandle(SQL_HANDLE_STMT, sqlstate);
	SQLDisconnect(sqlCon);
	SQLFreeHandle(SQL_HANDLE_DBC, sqlenvirot);
	SQLFreeHandle(SQL_HANDLE_ENV,sqlenvirot);
}

void Conection::show_Error(unsigned int handle,const SQLHANDLE &han) {
	SQLCHAR sqlstate[1024];
	SQLCHAR sqlmessag[1024];
	if (SQL_SUCCESS == SQLGetDiagRec(handle, han, 1, sqlstate, NULL, sqlmessag, 1024, NULL))
		std::cout << "Mensaje " << sqlmessag << "Estado " << sqlstate << std::endl;
}

void Conection::setStore(const Store & st) {
	this->al = st;
}

void Conection::insertSinAlarm() {
	Signal sig;
	SubTramSpo2 *spo = NULL;
	SubTramaArt_AP *AP = NULL;
	SubTramaImpedancia *IM = NULL;
	SubtRamTemp * sue3 = NULL;
	QueryMon();
	if (open == false) {
		OpenCo();
	}
	loadTable();
	std::cout << "load ecg" << std::endl;
	std::cout << "cantidad de subtramas " << al.mp.getSubTra().size() << std::endl;
	ecg->setTimeStruc(st);
	ecg->loadECG(al, mon);
	std::cout << "load terminado" << std::endl;
	ecg->insertECG();
	ecg->Close();
	std::cout << "hasta aqui inserto ECG" << std::endl;
	open = false;
	if (al.ma.getSubTra().empty() == false && al.ma.getFuente().empty() == false && al.ma.getTipo() == 1) {
		if (open == false)OpenCo();
		abd->setHandeEnv(sqlenvirot);
		abd->setHandeCon(sqlCon);
		abd->setHandeState(sqlstate);
		abd->setTimeStruc(st);
		for (int i = 0; i < al.ma.getSubTra().size(); i++) {
			for (int j = 0; j < al.ma.getSubTra().at(i)->getMensajes().size(); j++) {
				std::string ms = al.ma.getSubTra().at(i)->getMensajes().at(j);
				abd->loadAlarm(al, mon, ms, ecg);
				abd->insertarTbaAlarma();
			}
		}
		abd->Close();
		open = false;
	}
	if (open == false)OpenCo();
	setHeaders();
	/*
	validacion de los dos tipos si existe uno puede que no exista el otroy vicebersa
	*/
	if (al.mp.getSubTra().empty() == false) {
		for (int i = 0; i < al.mp.getSubTra().size(); i++) {
			sig = al.mp.getSubTra().at(i)->datTram(sig);
			if (sig.tipo == "SPO2Sign.txt") {
				std::cout << "*****------Entro--SPO2-----*****" << std::endl;
				spoBD->loadSignal(sig, mon);
			}
			else {
				if (sig.tipo == "ROJASign.txt" || sig.tipo == "AMARILLASign.txt") {
					std::cout << "*****------Entro--Segnal-----*****" << std::endl;
					sr->loadSignal(sig, mon);
				}
				else {
					if (sig.tipo == "RESPSign.txt") {
						std::cout << "*****------Entro--REspSig-----*****" << std::endl;
						Fres->loadSignal(sig, mon);
					}
					else {
						//no temperatura sign

					}
				}
			}
		}
	}
	if (al.mpp.getSubTra().empty() == false) {
		for (int j = 0; j < al.mpp.getSubTra().size(); j++) {
			spo = dynamic_cast<SubTramSpo2 *>(al.mpp.getSubTra().at(j));
			std::cout << "validando" << std::endl;
			if (spo != NULL) {
				std::cout << "|||||ENTRO SPO2||||||" << std::endl;
				spoBD->loadParametros(spo, mon);
			}
			else {
				AP = dynamic_cast<SubTramaArt_AP *>(al.mpp.getSubTra().at(j));
				if (AP != NULL) {
					sr->loadParam(AP, mon);
				}
				else {
					IM = dynamic_cast<SubTramaImpedancia *>(al.mpp.getSubTra().at(j));
					if (IM != NULL) {
						Fres->LoadParam(IM, mon);
					}
					else {
						sue3 = dynamic_cast<SubtRamTemp *>(al.mpp.getSubTra().at(j));
						if (sue3 != NULL) {
							tbd->loadParam(sue3, mon);
						}
					}

				}

			}
		}
	}
	if (spoBD->isLoad()) {
		spoBD->insertarTablSPO2();
		spoBD->Close();
		std::cout << "|||||inserto SPO2||||||" << std::endl;
		open = false;
		if (open == false)OpenCo();
		setHeaders();
		spoBD->backEstad();
	}

	if (sr->isLoad()) {
		sr->insertTabSignalRed_Yell();
		std::cout << "|||||inserto amarilla||||||" << std::endl;
		sr->Close();
		open = false;
		if (open == false)OpenCo();
		setHeaders();
		sr->backEstad();
	}

	if (Fres->isLoad()) {
		Fres->insertTableFrec_Resp();
		std::cout << "|||||inserto FrecRespiratoia||||||" << std::endl;
		Fres->Close();
		open = false;
		if (open == false)OpenCo();
		setHeaders();
		Fres->backEstad();
	}
	if (sue3!= NULL){
		tbd->insetTableTempe();
		std::cout << "|||||inserto Tablaempleado||||||" << std::endl;
		tbd->Close();
		}
		Close();
		std::cout << "cierre BD"<<std::endl;
	open = false;
}


std::string Conection::getDataTime() {
		return this->date;
}

std::string Conection::getFuente() {
	return this->Ip;
}



bool Conection::isOpen() {
	return open;
}

void Conection::setTimeStruc(const TIMESTAMP_STRUCT &st) {
	this->st = st;
}

void Conection::loadTable() {
	if (ecg == NULL) {
		ecg = new Ecg(sqlenvirot, sqlCon, sqlstate);
	}
	else {
		ecg->setHandeEnv(sqlenvirot);
		ecg->setHandeCon(sqlCon);
		ecg->setHandeState(sqlstate);
	}
	if (Fres == NULL) {
		Fres = new frec_respiratoriDB(sqlenvirot, sqlCon, sqlstate);
	}
	else {
		Fres->setHandeEnv(sqlenvirot);
		Fres->setHandeCon(sqlCon);
		Fres->setHandeState(sqlstate);
	}
	if (abd == NULL) {
		abd = new AlarmaBD(sqlenvirot, sqlCon, sqlstate);
	}
	else {
		abd->setHandeEnv(sqlenvirot);
		abd->setHandeCon(sqlCon);
		abd->setHandeState(sqlstate);
	}
	if (tbd == NULL) {
		tbd = new TemperaturaDB(sqlenvirot, sqlCon, sqlstate);
	}
	else {
		tbd->setHandeEnv(sqlenvirot);
		tbd->setHandeCon(sqlCon);
		tbd->setHandeState(sqlstate);
	
	}

	if (sr==NULL) {
		sr = new Senal_Roja_Amarilla(sqlenvirot, sqlCon, sqlstate);
	}
	else {
		sr->setHandeEnv(sqlenvirot);
		sr->setHandeCon(sqlCon);
		sr->setHandeState(sqlstate);
	}

	if (spoBD == NULL) {
		spoBD = new SPO2BD(sqlenvirot, sqlCon, sqlstate);
	
	}
	else {
		spoBD->setHandeEnv(sqlenvirot);
		spoBD->setHandeCon(sqlCon);
		spoBD->setHandeState(sqlstate);
	}
	

}

void Conection::setHeaders() {
	spoBD->setHandeEnv(sqlenvirot);
	spoBD->setHandeCon(sqlCon);
	spoBD->setHandeState(sqlstate);
	spoBD->setTimeStruc(st);
	sr->setHandeEnv(sqlenvirot);
	sr->setHandeCon(sqlCon);
	sr->setHandeState(sqlstate);
	sr->setTimeStruc(st);
	Fres->setHandeEnv(sqlenvirot);
	Fres->setHandeCon(sqlCon);
	Fres->setHandeState(sqlstate);
	Fres->setTimeStruc(st);
}