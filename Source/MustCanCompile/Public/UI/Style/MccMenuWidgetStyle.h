// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateWidgetStyle.h"
#include "SlateWidgetStyleContainerBase.h"
#include "SlateBrush.h"

#include "MccMenuWidgetStyle.generated.h"

/**
 *
 */
USTRUCT()
struct MUSTCANCOMPILE_API FMccMenuStyle : public FSlateWidgetStyle
{
	GENERATED_USTRUCT_BODY()

		FMccMenuStyle();
	virtual ~FMccMenuStyle();

	// FSlateWidgetStyle
	virtual void GetResources(TArray<const FSlateBrush*>& OutBrushes) const override;
	static const FName TypeName;
	virtual const FName GetTypeName() const override { return TypeName; };
	static const FMccMenuStyle& GetDefault();

	UPROPERTY(EditAnywhere, Category = MenuHUD)
		FSlateBrush MenuHUDBackGroundBrush;

	UPROPERTY(EditAnywhere, Category = Menu)
		FSlateBrush MenuBackGroundBrush;

	UPROPERTY(EditAnywhere, Category = Icon)
		FSlateBrush LeftIconBrush;
	UPROPERTY(EditAnywhere, Category = Icon)
		FSlateBrush RightIconBrush;

	UPROPERTY(EditAnywhere, Category = Title)
		FSlateBrush TitleBorderBrush;

	UPROPERTY(EditAnywhere, Category = MenuItem)
		FSlateBrush MenuItemBrush;

	//60ºÅ×ÖÌå
	UPROPERTY(EditAnywhere, Category = Common)
		FSlateFontInfo Font_60;
	//40ºÅ×ÖÌå
	UPROPERTY(EditAnywhere, Category = Common)
		FSlateFontInfo Font_40;
	//30ºÅ×ÖÌå
	UPROPERTY(EditAnywhere, Category = Common)
		FSlateFontInfo Font_30;
};

/**
 */
UCLASS(hidecategories = Object, MinimalAPI)
class UMccMenuWidgetStyle : public USlateWidgetStyleContainerBase
{
	GENERATED_BODY()

public:
	/** The actual data describing the widget appearance. */
	UPROPERTY(Category = Appearance, EditAnywhere, meta = (ShowOnlyInnerProperties))
		FMccMenuStyle WidgetStyle;

	virtual const struct FSlateWidgetStyle* const GetStyle() const override
	{
		return static_cast<const struct FSlateWidgetStyle*>(&WidgetStyle);
	}
};