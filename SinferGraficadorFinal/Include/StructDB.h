#if !defined(_STRUCTBD_)
#define _STRUCTBD_
#pragma once

#include "MindrayPacket.h"
#include "MindrayAlarma.h"
#include "MindrayParametros.h"
#include "Struct.h"


struct Store {
	MindrayPacket mp;
	MindrayParametros mpp;
	MindrayAlarma ma;
};



#endif
