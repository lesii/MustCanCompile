// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/Style/MccStyle.h"
#include "SlateGameResources.h"


TSharedPtr<FSlateStyleSet> MccStyle::MccStyleInstance = NULL;

void MccStyle::Initialze()
{
	if (!MccStyleInstance.IsValid()) {
		MccStyleInstance = Creat();
		FSlateStyleRegistry::RegisterSlateStyle(*MccStyleInstance);
	}
}

FName MccStyle::GetStyleSetName()
{
	static FName slateSetName(TEXT("MccStyle"));
	return slateSetName;
}

void MccStyle::ShutDown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*MccStyleInstance);
	ensure(MccStyleInstance.IsUnique());
	MccStyleInstance.Reset();
}

const ISlateStyle& MccStyle::Get()
{
	return *MccStyleInstance;
}

TSharedRef<class FSlateStyleSet> MccStyle::Creat()
{
	TSharedRef<class FSlateStyleSet> styleRef = FSlateGameResources::New(MccStyle::GetStyleSetName(), "/Game/UI/Styles", "/Game/UI/Styles");
	styleRef->Set("MenuItemFont", FSlateFontInfo("Roboto-Regular.ttf", 50));
	return styleRef;
}
