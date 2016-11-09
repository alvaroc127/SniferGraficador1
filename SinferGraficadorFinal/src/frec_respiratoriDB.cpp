#include "..\Include\frec_respiratoriDB.h"



frec_respiratoriDB::frec_respiratoriDB(CDatabase *bd) : CRecordset(bd) {


}

frec_respiratoriDB::frec_respiratoriDB()
{
}


frec_respiratoriDB::~frec_respiratoriDB()
{
}



CString frec_respiratoriDB::GetDefaultSQL() {
	return _T("frec_respiratoria");
}

void frec_respiratoriDB::loadFrecRes(Store s,SubTramaImpedancia *imp,Monitor1 *mon ) {
	Signal sig;
	this->dat_Sig = s.mpp.getDataTime().c_str();
	this->impedancia = imp->getimpe();
	this->id = mon->getId();
	for (int i = 0; i < s.mp.getSubTra().size();i++) {
		sig=s.mp.getSubTra().at(i)->datTram(sig);
		if (sig.tipo=="RESPSign.txt") {
			this->sig = sig.sign1;
		}
	}
}