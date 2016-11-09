#include "..\Include\Senal_Roja_Amarilla.h"



Senal_Roja_Amarilla::Senal_Roja_Amarilla()
{
}


Senal_Roja_Amarilla::~Senal_Roja_Amarilla()
{


}


Senal_Roja_Amarilla::Senal_Roja_Amarilla(CDatabase *cb) : CRecordset(cb) {



}

CString Senal_Roja_Amarilla::GetDefaultSQL() {
	return _T("senal_roja_amarilla");
}

void Senal_Roja_Amarilla::loadSrA(Store s,SubTramaArt_AP *ap, Monitor1 * mon) {
	Signal sig;
	this->dateTime = s.mpp.getDataTime().c_str();
	this->id = mon->getId();
	if (ap->isBand()) {
		this->senial = 1;//amarilla 
	}else{
		this->senial = 2;//roja
	}
	this->max = ap->getAlto();
	this->min = ap->getBajo();
	this->parentesis = ap->getParentesis();
	for (int i = 0; i < s.mp.getSubTra().size();i++) {
		sig=s.mp.getSubTra().at(i)->datTram(sig);
		if (sig.tipo=="ROJASign.txt" || sig.tipo == "AMARILLASign.txt") {
			this->sig = sig.sign1;
		}
	}
}