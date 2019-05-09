#include <binder/Parcel.h>
#include <binder/IPCThreadState.h>
#include <utils/String16.h>
#include <utils/threads.h>
#include <utils/Atomic.h>
#include <cutils/properties.h>
#include <cutils/compiler.h>

#include "YongServiceListener.h"

namespace android{

int YongServiceListener::onStatusChanged(int a){
	LOGD("TK---->>>>>>YongServiceListener.cpp>>>>YongServiceListener::onStatusChanged a = %d\n", a);
	return 1;
}

status_t YongServiceListener::onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags){
	LOGD("TK---->>>>>>YongServiceListener.cpp>>>>YongServiceListener::onTransact\n");
	return BnYongServiceListener::onTransact(code, data, reply, flags);
}

}
