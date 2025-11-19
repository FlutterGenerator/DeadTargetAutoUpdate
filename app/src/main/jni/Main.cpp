#include <list>
#include <vector>
#include <string.h>
#include <pthread.h>
#include <cstring>
#include <jni.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <dlfcn.h>
#include "Includes/Logger.h"
#include "Includes/obfuscate.h"
#include "Includes/Utils.h"
#include "KittyMemory/MemoryPatch.h"
#include "Includes/MonoString.h"
#include "Menu/Register.h"
#include "AutoHook/AutoHook.h"
#include "Includes/Strings.h"
#include "And64InlineHook/And64InlineHook.hpp"
//@liyaharuno
//@CheatCodeRevo
//Target lib here
#define targetLibName OBFUSCATE("libil2cpp.so")

#include "Includes/Macros.h"

//---👇🏻PUT YOUR BOOL&FLOAT HERE👇🏻---

bool Ismod1 = false;
bool Ismod2 = false;
bool Ismod3 = false;
bool Ismod4 = false;
bool Ismod5 = false;
bool Ismod6 = false;
bool Ismod7 = false;
bool Ismod8 = false;

//---👇🏻PUT YOUR HOOKS HERE 👇🏻---

long (*old_mod1)(void *instance);
long mod1(void *instance) {
    if (instance != NULL && Ismod1) {
        return 999999;
    }
    return old_mod1(instance);
}



long (*old_mod2)(void *instance);
long mod2(void *instance) {
    if (instance != NULL && Ismod2) {
        return 999999;
    }
    return old_mod2(instance);
}



long (*old_mod3)(void *instance);
long mod3(void *instance) {
    if (instance != NULL && Ismod3) {
        return 999999;
    }
    return old_mod3(instance);
}



int (*old_mod4)(void *instance);
int mod4(void *instance) {
    if (instance != NULL && Ismod4) {
        return 999999;
    }
    return old_mod4(instance);
}



int (*old_mod5)(void *instance);
int mod5(void *instance) {
    if (instance != NULL && Ismod5) {
        return 999999;
    }
    return old_mod5(instance);
}



int (*old_mod6)(void *instance);
int mod6(void *instance) {
    if (instance != NULL && Ismod6) {
        return 999999;
    }
    return old_mod6(instance);
}



int (*old_mod7)(void *instance);
int mod7(void *instance) {
    if (instance != NULL && Ismod7) {
        return 999999;
    }
    return old_mod7(instance);
}



long (*old_mod8)(void *instance);
long mod8(void *instance) {
    if (instance != NULL && Ismod8) {
        return 999999;
    }
    return old_mod8(instance);
}


