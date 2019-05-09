#ifndef __IYongListener_H__
#define __IYongListener_H__

#include <binder/IInterface.h>

namespace android{
  class IYongListener : public IInterface{
    	public:
      		DECLARE_META_INTERFACE(YongListener);
      		virtual int onStatusChanged(int a) = 0;
  };

	class BnYongListener : public BnInterface<IYongListener>{
  		public:
    		virtual status_t    onTransact( uint32_t code,
                                    const Parcel& data,
                                    Parcel* reply,
                                    uint32_t flags = 0);
  };
}

#endif
