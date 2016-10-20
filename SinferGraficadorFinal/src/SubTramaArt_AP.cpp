#include "..\Include\SubTramaArt_AP.h"

SubTramaArt_AP::SubTramaArt_AP(uint8_t start[], uint8_t vodi[], uint8_t size[]):SubTramaParam(start,vodi,size) {

}

SubTramaArt_AP::SubTramaArt_AP(SubTramaParam * sub) : SubTramaParam(sub) {

}

SubTramaArt_AP::SubTramaArt_AP(const SubTramaArt_AP &) {


}
SubTramaArt_AP::SubTramaArt_AP(const SubTramaParam & sub) :SubTramaParam(sub) {

}

SubTramaArt_AP::SubTramaArt_AP()
{
}


SubTramaArt_AP::~SubTramaArt_AP()
{
	
}

void SubTramaArt_AP::clasficaSubTra(const std::vector<uint8_t> &datas,int pos) {
	bool ban = true;
	for (int j = pos; j < datas.size() && pos + 3 < datas.size() && ban == true; j++) {
		pos = runData(datas, pos);
		switch (this->val)
		{
		case(8454149):
			pos = loadHight(datas,pos);
			this->band = true;
			break;

		case(8519685):
			pos = loadLow(datas, pos);
			this->band = true;
			break;

		case(8585221):
			pos = loadParentesis(datas, pos);
			this->band = true;
			break;
			case(8650757):
				pos = loadHight(datas, pos);
				this->band = false;
			break;

			case(8716293):
				pos = loadLow(datas,pos);
				this->band = false;
			break;

			case(8781829):
				pos = loadParentesis(datas, pos);
				this->band = false;
				break;

			case(150281):
				ban = false;
				break;
		}

	}
};


int SubTramaArt_AP::runData(const std::vector<uint8_t> &datas,int pos) {
	uint32_t sal = (datas.at(pos++) << 16) | (datas.at(pos++) << 8) | (datas.at(pos++));
	this->val = (int)sal;
	return pos;
}

int SubTramaArt_AP::loadHight(const std::vector<uint8_t> &datas,int pos) {
	printf(" valor de hex %x ", datas.at(pos));
	printf(" %x\n", datas.at(pos + 1));
	uint16_t sal = (datas.at(pos++) << 8) | (datas.at(pos));
	this->alto = (int)sal;
	return ++pos;
}

int SubTramaArt_AP::loadLow(const std::vector<uint8_t> &datas, int pos) {
	//printf(" valor de hex %x ", datas.at(pos));
	//printf(" %x\n", datas.at(pos + 1));
	uint16_t sal = (datas.at(pos++) << 8) | (datas.at(pos));
	this->bajo = (int)sal;
	//std::cout << "esto vale impedancia " << bajo << std::endl;
	return ++pos;
}

int SubTramaArt_AP::loadParentesis(const std::vector<uint8_t> &datas,int pos) {
	printf(" valor de hex %x ", datas.at(pos));
	printf(" %x\n", datas.at(pos + 1));
	uint16_t sal = (datas.at(pos++) << 8) | (datas.at(pos));
	this->parentesis = (int)sal;
	return ++pos;
}

bool SubTramaArt_AP::isBand() {
	return this->band;
}

/// <summary>
/// Dats the tram.
/// </summary>
/// <param name="">The .</param>
/// <returns></returns>

Ap SubTramaArt_AP::datTram(Ap & tip) {
	tip.alto = this->alto;
	tip.bajo = this->bajo;
	tip.parentesis = this->parentesis;
	tip.tipo = "ART.txt";
	return tip;
}


Art SubTramaArt_AP::datTram1(Art & tip2) {
	tip2.alto = this->alto;
	tip2.bajo = this->bajo;
	tip2.parentesis = this->parentesis;
	tip2.tipo = "AP.txt";
	return tip2;
}