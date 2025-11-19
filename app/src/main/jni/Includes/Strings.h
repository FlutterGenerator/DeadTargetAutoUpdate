monoString *CreateMonoString(const char *str){
    dlerror();
    auto handle = dlopen("libil2cpp.so", RTLD_LAZY);
    const char* openerror = dlerror();
    if(openerror){
        LOGE(OBFUSCATE("Error Opening Lib: %s"), openerror);
        return nullptr;
    }
        const char* symerror = dlerror();
        if(symerror){
            LOGE(OBFUSCATE("Error Finding Symbol: %s"), symerror);
            return nullptr;
        }
        monoString *(*il2cpp_string_new)(const char *) = (monoString *(*)(const char *))dlsym(handle, OBFUSCATE("il2cpp_string_new"));
        return il2cpp_string_new(str);
}

