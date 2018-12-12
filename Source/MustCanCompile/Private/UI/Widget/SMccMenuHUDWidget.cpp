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
	//获取编辑器的MenuStyle
	MenuStyle = &MccStyle::Get().GetWidgetStyle<FMccMenuStyle>("BPMccMenuStyle");

	UIScaler.Bind(this, &SMccMenuHUDWidget::GetUIScaler);

	//UI的设置
	ChildSlot
		[

			SNew(SDPIScaler)	//新建一个DPI缩放
			.DPIScale(UIScaler)	//缩放DPI
		[

			SNew(SOverlay)	//新建一个Overlay


			+ SOverlay::Slot()	//对overlay添加一个slot(插槽)
		.HAlign(HAlign_Fill)	//水平方向填充fill
		.VAlign(VAlign_Fill)	//垂直方向 填充fill
		//.Padding(FMargin(30.f))	//全部间隔30
		[
			SNew(SImage)
			.Image(&MenuStyle->MenuHUDBackGroundBrush)	//在slot中添加一个Image(使用样式为MenuStyle的样式)
		]	//Slot结束

	+ SOverlay::Slot()	//对overlay添加一个slot(插槽)
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		//.Expose(ImageSlot)	//绑定进ImageSlot
		[
			SAssignNew(MenuWidget, SMccMenuWidget)

		]	//Slot结束

	/*
	+ SOverlay::Slot()	//对overlay添加一个slot
		.HAlign(HAlign_Left)
		.VAlign(VAlign_Top)
		[
			SNew(SButton)
			.OnClicked(this, &SMccMenuHUDWidget::OnClick)
		]	//Slot结束
	*/


		]	//DPIScaler结束

		];	//ChildSlot结束

	
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
