LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE    := libfreetype
include source_libfreetype.mak
LOCAL_CFLAGS += -w -fsigned-char -frtti
include $(BUILD_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE    := liblua
include source_liblua.mak
LOCAL_CFLAGS += -w -fsigned-char -frtti
include $(BUILD_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE    := libgameswf
include source_gameswf.mak
LOCAL_CFLAGS += -w -fsigned-char -frtti
include $(BUILD_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE    := libirrlicht
include source_irlicht.mak
LOCAL_CFLAGS += -w -fsigned-char -frtti
include $(BUILD_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE    := libirrlichtex
include source_irlichtex.mak
LOCAL_CFLAGS += -w -fsigned-char -frtti
include $(BUILD_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE    := libgsgameplay
include source_gameplay.mak
LOCAL_CFLAGS += -w -fsigned-char -frtti
LOCAL_STATIC_LIBRARIES := libfreetype liblua libgameswf libirrlicht libirrlichtex
LOCAL_LDLIBS := -lGLESv2 -ldl -llog -lc -lgcc
include $(BUILD_SHARED_LIBRARY)