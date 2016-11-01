#include "..\Include\Coneccion.h"



Conection::Conection()
{
	
}


Conection::~Conection()
{
}



void Conection::conectar() {
	con = new CDatabase();
	TRY{
	con->OpenEx(_T("DSN=FUCS;UID=pasante1;PSW=sebastian1"),CDatabase::forceOdbcDialog);
	
	}CATCH(CDBException, e) {
		AfxMessageBox(e->m_strError);
		return;
	}
	END_CATCH
}

CDatabase * Conection::getConection() {
	return this->con;
}



bool Conection::insertRegisMP(const MindrayPacket & mp) {
	

	return true;
}

bool Conection::insertRegisMA(const MindrayAlarma & ma) {


	return true;
}


bool Conection::inserRegisMPP(const MindrayParametros  & mp) {


	return true;

}