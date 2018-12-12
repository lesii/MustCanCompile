// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MccMenuController.generated.h"

/**
 * 
 */
UCLASS()
class MUSTCANCOMPILE_API AMccMenuController : public APlayerController
{
	GENERATED_BODY()

public:
	AMccMenuController();

protected:
	virtual void  BeginPlay() override;

};
