// Copyright (c) 2010-2011, duilib develop team(www.duilib.com).
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or 
// without modification, are permitted provided that the 
// following conditions are met.
//
// Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//
// Redistributions in binary form must reproduce the above 
// copyright notice, this list of conditions and the following
// disclaimer in the documentation and/or other materials 
// provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND 
// CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
// INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
// BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS 
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#if defined(UILIB_EXPORTS)
#if defined(_MSC_VER)
#define UILIB_API __declspec(dllexport)
#else
#define UILIB_API 
#endif
#else
#if defined(_MSC_VER)
#define UILIB_API __declspec(dllimport)
#else
#define UILIB_API 
#endif
#endif

#define UILIB_COMDAT __declspec(selectany)

#define _WINSOCKAPI_   /* Prevent inclusion of winsock.h in windows.h */

#include "resource.h"

#include <windows.h>
#include <windowsx.h>
#include <commctrl.h>
#include <stddef.h>
#include <richedit.h>
#include <tchar.h>
#include <assert.h>
#include <crtdbg.h>
#include <malloc.h>

#include "IDuiObject.h"
#include "Utils/Utils.h"
#include "Utils/UIDelegate.h"
#include "Utils/UIReflection.h"
#include "Core/UIDefine.h"
#include "Core/UITrayIcon.h"
#include "Core/UIManager.h"
#include "Core/UIBase.h"
#include "Core/UIControl.h"
#include "Core/UIContainer.h"
#include "Core/UIMarkup.h"
#include "Core/UIDlgBuilder.h"
#include "Core/UIRender.h"
#include "Core/UITimer.h"
#include "Utils/WindowImpl.h"
#include "Utils/Window.h"

#include "CommonInclude.h"
#include "ControlInclude.h"
#include "ExtendInclude.h"
//#include "LuaInclude.h"
#include "NetInclude.h"

extern HINSTANCE g_dllModule ;


#ifdef _USE_DUILIB_
#if defined(_DEBUG)
	#ifdef USE_STATIC_LIB
		#if defined(_UNICODE)
			#pragma comment(lib,"DuiLib_ud_s.lib")
		#else
			#pragma comment(lib,"DuiLib_d_s.lib")
		#endif
	#else
		#if defined(_UNICODE)
			#pragma comment(lib,"DuiLib_ud.lib")
		#else
			#pragma comment(lib,"DuiLib_d.lib")
		#endif
	#endif
#else
	#ifdef USE_STATIC_LIB
		#if defined(_UNICODE)
			#pragma comment(lib,"DuiLib_u_s.lib")
		#else
			#pragma comment(lib,"DuiLib_s.lib")
		#endif
	#else
		#if defined(_UNICODE)
			#pragma comment(lib,"DuiLib_u.lib")
		#else
			#pragma comment(lib,"DuiLib.lib")
		#endif
	#endif
#endif
#endif
