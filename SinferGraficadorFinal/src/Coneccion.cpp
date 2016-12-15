#include "..\Include\Coneccion.h"


Conection::Conection()
{
	
}


Conection::~Conection()
{
}

void Conection::loadOtherDat() {
	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, sqlCon, &sqlstate)) {
		Close();
	}
	open1 = true;
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
	try {
		QueryMon();
		if (open1 == false) {
			loadOtherDat();
		}
		loadTable();
		ecg->setTimeStruc(st);
		ecg->loadECG(mon);
		ecg->insertECG();
		ecg->Close();
		if (ga.sizeFile1(direcc + mon->getIp() + "\\ALARMAMEN.txt") == 0) {
			ecg->backEstad();
		}
		open1 = false;
		if (open1==false) {
			loadOtherDat();
		}
		loadTable();
		Fres->setTimeStruc(st);
		Fres->loadFrecRes(mon);
		Fres->insertTableFrec_Resp();
		Fres->Close();
		Fres->backEstad();
		open1 = false;
		if (open1 == false) {
			loadOtherDat();
		}
		loadTable();
		spoBD->setTimeStruc(st);
		spoBD->loadSPO2(mon);
		spoBD->insertarTablSPO2();
		spoBD->Close();
		spoBD->backEstad();
		open1 = false;
		if (open1==false) {
			loadOtherDat();
		}
		loadTable();
		sr->setTimeStruc(st);
		if (ga.sizeFile1(direcc + mon->getIp()+"\\ART.txt") > 0 || ga.sizeFile1(direcc+ mon->getIp()+"\\ROJASign.bin") > 0 ) {
			sr->loadSArt(mon);
			sr->insertTabSignalRed_Yell();
		}
		sr->backEstad();
		sr->Close();
		open1 = false;
		if (open1 == false) {
			loadOtherDat();
		}
		loadTable();
		if (ga.sizeFile1(direcc + mon->getIp() + "\\AP.txt") > 0||ga.sizeFile1(direcc + mon->getIp() + "\\AMARILLASign.bin") > 0) {
				sr->loadSAP(mon);
				sr->insertTabSignalRed_Yell();
		}
		sr->Close();
		sr->backEstad();
		open1 = false;
		if (open1 == false) {
			loadOtherDat();
		}
		loadTable();
		tbd->setTimeStruc(st);
		if (ga.sizeFile1(direcc + mon->getIp() + "\\TEMPPARAM.txt") > 0) {
			tbd->loadTemp(mon);
			tbd->insetTableTempe();
		}
		tbd->Close();
		tbd->backEstad();
		open1 = false;
		if (open1 == false) {
			loadOtherDat();
		}
		loadTable();
		abd->setTimeStruc(st);
		if (ga.sizeFile1(direcc + mon->getIp()+"\\ALARMAMEN.txt") > 0) {
			abd->loadMens(mon->getIp() + "\\ALARMAMEN.txt");
			for (int i = 0 ; i < abd->getMensajes().size() ;i++) {
				if (open1 == false) {
					loadOtherDat();
				}
				loadTable();
				aidbd->setSeveri(abd->contChar(abd->getMensajes().at(i)));
				aidbd->setDescrip(abd->getMensajes().at(i));
				if (aidbd->queryAlarmaIDBD() == false) {//no existe el registro alarmaID
					aidbd->Close();
					open1 = false;
					if (open1 == false) {
						loadOtherDat();
					}
					loadTable();
					aidbd->insertAlarmaID();
					aidbd->Close();
					open1 = false;
					if (open1 == false) {
						loadOtherDat();
					}
					loadTable();
					abd->loadAlarm(mon, ecg,aidbd);
					abd->insertarTbaAlarma(); 
					abd->Close();
					open1 = false;
				}
				else {//el regitro exist
					aidbd->Close();
					open1 = false;
					if (open1 == false) {
						loadOtherDat();
					}
					loadTable();
					abd->loadAlarm(mon, ecg,aidbd);
					abd->insertarTbaAlarma();
					abd->Close();
					open1 = false;
				}
			}
			abd->clearMensajes();
			open1 = false;
		}
	}
	catch (const std::bad_alloc &ba) {
		std::cerr << "error de memori"<< ba.what() << std::endl;
	}
}

void Conection::QueryMon() {
	mon->queryMonitor();
	mon->Close();
	open1 = false;
}

void Conection::loadDate_Ip() {
	this->date = al.mpp.getDataTime();
	this->Ip = al.mpp.getFuente();
}

void Conection::Close() {
	SQLFreeHandle(SQL_HANDLE_STMT, sqlstate);
	sqlstate = NULL;
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
		ecg->setHandeState(sqlstate);
	}

	if (Fres == NULL) {
		Fres = new frec_respiratoriDB(sqlenvirot, sqlCon, sqlstate);
	}
	else {
		Fres->setHandeState(sqlstate);
	}
	if (spoBD == NULL) {
		spoBD = new SPO2BD(sqlenvirot, sqlCon, sqlstate);

	}
	else {
		spoBD->setHandeState(sqlstate);
	}
	if (tbd == NULL) {
		tbd = new TemperaturaDB(sqlenvirot, sqlCon, sqlstate);
	}
	else {
		tbd->setHandeState(sqlstate);

	}

	if (sr == NULL) {
		sr = new Senal_Roja_Amarilla(sqlenvirot, sqlCon, sqlstate);
	}
	else {
		sr->setHandeState(sqlstate);
	}
	if (tbd == NULL) {
		tbd = new TemperaturaDB(sqlenvirot, sqlCon, sqlstate);
	}
	else {
		tbd->setHandeState(sqlstate);
	}
	if (abd==NULL) {
		abd = new AlarmaBD(sqlenvirot, sqlCon, sqlstate);
	
	}else{
		abd->setHandeState(sqlstate);
	}
	if (aidbd == NULL) {
		aidbd = new AlarmaIDBD(sqlenvirot, sqlCon, sqlstate);
	}
	else {
		aidbd->setHandeState(sqlstate);
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

bool Conection::isConect2(){
	return open1;
}