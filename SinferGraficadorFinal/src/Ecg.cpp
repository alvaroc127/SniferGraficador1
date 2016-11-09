#include "..\Include\Ecg.h"



Ecg::Ecg(CDatabase * bd) : CRecordset(bd) {
	this->aVF = 0;
	this->aVL = 0;
	this->aVR = 0;
	this->date_sig = "";
	this->ECG1.clear();
	this->ECG2.clear();
	this->ECG3.clear();
	this->fre_Card = 0;
	this->I=0;
	this->II=0;
	this->III=0;
	this->V=0;
	this->CVP = 0;
	this-> id = 0;

}

Ecg::Ecg(){


}


Ecg::~Ecg(){

}

void Ecg::loadECG( Store  s, Monitor1 *mon) {
	Signal sig;
	ECG ecg;
	this->id = mon->getId();
	date_sig = s.mpp.getDataTime().c_str();
	for (int i = 0; i < s.mp.getSubTra().size();i++) {
		sig=s.mp.getSubTra().at(i)->datTram(sig);
		if (sig.tipo=="ECG1.txt") {
			this->ECG1 = sig.sign1;
		}
		else if (sig.tipo=="ECG2.txt") {
			this->ECG2 = sig.sign1;
		}
		else if (sig.tipo=="ECG3.txt") {
			this->ECG3 = sig.sign1;
		}
	}
	for (int a = 0; a < s.mpp.getSubTra().size();a++) {
		SubTramaECG * sue = dynamic_cast<SubTramaECG *> (s.mpp.getSubTra().at(a));
		if (sue!= NULL) {
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
		}
	}
}


CString Ecg::GetDefaultSQL() {
	return _T("ECG");
}



bool Ecg::openTab() {
	bool open=false;
	TRY {
		this->Open();
		open = true;
	}
	CATCH (CDBException, ec) {
		open = false;
	}
	END_CATCH
	return open;
}

bool Ecg::isLoad() {
	bool ban = id != 0 ? true : false;
	return ban;
}


std::vector<uint8_t> Ecg::getEcg1() {
	return this->ECG1;
}

std::vector<uint8_t> Ecg::getEcg2() {
	return this->ECG2;
}

std::vector<uint8_t> Ecg::getEcg3() {
	return this->ECG3;
}
 
float Ecg::getAvr() {

	return  this->aVR;
}


float Ecg::getAvl() {
	return this->aVL;

}

float Ecg::getI() {
	return this->I;

}



float Ecg::getII() {

	return  this->II;
}


float Ecg::getIII() {
	return this->III;
}


float Ecg::getV() {
	return V;
}


float  Ecg::getaVF() {
	return aVF;
}


float Ecg::getCVP() {
	return this->CVP;
}


float Ecg::getFrec_Cardi() {
	return this->fre_Card;
}