ProcMap il2cppMap;
void *hack_thread(void *) {
    LOGI(OBFUSCATE("pthread created"));
    
    do {
        il2cppMap = KittyMemory::getLibraryMap("libil2cpp.so");
         sleep(5); // Don't Increase
    } while (!il2cppMap.isValid());


/*void *hack_thread(void *) {
    LOGI(OBFUSCATE("pthread created"));

    do {
        sleep(25);
    } while (!isLibraryLoaded("libil2cpp.so"));

    do {
        sleep(5);
    } while (!isLibraryLoaded("MyLibName.so"));
	
	*/
    
    
    LOGI(OBFUSCATE("%s has been loaded"), (const char *) targetLibName);


//👇🏻---IF YOUR HOOK 64BIT THEN PUT HERE👇🏻---
#if defined(__aarch64__)

auto PlayerDSystem = new LoadClass("DProject", OBFUSCATE("DSystem"));

DWORD Getget_payMoney = PlayerDSystem->GetMethodOffsetByName(OBFUSCATE("get_payMoney"), 0);

A64HookFunction((void *)("libil2cpp.so", Getget_payMoney), (void *) mod1, (void **) &old_mod1);

DWORD Getget_Diamond = PlayerDSystem->GetMethodOffsetByName(OBFUSCATE("get_Diamond"), 0);

A64HookFunction((void *)("libil2cpp.so", Getget_Diamond), (void *) mod2, (void **) &old_mod2);

DWORD Getget_gameMoney = PlayerDSystem->GetMethodOffsetByName(OBFUSCATE("get_gameMoney"), 0);

A64HookFunction((void *)("libil2cpp.so", Getget_gameMoney), (void *) mod3, (void **) &old_mod3);

DWORD Getget_aidKitCount = PlayerDSystem->GetMethodOffsetByName(OBFUSCATE("get_aidKitCount"), 0);

A64HookFunction((void *)("libil2cpp.so", Getget_aidKitCount), (void *) mod4, (void **) &old_mod4);

DWORD Getget_grenadesCount = PlayerDSystem->GetMethodOffsetByName(OBFUSCATE("get_grenadesCount"), 0);

A64HookFunction((void *)("libil2cpp.so", Getget_grenadesCount), (void *) mod5, (void **) &old_mod5);

DWORD Getget_level = PlayerDSystem->GetMethodOffsetByName(OBFUSCATE("get_level"), 0);

A64HookFunction((void *)("libil2cpp.so", Getget_level), (void *) mod6, (void **) &old_mod6);



auto PlayerGunController = new LoadClass("DProject", OBFUSCATE("GunController"));

DWORD Getget_curBullet = PlayerGunController->GetMethodOffsetByName(OBFUSCATE("get_curBullet"), 0);

A64HookFunction((void *)("libil2cpp.so", Getget_curBullet), (void *) mod7, (void **) &old_mod7);



auto PlayerUpgradeWeaponRecord = new LoadClass("DProject", OBFUSCATE("UpgradeWeaponRecord"));

DWORD GetGetDamage = PlayerUpgradeWeaponRecord->GetMethodOffsetByName(OBFUSCATE("GetDamage"), 0);

A64HookFunction((void *)("libil2cpp.so", GetGetDamage), (void *) mod8, (void **) &old_mod8);



//👇🏻---IF YOUR HOOK 32BIT THEN PUT HERE👇🏻---
#else

auto PlayerDSystem = new LoadClass("DProject", OBFUSCATE("DSystem"));

DWORD Getget_payMoney = PlayerDSystem->GetMethodOffsetByName(OBFUSCATE("get_payMoney"), 0);

MSHookFunction((void *)("libil2cpp.so", Getget_payMoney), (void *) mod1, (void **) &old_mod1);

DWORD Getget_Diamond = PlayerDSystem->GetMethodOffsetByName(OBFUSCATE("get_Diamond"), 0);

MSHookFunction((void *)("libil2cpp.so", Getget_Diamond), (void *) mod2, (void **) &old_mod2);

DWORD Getget_gameMoney = PlayerDSystem->GetMethodOffsetByName(OBFUSCATE("get_gameMoney"), 0);

MSHookFunction((void *)("libil2cpp.so", Getget_gameMoney), (void *) mod3, (void **) &old_mod3);

DWORD Getget_aidKitCount = PlayerDSystem->GetMethodOffsetByName(OBFUSCATE("get_aidKitCount"), 0);

MSHookFunction((void *)("libil2cpp.so", Getget_aidKitCount), (void *) mod4, (void **) &old_mod4);

DWORD Getget_grenadesCount = PlayerDSystem->GetMethodOffsetByName(OBFUSCATE("get_grenadesCount"), 0);

MSHookFunction((void *)("libil2cpp.so", Getget_grenadesCount), (void *) mod5, (void **) &old_mod5);

DWORD Getget_level = PlayerDSystem->GetMethodOffsetByName(OBFUSCATE("get_level"), 0);

MSHookFunction((void *)("libil2cpp.so", Getget_level), (void *) mod6, (void **) &old_mod6);



auto PlayerGunController = new LoadClass("DProject", OBFUSCATE("GunController"));

DWORD Getget_curBullet = PlayerGunController->GetMethodOffsetByName(OBFUSCATE("get_curBullet"), 0);

MSHookFunction((void *)("libil2cpp.so", Getget_curBullet), (void *) mod7, (void **) &old_mod7);



auto PlayerUpgradeWeaponRecord = new LoadClass("DProject", OBFUSCATE("UpgradeWeaponRecord"));

DWORD GetGetDamage = PlayerUpgradeWeaponRecord->GetMethodOffsetByName(OBFUSCATE("GetDamage"), 0);

MSHookFunction((void *)("libil2cpp.so", GetGetDamage), (void *) mod8, (void **) &old_mod8);



    LOGI(OBFUSCATE("Done"));
#endif


    

    return NULL;
}



