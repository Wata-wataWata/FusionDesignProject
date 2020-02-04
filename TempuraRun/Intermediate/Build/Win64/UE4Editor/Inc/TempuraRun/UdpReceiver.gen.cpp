// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TempuraRun/UdpReceiver.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUdpReceiver() {}
// Cross Module References
	TEMPURARUN_API UClass* Z_Construct_UClass_AUdpReceiver_NoRegister();
	TEMPURARUN_API UClass* Z_Construct_UClass_AUdpReceiver();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_TempuraRun();
	TEMPURARUN_API UFunction* Z_Construct_UFunction_AUdpReceiver_Close();
	TEMPURARUN_API UFunction* Z_Construct_UFunction_AUdpReceiver_Connect();
	TEMPURARUN_API UFunction* Z_Construct_UFunction_AUdpReceiver_GetIsJumping();
	TEMPURARUN_API UFunction* Z_Construct_UFunction_AUdpReceiver_GetPos();
	TEMPURARUN_API UFunction* Z_Construct_UFunction_AUdpReceiver_GetSpeed();
// End Cross Module References
	void AUdpReceiver::StaticRegisterNativesAUdpReceiver()
	{
		UClass* Class = AUdpReceiver::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Close", &AUdpReceiver::execClose },
			{ "Connect", &AUdpReceiver::execConnect },
			{ "GetIsJumping", &AUdpReceiver::execGetIsJumping },
			{ "GetPos", &AUdpReceiver::execGetPos },
			{ "GetSpeed", &AUdpReceiver::execGetSpeed },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AUdpReceiver_Close_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AUdpReceiver_Close_Statics::Function_MetaDataParams[] = {
		{ "Category", "UDP" },
		{ "Comment", "/* \xe3\x83\x9d??E\xe3\x83\x88\xe3\x82\x92\xe9\x96\x89\xe3\x81\x98\xe3\x81\xa6\xe5\x8f\x97\xe4\xbf\xa1\xe3\x82\x92\xe7\xb5\x82\xe4\xba\x81""E??\xe3\x81\xbe\xe3\x81\x81""E*/" },
		{ "ModuleRelativePath", "UdpReceiver.h" },
		{ "ToolTip", "\xe3\x83\x9d??E\xe3\x83\x88\xe3\x82\x92\xe9\x96\x89\xe3\x81\x98\xe3\x81\xa6\xe5\x8f\x97\xe4\xbf\xa1\xe3\x82\x92\xe7\xb5\x82\xe4\xba\x81""E??\xe3\x81\xbe\xe3\x81\x81""E" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AUdpReceiver_Close_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AUdpReceiver, nullptr, "Close", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AUdpReceiver_Close_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AUdpReceiver_Close_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AUdpReceiver_Close()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AUdpReceiver_Close_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AUdpReceiver_Connect_Statics
	{
		struct UdpReceiver_eventConnect_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AUdpReceiver_Connect_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((UdpReceiver_eventConnect_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AUdpReceiver_Connect_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UdpReceiver_eventConnect_Parms), &Z_Construct_UFunction_AUdpReceiver_Connect_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AUdpReceiver_Connect_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AUdpReceiver_Connect_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AUdpReceiver_Connect_Statics::Function_MetaDataParams[] = {
		{ "Category", "UDP" },
		{ "Comment", "/* \xe3\x83\x9d??E\xe3\x83\x88\xe3\x82\x92\xe9\x96\x8b\xe3\x81\x84\xe3\x81\xa6\xe5\x8f\x97\xe4\xbf\xa1\xe5\xbe\x81""E??\xe3\x81\xab\xe3\x81\x97\xe3\x81\xbe\xe3\x81\x81""E*/" },
		{ "ModuleRelativePath", "UdpReceiver.h" },
		{ "ToolTip", "\xe3\x83\x9d??E\xe3\x83\x88\xe3\x82\x92\xe9\x96\x8b\xe3\x81\x84\xe3\x81\xa6\xe5\x8f\x97\xe4\xbf\xa1\xe5\xbe\x81""E??\xe3\x81\xab\xe3\x81\x97\xe3\x81\xbe\xe3\x81\x81""E" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AUdpReceiver_Connect_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AUdpReceiver, nullptr, "Connect", nullptr, nullptr, sizeof(UdpReceiver_eventConnect_Parms), Z_Construct_UFunction_AUdpReceiver_Connect_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AUdpReceiver_Connect_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AUdpReceiver_Connect_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AUdpReceiver_Connect_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AUdpReceiver_Connect()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AUdpReceiver_Connect_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AUdpReceiver_GetIsJumping_Statics
	{
		struct UdpReceiver_eventGetIsJumping_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AUdpReceiver_GetIsJumping_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((UdpReceiver_eventGetIsJumping_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AUdpReceiver_GetIsJumping_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UdpReceiver_eventGetIsJumping_Parms), &Z_Construct_UFunction_AUdpReceiver_GetIsJumping_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AUdpReceiver_GetIsJumping_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AUdpReceiver_GetIsJumping_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AUdpReceiver_GetIsJumping_Statics::Function_MetaDataParams[] = {
		{ "Category", "Get parameter" },
		{ "ModuleRelativePath", "UdpReceiver.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AUdpReceiver_GetIsJumping_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AUdpReceiver, nullptr, "GetIsJumping", nullptr, nullptr, sizeof(UdpReceiver_eventGetIsJumping_Parms), Z_Construct_UFunction_AUdpReceiver_GetIsJumping_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AUdpReceiver_GetIsJumping_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AUdpReceiver_GetIsJumping_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AUdpReceiver_GetIsJumping_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AUdpReceiver_GetIsJumping()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AUdpReceiver_GetIsJumping_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AUdpReceiver_GetPos_Statics
	{
		struct UdpReceiver_eventGetPos_Parms
		{
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AUdpReceiver_GetPos_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UdpReceiver_eventGetPos_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AUdpReceiver_GetPos_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AUdpReceiver_GetPos_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AUdpReceiver_GetPos_Statics::Function_MetaDataParams[] = {
		{ "Category", "Get parameter" },
		{ "ModuleRelativePath", "UdpReceiver.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AUdpReceiver_GetPos_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AUdpReceiver, nullptr, "GetPos", nullptr, nullptr, sizeof(UdpReceiver_eventGetPos_Parms), Z_Construct_UFunction_AUdpReceiver_GetPos_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AUdpReceiver_GetPos_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AUdpReceiver_GetPos_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AUdpReceiver_GetPos_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AUdpReceiver_GetPos()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AUdpReceiver_GetPos_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AUdpReceiver_GetSpeed_Statics
	{
		struct UdpReceiver_eventGetSpeed_Parms
		{
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AUdpReceiver_GetSpeed_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UdpReceiver_eventGetSpeed_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AUdpReceiver_GetSpeed_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AUdpReceiver_GetSpeed_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AUdpReceiver_GetSpeed_Statics::Function_MetaDataParams[] = {
		{ "Category", "Get parameter" },
		{ "ModuleRelativePath", "UdpReceiver.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AUdpReceiver_GetSpeed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AUdpReceiver, nullptr, "GetSpeed", nullptr, nullptr, sizeof(UdpReceiver_eventGetSpeed_Parms), Z_Construct_UFunction_AUdpReceiver_GetSpeed_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AUdpReceiver_GetSpeed_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AUdpReceiver_GetSpeed_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AUdpReceiver_GetSpeed_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AUdpReceiver_GetSpeed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AUdpReceiver_GetSpeed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AUdpReceiver_NoRegister()
	{
		return AUdpReceiver::StaticClass();
	}
	struct Z_Construct_UClass_AUdpReceiver_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Port_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Port;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AUdpReceiver_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_TempuraRun,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AUdpReceiver_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AUdpReceiver_Close, "Close" }, // 394410419
		{ &Z_Construct_UFunction_AUdpReceiver_Connect, "Connect" }, // 994726508
		{ &Z_Construct_UFunction_AUdpReceiver_GetIsJumping, "GetIsJumping" }, // 3715693224
		{ &Z_Construct_UFunction_AUdpReceiver_GetPos, "GetPos" }, // 3968818053
		{ &Z_Construct_UFunction_AUdpReceiver_GetSpeed, "GetSpeed" }, // 527684869
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AUdpReceiver_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "UdpReceiver.h" },
		{ "ModuleRelativePath", "UdpReceiver.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AUdpReceiver_Statics::NewProp_Port_MetaData[] = {
		{ "Category", "UDP" },
		{ "Comment", "/* UDP\xe5\xbe\x81""E??\xe5\x8f\x97\xe3\x81\x91\xe3\x83\x9d??E\xe3\x83\x88\xe7\x95\xaa\xe5\x8f\xb7 */" },
		{ "ModuleRelativePath", "UdpReceiver.h" },
		{ "ToolTip", "UDP\xe5\xbe\x81""E??\xe5\x8f\x97\xe3\x81\x91\xe3\x83\x9d??E\xe3\x83\x88\xe7\x95\xaa\xe5\x8f\xb7" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_AUdpReceiver_Statics::NewProp_Port = { "Port", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AUdpReceiver, Port), METADATA_PARAMS(Z_Construct_UClass_AUdpReceiver_Statics::NewProp_Port_MetaData, ARRAY_COUNT(Z_Construct_UClass_AUdpReceiver_Statics::NewProp_Port_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AUdpReceiver_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AUdpReceiver_Statics::NewProp_Port,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AUdpReceiver_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AUdpReceiver>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AUdpReceiver_Statics::ClassParams = {
		&AUdpReceiver::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AUdpReceiver_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		ARRAY_COUNT(FuncInfo),
		ARRAY_COUNT(Z_Construct_UClass_AUdpReceiver_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(Z_Construct_UClass_AUdpReceiver_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AUdpReceiver_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AUdpReceiver()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AUdpReceiver_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AUdpReceiver, 1461251088);
	template<> TEMPURARUN_API UClass* StaticClass<AUdpReceiver>()
	{
		return AUdpReceiver::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AUdpReceiver(Z_Construct_UClass_AUdpReceiver, &AUdpReceiver::StaticClass, TEXT("/Script/TempuraRun"), TEXT("AUdpReceiver"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AUdpReceiver);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
