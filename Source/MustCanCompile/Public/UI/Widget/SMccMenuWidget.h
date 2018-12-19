// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "MccTypes.h"
/**
 * 
 */

class SVerticalBox;

class MUSTCANCOMPILE_API SMccMenuWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMccMenuWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);


private:

	void MenuItemOnClicked(EMenuItem::Type ItemType);

private:
	const struct FMccMenuStyle * MenuStyle;

	TSharedPtr<SBox> RootSizeBox;	//������ڵ�

	TSharedPtr<STextBlock> TittleText;	//�����������

	TSharedPtr<SVerticalBox> ContentBox;	//���洹ֱ�����б�

};
