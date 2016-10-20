#include "..\Include\SubTramaMi.h"
#include <string>

using namespace std;

SubTramaMi::SubTramaMi(const SubTramaMi & sub) {
	
}



SubTramaMi::SubTramaMi()
{

}


SubTramaMi::~SubTramaMi()
{
	datas.erase(datas.begin(), datas.end());
	datas.clear();
}


int SubTramaMi::loadHead(const std::vector<uint8_t> &datas, int pos) {
	int pos1 = 0;
	for (int i = 0; i < datas.size() && i < 4; i++) {
		if (i < 1) {
			this->start[pos1++] = (0x0 << 8) | datas.at(pos++);
		}
		else if (i >= 1 && i < 3) {
			if (i == 1) pos1 = 0;
			this->size[pos1++] = (0x0 << 8) | datas.at(pos++);
		}
		else {
			if (i == 3)pos1 = 0;
			this->end[pos1++] = (0x0 << 8) | datas.at(pos++);
		}
	}
	return pos;
}

int SubTramaMi::sizePSubtrama(){
	uint16_t con = ((this->size[0] << 8) | this->size[1]);
	return (int)con;
}


int SubTramaMi::sizeSub(){
	return lenght(start)+lenght(end)+lenght(this->size);
}

std::string SubTramaMi::joinHeader() {
	uint32_t con = ((this->start[0] << 24) | (this->size[0]<< 16)| (this->size[1]<<8) | this->end[0]);
	return  to_string((long long)con);
}

int SubTramaMi::addData(const std::vector<uint8_t> &datas,int pos, int tam) {
	int cont = 0;
	for (int i = pos; i < datas.size() && cont < tam;i++) {
		this->datas.push_back(datas.at(i));
		pos = i;
		cont++;
	}
	return ++pos;
}

int SubTramaMi::dataSize() {
	return this->datas.size();
}


Signal SubTramaMi::datTram(Signal & sig)
{
	sig.sign1 = this->datas;
	std::string var=joinHeader();

	if (var == "16842753") {
		sig.asignarTipo("ECGSig1.txt");
		sig.tipo = "ECGSig1.txt";
	
		//getchar();
	}
	else if (var == "33619969") {
		sig.asignarTipo("ECGSig2.txt");
		sig.tipo = "ECGSig2.txt";
	}
	else if (var == "117506049") {
		sig.asignarTipo("ECGSig3.txt");
		sig.tipo = "ECGSig3.txt";
	}
	else if (var == "436240385") {
		sig.asignarTipo("RESPSign.txt");
		sig.tipo = "RESPSign.txt";
	}
	else if (var == "419495937") {
		sig.asignarTipo("SPO2Sign.txt");
		sig.tipo = "SPO2Sign.txt";
	}
	else if (var == "520126469") {
		sig.asignarTipo("ROJASign.txt");
		sig.tipo = "ROJASign.txt";
	}
	else if ( var == "520126469") {
		sig.asignarTipo("AMARILLASign.txt");
		sig.tipo = "AMARILLASign.txt";
	}
	return sig;
}


