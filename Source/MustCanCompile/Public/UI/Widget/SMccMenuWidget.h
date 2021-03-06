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

	TSharedPtr<SBox> RootSizeBox;	//保存根节点

	TSharedPtr<STextBlock> TittleText;	//保存标题文字

	TSharedPtr<SVerticalBox> ContentBox;	//保存垂直内容列表

};
