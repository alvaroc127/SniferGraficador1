#include "..\Include\AlarmaBD.h"



AlarmaBD::AlarmaBD()
{
}


AlarmaBD::~AlarmaBD()
{
}


AlarmaBD::AlarmaBD(CDatabase * bd) : CRecordset( bd ) {


}

bool AlarmaBD::openTab() {
	bool open = false;
	TRY{
		this->Open();
	open = true;
	}
		CATCH(CDBException, ec) {
		open = false;
	}
	END_CATCH
		return open;
}

CString  AlarmaBD::GetDefaultSQL() {
	return _T("alarm");
}


void AlarmaBD::loadAlarm(Store s,Monitor1 * mon,std::string ms,Ecg *ecg ) {
	this->num_cam = mon->getNumCam();
	this->dateTime = s.mpp.getDataTime().c_str();
	this->alarmSeverity = contChar(ms);
	this->description = ms.c_str();
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
	int con=0;
	for (int i = 0; i < mens.size();i++) {
		if (mens.at(i) == '*') {
			con++;
		}
	}
	return con;
}