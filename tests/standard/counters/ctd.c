#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

#include <munit/munit.h>

#include <echidna.h>
#include <ll.h>
#include <macros.h>
#include <runtime.h>
#include <symbol.h>
#include <value.h>

#include <suite.h>


//  xxd -i src/ctd.txt

static char _Source[] = {

    0x50, 0x52, 0x4f, 0x47, 0x52, 0x41, 0x4d, 0x20, 
    0x74, 0x65, 0x73, 0x74, 0x0a, 0x56, 0x41, 0x52, 
    0x20, 0x69, 0x6e, 0x70, 0x75, 0x74, 0x2c, 0x20, 
    0x72, 0x65, 0x73, 0x65, 0x74, 0x3a, 0x20, 0x42, 
    0x4f, 0x4f, 0x4c, 0x20, 0x3a, 0x3d, 0x20, 0x46, 
    0x41, 0x4c, 0x53, 0x45, 0x3b, 0x20, 0x45, 0x4e, 
    0x44, 0x5f, 0x56, 0x41, 0x52, 0x0a, 0x56, 0x41, 
    0x52, 0x20, 0x63, 0x6f, 0x75, 0x6e, 0x74, 0x3a, 
    0x20, 0x25, 0x73, 0x20, 0x3a, 0x3d, 0x20, 0x30, 
    0x3b, 0x20, 0x45, 0x4e, 0x44, 0x5f, 0x56, 0x41, 
    0x52, 0x0a, 0x56, 0x41, 0x52, 0x20, 0x6d, 0x61, 
    0x78, 0x69, 0x6d, 0x75, 0x6d, 0x3a, 0x20, 0x25, 
    0x73, 0x20, 0x3a, 0x3d, 0x20, 0x35, 0x3b, 0x20, 
    0x45, 0x4e, 0x44, 0x5f, 0x56, 0x41, 0x52, 0x0a, 
    0x56, 0x41, 0x52, 0x20, 0x66, 0x62, 0x3a, 0x20, 
    0x43, 0x54, 0x44, 0x3b, 0x20, 0x45, 0x4e, 0x44, 
    0x5f, 0x56, 0x41, 0x52, 0x0a, 0x0a, 0x41, 0x44, 
    0x44, 0x20, 0x63, 0x6f, 0x75, 0x6e, 0x74, 0x2c, 
    0x20, 0x31, 0x0a, 0x53, 0x54, 0x20, 0x63, 0x6f, 
    0x75, 0x6e, 0x74, 0x0a, 0x0a, 0x4c, 0x44, 0x20, 
    0x63, 0x6f, 0x75, 0x6e, 0x74, 0x0a, 0x4d, 0x4f, 
    0x44, 0x20, 0x32, 0x0a, 0x45, 0x51, 0x20, 0x30, 
    0x0a, 0x53, 0x54, 0x20, 0x69, 0x6e, 0x70, 0x75, 
    0x74, 0x0a, 0x0a, 0x4c, 0x44, 0x20, 0x63, 0x6f, 
    0x75, 0x6e, 0x74, 0x0a, 0x4d, 0x4f, 0x44, 0x20, 
    0x31, 0x35, 0x0a, 0x45, 0x51, 0x20, 0x31, 0x0a, 
    0x53, 0x54, 0x20, 0x72, 0x65, 0x73, 0x65, 0x74, 
    0x0a, 0x0a, 0x43, 0x41, 0x4c, 0x20, 0x66, 0x62, 
    0x28, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x43, 0x44, 
    0x20, 0x3a, 0x3d, 0x20, 0x69, 0x6e, 0x70, 0x75, 
    0x74, 0x2c, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x4c, 
    0x44, 0x20, 0x3a, 0x3d, 0x20, 0x72, 0x65, 0x73, 
    0x65, 0x74, 0x2c, 0x0a, 0x20, 0x20, 0x20, 0x20, 
    0x50, 0x56, 0x20, 0x3a, 0x3d, 0x20, 0x6d, 0x61, 
    0x78, 0x69, 0x6d, 0x75, 0x6d, 0x0a, 0x29, 0x0a, 
    0x0a, 0x4c, 0x44, 0x20, 0x63, 0x6f, 0x75, 0x6e, 
    0x74, 0x0a, 0x45, 0x51, 0x20, 0x32, 0x30, 0x0a, 
    0x52, 0x45, 0x54, 0x43, 0x4e, 0x0a, 0x5f, 0x65, 
    0x78, 0x69, 0x74, 0x0a, 0x0a, 0x45, 0x4e, 0x44, 
    0x5f, 0x50, 0x52, 0x4f, 0x47, 0x52, 0x41, 0x4d, 
    0x0a, 0x0a, 0x43, 0x4f, 0x4e, 0x46, 0x49, 0x47, 
    0x55, 0x52, 0x41, 0x54, 0x49, 0x4f, 0x4e, 0x20, 
    0x63, 0x6f, 0x6e, 0x66, 0x69, 0x67, 0x31, 0x0a, 
    0x54, 0x41, 0x53, 0x4b, 0x20, 0x74, 0x61, 0x73, 
    0x6b, 0x31, 0x20, 0x28, 0x49, 0x4e, 0x54, 0x45, 
    0x52, 0x56, 0x41, 0x4c, 0x20, 0x3a, 0x3d, 0x20, 
    0x74, 0x23, 0x31, 0x30, 0x6d, 0x73, 0x2c, 0x20, 
    0x50, 0x52, 0x49, 0x4f, 0x52, 0x49, 0x54, 0x59, 
    0x20, 0x3a, 0x3d, 0x20, 0x31, 0x29, 0x3b, 0x0a, 
    0x50, 0x52, 0x4f, 0x47, 0x52, 0x41, 0x4d, 0x20, 
    0x70, 0x72, 0x6f, 0x67, 0x72, 0x61, 0x6d, 0x31, 
    0x20, 0x57, 0x49, 0x54, 0x48, 0x20, 0x74, 0x61, 
    0x73, 0x6b, 0x31, 0x3a, 0x20, 0x74, 0x65, 0x73, 
    0x74, 0x3b, 0x0a, 0x45, 0x4e, 0x44, 0x5f, 0x43, 
    0x4f, 0x4e, 0x46, 0x49, 0x47, 0x55, 0x52, 0x41, 
    0x54, 0x49, 0x4f, 0x4e, 0x0a, 0x00
};

