// Fill out your copyright notice in the Description page of Project Settings.

#include "MenuGameMode.h"
#include "MccMenuController.h"
#include "UI/HUD/MccHUD.h"


AMenuGameMode::AMenuGameMode()
{
	PlayerControllerClass = AMccMenuController::StaticClass();
	HUDClass = AMccHUD::StaticClass();
}