jobjectArray GetFeatureList(JNIEnv *env, jobject context) {
    jobjectArray ret;

    const char *features[] = {
    //👇🏻---YOUR MENU---👇🏻
            OBFUSCATE("Category_Deadtarget All Mod"),
            OBFUSCATE("1_Toggle_Play Money"),
			OBFUSCATE("2_Toggle_Diamond"),
			OBFUSCATE("3_Toggle_Game Money"),
			OBFUSCATE("4_Toggle_Aidkit"),
			OBFUSCATE("5_Toggle_Grenade"),
			OBFUSCATE("6_Toggle_Level"),
			OBFUSCATE("7_Toggle_Ammo"),
			OBFUSCATE("8_Toggle_Damage"),
			
    };

    //MODDED BY LIYA HACK
    int Total_Feature = (sizeof features / sizeof features[0]);
    ret = (jobjectArray)
            env->NewObjectArray(Total_Feature, env->FindClass(OBFUSCATE("java/lang/String")),
                                env->NewStringUTF(""));

    for (int i = 0; i < Total_Feature; i++)
        env->SetObjectArrayElement(ret, i, env->NewStringUTF(features[i]));

    return (ret);
}

void Changes(JNIEnv *env, jclass clazz, jobject obj,
                                        jint featNum, jstring featName, jint value,
                                        jboolean boolean, jstring str) {

    LOGD(OBFUSCATE("Feature name: %d - %s | Value: = %d | Bool: = %d | Text: = %s"), featNum,
         env->GetStringUTFChars(featName, 0), value,
         boolean, str != NULL ? env->GetStringUTFChars(str, 0) : "");



    switch (featNum) {
    case 1:
    Ismod1 = boolean;
    break;
	case 2:
    Ismod2 = boolean;
    break;
	case 3:
    Ismod3 = boolean;
    break;
	case 4:
    Ismod4 = boolean;
    break;
	case 5:
    Ismod5 = boolean;
    break;
	case 6:
    Ismod6 = boolean;
    break;
	case 7:
    Ismod7 = boolean;
    break;
	case 8:
    Ismod8 = boolean;
    break;
    }
}


__attribute__((constructor))
void lib_main() {
    pthread_t ptid;
    pthread_create(&ptid, NULL, hack_thread, NULL);
}

extern "C"
JNIEXPORT jint JNICALL
JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *env;

    vm->GetEnv((void **) &env, JNI_VERSION_1_6);

    static const JNINativeMethod menuMethods[] = {
            {OBFUSCATE("Icon"), OBFUSCATE("()Ljava/lang/String;"), reinterpret_cast<void *>(Icon)},
            {OBFUSCATE("IconWebViewData"),  OBFUSCATE("()Ljava/lang/String;"), reinterpret_cast<void *>(IconWebViewData)},
            {OBFUSCATE("IsGameLibLoaded"),  OBFUSCATE("()Z"), reinterpret_cast<void *>(isGameLibLoaded)},
            {OBFUSCATE("Init"),  OBFUSCATE("(Landroid/content/Context;Landroid/widget/TextView;Landroid/widget/TextView;)V"), reinterpret_cast<void *>(Init)},
            {OBFUSCATE("SettingsList"),  OBFUSCATE("()[Ljava/lang/String;"), reinterpret_cast<void *>(SettingsList)},
            {OBFUSCATE("GetFeatureList"),  OBFUSCATE("()[Ljava/lang/String;"), reinterpret_cast<void *>(GetFeatureList)},
    };

    if (Register(env, "com/android/support/Menu", menuMethods, sizeof(menuMethods) / sizeof(JNINativeMethod)) != 0)
        return JNI_ERR;

    static const JNINativeMethod prefMethods[] = {
            { OBFUSCATE("Changes"), OBFUSCATE("(Landroid/content/Context;ILjava/lang/String;IZLjava/lang/String;)V"), reinterpret_cast<void *>(Changes)},
    };

    if (Register(env, "com/android/support/Preferences",
                 prefMethods, sizeof(prefMethods) / sizeof(JNINativeMethod)) != 0)
        return JNI_ERR;

    static const JNINativeMethod mainMethods[] = {
            { OBFUSCATE("CheckOverlayPermission"), OBFUSCATE("(Landroid/content/Context;)V"), reinterpret_cast<void *>(CheckOverlayPermission)},
    };

    if (Register(env, "com/android/support/Main", mainMethods, sizeof(mainMethods) / sizeof(JNINativeMethod)) != 0)
        return JNI_ERR;

    return JNI_VERSION_1_6;
}