//  xxd -i src/ctd_type.txt

static char _Source_Type[] = {

    0x50, 0x52, 0x4f, 0x47, 0x52, 0x41, 0x4d, 0x20, 
    0x74, 0x65, 0x73, 0x74, 0x0a, 0x56, 0x41, 0x52, 
    0x20, 0x69, 0x6e, 0x70, 0x75, 0x74, 0x2c, 0x20, 
    0x72, 0x65, 0x73, 0x65, 0x74, 0x3a, 0x20, 0x42, 
    0x4f, 0x4f, 0x4c, 0x20, 0x3a, 0x3d, 0x20, 0x46, 
    0x41, 0x4c, 0x53, 0x45, 0x3b, 0x20, 0x45, 0x4e, 
    0x44, 0x5f, 0x56, 0x41, 0x52, 0x0a, 0x56, 0x41, 
    0x52, 0x20, 0x63, 0x6f, 0x75, 0x6e, 0x74, 0x3a, 
    0x20, 0x25, 0x73, 0x20, 0x3a, 0x3d, 0x20, 0x30, 
    0x3b, 0x20, 0x45, 0x4e, 0x44, 0x5f, 0x56, 0x41, 
    0x52, 0x0a, 0x56, 0x41, 0x52, 0x20, 0x6d, 0x61, 
    0x78, 0x69, 0x6d, 0x75, 0x6d, 0x3a, 0x20, 0x25, 
    0x73, 0x20, 0x3a, 0x3d, 0x20, 0x35, 0x3b, 0x20, 
    0x45, 0x4e, 0x44, 0x5f, 0x56, 0x41, 0x52, 0x0a, 
    0x56, 0x41, 0x52, 0x20, 0x66, 0x62, 0x3a, 0x20, 
    0x43, 0x54, 0x44, 0x5f, 0x25, 0x73, 0x3b, 0x20, 
    0x45, 0x4e, 0x44, 0x5f, 0x56, 0x41, 0x52, 0x0a, 
    0x0a, 0x41, 0x44, 0x44, 0x20, 0x63, 0x6f, 0x75, 
    0x6e, 0x74, 0x2c, 0x20, 0x31, 0x0a, 0x53, 0x54, 
    0x20, 0x63, 0x6f, 0x75, 0x6e, 0x74, 0x0a, 0x0a, 
    0x4c, 0x44, 0x20, 0x63, 0x6f, 0x75, 0x6e, 0x74, 
    0x0a, 0x4d, 0x4f, 0x44, 0x20, 0x32, 0x0a, 0x45, 
    0x51, 0x20, 0x30, 0x0a, 0x53, 0x54, 0x20, 0x69, 
    0x6e, 0x70, 0x75, 0x74, 0x0a, 0x0a, 0x4c, 0x44, 
    0x20, 0x63, 0x6f, 0x75, 0x6e, 0x74, 0x0a, 0x4d, 
    0x4f, 0x44, 0x20, 0x31, 0x35, 0x0a, 0x45, 0x51, 
    0x20, 0x31, 0x0a, 0x53, 0x54, 0x20, 0x72, 0x65, 
    0x73, 0x65, 0x74, 0x0a, 0x0a, 0x43, 0x41, 0x4c, 
    0x20, 0x66, 0x62, 0x28, 0x0a, 0x20, 0x20, 0x20, 
    0x20, 0x43, 0x44, 0x20, 0x3a, 0x3d, 0x20, 0x69, 
    0x6e, 0x70, 0x75, 0x74, 0x2c, 0x0a, 0x20, 0x20, 
    0x20, 0x20, 0x4c, 0x44, 0x20, 0x3a, 0x3d, 0x20, 
    0x72, 0x65, 0x73, 0x65, 0x74, 0x2c, 0x0a, 0x20, 
    0x20, 0x20, 0x20, 0x50, 0x56, 0x20, 0x3a, 0x3d, 
    0x20, 0x6d, 0x61, 0x78, 0x69, 0x6d, 0x75, 0x6d, 
    0x0a, 0x29, 0x0a, 0x0a, 0x4c, 0x44, 0x20, 0x63, 
    0x6f, 0x75, 0x6e, 0x74, 0x0a, 0x45, 0x51, 0x20, 
    0x32, 0x30, 0x0a, 0x52, 0x45, 0x54, 0x43, 0x4e, 
    0x0a, 0x5f, 0x65, 0x78, 0x69, 0x74, 0x0a, 0x0a, 
    0x45, 0x4e, 0x44, 0x5f, 0x50, 0x52, 0x4f, 0x47, 
    0x52, 0x41, 0x4d, 0x0a, 0x0a, 0x43, 0x4f, 0x4e, 
    0x46, 0x49, 0x47, 0x55, 0x52, 0x41, 0x54, 0x49, 
    0x4f, 0x4e, 0x20, 0x63, 0x6f, 0x6e, 0x66, 0x69, 
    0x67, 0x31, 0x0a, 0x54, 0x41, 0x53, 0x4b, 0x20, 
    0x74, 0x61, 0x73, 0x6b, 0x31, 0x20, 0x28, 0x49, 
    0x4e, 0x54, 0x45, 0x52, 0x56, 0x41, 0x4c, 0x20, 
    0x3a, 0x3d, 0x20, 0x74, 0x23, 0x31, 0x30, 0x6d, 
    0x73, 0x2c, 0x20, 0x50, 0x52, 0x49, 0x4f, 0x52, 
    0x49, 0x54, 0x59, 0x20, 0x3a, 0x3d, 0x20, 0x31, 
    0x29, 0x3b, 0x0a, 0x50, 0x52, 0x4f, 0x47, 0x52, 
    0x41, 0x4d, 0x20, 0x70, 0x72, 0x6f, 0x67, 0x72, 
    0x61, 0x6d, 0x31, 0x20, 0x57, 0x49, 0x54, 0x48, 
    0x20, 0x74, 0x61, 0x73, 0x6b, 0x31, 0x3a, 0x20, 
    0x74, 0x65, 0x73, 0x74, 0x3b, 0x0a, 0x45, 0x4e, 
    0x44, 0x5f, 0x43, 0x4f, 0x4e, 0x46, 0x49, 0x47, 
    0x55, 0x52, 0x41, 0x54, 0x49, 0x4f, 0x4e, 0x0a, 
    0x00
};

