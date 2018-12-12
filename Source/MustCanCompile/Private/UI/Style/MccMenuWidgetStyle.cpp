// Fill out your copyright notice in the Description page of Project Settings.

#include "MccMenuWidgetStyle.h"

FMccMenuStyle::FMccMenuStyle()
{
}

FMccMenuStyle::~FMccMenuStyle()
{
}

const FName FMccMenuStyle::TypeName(TEXT("FMccMenuStyle"));

const FMccMenuStyle& FMccMenuStyle::GetDefault()
{
	static FMccMenuStyle Default;
	return Default;
}

void FMccMenuStyle::GetResources(TArray<const FSlateBrush*>& OutBrushes) const
{
	// Add any brush resources here so that Slate can correctly atlas and reference them
}

