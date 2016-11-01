#include "..\Include\Ecg.h"



Ecg::Ecg(CDatabase * bd) : CRecordset(bd) {


}

Ecg::Ecg(){


}


Ecg::~Ecg(){

}

void Ecg::loadECG( MindrayPacket & mp) {
	date_sig = mp.getDataTime();
	


}
