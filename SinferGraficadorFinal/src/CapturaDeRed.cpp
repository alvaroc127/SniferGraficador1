#include "..\Include\CapturaDeRed.h"

//#include<crtdbg.h>


using namespace Tins;
using namespace std;


/// <summary>
/// This Method capture packet TCP of network and send from claisify
/// </summary>
//unsigned __stdcall CapturarPacket1(void *);
//struct MyData *dta = NULL;

CapturaDeRed::CapturaDeRed() 
{
	
};




CapturaDeRed::~CapturaDeRed()
{
};

/*
sacar carga util empezar mecanismos de clasificacion.
*/
string CapturaDeRed::clasificarPacket(const std::vector<uint8_t> & carga, int pos) {
	string cab;
	stringstream ss;
	if (carga.empty() == false && carga.size() > 4 && pos + 1 < carga.size()) {
		for (int i = 0; i < 6 && i<carga.size()&& pos < carga.size(); i++) {
			ss << std::hex <<(int)carga.at(pos++);
		}
		cab = ss.str();
		ss.clear();
		cout.clear();
	}
	return cab;
}

void CapturaDeRed::CapturarPacket1() {
	Tins::Sniffer snfi(configCapture().name(), configSniffer());
	int pos =0,posAux = 0;
	bool band = true;
	do {
		PDU * pack = snfi.next_packet();
		TCP tcp = pack->rfind_pdu<TCP>();
		IP ip = pack->rfind_pdu<IP>();
		try {
		 RawPDU raw = tcp.rfind_pdu<RawPDU>();
			do {
				posAux = pos;
				pos=confHead(clasificarPacket(raw.payload(),pos), ip.src_addr().to_string(), raw.payload(),pos);
				//cout << "pos " << pos <<"posaux"<< posAux << endl;
				//printf("valor de wait %d \n",wait);
				if (pos == posAux && this->wait==true) {
					pos=searchHead(raw.payload(), pos);
					//cout<<"esto es "<<"esto es pos"<<pos<<"-- "<<posAux<<"-*///"<<clasificarPacket(raw.payload(),pos)<<"esto es "<<endl;
					if (pos==posAux) {
						band = false;
					}
				}
			} while ( pos < raw.payload().size() &&true== this->wait && true==band);
			cout << "salio" << endl;
			pos = 0;
			wait = true;
			band = true; 
			delete(pack);
		}
		catch (pdu_not_found) {
			//cout << "problema no encontrado" << endl;
			cout.clear();
			delete(pack);
		}
	} while (true);
}

/*
unsigned __stdcall CapturarPacket1(void *ap)
{
	dta = (MyData*)ap;
	Sniffer snfi(dta->ifaceName.name(), dta->s1);
	do {
		PDU *pack = snfi.next_packet();
	 	TCP  tcp = pack->rfind_pdu<TCP>();
		try {
			RawPDU & raw = tcp.rfind_pdu<RawPDU>();
			CapturaDeRed::clasificarPacket(raw.payload());
			delete(pack);
		}
		catch (pdu_not_found) {
			cout << "problema no encontrado" << endl;
			delete(pack);
		}
	} while (true);
	_endthreadex(0);
	return 0;
}
*/



Tins::NetworkInterface  CapturaDeRed::configCapture() {
	NetworkInterface a;
		vector<NetworkInterface> infaces = NetworkInterface::all();
		a = infaces.at(0);
		infaces.clear();
	return a;
}


 Tins::SnifferConfiguration  CapturaDeRed::configSniffer() {
	SnifferConfiguration sc;
	sc.set_promisc_mode(true);
	sc.set_snap_len(64 *1024);
	sc.set_filter("ip and tcp");
	return sc;
}


void CapturaDeRed::startCapture() {
	CapturarPacket1();
	/*
	HANDLE hTread;
	unsigned threadID;
	 MyData *data=new MyData;
	data->ifaceName = configCapture();
	data->s1 = configSniffer();

	creo el hil y lo asigno
	hTread = (HANDLE)_beginthreadex(NULL, 0,&CapturarPacket1, data, 0, &threadID);
	if (hTread) {
		std::cout << "hilo iniciado" << endl;
		SetPriorityClass(hTread, HIGH_PRIORITY_CLASS);
		WaitForSingleObject(hTread,INFINITE);
		delete(data);
	}
	*/
}



