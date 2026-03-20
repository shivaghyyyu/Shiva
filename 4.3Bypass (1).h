#include <jni.h>
#include <string>
#include <list>
#include <vector>
#include <string.h>
#include <pthread.h>
#include <vector>
#include <thread>
#include <jni.h>
#include <fstream>
#include <unistd.h>
#include <sys/mman.h>
#include <unwind.h>
#include <dlfcn.h>
#include <libgen.h>
#include <stdint.h>
#include <cstring>
#include <functional>
#include <iostream>
#include <unordered_map>
#include <string>
#include <cstdlib>
#include <ctime>
#include <chrono> 
#include <fcntl.h>
#include <sys/stat.h>
#include <cstddef>
#include <semaphore.h>
#include <stdint.h>
#include <sstream>
#include <stdarg.h>
#include <stdio.h>
#include <curl/curl.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <stdlib.h>
#include <cstdint>
#include <cstdio>
#include <stdbool.h>
#include "Main/Tools.h" 
#include "Main/Logger.h"
#include "Main/oxorany.h"
#include "Main/obfuscate.h"
#include "Main/Utils.h"
#include "Main/KittyMemory/MemoryPatch.h"
#include <random> //
#include "Main/Dobby/Dobby.h"
#include "Main/Macros.h"

//CRASHFIXER 
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>

class _BYTE;
class _QWORD;
class _DWORD;
class _WORD;
#define _QWORD long
#define _DWORD long
#define _BYTE long
#define _WORD long
//#define HOOK_LIB
#define targetLibName oxorany("libanogs.so")
#define targetLibName oxorany("libUE4.so")
#include <unordered_map>
using namespace std;
#define __int8 char
#define __int16 short
#define __int32 int
#define __int64 long long
#define _BYTE  uint8_t
#define _WORD  uint16_t
#define _DWORD uint32_t
#define _QWORD uint64_t
#define _OWORD uint64_t
#define _BOOL8 uint64_t
char *Offset;
#define ret_zero
#define j_j__free
#define log_suspicious_activity
#define apply_cheat_penalty
#define check_memory_integrity
#define __OFSUB__
#define AnoSDKIoctlOld_0
#define HIWORD
#define JUMPOUT
#define byte_4
#define ARM64_SYSREG
#include <random>
#define _ReadStatusReg
#define BYTE5
#define BYTE4
#define HIBYTE
#define BYTE6
#define sub_95A8204
#define IsMemoryReadable
#define BYTE1
#define BYTE3
#define MEMORY_BASIC_INFORMATION mbi
#define BYTE2
#define _WriteStatusReg
typedef long long int64; 
typedef short int16;     
uintptr_t ANOGS;
uintptr_t UE5;
DWORD EGLBase = 0;
DWORD EGLSize = 0;
DWORD EGLAlloc = 0;
DWORD libcBase = 0;
DWORD libcSize = 0;
DWORD libcAlloc = 0;
DWORD libUE4Base = 0;
DWORD UE4Base = 0;
DWORD libanogsBase = 0;
DWORD libanortBase = 0;
DWORD libanogsAlloc = 0;
DWORD libUE4Alloc = 0;
unsigned int libanogsSize  = 0;
unsigned int libUE4Size  = 0;
DWORD NewBase = 0;
uintptr_t anogs;







// ---------- Base Writer ----------

template<typename T>
bool WriteMemoryy(uintptr_t address, T value) {
    T* ptr = (T*)address;
    *ptr = value;
    return true;
}

uintptr_t get_module_base(const char* module_name) {
    FILE* fp = fopen("/proc/self/maps", "r");
    if (!fp) return 0;

    uintptr_t base = 0;
    char line[512];
    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, module_name)) {
            char* dash = strchr(line, '-');
            if (!dash) continue;
            *dash = 0;
            base = strtoull(line, NULL, 16);
            break;
        }
    }
    fclose(fp);
    return base;
}

// ---------- Generic Macro ----------

#define WRITE_MEMORY(lib, offset, value) do { \
    uintptr_t base = get_module_base(lib); \
    if (base) { \
        WriteMemoryy(base + offset, value); \
    } else { \
        LOGI("Module %s base not found!\n", lib); \
    } \
} while(0)

// ---------- Type-specific Macros ----------

    

int Write_DWORD(long int addr, uint32_t value) {
    Tools::WriteAddr((void*)(addr), (void*)&value, sizeof(uint32_t));
    return 0;
}

int Write_QWORD(long int addr, uint64_t value) {
    Tools::WriteAddr((void*)(addr), (void*)&value, sizeof(uint64_t));
    return 0;
}

int Write_FLOAT(long int addr, float value) {
    Tools::WriteAddr((void*)(addr), (void*)&value, sizeof(float));
    return 0;
}


