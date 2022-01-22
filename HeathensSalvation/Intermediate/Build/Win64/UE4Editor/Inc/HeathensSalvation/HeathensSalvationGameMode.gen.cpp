// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HeathensSalvation/HeathensSalvationGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHeathensSalvationGameMode() {}
// Cross Module References
	HEATHENSSALVATION_API UClass* Z_Construct_UClass_AHeathensSalvationGameMode_NoRegister();
	HEATHENSSALVATION_API UClass* Z_Construct_UClass_AHeathensSalvationGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_HeathensSalvation();
// End Cross Module References
	void AHeathensSalvationGameMode::StaticRegisterNativesAHeathensSalvationGameMode()
	{
	}
	UClass* Z_Construct_UClass_AHeathensSalvationGameMode_NoRegister()
	{
		return AHeathensSalvationGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AHeathensSalvationGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AHeathensSalvationGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_HeathensSalvation,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHeathensSalvationGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "HeathensSalvationGameMode.h" },
		{ "ModuleRelativePath", "HeathensSalvationGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AHeathensSalvationGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AHeathensSalvationGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AHeathensSalvationGameMode_Statics::ClassParams = {
		&AHeathensSalvationGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_AHeathensSalvationGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AHeathensSalvationGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AHeathensSalvationGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AHeathensSalvationGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AHeathensSalvationGameMode, 1124160977);
	template<> HEATHENSSALVATION_API UClass* StaticClass<AHeathensSalvationGameMode>()
	{
		return AHeathensSalvationGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AHeathensSalvationGameMode(Z_Construct_UClass_AHeathensSalvationGameMode, &AHeathensSalvationGameMode::StaticClass, TEXT("/Script/HeathensSalvation"), TEXT("AHeathensSalvationGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AHeathensSalvationGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
