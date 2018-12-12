// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/UI/Widget/SMccMenuWidget.h"
#include "SlateOptMacros.h"
#include "MccStyle.h"
#include "MccMenuWidgetStyle.h"
#include "SBox.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SMccMenuWidget::Construct(const FArguments& InArgs)
{
	MenuStyle = &MccStyle::Get().GetWidgetStyle<FMccMenuStyle>("BPMccMenuStyle");

	ChildSlot
		[
			SAssignNew(RootSizeBox, SBox)
			[
				SNew(SOverlay)
				+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.HAlign(HAlign_Fill)
		.Padding(FMargin(0.f, 50.f, 0.f, 0.f))	//左上右下
		[
			SNew(SImage)
			.Image(&MenuStyle->MenuBackGroundBrush)
		]	//Overlay::Slot结束


	+ SOverlay::Slot()
		.HAlign(HAlign_Right)
		.VAlign(VAlign_Center)
		.Padding(FMargin(0.f, 25.f, 0.f, 0.f))
		[
			SNew(SImage)
			.Image(&MenuStyle->LeftIconBrush)
		]	//Overlay::Slot结束

	+ SOverlay::Slot()
		.HAlign(HAlign_Left)
		.VAlign(VAlign_Center)
		.Padding(FMargin(0.f, 25.f, 0.f, 0.f))
		[
			SNew(SImage)
			.Image(&MenuStyle->LeftIconBrush)
		]	//Overlay::Slot结束


	+ SOverlay::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Top)
		[
			SNew(SBox)
			.WidthOverride(400.f)
		.HeightOverride(100.f)
		[
			SNew(SBorder)
			.BorderImage(&MenuStyle->TitleBorderBrush)
		.HAlign(HAlign_Center)	//设置子控件的位置
		.VAlign(VAlign_Center)
		[
			SAssignNew(TittleText, STextBlock)
			.Font(MccStyle::Get().GetFontStyle("MenuItemFont"))
		.Text(FText::FromString("I am LeSii"))
		]	//SBorder结束	

		]	//SBox结束

		]//Overlay::Slot结束



			]	//SizeBox结束
		];	//ChildSlot结束

	RootSizeBox->SetWidthOverride(600.f);	//设置长宽
	RootSizeBox->SetHeightOverride(510.f);	//设置长宽

}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
