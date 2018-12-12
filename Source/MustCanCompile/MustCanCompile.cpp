// Fill out your copyright notice in the Description page of Project Settings.

#include "MustCanCompile.h"
#include "Modules/ModuleManager.h"
#include "SlateStyleRegistry.h"
#include "UI/Style/MccStyle.h"


void FMustCanCompileModule::StartupModule()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(MccStyle::GetStyleSetName());
	MccStyle::Initialze();
}

void FMustCanCompileModule::ShutdownModule()
{
	MccStyle::ShutDown();
}

IMPLEMENT_PRIMARY_GAME_MODULE(FMustCanCompileModule, MustCanCompile, "MustCanCompile");
