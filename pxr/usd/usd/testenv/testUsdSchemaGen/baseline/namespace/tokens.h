//
// Copyright 2016 Pixar
//
// Licensed under the Apache License, Version 2.0 (the "Apache License")
// with the following modification; you may not use this file except in
// compliance with the Apache License and the following modification to it:
// Section 6. Trademarks. is deleted and replaced with:
//
// 6. Trademarks. This License does not grant permission to use the trade
//    names, trademarks, service marks, or product names of the Licensor
//    and its affiliates, except as required to comply with Section 4(c) of
//    the License and to reproduce the content of the NOTICE file.
//
// You may obtain a copy of the Apache License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the Apache License with the above modification is
// distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied. See the Apache License for the specific
// language governing permissions and limitations under the Apache License.
//
#ifndef USDCONTRIVED_TOKENS_H
#define USDCONTRIVED_TOKENS_H

/// \file usdContrived/tokens.h

// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// 
// This is an automatically generated file (by usdGenSchema.py).
// Do not hand-edit!
// 
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

#include "pxr/pxr.h"
#include "pxr/usd/usdContrived/api.h"
#include "pxr/base/tf/staticData.h"
#include "pxr/base/tf/token.h"
#include <vector>

namespace foo {


/// \class UsdContrivedTokensType
///
/// \link UsdContrivedTokens \endlink provides static, efficient
/// \link TfToken TfTokens\endlink for use in all public USD API.
///
/// These tokens are auto-generated from the module's schema, representing
/// property names, for when you need to fetch an attribute or relationship
/// directly by name, e.g. UsdPrim::GetAttribute(), in the most efficient
/// manner, and allow the compiler to verify that you spelled the name
/// correctly.
///
/// UsdContrivedTokens also contains all of the \em allowedTokens values
/// declared for schema builtin attributes of 'token' scene description type.
/// Use UsdContrivedTokens like so:
///
/// \code
///     gprim.GetMyTokenValuedAttr().Set(UsdContrivedTokens->libraryToken1);
/// \endcode
struct UsdContrivedTokensType {
    USDCONTRIVED_API UsdContrivedTokensType();
    /// \brief "libraryToken1"
    /// 
    /// Special token for the usdContrived library.
    const TfToken libraryToken1;
    /// \brief "/non-identifier-tokenValue!"
    /// 
    /// libraryToken2 doc
    const TfToken libraryToken2;
    /// \brief "myColorFloat"
    /// 
    /// UsdContrivedBase
    const TfToken myColorFloat;
    /// \brief "myDouble"
    /// 
    /// UsdContrivedBase
    const TfToken myDouble;
    /// \brief "myFloat"
    /// 
    /// UsdContrivedBase
    const TfToken myFloat;
    /// \brief "myNormals"
    /// 
    /// UsdContrivedBase
    const TfToken myNormals;
    /// \brief "myPoints"
    /// 
    /// UsdContrivedBase
    const TfToken myPoints;
    /// \brief "myVaryingToken"
    /// 
    /// UsdContrivedBase
    const TfToken myVaryingToken;
    /// \brief "myVaryingTokenArray"
    /// 
    /// UsdContrivedBase
    const TfToken myVaryingTokenArray;
    /// \brief "myVelocities"
    /// 
    /// UsdContrivedBase
    const TfToken myVelocities;
    /// \brief "testAttrOne"
    /// 
    /// UsdContrivedSingleApplyAPI
    const TfToken testAttrOne;
    /// \brief "testAttrTwo"
    /// 
    /// UsdContrivedSingleApplyAPI
    const TfToken testAttrTwo;
    /// \brief "unsignedChar"
    /// 
    /// UsdContrivedBase
    const TfToken unsignedChar;
    /// \brief "unsignedInt"
    /// 
    /// UsdContrivedBase
    const TfToken unsignedInt;
    /// \brief "unsignedInt64Array"
    /// 
    /// UsdContrivedBase
    const TfToken unsignedInt64Array;
    /// \brief "VariableTokenAllowed1"
    /// 
    /// Possible value for UsdContrivedBase::GetMyVaryingTokenAttr()
    const TfToken VariableTokenAllowed1;
    /// \brief "VariableTokenAllowed2"
    /// 
    /// Possible value for UsdContrivedBase::GetMyVaryingTokenAttr()
    const TfToken VariableTokenAllowed2;
    /// \brief "VariableTokenAllowed<3>"
    /// 
    /// Possible value for UsdContrivedBase::GetMyVaryingTokenAttr()
    const TfToken VariableTokenAllowed_3_;
    /// \brief "VariableTokenArrayAllowed1"
    /// 
    /// Possible value for UsdContrivedBase::GetMyVaryingTokenArrayAttr()
    const TfToken VariableTokenArrayAllowed1;
    /// \brief "VariableTokenArrayAllowed2"
    /// 
    /// Possible value for UsdContrivedBase::GetMyVaryingTokenArrayAttr()
    const TfToken VariableTokenArrayAllowed2;
    /// \brief "VariableTokenArrayAllowed<3>"
    /// 
    /// Possible value for UsdContrivedBase::GetMyVaryingTokenArrayAttr()
    const TfToken VariableTokenArrayAllowed_3_;
    /// \brief "VariableTokenDefault"
    /// 
    /// Fallback value for UsdContrivedBase::GetMyVaryingTokenAttr()
    const TfToken VariableTokenDefault;
    /// \brief "Base"
    /// 
    /// Schema identifer and family for UsdContrivedBase
    const TfToken Base;
    /// \brief "SingleApplyAPI"
    /// 
    /// Schema identifer and family for UsdContrivedSingleApplyAPI
    const TfToken SingleApplyAPI;
    /// A vector of all of the tokens listed above.
    const std::vector<TfToken> allTokens;
};

/// \var UsdContrivedTokens
///
/// A global variable with static, efficient \link TfToken TfTokens\endlink
/// for use in all public USD API.  \sa UsdContrivedTokensType
extern USDCONTRIVED_API TfStaticData<UsdContrivedTokensType> UsdContrivedTokens;

}

#endif
