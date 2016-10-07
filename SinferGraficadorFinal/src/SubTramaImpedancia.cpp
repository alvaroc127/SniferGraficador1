#include "..\Include\SubTramaImpedancia.h"
#include <iostream>


SubTramaImpedancia::SubTramaImpedancia(uint8_t start[],uint8_t vodi[],uint8_t size[]):SubTramaParam(start,vodi,size) {


}

SubTramaImpedancia::SubTramaImpedancia(const SubTramaImpedancia &a) {

}

SubTramaImpedancia::SubTramaImpedancia(const SubTramaParam & sub) :SubTramaParam(sub) {

}

SubTramaImpedancia::SubTramaImpedancia( SubTramaParam  * sub) : SubTramaParam(sub) {

}

SubTramaImpedancia::SubTramaImpedancia()
{
}


SubTramaImpedancia::~SubTramaImpedancia()
{

}



void SubTramaImpedancia::clasficaSubTra(const std::vector<uint8_t> &datas, int pos){
	bool ban = true;
	for (int j = pos; j < datas.size() && pos + 3 < datas.size() && ban == true; j++) {
		pos = runData(datas, pos);
		std::cout << "valor de sal/*/*/ " << val << std::endl;
		if (this->val == 1114117) {
			pos = loadImpedancia(datas, pos);
		}
		else if (this->val ==  150281) {
			ban = false;
		}
	}
}


int SubTramaImpedancia::runData(const std::vector<uint8_t> &datas, int pos) {
	uint32_t sal = (datas.at(pos++) << 16) | (datas.at(pos++) << 8) | (datas.at(pos++));
	this->val = (int)sal;
	return pos;
}

int SubTramaImpedancia::loadImpedancia(const std::vector<uint8_t> &datas,int pos) {
	printf(" valor de hex %x ", datas.at(pos));
	printf(" %x\n", datas.at(pos+1));
	uint16_t sal = (datas.at(pos++) << 8) | (datas.at(pos));
	this->impedanciaX2 = (int)sal;
	std::cout << "esto vale impedancia " << impedanciaX2 << std::endl;
	return ++pos;
}

/// <summary>
/// Dats the tram.
/// </summary>
/// <param name="">The .</param>
/// <returns></returns>

Impedancia SubTramaImpedancia::datTram(Impedancia &tip) {
	tip.impedanciaX2=this->impedanciaX2;
	tip.tipo = "IMPEPARAM.txt";
	return tip;
}