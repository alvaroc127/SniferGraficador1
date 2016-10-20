#include "..\Include\SubTramaECG.h"




SubTramaECG::SubTramaECG(const SubTramaECG &) {

}

SubTramaECG::SubTramaECG()
{

}

SubTramaECG::SubTramaECG(uint8_t start[] , uint8_t vodi[], uint8_t size[]):SubTramaParam(start,vodi,size){
	
}


SubTramaECG::~SubTramaECG()
{
	
}

SubTramaECG::SubTramaECG(SubTramaParam * sub):SubTramaParam(sub) {

}

SubTramaECG::SubTramaECG(const SubTramaParam & sub ):SubTramaParam(sub) {

}

int SubTramaECG::runData(const std::vector<uint8_t> &datas,int pos) {
	uint32_t sal = (datas.at(pos++) << 16) | (datas.at(pos++) << 8) | (datas.at(pos++));
	this->val = (int)sal;
	return pos;
}




void SubTramaECG::clasficaSubTra(const std::vector<uint8_t> &datas,int pos) {
	bool ban = true;
	for (int j = pos; j < datas.size() && pos + 3 < datas.size() && ban == true;j++) {
		pos = runData(datas, pos);
	
		switch (this->val) {
		case(65541):
			pos = loadFrecu(datas, pos);
			break;

		case(131077):
			pos = loadCVP(datas, pos);
			break;

		case(328202):
			pos = loadI(datas, pos);
			break;

		case(393738):
			pos = loadII(datas, pos);
			break;

		case(459274):
			pos = loadIII(datas, pos);
			break;

		case(524810):
			pos = loadAVR(datas, pos);
			break;

		case(590346):
			pos = loadAVL(datas, pos);
			break;

		case(655882):
			pos = loadAVF(datas, pos);
			break;


		case(13173258):
			pos = loadV(datas, pos);
			break;

		case(150281):
			ban = false;
			break;
		}
	}
}



int SubTramaECG::loadFrecu(const std::vector<uint8_t> &datas, int pos) {
	uint16_t sal = (datas.at(pos++) << 8) | (datas.at(pos));
	this->frecuencia = (int)sal;
	return ++pos;
}

int SubTramaECG::loadCVP(const std::vector<uint8_t> &datas,int pos) {
	uint16_t sal = (datas.at(pos++) << 8) | (datas.at(pos));
	this->CVP = (int)sal;
	if (this->CVP>32768) {
		CVP = (CVP - 65536) / 100;
	}
	else {
		CVP = CVP / 100;
	}
	return ++pos;
}



int SubTramaECG::loadAVR(const std::vector<uint8_t> &datas, int pos) {
	uint16_t sal = (datas.at(pos++) << 8) | (datas.at(pos));
	this->aVR = (int)sal;
	if (this->aVR>32768) {
		this->aVR = (aVR - 65536) / 100;
	}
	else {
		aVR = aVR / 100;
	}
	return ++pos;
}




int SubTramaECG::loadAVL(const std::vector<uint8_t> &datas, int pos) {
	uint16_t sal = (datas.at(pos++) << 8) | (datas.at(pos));
	this->aVL= (int)sal;
	if (this->aVL>32768) {
		aVL = (aVL - 65536) / 100;
	}
	else {
		aVL = aVL / 100;
	}
	return ++pos;
}


int SubTramaECG::loadAVF(const std::vector<uint8_t> &datas, int pos) {
	uint16_t sal = (datas.at(pos++) << 8) | (datas.at(pos));
	this->aVF = (int)sal;
	if (this->aVF>32768) {
		aVF = (aVF - 65536) / 100;
	}
	else {
		aVF = aVF / 100;
	}
	return ++pos;
}


int SubTramaECG::loadV(const std::vector<uint8_t> &datas, int pos) {
	uint16_t sal = (datas.at(pos++) << 8) | (datas.at(pos));
	this->V = (int)sal;
	if (this->V > 32768) {
		V = (V - 65536) / 100;
	}
	else {
		V = V / 100;
	}
	return ++pos;
}


int SubTramaECG::loadIII(const std::vector<uint8_t> &datas, int pos) {
	uint16_t sal = (datas.at(pos++) << 8) | (datas.at(pos));
	this->III = (int)sal;
	if (this->III>32768) {
		III = (III - 65536) / 100;
	}
	else {
		III = III / 100;
	}
	return ++pos;
}


int SubTramaECG::loadII(const std::vector<uint8_t> &datas, int pos) {
	uint16_t sal = (datas.at(pos++) << 8) | (datas.at(pos));
	this->II = (int)sal;
	if (this->II>32768) {
		II = (II - 65536) / 100;
	}
	else {
		II = II / 100;
	}
	return ++pos;
}


int SubTramaECG::loadI(const std::vector<uint8_t> &datas, int pos) {
	uint16_t sal = (datas.at(pos++) << 8) | (datas.at(pos));
	this->I = (int)sal;
	
	if (this->I>32768) {
		I = (I - 65536) / 100;
	}
	else {
		I = I / 100;
	}
	return ++pos;
}


ECG SubTramaECG::datTram(ECG & tip) {
	 tip.aVF=this->aVF;
	 tip.aVL=this->aVL;
	 tip.aVR=this->aVR;
	 tip.CVP=this->CVP;
	tip.frecuencia=this->frecuencia;
	tip.I=this->I;
	tip.V=this->V;
	 tip.II=this->II;
	 tip.III=this->III;
	 tip.tipo = "ECGPARAM.txt";
	 return tip;
}