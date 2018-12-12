// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/HUD/MccHUD.h"
#include "UI/Widget/SMccMenuHUDWidget.h"
#include "SlateBasics.h"
#include "Engine/Engine.h"

AMccHUD::AMccHUD()
{
	if (GEngine && GEngine->GameViewport) {
		SAssignNew(MenuHUDWidget, SMccMenuHUDWidget);
		GEngine->GameViewport->AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(MenuHUDWidget.ToSharedRef()));
	}

}
