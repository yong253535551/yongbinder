LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
	../interface/IYongService.cpp \
	../interface/IYongServiceListener.cpp \
	YongServiceListener.cpp \
	main.cpp

LOCAL_CFLAGS +=-DANDROID_LOG

LOCAL_C_INCLUDES += \
	$(LOCAL_PATH) \
    $(LOCAL_PATH)/include \
	$(LOCAL_PATH)/interface

LOCAL_SHARED_LIBRARIES := \
	libui libcutils libutils libbinder libsonivox libicuuc libexpat \
	libdl

LOCAL_MODULE_TAGS := optional

LOCAL_MODULE := yong_client

include $(BUILD_EXECUTABLE)