static int _Cycle = 0;

static VALUE_TYPE _Type[] = {
    TYPE_LINT,
    TYPE_DINT,
    TYPE_INT,
    TYPE_SINT,
    TYPE_ULINT,
    TYPE_UDINT,
    TYPE_UINT,
    TYPE_USINT,
    
    TYPE_NONE
};

static int _Value[] = { 5, 4, 4, 3, 3, 2, 2, 1, 1, 0, 0, -1, -1, -2, -2, 5, 5, 4, 4, 3 };


static void
_test_counter_callback(ECHIDNA *Context, void *Arg, void *User) {
    RUNTIME *pRun;
    RUNTIME_CONTEXT *pContext;
    SYMBOL *pSymbol;
    VALUE sValue;
    uint8_t uValue;
    
    /* Arg == &RUNTIME_CONTEXT.Stats */
    munit_assert_not_null(Arg);
    munit_assert_not_null(pContext = container_of(Arg, RUNTIME_CONTEXT, Stats));
    munit_assert_not_null(pRun = (RUNTIME *) pContext->Parent);
    munit_assert_int(_Cycle, >=, 0);
    munit_assert_int(_Cycle, <, 20);
    
    munit_assert_not_null(pSymbol = symbol_search(Context, "config1", "__Single", "program1", "fb.CV"));
    value_copy(&sValue, &pSymbol->Value);
    memcpy((char *) &sValue.Value.Pointer, &pRun->Memory[pSymbol->Offset], sValue.Length);
    if(_Value[_Cycle] < 0) {
        switch(sValue.Type) {
            case TYPE_LINT:
            case TYPE_DINT:
            case TYPE_INT:
            case TYPE_SINT:
                munit_assert_int(value_cast(&sValue, TYPE_DINT), ==, 0);
                munit_assert_int(_Value[_Cycle], ==, sValue.Value.S32);
                break;

            default:
                break;
        }
    }
    
    munit_assert_not_null(pSymbol = symbol_search(Context, "config1", "__Single", "program1", "fb.Q"));
    value_copy(&sValue, &pSymbol->Value);
    memcpy((char *) &sValue.Value.Pointer, &pRun->Memory[pSymbol->Offset], sValue.Length);
    munit_assert_uint32(sValue.Type, ==, TYPE_BOOL);
    uValue = (uint8_t) (_Value[_Cycle] <= 0);
    munit_assert_uint8(sValue.Value.B1, ==, uValue);

    ++_Cycle;
}


