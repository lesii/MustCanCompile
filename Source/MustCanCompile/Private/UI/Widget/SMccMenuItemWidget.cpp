// Fill out your copyright notice in the Description page of Project Settings.

#include "SMccMenuItemWidget.h"
#include "SlateOptMacros.h"
#include "SBox.h"
#include "MccTypes.h"
#include "MccStyle.h"
#include "MccMenuWidgetStyle.h"
#include "STextBlock.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SMccMenuItemWidget::Construct(const FArguments& InArgs)
{
	MenuStyle = &MccStyle::Get().GetWidgetStyle<FMccMenuStyle>("BPMccMenuStyle");	//获取WidgetStyle

	OnClicked = InArgs._OnClicked;
	ItemType = InArgs._ItemType.Get();

	ChildSlot
		[
			SNew(SBox)
			.WidthOverride(500.f)
		.HeightOverride(100.f)
		[
			SNew(SOverlay)
	+ SOverlay::Slot()
		.VAlign(VAlign_Fill)
		.HAlign(HAlign_Fill)
		[
			SNew(SImage)
			.Image(&MenuStyle->MenuItemBrush)
		.ColorAndOpacity(this, &SMccMenuItemWidget::GetTintColor)	//绑定这个方法改变颜色后，这个函数会调用
		] //Slot结束

	+ SOverlay::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		[
			SNew(STextBlock)
			.Text(InArgs._ItemText)
		.Font(MenuStyle->Font_60)
		]



		]	//SBOX结束

		];	//ChildSlot结束
	
	bIsMouseButtonDown = false;
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

FReply SMccMenuItemWidget::OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	bIsMouseButtonDown = true;
	return FReply::Handled();
}

FReply SMccMenuItemWidget::OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	//如果按钮按下了并且OnClicked绑定了方法
	if (bIsMouseButtonDown)
	{
		bIsMouseButtonDown = false;
		OnClicked.ExecuteIfBound(ItemType);
	}

	return FReply::Handled();
}

void SMccMenuItemWidget::OnMouseLeave(const FPointerEvent& MouseEvent)
{
	bIsMouseButtonDown = false;
}

FSlateColor SMccMenuItemWidget::GetTintColor() const
{
	if (bIsMouseButtonDown) return FLinearColor(1.f, 0.1f, 0.1f, 0.5f);
	else return FLinearColor(1.f, 1.f, 1.f, 1.f);
}
