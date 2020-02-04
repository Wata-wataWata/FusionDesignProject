// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TEMPURARUN_UdpReceiver_generated_h
#error "UdpReceiver.generated.h already included, missing '#pragma once' in UdpReceiver.h"
#endif
#define TEMPURARUN_UdpReceiver_generated_h

#define TempuraRun_Source_TempuraRun_UdpReceiver_h_14_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetPos) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetPos(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetIsJumping) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->GetIsJumping(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetSpeed) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetSpeed(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execClose) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Close(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConnect) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->Connect(); \
		P_NATIVE_END; \
	}


#define TempuraRun_Source_TempuraRun_UdpReceiver_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetPos) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetPos(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetIsJumping) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->GetIsJumping(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetSpeed) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetSpeed(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execClose) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Close(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConnect) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->Connect(); \
		P_NATIVE_END; \
	}


#define TempuraRun_Source_TempuraRun_UdpReceiver_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAUdpReceiver(); \
	friend struct Z_Construct_UClass_AUdpReceiver_Statics; \
public: \
	DECLARE_CLASS(AUdpReceiver, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/TempuraRun"), NO_API) \
	DECLARE_SERIALIZER(AUdpReceiver)


#define TempuraRun_Source_TempuraRun_UdpReceiver_h_14_INCLASS \
private: \
	static void StaticRegisterNativesAUdpReceiver(); \
	friend struct Z_Construct_UClass_AUdpReceiver_Statics; \
public: \
	DECLARE_CLASS(AUdpReceiver, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/TempuraRun"), NO_API) \
	DECLARE_SERIALIZER(AUdpReceiver)


#define TempuraRun_Source_TempuraRun_UdpReceiver_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AUdpReceiver(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AUdpReceiver) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AUdpReceiver); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AUdpReceiver); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AUdpReceiver(AUdpReceiver&&); \
	NO_API AUdpReceiver(const AUdpReceiver&); \
public:


#define TempuraRun_Source_TempuraRun_UdpReceiver_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AUdpReceiver(AUdpReceiver&&); \
	NO_API AUdpReceiver(const AUdpReceiver&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AUdpReceiver); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AUdpReceiver); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AUdpReceiver)


#define TempuraRun_Source_TempuraRun_UdpReceiver_h_14_PRIVATE_PROPERTY_OFFSET
#define TempuraRun_Source_TempuraRun_UdpReceiver_h_11_PROLOG
#define TempuraRun_Source_TempuraRun_UdpReceiver_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TempuraRun_Source_TempuraRun_UdpReceiver_h_14_PRIVATE_PROPERTY_OFFSET \
	TempuraRun_Source_TempuraRun_UdpReceiver_h_14_RPC_WRAPPERS \
	TempuraRun_Source_TempuraRun_UdpReceiver_h_14_INCLASS \
	TempuraRun_Source_TempuraRun_UdpReceiver_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TempuraRun_Source_TempuraRun_UdpReceiver_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TempuraRun_Source_TempuraRun_UdpReceiver_h_14_PRIVATE_PROPERTY_OFFSET \
	TempuraRun_Source_TempuraRun_UdpReceiver_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	TempuraRun_Source_TempuraRun_UdpReceiver_h_14_INCLASS_NO_PURE_DECLS \
	TempuraRun_Source_TempuraRun_UdpReceiver_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TEMPURARUN_API UClass* StaticClass<class AUdpReceiver>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TempuraRun_Source_TempuraRun_UdpReceiver_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