int CapturaDeRed::confHead(const std::string &head, const std::string &ip,const std::vector<uint8_t>  & datas , int pos) {
	cout << "esto es head" << head<<endl;
	if (head == "1509d00") {
		if(this->dat_time.empty()==false){
		MindrayPacket mp;
		mp.setFuente(ip);
		mp.setDtaTime(this->dat_time);
		HeaderTram he = mp.getHead();
		he.loadHead(datas, pos);
		cout << "la ip es" << mp.getFuente() << "con cabeza" << head << endl; cout<< "el paquete llego a las" << mp.getDataTime() << " el tamanio " << he.sizePacket() << endl;
		cout << "restante trama" << datas.size() - pos << endl;
		if (he.sizePacket() <= (datas.size() - pos) ) {
			mp.setHead(he);
			pos=mp.clasifyData(datas, pos);
			this->wait = true;
			if (guardarMP(mp)) {
				mp.~MindrayPacket();
				he.~HeaderTram();
			}
		}
		else {
			setVector(datas);
			this->mp = mp;
			this->wait = false;
			posG = pos;
			mp.~MindrayPacket();
			he.~HeaderTram();
			}
		}
		else {
			//cout << "no cargo ECG"<<endl;
		}
	}
	else if (head == "150cc00") {
		this->dat_time.swap(captDta_time());
		MindrayParametros mp1;
		mp1.setFuente(ip);
		//cout<<mp.getFuente()<<endl;
		mp1.setDtaTime(dat_time);
		//cout << mp.getDataTime() << endl;
		HeaderTram he = mp1.getHead();
		//cout << "pos head"<< pos << endl;
		he.loadHead(datas, pos);
		cout << "en parametros la ip es" << mp1.getFuente() << "con cabeza" << head << endl; cout << "el paquete llego a las" << mp1.getDataTime() << " el tamanio " << he.sizePacket() << endl;
		if (datas.size() >= he.sizePacket()) {
			mp1.setHead(he);
			pos=mp1.clasifyData(datas, pos);
			this->wait = true;
			if (guardarMPP(mp1)) {
				mp1.~MindrayParametros();
			}
		}
		else {
			setVector(datas);
			this->mpp = mp1;
			this->wait = false;
			posG = pos;
			mp1.~MindrayParametros();
			he.~HeaderTram();
			//guarda el paqutee
			// cargar datos 
		}
	}else if (head == "1503600" || head == "1503800") {
		//cargar el identificadorde alarma para  //alarma fisiologica y de sistema
		MindrayAlarma ma;
		if (head == "1503600") {
			ma.setTipo(1);
		}
		else {
			ma.setTipo(0);
		}
		ma.setFuente(ip);
		//cout<<mp.getFuente()<<endl;
		ma.setDtaTime(this->dat_time);
		//cout << mp.getDataTime() << endl;
		HeaderTram he = ma.getHead();
		he.loadHead(datas, pos);
		cout << "la ip es" << ma.getFuente() << "con cabeza" << head << endl; cout << "el paquete llego a las" << ma.getDataTime() << " el tamanio " << he.sizePacket() << endl;
		if (datas.size() >= he.sizePacket()) {
		ma.setHead(he);
		pos=ma.clasifyData(datas, pos);
		if (guardarMA(ma)) {
			cout << "la ip es" << ma.getFuente() << "con cabeza" << head << endl; cout << "el paquete llego a las" << ma.getDataTime() << " el tamanio " << he.sizePacket() << endl;
			ma.~MindrayAlarma();
			}
		}
		else {
			setVector(datas);
			this->ma = ma;
			this->wait = false;
			posG = pos;
			ma.~MindrayAlarma();
			he.~HeaderTram();
		}
	}
	else {
		if (datWait.empty() == false) {
			datWait.insert(std::end(datWait), std::begin(datas), std::end(datas));
			if (this->mp.getFuente().empty() == false) {
				pos = mp.clasifyData(datWait, posG);
				guardarMP(mp);
				mp.getFuente().clear();
				datWait.clear();
			}
			else if (this->ma.getFuente().empty() == false) {
				ma.clasifyData(datWait, posG);
				guardarMA(ma);
				ma.getFuente().clear();
				datWait.clear();
			}
			else if (this->mpp.getFuente().empty() == false) {
				mpp.clasifyData(datWait, posG);
				guardarMPP(mpp);
				mpp.getFuente().clear();
				datWait.clear();
			}
			else {

			}
		}
		else {

		}
	}
	return pos;
}


