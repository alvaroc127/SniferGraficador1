#include "..\Include\MindrayAlarma.h"
#include <iostream>


MindrayAlarma::MindrayAlarma(const MindrayAlarma &a) {


}

MindrayAlarma::MindrayAlarma()
{
	
}


MindrayAlarma::~MindrayAlarma()
{
	this->head.~HeaderTram();
	this->subtra.erase(subtra.begin(), subtra.end());
	this->subtra.clear();
	this->fuente.clear();
	this->date_time.clear();
}

int MindrayAlarma::carfarSubTram(const std::vector<uint8_t> &datas,int pos) {
	int tama = 0;
	SubTramaAlarma *sub=new SubTramaAlarma;
	pos = sub->loadHead(datas, pos);
	tama = sub->sizePSubtrama();
	std::cout << "uso " << sub->joinHeader()<<"tamanio "<<tama<< std::endl;
	std::cout << "tam " << this->tam << "tamanio " << tama << std::endl;
	if (sub->joinHeader() == "10190000" || sub->joinHeader() == "10790000") {
		pos = sub->loadCant(datas, pos);
		//printf("el valor actual en datas es %X\n", datas.at(pos));
		//printf("y el siguiente %X\n", datas.at(pos + 1));
		if (sub->getCant()>0) {
			pos = sub->loadTam(datas,pos);
			//printf("el valor actual en datas es %X\n", datas.at(pos));
			//printf("y el siguiente %X\n", datas.at(pos + 1));
			sub->cargarMensaje(datas, pos, tama);
			pos = sub->addData(datas, pos-4, tama);
			this->tam += tama + sub->sizeSub();
		}
		else {
			this->tam += tama + sub->sizeSub();
		}

	}
	else {
		pos = sub->addData(datas, pos, tama);
		//printf("el valor actual en datas es %X\n", datas.at(pos));
		//printf("y el siguiente %X\n", datas.at(pos + 1));
		std::cout << "tam" << tam << std::endl;
		this->tam+= tama + sub->sizeSub();
	}
	subtra.push_back(sub);
	return pos;
}



int MindrayAlarma::clasifyData(const std::vector<uint8_t> &datas,int pos) {
	int tma = 0;
	pos = this->head.loadHead(datas, pos);
	tma = head.sizePacket();
	this->tam = head.cantPacket(1);
	//std::cout << "tam" << tam << std::endl;
	//printf("el valor actual en datas es %X\n", datas.at(pos)); 
	//printf("y el siguiente %X\n", datas.at(pos + 1));
	do {
		pos = carfarSubTram(datas, pos);
		//std::cout << "tma" << tma << std::endl;
		//std::cout << "tam" << tam << std::endl;
	} while (this->tam < tma);
	this->tam = 0;
	//cout << "tam paquete : "<< this->head.sizePacket() << endl;
	return pos;
}

int MindrayAlarma::getTipo(int tip) const {
	return tip + 2;
}

std::string MindrayAlarma::getFuente() {
	return this->fuente;
}


void  MindrayAlarma::setFuente(const std::string fuent){
	this->fuente = fuent;
}


void MindrayAlarma::setDtaTime(const std::string datT) {
	this->date_time = datT;
}



HeaderTram MindrayAlarma::getHead() {
	return this->head;
}

std::string MindrayAlarma::getDataTime() {
	return this->date_time;
}


void MindrayAlarma::setHead(const HeaderTram &het) {
	this->head = het;
}

void MindrayAlarma::setTipo(int tp) {
	this->tip = tp;
}

std::vector<SubTramaAlarma *> MindrayAlarma::getSubTra() {
	return this->subtra;
}

