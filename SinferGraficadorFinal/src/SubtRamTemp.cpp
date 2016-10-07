#include "..\Include\SubtRamTemp.h"
#include <iostream>




SubtRamTemp::SubtRamTemp( SubTramaParam * sub) :SubTramaParam(sub) {

}


SubtRamTemp::SubtRamTemp()
{
}

SubtRamTemp::SubtRamTemp(uint8_t start[],uint8_t vodi[],uint8_t size[]) :SubTramaParam(start,vodi,size) {


}


SubtRamTemp::~SubtRamTemp()
{
	

}


SubtRamTemp::SubtRamTemp(const SubTramaParam & sub) :SubTramaParam(sub) {

}

void SubtRamTemp::clasficaSubTra(const std::vector<uint8_t> &datas,int pos) {
	bool ban = true;
	for (int j = pos; j < datas.size() && pos + 3 < datas.size() && ban == true; j++) {
		pos = runData(datas, pos);
		switch (this->val) {
			case(2294026):
				pos = loadT1(datas,pos);
			break;

			case(2359562):
				pos = loadT2(datas, pos);
			break;

			case(2425098):
				pos = loadTD(datas,pos);
				break;

			case(150281):
				ban = false;
				break;
		}	
		
	}
}

int SubtRamTemp::runData(const std::vector<uint8_t> &datas,int pos) {
	uint32_t sal = (datas.at(pos++) << 16) | (datas.at(pos++) << 8) | (datas.at(pos++));
	this->val = (int)sal;
	return pos;
}

int SubtRamTemp::loadT1(const std::vector<uint8_t> &datas,int pos) {
	printf(" valor de hex %x ", datas.at(pos));
	printf(" %x\n", datas.at(pos + 1));
	uint16_t sal = (datas.at(pos++) << 8) | (datas.at(pos));
	this->T1 = (int)sal;
	if (this->T1>32768) {
		this->T1 = this->T1 - 65536;
		T1 = T1 / 100;
	}
	else {
		T1 = T1 / 100;
	}
	return ++pos;
}

int SubtRamTemp::loadT2(const std::vector<uint8_t> &datas, int pos) {
	printf(" valor de hex %x ", datas.at(pos));
	printf(" %x\n", datas.at(pos + 1));
	uint16_t sal = (datas.at(pos++) << 8) | (datas.at(pos));
	this->T2 = (int)sal;
	std::cout << "esto vale impedancia " << T2 << std::endl;
	if (this->T2>32768) {
		T2 = T2 - 65536;
		T2 = T2 / 100;
	}
	else {
		T2 = T2 / 100;
	}
	return ++pos;
}

int SubtRamTemp::loadTD(const std::vector<uint8_t> &datas, int pos) {
	uint16_t sal = (datas.at(pos++) << 8) | (datas.at(pos));
	this->TD = (int)sal;
	if (this->TD>32768) {
		TD = TD - 65536;
		TD = TD / 100;
	}
	else {
		TD = TD / 100;
	}
	return ++pos;
}

/// <summary>
/// Dats the tram.
/// </summary>
/// <param name="">The .</param>
/// <returns></returns>

Temp SubtRamTemp::datTram(Temp &tip) {
	tip.T1=this->T1;
	tip.T2=this->T2;
	tip.TD=this->TD;
	tip.tipo="TEMPPARAM.txt";
	return tip;
}