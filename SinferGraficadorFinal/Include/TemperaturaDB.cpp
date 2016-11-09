#include "TemperaturaDB.h"



TemperaturaDB::TemperaturaDB()
{
}


TemperaturaDB::~TemperaturaDB()
{
}


TemperaturaDB::TemperaturaDB(CDatabase *db) : CRecordset(db) {





}

CString TemperaturaDB::GetDefaultSQL() {
	return _T("temperatura");
}



void TemperaturaDB::loadTemp(Store st,SubtRamTemp *sun, Monitor1 *mon) {
	this->dat_Sig = st.mpp.getDataTime().c_str();
	/*
	falta cargar esto
	*/
}