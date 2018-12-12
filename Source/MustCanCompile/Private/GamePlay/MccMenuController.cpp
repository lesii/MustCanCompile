// Fill out your copyright notice in the Description page of Project Settings.

#include "MccMenuController.h"

AMccMenuController::AMccMenuController()
{
	bShowMouseCursor = true;	//显示鼠标。
}

void AMccMenuController::BeginPlay()
{
	FInputModeUIOnly InputMode;
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::LockAlways);	//锁定鼠标在UI中。
	SetInputMode(InputMode);
}
