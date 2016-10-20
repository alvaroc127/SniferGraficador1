#include "..\Include\SubTramSpo2.h"


SubTramSpo2::SubTramSpo2( SubTramaParam * sub) :SubTramaParam(sub) {

}

SubTramSpo2::SubTramSpo2(const SubTramaParam & sub) :SubTramaParam(sub) {

}

SubTramSpo2::SubTramSpo2(uint8_t start[],uint8_t vodi[],uint8_t size[]) :SubTramaParam(start,vodi,size){



}

SubTramSpo2::SubTramSpo2()
{
}


SubTramSpo2::~SubTramSpo2()
{
}

void SubTramSpo2::clasficaSubTra(const std::vector<uint8_t> &datas, int pos) {
	bool ban = true;
	for (int j = pos; j < datas.size() && pos + 3 < datas.size() && ban == true; j++) {
		pos = runData(datas, pos);
		switch (this->val)
		{
		case(1179653):
			pos = loadDato1(datas,pos);
		break;

		case(1245189):
			pos = loadFrequency(datas, pos);
		break;

		case(150281):
			ban = false;
		break;
		}
		
	}
}


int SubTramSpo2::loadDato1(const std::vector<uint8_t> &datas,int pos) {
	uint16_t sal = (datas.at(pos++) << 8) | (datas.at(pos));
	this->dato1 = (int)sal;
	if (this->dato1>32768) {
		dato1 =dato1 - 65536;
		dato1 = dato1 / 100;
	}
	else {
		dato1 = dato1 / 100;
	}
	return ++pos;

}

int SubTramSpo2::loadFrequency(const std::vector<uint8_t> &datas,int pos) {
	uint16_t sal = (datas.at(pos++) << 8) | (datas.at(pos));
	this->frecuencia = (int)sal;
	if (this->frecuencia>32768) {
		frecuencia = frecuencia - 65536;
		frecuencia = frecuencia / 100;
	}
	else {
		frecuencia = frecuencia / 100;
	}
	return ++pos;
}

int SubTramSpo2::runData(const std::vector<uint8_t> &datas, int pos) {
	uint32_t sal = (datas.at(pos++) << 16) | (datas.at(pos++) << 8) | (datas.at(pos++));
	this->val = (int)sal;
	return pos;
}

/// <summary>
/// Dats the tram.
/// </summary>
/// <param name="">The .</param>
/// <returns></returns>

SPO2 SubTramSpo2::datTram(SPO2 &tip) {
	tip.dato1=this->dato1;
	tip.frecuencia=this->frecuencia;
	tip.tipo="SPO2PARAM.txt";
	return tip;
}