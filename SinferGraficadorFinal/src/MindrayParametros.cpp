#include "..\Include\MindrayParametros.h"
#include "..\Include\SubTramaArt_AP.h"
#include "..\Include\SubTramaECG.h"
#include "..\Include\SubTramaImpedancia.h"
#include "..\Include\SubtRamTemp.h"
#include "..\Include\SubTramSpo2.h"

using namespace std;

MindrayParametros::MindrayParametros()
{};


MindrayParametros::MindrayParametros(const MindrayParametros &)
{};

MindrayParametros::~MindrayParametros()
{
	
	this->head.~HeaderTram();
	this->subtrmas.erase(subtrmas.begin(), subtrmas.end());
	this->subtrmas.clear();
	this->fuente.clear();
	this->data_time.clear();
};


int MindrayParametros::carfarSubTram(const std::vector<uint8_t> &datas, int pos) {
	int tama = 0;
	SubTramaParam sub;
	pos=sub.loadHead(datas, pos);
	tama = sub.sizePSubtrama();
	//cout << "esto es cabeza sub [][][][][]" << sub.joinHeader() << endl;
	//cout << "esto vale tama ??" << tama <<"¡¡??esto vale tam +++"<<this->tam<< endl;
	//code type
	//cout << "retorno /*/" << sub.seleccionMetod(codeType(datas, pos)) << endl;
	if (sub.seleccionMetod(codeType(datas,pos))==0) {
		SubTramaECG *su=new SubTramaECG(sub);
		 su->clasficaSubTra(datas,pos);
		 //cout << "esto es pos " << pos<<" esto es size"<<su.sizePSubtrama()<<"esto es la otra "<<sub.sizePSubtrama()<<endl;
		 pos = su->addData(datas, pos, su->sizePSubtrama());
		 this->tam+= tama + su->sizeSub();
		 //cout << "pos "<<pos << "esto es tam " << tam << "esto es tama " << tama << "su size ECGGGGG " << su.sizeSub() << endl;
		 this->subtrmas.push_back(su);
	}
	else if (sub.seleccionMetod(codeType(datas,pos))==1) {
		SubTramaImpedancia *su1= new SubTramaImpedancia(sub);
		su1->clasficaSubTra(datas, pos);
		su1->setSiz(sub.sizeSub());
		pos = su1->addData(datas, pos, su1->sizePSubtrama());
		this->tam+= tama + su1->sizeSub();
		//cout << "esto es tam" << tam << "esto es tama " << tama << "su size IMPEDANCIA " << su1.sizeSub() << endl;
		this->subtrmas.push_back(su1);
	}
	else if (sub.seleccionMetod(codeType(datas, pos))==2){
		SubtRamTemp *su2=new SubtRamTemp(sub);
		su2->clasficaSubTra(datas,pos);
		su2->setSiz(sub.sizeSub());
		pos = su2->addData(datas, pos, su2->sizePSubtrama());
		this->tam+= tama + su2->sizeSub();
		//cout << "esto es tam" << tam << "esto es tama " << tama << "su size TramaT " << su2.sizeSub() << endl;
		this->subtrmas.push_back(su2);
		//su2.~SubtRamTemp();
	}
	else if (sub.seleccionMetod(codeType(datas, pos))==3) {
		SubTramSpo2 *su3=new SubTramSpo2(sub);
		su3->clasficaSubTra(datas, pos);
		su3->setSiz(sub.sizeSub());
		//sub.~SubTramaParam();
		pos = su3->addData(datas,pos,su3->sizePSubtrama());
		this->tam+= tama + su3->sizeSub();
		//cout << "esto es tam" << tam << "esto es tama " << tama << "su size SPO2 " << su3.sizeSub() << endl;
		this->subtrmas.push_back(su3);
		//su3.~SubTramSpo2();
	}
	else if (sub.seleccionMetod(codeType(datas, pos)) == 5 || sub.seleccionMetod(codeType(datas, pos)) == 6) {
		SubTramaArt_AP *su4=new SubTramaArt_AP(sub);
		su4->clasficaSubTra(datas, pos);
		su4->setSiz(sub.sizeSub());
		pos = su4->addData(datas, pos, su4->sizePSubtrama());
		this->tam+= tama + su4->sizeSub();
		//cout << "esto es tam" << tam << "esto es tama " << tama << "su size  Art AP" << su4.sizeSub() << endl;
		this->subtrmas.push_back(su4);
	}
	else {
		SubTramaParam *pa = new SubTramaParam(sub);
		pos = pa->addData(datas, pos,pa->sizePSubtrama());
		this->tam+= tama + pa->sizeSub();
		this->subtrmas.push_back(pa);
		//delete sub;
		//cout << "esto es tam" << tam << "esto es tama " << tama << "su size  " << sub.sizeSub() << endl;
		//cout <<"pos*/-/-*/-*/-*/-/*" << pos << endl;
		//cout << "aqui " << sub.sizeSub() <<" valor" <<this->tam<< endl;
	}
	return pos;
};

int MindrayParametros::clasifyData(const vector<uint8_t> &datas, int pos) {
	int tam1 = head.sizePacket();
	pos = this->head.loadHead(datas, pos);
	this->tam = head.cantPacket(1);
	do{
		pos=carfarSubTram(datas, pos);
		//cout <<"/*-*-//-acun tan"<<this->tam<<"/**/*- tam head"<< tam1 << endl;
		//getchar();
		cout.clear();
	} while (this->tam < tam1);
	this->tam = 0;
	return pos;
};




std::string MindrayParametros::getFuente() {
	return this->fuente;
}


void MindrayParametros::setFuente(const std::string &fuente) {
	this->fuente =fuente;
}

void MindrayParametros::setDtaTime(const std::string &data_Time) {
	this->data_time =data_Time;
}

 std::string MindrayParametros::getDataTime() {
	return this->data_time;
}

 HeaderTram  MindrayParametros::getHead() {
	return this->head;
}

void MindrayParametros::setHead(const HeaderTram &hed) {
	this->head = hed;
}

int MindrayParametros::codeType(const std::vector<uint8_t> &datas,int pos) {
	uint32_t sal =(datas.at(pos++) << 16) | (datas.at(pos++) << 8) | (datas.at(pos++));
	return (int)sal;
}

std::vector<SubTramaParam *> MindrayParametros::getSubTra() {
	return this->subtrmas;
}


MindrayParametros *  MindrayParametros::clone() {
	return new MindrayParametros(*this);
}

