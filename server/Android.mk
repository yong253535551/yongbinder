LOCAL_PATH:= $(call my-dir)
 
include $(CLEAR_VARS)
 
LOCAL_SRC_FILES:= \
	../interface/IYongService.cpp \
	../interface/IYongServiceListener.cpp \
	YongService.cpp \
	main.cpp

LOCAL_C_INCLUDES += \
	$(LOCAL_PATH) \
	$(LOCAL_PATH)/include
 
LOCAL_SHARED_LIBRARIES := \
	libui libcutils libutils libbinder libsonivox libicuuc libexpat \
	libdl
 
LOCAL_MODULE_TAGS := optional

LOCAL_MODULE := yong_server

include $(BUILD_EXECUTABLE)
