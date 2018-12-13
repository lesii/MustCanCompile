// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "DelegateCombinations.h"
#include "MccTypes.h"


DECLARE_DELEGATE_OneParam(FItemClicked, const EMenuItem::Type)

/**
 * 
 */
class MUSTCANCOMPILE_API SMccMenuItemWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMccMenuItemWidget)
	{}
	SLATE_ATTRIBUTE(FText, ItemText)

		SLATE_EVENT(FItemClicked,OnClicked)

		SLATE_ATTRIBUTE(EMenuItem::Type, ItemType)
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	//��д���OnMuserButtonDown����
	virtual FReply OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;

	virtual FReply OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;

	virtual void OnMouseLeave(const FPointerEvent& MouseEvent) override;


private:
	FSlateColor GetTintColor() const;	//��ȡ��ɫ


private:

	//�����¼�ί��
	FItemClicked OnClicked;

	//��ť����
	EMenuItem::Type ItemType;

	const struct FMccMenuStyle * MenuStyle;

	bool bIsMouseButtonDown;
};
