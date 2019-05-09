#include "../interface/IYongService.h"
#include "../interface/IYongServiceListener.h"
#include <binder/BinderService.h>

namespace android{

	class YongServiceListener: public BnYongServiceListener{
		friend class BinderService<YongServiceListener>;
    	public:
      	virtual int onStatusChanged(int a);
      	virtual     status_t    onTransact(
                                uint32_t code,
                                const Parcel& data,
                                Parcel* reply,
                                uint32_t flags);
	};
}
