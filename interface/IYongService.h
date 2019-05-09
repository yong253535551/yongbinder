#ifndef __IYongService_H__
#define __IYongService_H__

#include <binder/IInterface.h>
#include "IYongServiceListener.h"

#include <android/log.h>

#define YONG_LOG_TAG "YONG_LOG"
#define LOGD(...) ((void)__android_log_print(ANDROID_LOG_DEBUG, YONG_LOG_TAG, __VA_ARGS__))
#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, YONG_LOG_TAG, __VA_ARGS__))
#define LOGW(...) ((void)__android_log_print(ANDROID_LOG_WARN, YONG_LOG_TAG, __VA_ARGS__))
#define LOGE(...) ((void)__android_log_print(ANDROID_LOG_ERROR, YONG_LOG_TAG, __VA_ARGS__))

namespace android{
  class IYongService : public IInterface{
    public:
      	DECLARE_META_INTERFACE(YongService);
      	virtual int setValue(int a) = 0;
      	virtual int addListener(const sp<IYongServiceListener>& listener) = 0;
  };

  class BnYongService : public BnInterface<IYongService>{
  	public:
    	virtual status_t    onTransact( uint32_t code,
                                    const Parcel& data,
                                    Parcel* reply,
                                    uint32_t flags = 0);
  };
}

#endif
