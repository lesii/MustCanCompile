// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/Widget/SMccMenuHUDWidget.h"
#include "SlateOptMacros.h"
#include "SButton.h"
#include "SImage.h"
#include "UI/Style/MccStyle.h"
#include "MccMenuWidgetStyle.h"
#include "Engine/Engine.h"
#include "SDPIScaler.h"
#include "SMccMenuWidget.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SMccMenuHUDWidget::Construct(const FArguments& InArgs)
{
	//��ȡ�༭����MenuStyle
	MenuStyle = &MccStyle::Get().GetWidgetStyle<FMccMenuStyle>("BPMccMenuStyle");

	UIScaler.Bind(this, &SMccMenuHUDWidget::GetUIScaler);

	//UI������
	ChildSlot
		[

			SNew(SDPIScaler)	//�½�һ��DPI����
			.DPIScale(UIScaler)	//����DPI
		[

			SNew(SOverlay)	//�½�һ��Overlay


			+ SOverlay::Slot()	//��overlay���һ��slot(���)
		.HAlign(HAlign_Fill)	//ˮƽ�������fill
		.VAlign(VAlign_Fill)	//��ֱ���� ���fill
		//.Padding(FMargin(30.f))	//ȫ�����30
		[
			SNew(SImage)
			.Image(&MenuStyle->MenuHUDBackGroundBrush)	//��slot�����һ��Image(ʹ����ʽΪMenuStyle����ʽ)
		]	//Slot����

	+ SOverlay::Slot()	//��overlay���һ��slot(���)
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		//.Expose(ImageSlot)	//�󶨽�ImageSlot
		[
			SAssignNew(MenuWidget, SMccMenuWidget)

		]	//Slot����

	/*
	+ SOverlay::Slot()	//��overlay���һ��slot
		.HAlign(HAlign_Left)
		.VAlign(VAlign_Top)
		[
			SNew(SButton)
			.OnClicked(this, &SMccMenuHUDWidget::OnClick)
		]	//Slot����
	*/


		]	//DPIScaler����

		];	//ChildSlot����

	
}

float SMccMenuHUDWidget::GetUIScaler() const
{
	return GetViewportSize().Y / 1080.f;
}

FVector2D SMccMenuHUDWidget::GetViewportSize() const
{
	FVector2D Result(1920, 1080);
	if (GEngine && GEngine->GameViewport)
		GEngine->GameViewport->GetViewportSize(Result);
	
	return Result;
}

//------------------------------
/*
FReply SMccMenuHUDWidget::OnClick()
{
	ImageSlot->HAlign(HAlign_Left).VAlign(VAlign_Bottom);
	return FReply::Handled();
}

*/



END_SLATE_FUNCTION_BUILD_OPTIMIZATION
