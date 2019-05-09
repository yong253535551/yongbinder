#include <stdio.h>
#include "YongServiceListener.h"

using namespace android;

int main(int argc, char* argv[]){
	int ret = 0;

	ProcessState::self()->startThreadPool();
	sp<IServiceManager> sm = defaultServiceManager();
	sp<IBinder> binder = sm->getService(String16("yong.IYongService"));
	if(binder == NULL){
    	printf("fail to get service yong.IYongService...\n");
    	return 0;
	}
	sp<IYongService> service = interface_cast<IYongService>(binder);

	sp<YongServiceListener> listener(new YongServiceListener());
	if(listener == NULL){
		printf("YongServiceListener == NULL...\n");
		return 0;
	}

	ret = service->addListener(listener);
	if(ret < 0){
		printf("fail to addListener...\n");
	}

	ret = service->setValue(2);

	LOGD("TK-------->>>result is %d\n", ret);

	return 0;
}