string  CapturaDeRed::captDta_time() {
	string data_ti;
	SYSTEMTIME  lt;
	GetLocalTime(&lt);
	data_ti+=std::to_string(lt.wYear)+"-"+std::to_string(lt.wMonth)+"-"+std::to_string(lt.wDayOfWeek)+" "+std::to_string(lt.wHour)+":"+std::to_string(lt.wMinute)+":"+std::to_string(lt.wSecond)+":"+
	std::to_string(lt.wMilliseconds);
	return  data_ti;
}



void CapturaDeRed::setVector(const vector<uint8_t> &v) {
	this->datWait = v;
}

 vector<uint8_t> CapturaDeRed::getDataWait() {
	return this->datWait;
}


int CapturaDeRed::searchHead(const vector<uint8_t> &datas, int pos) {
	string hed;
	stringstream posib;
	bool ban = false;
	int cont = 0;
	uint32_t var;
	uint32_t var2;
	for (pos; pos < datas.size()  && pos+6 <datas.size() && ban==false ;pos++) {
		cont = pos;
		var = ((datas.at(cont++) << 16) | (datas.at(cont++) << 8) | (datas.at(cont++)));
		var2 = ((datas.at(cont++) << 16) | (datas.at(cont++) << 8) | (datas.at(cont++)));
		posib << std::hex <<var;
		posib << std::hex << var2;
		hed = posib.str();
		posib.str("");
		//printf("esto es el valor %x",var);
		//printf("%x\n", var2);
		cout<<hed<<endl;
		if (hed == "105009d0000") {
			ban = true;
			//cout << "esto es cabeza1-*-*"<< hed<< endl;
			pos = cont - 6;
		}
		else if (hed == "10500cc0000"){
			//cout << "esto es cabeza2-*-*" << hed << endl;
			ban = true;
			pos = cont - 6;
		}
		else if (hed == "10500360000" || hed == "10500380000") {
			//cout << "esto es cabeza3-*-*" << hed << endl;
			ban = true;
			pos = cont - 6;
		}
		else {
			hed.clear();
		} 
	}
	posib.clear();
	hed.clear();
	return pos-1;
}


bool CapturaDeRed::guardarMP(MindrayPacket &mp) {
	Signal sig;
	if (this->ga.searchIp(mp.getFuente())) {
		for (int i = 0; i < mp.getSubTra().size(); i++)
		{
		ga.EscribirDatSig(mp.getSubTra().at(i)->datTram(sig),mp);
		delete mp.getSubTra().at(i);
		}
}
else {
	this->ga.crearArchivo(mp.getFuente());
	for (int i = 0; i < mp.getSubTra().size(); i++)
	{
		ga.EscribirDatSig(mp.getSubTra().at(i)->datTram(sig),mp);
		delete mp.getSubTra().at(i);
		}
	}
return true;
}




