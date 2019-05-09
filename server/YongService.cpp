#include <binder/IPCThreadState.h>
#include <binder/IServiceManager.h>
#include <utils/Log.h>
#include <binder/Parcel.h>
#include <binder/IPCThreadState.h>
#include <utils/String16.h>
#include <utils/threads.h>
#include <utils/Atomic.h>

#include <cutils/properties.h>
#include <cutils/compiler.h>

#include "YongService.h"

namespace android{

void  YongService::instantiate()
{
	defaultServiceManager()->addService(String16("yong.IYongService"), new YongService());
}

int YongService::setValue(int a)
{
	LOGD("TK---->>>>>>YongService.cpp>>>>YongService::setValue\n");
	mListener->onStatusChanged(2);

	return a;
}

int YongService::addListener(const sp<IYongServiceListener>& listener)
{
	LOGD("TK---->>>>>>YongService.cpp>>>>YongService::addListener\n");
	mListener = listener;

	return 1;
}

status_t YongService::onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags)
{
	LOGD("TK---->>>>>>YongService.cpp>>>>YongService::onTransact\n");

	return BnYongService::onTransact(code, data, reply, flags);
}

}
