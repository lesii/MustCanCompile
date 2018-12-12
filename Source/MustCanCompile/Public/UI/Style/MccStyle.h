// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SlateBasics.h"

/**
 * 
 */
class MUSTCANCOMPILE_API MccStyle
{
public:

	static void Initialze();

	static FName GetStyleSetName();

	static void ShutDown();

	static const ISlateStyle& Get();

private:
	static TSharedRef<class FSlateStyleSet> Creat();

	static TSharedPtr<FSlateStyleSet> MccStyleInstance;
};
