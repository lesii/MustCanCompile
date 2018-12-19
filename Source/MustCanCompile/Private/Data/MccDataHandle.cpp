// Fill out your copyright notice in the Description page of Project Settings.

#include "MccDataHandle.h"

TSharedPtr<MccDataHandle> MccDataHandle::DataInstance = nullptr;

void MccDataHandle::Initialize()
{
	if (!DataInstance.IsValid())
		DataInstance = Creat();
}


void MccDataHandle::ChangeLocalizationCultrue(ECultureTeam _Culture)
{
	switch (_Culture)
	{
	case ECultureTeam::EN:
		FInternationalization::Get().SetCurrentCulture(TEXT("en"));
		break;
	case ECultureTeam::CH:
		FInternationalization::Get().SetCurrentCulture(TEXT("ch"));
		break;
	default:
		break;
	}

	CurrentCulture = _Culture;
}

TSharedPtr<MccDataHandle> MccDataHandle::MccDataHandle::Get()
{
	Initialize();
	return DataInstance;
}

TSharedRef<MccDataHandle> MccDataHandle::MccDataHandle::Creat()
{
	TSharedRef<MccDataHandle> DataRef = MakeShareable(new MccDataHandle());	//MakeShareable 创建共享引用和共享指针
	return DataRef;
}


MccDataHandle::MccDataHandle()
{
}
