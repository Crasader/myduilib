#include "StdAfx.h"
#include "UIReflection.h"

namespace DuiLib
{

	//************************************
	// ��������: RegistDuiClass
	// ��������: void
	// ������Ϣ: string _duiClassName					����
	// ������Ϣ: DuiInstanceFun _createDuiInstanceFun	ע��ĺ���ָ��
	// ����˵�����෴��ע�ᣬ���Ѿ�ע�������ֱ�ӷ���
	//************************************
#ifdef _UNICODE
	void DuiObjectMap::RegistDuiClass(const wchar_t* _duiClassName, DuiInstanceFun _createDuiInstanceFun)
	{
		if (GetDuiClassMaps().size()>0 && GetDuiClassMaps().find(_duiClassName) != GetDuiClassMaps().end())
			return;

		GetDuiClassMaps()[_duiClassName] = _createDuiInstanceFun;
	}

	//************************************
	// ��������: createInstance
	// ��������: void*
	// ������Ϣ: string _duiClassName
	// ����˵����ͨ����������ʵ��
	//************************************
	void* DuiObjectMap::createInstance(const wchar_t* _duiClassName)
	{
		if (GetDuiClassMaps().size()>0 && GetDuiClassMaps().find(_duiClassName) == GetDuiClassMaps().end())
		{
			std::map<wstring, DuiInstanceFun>& mDuiClassMaps = GetDuiClassMaps();
			DUITRACE(_T("û���ҵ������%s ,�ö����಻����UI��ע���,�����ⲿ����CreateControl\r\n"), _duiClassName);
			return NULL;
		}

		return (GetDuiClassMaps()[_duiClassName])();
	}

	//************************************
	// ��������: GetDuiClassMaps
	// ��������: std::map<string, DuiInstanceFun>&
	// ����˵��: 
	//************************************
	std::map<wstring, DuiInstanceFun>& DuiObjectMap::GetDuiClassMaps()
	{
		static std::map<wstring, DuiInstanceFun> m_duiClassMaps;
		return m_duiClassMaps;
	}
#else
	void DuiObjectMap::RegistDuiClass(const char* _duiClassName, DuiInstanceFun _createDuiInstanceFun)
	{
		if (GetDuiClassMaps().size() > 0 && GetDuiClassMaps().find(_duiClassName) != GetDuiClassMaps().end())
			return;

		GetDuiClassMaps()[_duiClassName] = _createDuiInstanceFun;
	}
	void* DuiObjectMap::createInstance(const char* _duiClassName)
	{
		if (GetDuiClassMaps().size() > 0 && GetDuiClassMaps().find(_duiClassName) == GetDuiClassMaps().end())
		{
			std::map<string, DuiInstanceFun>& mDuiClassMaps = GetDuiClassMaps();
			DUITRACE(_T("û���ҵ������%s ,�ö����಻����UI��ע���,�����ⲿ����CreateControl\r\n"), _duiClassName);
			return NULL;
		}

		return (GetDuiClassMaps()[_duiClassName])();
	}
	std::map<string, DuiInstanceFun>& DuiObjectMap::GetDuiClassMaps()
	{
		static std::map<string, DuiInstanceFun> m_duiClassMaps;
		return m_duiClassMaps;
	}
#endif


}

