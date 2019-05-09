#include <binder/BinderService.h>

#include "../interface/IYongService.h"
#include "../interface/IYongServiceListener.h"

namespace android{
	class YongService: public BinderService<YongService>, public BnYongService{
   		friend class BinderService<YongService>;
    	public:
      	static void instantiate();

   			virtual int setValue(int a);
   			virtual int addListener(const sp<IYongServiceListener>& listener);
   			virtual     status_t    onTransact(
                             uint32_t code,
                             const Parcel& data,
                             Parcel* reply,
                             uint32_t flags);
		protected:
   			sp<IYongServiceListener> mListener;
				pthread_t mServiceThreadId;
				bool mUpdate;
	};
}
