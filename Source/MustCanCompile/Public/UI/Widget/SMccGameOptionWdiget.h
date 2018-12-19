// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Widgets/SCompoundWidget.h"
#include "CoreMinimal.h"

/**
 * 
 */
class MUSTCANCOMPILE_API SMccGameOptionWdiget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMccGameOptionWdiget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

private:

	void StyleInitialize();

	//中文checkBox事件,参数是ECheckBoxState
	void ZhCheckBoxStateChanged(ECheckBoxState NewState);

	void EnCheckBoxStateChanged(ECheckBoxState NewState);


private:
	const struct FMccMenuStyle * MenuStyle;

	TSharedPtr<SCheckBox> EnCheckBox;
	TSharedPtr<SCheckBox> ZhCheckBox;

};
