// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/UI/Widget/SMccMenuWidget.h"
#include "SlateOptMacros.h"
#include "MccStyle.h"
#include "MccMenuWidgetStyle.h"
#include "SBox.h"
#include "SBoxPanel.h"
#include "SMccMenuItemWidget.h"
#include "MccTypes.h"
#include "Common/MccHelper.h"
#include "UI/Widget//SMccGameOptionWdiget.h"

/*
//#include "Internationalization.h"

	FInternationalization::Get().SetCurrentCulture(TEXT("en"));	//显示英文
	FInternationalization::Get().SetCurrentCulture(TEXT("ch"));	//显示中文
*/




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
		.Text(NSLOCTEXT("MccMenu","Menu","Menu"))
		]	//SBorder结束	

		]	//SBox结束

		]//Overlay::Slot结束


	+ SOverlay::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Top)
		.Padding(FMargin(0.f, 130.f, 0.f, 0.f))
		[
			SAssignNew(ContentBox, SVerticalBox)
		]	//Slot结束

			]	//SizeBox结束
		];	//ChildSlot结束

	RootSizeBox->SetWidthOverride(600.f);	//设置长宽
	RootSizeBox->SetHeightOverride(510.f);	//设置长宽

	//垂直内容列表Slot
	ContentBox->AddSlot()
		[

			SNew(SMccGameOptionWdiget)
			/*
			SNew(SMccMenuItemWidget)
			.ItemText(NSLOCTEXT("MccMenu", "StartGame", "StartGame"))
			.ItemType(EMenuItem::StartGame)
			.OnClicked(this,&SMccMenuWidget::MenuItemOnClicked)
		*/

		];

}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SMccMenuWidget::MenuItemOnClicked(EMenuItem::Type ItemType)
{
	//MccHelper::Debug(FString("hhhhhh"), 5.f);
}
