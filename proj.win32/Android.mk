LOCAL_PATH := $(call my-dir)
 
include $(CLEAR_VARS)
 
LOCAL_MODULE := game_shared
 
LOCAL_MODULE_FILENAME := libgame
 
LOCAL_SRC_FILES := hellocpp/main.cpp \ 
../../Classes/AppDelegate.cpp \ 
../../Classes/GameLogic/ClearLogic.cpp \ 
../../Classes/GameUI/GameBoard.cpp \ 
../../Classes/GameUI/GameScene.cpp \ 
../../Classes/HelloWorldScene.cpp 

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes 
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes 
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/GameLogic 
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/GameUI 
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/GlobalData 

LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static cocosdenshion_static cocos_extension_static 

include $(BUILD_SHARED_LIBRARY) 

$(call import-module,CocosDenshion/android) \ 
$(call import-module,cocos2dx) \ 
$(call import-module,extensions)	 