bool CapturaDeRed::guardarMPP(MindrayParametros &mp) {
	Impedancia imp;
	ECG ecg;
	Art art;
	Ap ap;
	SPO2 spo2;
	Temp temp;
	if (this->ga.searchIp(mp.getFuente())) {
		
		for (int i = 0; i < mp.getSubTra().size(); i++)
		{
			SubTramaECG * sue = dynamic_cast<SubTramaECG *> (mp.getSubTra().at(i));
			if (sue != NULL) {
				ga.EscribirDatECG(sue-> datTram(ecg), mp);
				delete mp.getSubTra().at(i);
			}
			else {
				SubTramaImpedancia * sue1 = dynamic_cast<SubTramaImpedancia *> (mp.getSubTra().at(i));
				if (sue1 != NULL) {
					ga.EscribirDatImpedancia(sue1->datTram(imp), mp);
					delete mp.getSubTra().at(i);
				}
				else {
					SubTramSpo2 * sue2 = dynamic_cast<SubTramSpo2 *> (mp.getSubTra().at(i));
					if (sue2 != NULL ) {
						ga.EscribirDatSpo2(sue2->datTram(spo2), mp);
						delete mp.getSubTra().at(i);
					}
					else {
						SubtRamTemp * sue3 = dynamic_cast<SubtRamTemp *> (mp.getSubTra().at(i));
						if (sue != NULL) {
							ga.EscribirDatTemp(sue3->datTram(temp), mp);
							delete mp.getSubTra().at(i);
						}
						else {
							SubTramaArt_AP * sue4 = dynamic_cast<SubTramaArt_AP *> (mp.getSubTra().at(i));
							if (sue4 !=NULL) {
								if (sue4->isBand()) {
									ga.EscribirDatAp(sue4->datTram(ap), mp);
									delete mp.getSubTra().at(i);
								}
								else {
									ga.EscribirDatArt(sue4->datTram1(art), mp);
									delete mp.getSubTra().at(i);
								}
							}
							else {
								delete mp.getSubTra().at(i);
							}
						}
					}
				}
			}
		}
	}
	else {
	this->ga.crearArchivo(mp.getFuente());
		for (int i = 0; i < mp.getSubTra().size(); i++)
		{
			SubTramaECG * sue = dynamic_cast<SubTramaECG *> (mp.getSubTra().at(i));
			if (sue != NULL) {
				ga.EscribirDatECG(sue->datTram(ecg), mp);
				delete mp.getSubTra().at(i);
			}
			else {
				SubTramaImpedancia * sue1 = dynamic_cast<SubTramaImpedancia *> (mp.getSubTra().at(i));
				if (sue1 != NULL) {
					ga.EscribirDatImpedancia(sue1->datTram(imp), mp);
					delete mp.getSubTra().at(i);
				}
				else {
					SubTramSpo2 * sue2 = dynamic_cast<SubTramSpo2 *> (mp.getSubTra().at(i));
					if (sue2 != NULL) {
						ga.EscribirDatSpo2(sue2->datTram(spo2), mp);
						delete mp.getSubTra().at(i);
					}
					else {
						SubtRamTemp * sue3 = dynamic_cast<SubtRamTemp *> (mp.getSubTra().at(i));
						if (sue != NULL) {
							ga.EscribirDatTemp(sue3->datTram(temp), mp);
							delete mp.getSubTra().at(i);
						}
						else {
							SubTramaArt_AP * sue4 = dynamic_cast<SubTramaArt_AP *> (mp.getSubTra().at(i));
							if (sue4 != NULL) {
								if (sue4->isBand()) {
									ga.EscribirDatAp(sue4->datTram(ap), mp);
									delete mp.getSubTra().at(i);
								}
								else {
									ga.EscribirDatArt(sue4->datTram1(art), mp);
									delete mp.getSubTra().at(i);
								}
							}
							else {
								delete mp.getSubTra().at(i);
							}
						}
					}
				}
			}
		}
	}
return true;
}



bool CapturaDeRed::guardarMA(MindrayAlarma &ma) {
	if (this->ga.searchIp(ma.getFuente())) {
		for (int i = 0; i < ma.getSubTra().size(); i++)
		{
			this->ga.EscribirDatALarma(ma.getSubTra().at(i)->getMensajes(), ma);
			delete ma.getSubTra().at(i);
		}
	}
	else {
		this->ga.crearArchivo(ma.getFuente());
		for (int i = 0; i < ma.getSubTra().size(); i++)
		{
			this->ga.EscribirDatALarma(ma.getSubTra().at(i)->getMensajes(), ma);
			delete ma.getSubTra().at(i);
		}
	}
	return true;
}


