#include "IYongService.h"
#include <binder/Parcel.h>
#include <binder/IInterface.h>
#include "IYongServiceListener.h"

namespace android{

enum {
    YONG_ONSTATUSCHANGED = 0,
    YONG_ADDLISTENER,
    YONG_REMOVELISTENER,
    YONG_SET_VALUE,
};

class BpYongService : public BpInterface<IYongService>{
public:
	BpYongService(const sp<IBinder>& impl) : BpInterface<IYongService>(impl){

	}

	virtual int setValue(int a)
  {
    	LOGD("==========================================================\n");
      LOGD("TK---->>>>>>IYongBinderService.cpp>>>>BpYongBinderService::setValue\n");
      Parcel data,reply;
      data.writeInt32(a);
      remote()->transact(YONG_SET_VALUE, data, &reply);
      return reply.readInt32();
  }

	virtual int addListener(const sp<IYongServiceListener>& listener)
  {
   		LOGD("==========================================================\n");
      LOGD("TK---->>>>>>IYongService.cpp>>>>BpYongService::addListener\n");
      Parcel data, reply;
      data.writeStrongBinder(listener->asBinder(listener));
      remote()->transact(YONG_ADDLISTENER, data, &reply);
      return reply.readInt32();
  }
};

IMPLEMENT_META_INTERFACE(YongService, "android.yong.IYongService");

status_t BnYongService::onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags)
{
    LOGD("TK---->>>>>>IYongService.cpp>>>>BnYongService::onTransact\n");
    switch (code) {
    	case YONG_SET_VALUE:
		  {
        	LOGD("TK---->>>>>>IYongService.cpp>>>>BnYongService::onTransact>>YONG_SET_VALUE\n");
        	reply->writeInt32(setValue((int) data.readInt32()) );
        	return NO_ERROR;
      }
			break;
   		case YONG_ADDLISTENER:
		  {
        	LOGD("TK---->>>>>>IYongService.cpp>>>>BnYongService::onTransact>>YONG_ADDLISTENER\n");
        	sp<IYongServiceListener> listener = interface_cast<IYongServiceListener>(data.readStrongBinder());
          if(listener == NULL){
            	printf("callback == NULL...\n");
          }

        	reply->writeInt32(addListener(listener));
        	return NO_ERROR;
      }
      default:
		  {
        	LOGD("TK---->>>>>>IYongService.cpp>>>>BnYongService::onTransact>>333\n");
        	return BBinder::onTransact(code, data, reply, flags);
      }
    }
}

}
