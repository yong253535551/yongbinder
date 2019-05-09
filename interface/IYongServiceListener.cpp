#include <binder/Parcel.h>
#include <binder/IInterface.h>

#include "IYongService.h"

namespace android{

  enum {
      YONG_ONSTATUSCHANGED = 0,
      YONG_ADDLISTENER,
      YONG_REMOVELISTENER,
      YONG_SET_VALUE,
  };

class BpYongServiceListener : public BpInterface<IYongServiceListener>{
  public:
	   BpYongServiceListener(const sp<IBinder>& impl) : BpInterface<IYongServiceListener>(impl){

	   }

    virtual int onStatusChanged(int a){
        LOGD("==========================================================\n");
        LOGD("TK---->>>>>>IYongServiceListener.cpp>>>>BpYongServiceListener::onStatusChanged\n");
        Parcel data,reply;
        data.writeInt32(a);
        remote()->transact(YONG_ONSTATUSCHANGED,data,&reply);
        return reply.readInt32();
    }

};

IMPLEMENT_META_INTERFACE(YongServiceListener, "android.yong.IYongServiceListener");

status_t BnYongServiceListener::onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags)
{
	LOGD("TK---->>>>>>IYongServiceListener.cpp>>>>BnYongServiceListener::onTransact\n");
	switch (code) {
    case YONG_ONSTATUSCHANGED:
		{
      LOGD("TK---->>>>>>IYongServiceListener.cpp>>>>BnYongServiceListener::onTransact>>YONG_ONSTATUSCHANGED\n");
      reply->writeInt32(onStatusChanged((int) data.readInt32()) );
      return NO_ERROR;
    }
		  break;
    default:
    {
      LOGD("TK---->>>>>>IYongServiceListener.cpp>>>>BnYongServiceListener::onTransact>>222\n");
      return BBinder::onTransact(code, data, reply, flags);
    }
  }
}

}
