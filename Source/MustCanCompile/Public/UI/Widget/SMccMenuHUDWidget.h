// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "SOverlay.h"

/**
 * 
 */
class MUSTCANCOMPILE_API SMccMenuHUDWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMccMenuHUDWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);


private:
	float GetUIScaler() const;
	FVector2D GetViewportSize() const;

	FReply OnClick();

private:

	//��ȡMenu��ʽ
	const struct FMccMenuStyle * MenuStyle;

	//DPI����ϵ��
	TAttribute<float> UIScaler;

	TSharedPtr<class SMccMenuWidget> MenuWidget;

	//SOverlay::FOverlaySlot* ImageSlot;	//Ѱ��SOverlay���е�FOverlaySlot���ָ�����
};