int Write_DOUBLE(long int addr, double value) {
    Tools::WriteAddr((void*)(addr), (void*)&value, sizeof(double));
    return 0;
}

int Write_BYTE(long int addr, uint8_t value) {
    Tools::WriteAddr((void*)(addr), (void*)&value, sizeof(uint8_t));
    return 0;
}
int Write_WORD(long int addr, uint16_t value) {
    Tools::WriteAddr((void*)(addr), (void*)&value, sizeof(uint16_t));
    return 0;
}

//ADD HOOK DEFINE HERE 
__int64 (*osub_2328F0)(__int64 a1, const char* a2, char a3);
__int64 hsub_2328F0(__int64 a1, const char* a2, char a3)
{
    if (a2 && strstr(a2, "screenshot") ||
        a2 && strstr(a2, "nw_stp_pnts") ||
        a2 && strstr(a2, "XTask_ob_cdn1.zip_report_acc.img") ||
        a2 && strstr(a2, "anti_profiler") ||
        a2 && strstr(a2, "anti_lose_jnienv") ||
        a2 && strstr(a2, "simu_vap"))
    {
        return 0;
    }

    return osub_2328F0(a1, a2, a3);
}

__int64 sub_4633F4()
{
 return 0LL;
}
__int64 sub_461F04()
{
 return 0LL;
}
__int64 sub_4D4C94()
{
 return 0LL;
}

__int64 sub_5026EC()
{
 return 0LL;
}
#include "Main/encrypt_protect.h"
// Hook install (run at init)
 
void *THUNDER1_thread(void *) {
        UE5 = Tools::GetBaseAddress("libUE4.so");
        while (!UE5) {
        UE5 = Tools::GetBaseAddress("libUE4.so");
            sleep(1);
    }
    
    ANOGS = Tools::GetBaseAddress("libanogs.so");
        while (!ANOGS) {
        ANOGS = Tools::GetBaseAddress("libanogs.so");
            sleep(1);
    }
    do {
        sleep(1);
    } while (!isLibraryLoaded(targetLibName));
    libanogsBase = findLibrary("libanogs.so");
    libUE4Base   = findLibrary("libUE4.so");
    
    libanogsAlloc = (DWORD)malloc(libanogsSize);
    libUE4Alloc   = (DWORD)malloc(libUE4Size);
    memcpy((void *)libanogsAlloc, (void *)libanogsBase, libanogsSize);
    memcpy((void *)libUE4Alloc, (void *)libUE4Base, libUE4Size);
    LOGI(" THUNDER BYPASS LOADED");
    LOGI("UE4 size : 0x%04X | ANOGS size : 0x%04X",libUE4Size,libanogsSize);
   #if defined(__aarch64__)
LOGI("====================================================");
LOGI("==========< LIBRARY LOADED BY @SANDIPVIP >==========");
LOGI("====================================================");
HOOK_LIB_NO_ORIG("libanogs.so","0x461F04",sub_461F04);
HOOK_LIB_NO_ORIG("libanogs.so","0x4633F4",sub_4633F4);
HOOK_LIB_NO_ORIG("libanogs.so","0x4D4C94",sub_4D4C94);
HOOK_LIB_NO_ORIG("libanogs.so","0x5026EC",sub_5026EC);
HOOK_LIB("libanogs.so","0x2328F0",hsub_2328F0,osub_2328F0);//C16
PATCH_LIB("libanogs.so","0x213360+0x8","C0 03 5F D6");//LOBBY FIXER 
PATCH_LIB("libanogs.so","0x3A564C","C0 03 5F D6");//VIOLATION
PATCH_LIB("libanogs.so","0x2234B0","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x268174","C0 03 5F D6");//3RD-PARTY
PATCH_LIB("libanogs.so","0x3A4CCC","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x39F56C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x330494","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x583ED40","00 00 80 D2 C0 03 5F D6");
//ELF CHECK
PATCH_LIB("libanogs.so","0x4E057C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x4E62FC","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x4E778C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x4E6E1C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x4E7D64","00 00 80 D2 C0 03 5F D6");
//10 YEAR REMOVER
MemoryPatch::createWithHex("libanogs.so",0x4EDC4C, "00 00 80 52 C0 03 5F D6").Modify();
MemoryPatch::createWithHex("libanogs.so",0x4ED954, "00 00 80 52 C0 03 5F D6").Modify();
//PATCH_LIB("libanogs.so","0x79F3A9A9B8","00 00 80 D2 C0 03 5F D6");

   LOGI(OBFUSCATE("Done"));
#endif
	 
  return NULL;
}



__attribute__((constructor)) void mainload() {
    
   pthread_t ptid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    pthread_create(&ptid, &attr, THUNDER1_thread, NULL);
    pthread_attr_destroy(&attr);
   
   
    
}
