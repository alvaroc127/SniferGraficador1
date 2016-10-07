#include "..\Include\SubTramaAlarma.h"
#include <iostream>


SubTramaAlarma::SubTramaAlarma()
{
}


SubTramaAlarma::~SubTramaAlarma()
{
	this->mensajes.erase(mensajes.begin(), mensajes.end());
	mensajes.clear();
}

SubTramaAlarma::SubTramaAlarma(const SubTramaAlarma &a) {

}


SubTramaAlarma::SubTramaAlarma(const SubTramaParam &sub):SubTramaParam(sub) {




}

void SubTramaAlarma::cargarMensaje(const std::vector<uint8_t> &datas, int pos, int tam) {
	std::string mens;
	int cont=0;
	for (int i = 4; i <tam;i++) {
		if (cont<getTam()) {
			mens += (char)datas.at(pos++);
			printf(" tamaño hex %x",this->tam[0]);
			printf("%x\n",this->tam[1]);
			std::cout << "mensaje -*/*-" << mens << std::endl;
			std::cout << "el tamaño es" << getTam() << " cont es " << cont << std::endl;
			cont++;
		}
		else  if(cont>=getTam() && getCant()>1){
			if (cont == getTam()) {
				pos=loadTam(datas, pos);
				this->mensajes.push_back(mens);
				std::cout << "mensaje /**/*" << mens << std::endl;
				std::cout << "el tamaño total" << tam << " i es " << i << std::endl;
				mens.clear();
				cont = 0;
			}

		}
	
	}
}

int SubTramaAlarma::loadCant(const std::vector<uint8_t> &datas, int pos){
	this->cant[0] = datas.at(pos++);
	this->cant[1] = datas.at(pos++);
	return pos;
}


int SubTramaAlarma::loadTam(const std::vector<uint8_t> &datas, int pos) {
	this->tam[0] = datas.at(pos++);
	this->tam[1] = datas.at(pos++);
	return pos;
}

int SubTramaAlarma::getCant() {
	uint16_t con = ((this->cant[0] << 8) | this->cant[1]);
	return (int)con;
}

int SubTramaAlarma::getTam() {
	int16_t con = ((this->tam[0] << 8) | this->tam[1]);
	return (int)con;
}

std::vector<std::string> SubTramaAlarma::getMensajes() {
	return this->mensajes;
}