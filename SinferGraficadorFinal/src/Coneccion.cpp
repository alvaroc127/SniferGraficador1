#include "..\Include\Coneccion.h"



Conection::Conection()
{
	
}


Conection::~Conection()
{
}



void Conection::conectar() {
	con = new CDatabase();
	TRY{
	con->OpenEx(_T("DSN=FUCS;UID=pasante1;PSW=sebastian1"),CDatabase::forceOdbcDialog);
	this->mon = new Monitor1(this->con);
	this->ecg = new Ecg(this->con);
	this->alar = new AlarmaBD(this->con);
	this->frec = new frec_respiratoriDB(this->con);
	this->sRa = new Senal_Roja_Amarilla(con);
	hB = new HabitacionDB(con);
	tem = new TemperaturaDB(con);
	}CATCH(CDBException, e) {
		AfxMessageBox(e->m_strError);
		return;
	}
	END_CATCH
}

CDatabase * Conection::getConection() {
	return this->con;
}




void Conection::insertRegisMP (MindrayPacket   mp) {
	if (mp.getDataTime() == this->date) {
		al.mp = mp;
	}
}

void Conection::insertRegisMA( MindrayAlarma  ma) {
	if (ma.getDataTime() == this->date) {
		al.ma = ma;
	}
}


void Conection::inserRegisMPP( MindrayParametros   mpp) {
	this->date = mpp.getDataTime();
	this->Ip = mpp.getFuente();
		al.mpp = mpp;
}


bool Conection::openECG() {
	

	return true;
}


bool Conection::openMonitor() {


	return true;
}

bool Conection::checkStore() {
	bool band=false;
	if ( al.ma.getFuente().empty() == false && al.mp.getFuente().empty() == false && al.mpp.getFuente().empty()==false ) {
		band = true;
	}
	else {
		band = false;
	}
	return band;
}



void Conection::inserTDatBas() {
	loadDatTableMon();
	TRY{
	if (mon->openTabMo()) {
		if (mon->GetRowsFetched() == 0) {
			if (ecg->openTab()) {
				ecg->loadECG(al, mon);
				ecg->AddNew();
				ecg->Update();
			}
			if (al.ma.getSubTra().empty() == false && al.ma.getTipo() == 1 && ecg->isLoad()) {
				for (int i = 0; i < al.ma.getSubTra().size(); i++) {
					for (int j = 0; j < al.ma.getSubTra().at(i)->getMensajes().size(); i++) {
						std::string ms = al.ma.getSubTra().at(i)->getMensajes().at(i);
						alar->loadAlarm(al, mon,ms,ecg);
						alar->AddNew();
						alar->Update();
					}
				}
			}
			if (al.mpp.getSubTra().empty() == false) {
				for (int x = 0; x < al.mpp.getSubTra().size(); x++) {
					SubTramaArt_AP *AP = dynamic_cast<SubTramaArt_AP *> (al.mpp.getSubTra().at(x));
					if (AP != NULL) {
						sRa->loadSrA(al, AP, mon);
						sRa->AddNew();
						sRa->Update();
					}
				}
			}
			if (al.mpp.getSubTra().empty() == false) {
				for (int c = 0; c < al.mpp.getSubTra().size(); c++) {
					SubTramaImpedancia *IM = dynamic_cast<SubTramaImpedancia *>(al.mpp.getSubTra().at(c));
					if (IM != NULL) {
						frec->loadFrecRes(al, IM, mon);
						frec->AddNew();
						frec->Update();
					}
				}
			}
			if (al.mpp.getSubTra().empty() == false) {
				for (int j = 0; j < al.mpp.getSubTra().size(); j++) {
					SubtRamTemp * sue3 = dynamic_cast<SubtRamTemp *> (al.mpp.getSubTra().at(j));
					if (sue3 != NULL) {
						tem->loadTemp(al, sue3, mon);
					}
				}
			}
		}
	this->al.ma.setDtaTime("");
	this->al.mp.setDtaTime("");
	this->al.mpp.setDtaTime("");
	this->al.ma.setFuente("");
	this->al.mp.setFuente("");
	this->al.mpp.setFuente("");
	}
	}CATCH(CDBException ,e) {

	}
	END_CATCH
}

void Conection::setIp(const std::string  & ip) {
	this->Ip = ip;
}


void Conection::setDate(const std::string   & date) {
	this->date = date;
}



void Conection::loadDatTableMon() {
	this->mon->setIp(this->Ip.c_str());
}