

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Tue Jul 25 10:40:13 2017
 */
/* Compiler settings for .\ClipboardLib.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __ClipboardLib_h_h__
#define __ClipboardLib_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IClipboard_FWD_DEFINED__
#define __IClipboard_FWD_DEFINED__
typedef interface IClipboard IClipboard;
#endif 	/* __IClipboard_FWD_DEFINED__ */


#ifndef __Clipboard_FWD_DEFINED__
#define __Clipboard_FWD_DEFINED__

#ifdef __cplusplus
typedef class Clipboard Clipboard;
#else
typedef struct Clipboard Clipboard;
#endif /* __cplusplus */

#endif 	/* __Clipboard_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __ClipboardLib_LIBRARY_DEFINED__
#define __ClipboardLib_LIBRARY_DEFINED__

/* library ClipboardLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_ClipboardLib;

#ifndef __IClipboard_DISPINTERFACE_DEFINED__
#define __IClipboard_DISPINTERFACE_DEFINED__

/* dispinterface IClipboard */
/* [uuid] */ 


EXTERN_C const IID DIID_IClipboard;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("A3117608-2FC5-4CAF-979C-636271D502CE")
    IClipboard : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IClipboardVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IClipboard * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IClipboard * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IClipboard * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IClipboard * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IClipboard * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IClipboard * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IClipboard * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IClipboardVtbl;

    interface IClipboard
    {
        CONST_VTBL struct IClipboardVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IClipboard_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IClipboard_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IClipboard_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IClipboard_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IClipboard_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IClipboard_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IClipboard_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IClipboard_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_Clipboard;

#ifdef __cplusplus

class DECLSPEC_UUID("D07AF957-C9ED-43C2-BF4C-4636A8C9F9FB")
Clipboard;
#endif
#endif /* __ClipboardLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


