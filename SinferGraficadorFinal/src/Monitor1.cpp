#include "..\Include\Monitor1.h"



Monitor1::Monitor1(CDatabase * db) :   CRecordset(db) {
	this->numCam = 0;
}

Monitor1::Monitor1()
{
}


Monitor1::~Monitor1()
{

}


CString Monitor1::GetDefaultSQL() {
		return SQLOpen.c_str();
}

bool Monitor1::openTabMo() {
	bool op = true;
	TRY{
		op = true;
	this->Open();
	}CATCH(CDBException ,e) {
		op = false;
	}
	END_CATCH
	return op;
}


void Monitor1::setIp(const CString & ip) {
	this->IP = ip;
}

void Monitor1::DoFieldExchange(CFieldExchange *pFX){
		pFX->SetFieldType(CFieldExchange::outputColumn);
		RFX_Int(pFX, _T("ID"), this->id);
		RFX_Text(pFX, _T("IP"), IP);
		RFX_Text(pFX, _T("FehaRegistro"), date_reg);
		RFX_Int(pFX, _T("Num_Cam"), this->numCam);
}
	


CString Monitor1::getDateRag() {
	return date_reg;
}

int Monitor1::getNumCam() {
	return numCam;
}

int Monitor1::getId() {
	return id;
}

CString Monitor1::getIp() {
	return this->IP;
}



