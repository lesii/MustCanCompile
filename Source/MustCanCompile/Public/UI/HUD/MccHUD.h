// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MccHUD.generated.h"

/**
 * 
 */
UCLASS()
class MUSTCANCOMPILE_API AMccHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	AMccHUD();

	TSharedPtr<class SMccMenuHUDWidget> MenuHUDWidget;

};
