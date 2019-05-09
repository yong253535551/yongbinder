#ifndef __IYongListener_H__
#define __IYongListener_H__

#include <binder/IInterface.h>

namespace android{
  class IYongServiceListener : public IInterface{
    	public:
      		DECLARE_META_INTERFACE(YongServiceListener);
      		virtual int onStatusChanged(int a) = 0;
  };

	class BnYongServiceListener : public BnInterface<IYongServiceListener>{
  		public:
    		virtual status_t    onTransact( uint32_t code,
                                    const Parcel& data,
                                    Parcel* reply,
                                    uint32_t flags = 0);
  };
}

#endif
