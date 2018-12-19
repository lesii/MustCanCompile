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
		]	//SOverlaySlot����

	+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		.Padding(FMargin(50.f))
		[
			SNew(SVerticalBox)
			//��һ��
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
		]	//	checkBox����

		]	//SOverlay Slot����

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
		]	//checkBox����

		]	//HorizontalBoxSlot����

		]	//VerticalBoxSlot����


	//�ڶ���
	+SVerticalBox::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		.FillHeight(1.f)
		[
			SNew(SOverlay)
		]	//VerticalBoxSlot����


	//������
	+SVerticalBox::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		.FillHeight(1.f)
		[
			SNew(SOverlay)
		]	//VerticalBoxSlot����

		]	//SOverlaySlot����

		]	//SBOX����

		];	//ChildeSlot����

	StyleInitialize();

}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SMccGameOptionWdiget::StyleInitialize()
{
	//������ʽ
	ZhCheckBox->SetUncheckedImage(&MenuStyle->UncheckedBoxBrush);
	ZhCheckBox->SetUncheckedHoveredImage(&MenuStyle->UncheckedBoxBrush);
	ZhCheckBox->SetUncheckedPressedImage(&MenuStyle->UncheckedBoxBrush);
	ZhCheckBox->SetCheckedImage(&MenuStyle->CheckedBoxBrush);
	ZhCheckBox->SetCheckedHoveredImage(&MenuStyle->CheckedBoxBrush);
	ZhCheckBox->SetCheckedPressedImage(&MenuStyle->CheckedBoxBrush);

	//Ӣ����ʽ
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
	//���ñ�ѡ�е�
	EnCheckBox->SetIsChecked(ECheckBoxState::Unchecked);
	ZhCheckBox->SetIsChecked(ECheckBoxState::Checked);

	//�������ݿ�����ת��Ϊ����
	MccDataHandle::Get()->ChangeLocalizationCultrue(ECultureTeam::ZH);

}

void SMccGameOptionWdiget::EnCheckBoxStateChanged(ECheckBoxState NewState)
{
	//���ñ�ѡ�е�
	EnCheckBox->SetIsChecked(ECheckBoxState::Checked);
	ZhCheckBox->SetIsChecked(ECheckBoxState::Unchecked);

	//�������ݿ�����ת��Ϊ����
	MccDataHandle::Get()->ChangeLocalizationCultrue(ECultureTeam::EN);
}