MunitResult
test_counters_ctd(const MunitParameter Parameters[], void *Fixture) {
    ECHIDNA *pContext;
    char sBuffer[1024];
    const char *pType;
    int nIndex, nType;

    nIndex = 0;
    do {       
        nType = _Type[nIndex];

        pContext = (ECHIDNA *) suite_setup(Parameters, NULL);
        pType = value_typetostr(nType);
        snprintf(sBuffer, sizeof(sBuffer), _Source, pType, pType);
        munit_assert_int(test_parse(pContext, sBuffer), ==, 0);
        pContext->Option |= (OPTION_COMPILE | OPTION_NOSIGNAL | OPTION_RUN);
        pContext->Output = NULL;
        munit_assert_int(echidna_compile(pContext), ==, 0);
        
        _Cycle = 0;
        munit_assert_int(echidna_callback(pContext, CALLBACK_CYCLE_FINISH, NULL, _test_counter_callback), ==, 0);
        munit_assert_int(echidna_run(pContext), ==, 0);
        munit_assert_int(_Cycle, ==, 20);
        suite_teardown(pContext);
    }
    while(_Type[++nIndex] != TYPE_NONE);

    return MUNIT_OK;
}


MunitResult
test_counters_ctdtype(const MunitParameter Parameters[], void *Fixture) {
    ECHIDNA *pContext;
    char sBuffer[1024];
    const char *pType;
    int nIndex, nType;

    nIndex = 0;
    do {       
        nType = _Type[nIndex];

        pContext = (ECHIDNA *) suite_setup(Parameters, NULL);
        pType = value_typetostr(nType);
        snprintf(sBuffer, sizeof(sBuffer), _Source_Type, pType, pType, pType);
        munit_assert_int(test_parse(pContext, sBuffer), ==, 0);
        pContext->Option |= (OPTION_COMPILE | OPTION_NOSIGNAL | OPTION_RUN);
        pContext->Output = NULL;
        munit_assert_int(echidna_compile(pContext), ==, 0);
        
        _Cycle = 0;
        munit_assert_int(echidna_callback(pContext, CALLBACK_CYCLE_FINISH, NULL, _test_counter_callback), ==, 0);
        munit_assert_int(echidna_run(pContext), ==, 0);
        munit_assert_int(_Cycle, ==, 20);
        suite_teardown(pContext);
    }
    while(_Type[++nIndex] != TYPE_NONE);

    //  TODO: Add CTD_* tests with invalid PV parameter - Need error callback handler
    
    return MUNIT_OK;
}


