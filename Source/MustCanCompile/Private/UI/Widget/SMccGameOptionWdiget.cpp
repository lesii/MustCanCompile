// Fill out your copyright notice in the Description page of Project Settings.

#include "SMccGameOptionWdiget.h"
#include "SlateOptMacros.h"
#include "MccStyle.h"
#include "MccMenuWidgetStyle.h"
#include "SBox.h"
#include "SImage.h"
#include "SBorder.h"
#include "SOverlay.h"
#include "STextBlock.h"
#include "SBoxPanel.h"
#include "SCheckBox.h"
#include "MccDataHandle.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SMccGameOptionWdiget::Construct(const FArguments& InArgs)
{
	MenuStyle = &MccStyle::Get().GetWidgetStyle<FMccMenuStyle>("BPMccMenuStyle");

	ChildSlot
		[
			SNew(SBox)
			.WidthOverride(500.f)
		.HeightOverride(300.f)
		[
			SNew(SOverlay)
			+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		[
			SNew(SImage)
			.Image(&MenuStyle->GameOptionBGBrush)
		]	//SOverlaySlot结束

	+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		.Padding(FMargin(50.f))
		[
			SNew(SVerticalBox)
			//第一行
		+ SVerticalBox::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		.FillHeight(1.f)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		.FillWidth(1.f)
		[
			SAssignNew(ZhCheckBox, SCheckBox)
			.OnCheckStateChanged(this, &SMccGameOptionWdiget::ZhCheckBoxStateChanged)
		[
			SNew(STextBlock)
			.Font(MenuStyle->Font_40)
		.ColorAndOpacity(MenuStyle->FontColor_Black)
		.Text(NSLOCTEXT("MccMenu", "Chinese", "Chinese"))
		]	//	checkBox结束

		]	//SOverlay Slot结束

	+ SHorizontalBox::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		.FillWidth(1.f)
		[
			SAssignNew(EnCheckBox, SCheckBox)
			.OnCheckStateChanged(this, &SMccGameOptionWdiget::EnCheckBoxStateChanged)
		[
			SNew(STextBlock)
			.Font(MenuStyle->Font_40)
		.ColorAndOpacity(MenuStyle->FontColor_Black)
		.Text(NSLOCTEXT("MccMenu", "English", "English"))
		]	//checkBox结束

		]	//HorizontalBoxSlot结束

		]	//VerticalBoxSlot结束


	//第二行
	+SVerticalBox::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		.FillHeight(1.f)
		[
			SNew(SOverlay)
		]	//VerticalBoxSlot结束


	//第三行
	+SVerticalBox::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		.FillHeight(1.f)
		[
			SNew(SOverlay)
		]	//VerticalBoxSlot结束

		]	//SOverlaySlot结束

		]	//SBOX结束

		];	//ChildeSlot结束

	StyleInitialize();

}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SMccGameOptionWdiget::StyleInitialize()
{
	//中文样式
	ZhCheckBox->SetUncheckedImage(&MenuStyle->UncheckedBoxBrush);
	ZhCheckBox->SetUncheckedHoveredImage(&MenuStyle->UncheckedBoxBrush);
	ZhCheckBox->SetUncheckedPressedImage(&MenuStyle->UncheckedBoxBrush);
	ZhCheckBox->SetCheckedImage(&MenuStyle->CheckedBoxBrush);
	ZhCheckBox->SetCheckedHoveredImage(&MenuStyle->CheckedBoxBrush);
	ZhCheckBox->SetCheckedPressedImage(&MenuStyle->CheckedBoxBrush);

	//英文样式
	EnCheckBox->SetUncheckedImage(&MenuStyle->UncheckedBoxBrush);
	EnCheckBox->SetUncheckedHoveredImage(&MenuStyle->UncheckedBoxBrush);
	EnCheckBox->SetUncheckedPressedImage(&MenuStyle->UncheckedBoxBrush);
	EnCheckBox->SetCheckedImage(&MenuStyle->CheckedBoxBrush);
	EnCheckBox->SetCheckedHoveredImage(&MenuStyle->CheckedBoxBrush);
	EnCheckBox->SetCheckedPressedImage(&MenuStyle->CheckedBoxBrush);



	switch (MccDataHandle::Get()->CurrentCulture)
	{
	case ECultureTeam::EN:
		EnCheckBox->SetIsChecked(ECheckBoxState::Checked);
		ZhCheckBox->SetIsChecked(ECheckBoxState::Unchecked);
		break;
	case ECultureTeam::ZH:
		EnCheckBox->SetIsChecked(ECheckBoxState::Unchecked);
		ZhCheckBox->SetIsChecked(ECheckBoxState::Checked);
		break;
	}

}

void SMccGameOptionWdiget::ZhCheckBoxStateChanged(ECheckBoxState NewState)
{
	//设置被选中的
	EnCheckBox->SetIsChecked(ECheckBoxState::Unchecked);
	ZhCheckBox->SetIsChecked(ECheckBoxState::Checked);

	//告诉数据控制类转换为中文
	MccDataHandle::Get()->ChangeLocalizationCultrue(ECultureTeam::ZH);

}

void SMccGameOptionWdiget::EnCheckBoxStateChanged(ECheckBoxState NewState)
{
	//设置被选中的
	EnCheckBox->SetIsChecked(ECheckBoxState::Checked);
	ZhCheckBox->SetIsChecked(ECheckBoxState::Unchecked);

	//告诉数据控制类转换为中文
	MccDataHandle::Get()->ChangeLocalizationCultrue(ECultureTeam::EN);
}
