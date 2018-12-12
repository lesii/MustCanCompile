// Fill out your copyright notice in the Description page of Project Settings.

#include "MccMenuController.h"

AMccMenuController::AMccMenuController()
{
	bShowMouseCursor = true;	//��ʾ��ꡣ
}

void AMccMenuController::BeginPlay()
{
	FInputModeUIOnly InputMode;
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::LockAlways);	//���������UI�С�
	SetInputMode(InputMode);
}
