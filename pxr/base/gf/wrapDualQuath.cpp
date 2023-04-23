//
// Copyright 2021 Pixar
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
////////////////////////////////////////////////////////////////////////
// This file is generated by a script.  Do not edit directly.  Edit the
// wrapDualQuat.template.cpp file to make changes.

#include "pxr/pxr.h"
#include "pxr/base/gf/dualQuatd.h"
#include "pxr/base/gf/dualQuatf.h"
#include "pxr/base/gf/dualQuath.h"

#include "pxr/base/tf/hash.h"
#include "pxr/base/tf/pyUtils.h"
#include "pxr/base/tf/wrapTypeHelpers.h"
#include "pxr/base/tf/pyContainerConversions.h"

#include <boost/python/class.hpp>
#include <boost/python/copy_const_reference.hpp>
#include <boost/python/def.hpp>
#include <boost/python/implicit.hpp>
#include <boost/python/make_constructor.hpp>
#include <boost/python/operators.hpp>
#include <boost/python/overloads.hpp>
#include <boost/python/return_arg.hpp>

#include <string>

using namespace boost::python;

using std::string;

PXR_NAMESPACE_USING_DIRECTIVE

namespace {

static string __repr__(GfDualQuath const &self) {
    return TF_PY_REPR_PREFIX + "DualQuath(" +
        TfPyRepr(self.GetReal()) + ", " +
        TfPyRepr(self.GetDual()) + ")";
}

static GfDualQuath __truediv__(const GfDualQuath &self, GfHalf value)
{
    return self / value;
}

static GfDualQuath& __itruediv__(GfDualQuath &self, GfHalf value)
{
    return self /= value;
}

static size_t __hash__(GfDualQuath const &self) {
    return TfHash{}(self);
}

// Zero-initialized default ctor for python.
static GfDualQuath *__init__() {
    return new GfDualQuath(GfQuath(0), GfQuath(0));
}

} // anonymous namespace

void wrapDualQuath()
{
    object getReal =
        make_function(&GfDualQuath::GetReal,
                      return_value_policy<return_by_value>());
    object setReal =
        make_function((void (GfDualQuath::*)(const GfQuath &))
                      &GfDualQuath::SetReal);

    object getDual =
        make_function(&GfDualQuath::GetDual,
                      return_value_policy<return_by_value>());
    object setDual =
        make_function((void (GfDualQuath::*)(const GfQuath &))
                      &GfDualQuath::SetDual);

    def( "Dot",
         (GfHalf (*)(const GfDualQuath &, const GfDualQuath &))
         GfDot);

    class_<GfDualQuath> cls("DualQuath", no_init);
    cls
        .def("__init__", make_constructor(__init__))

        .def( TfTypePythonClass() )

        .def(init<GfDualQuath>())
        .def(init<GfHalf>(arg("realVal")))
        .def(init< const GfQuath & >(arg("real")))
        .def(init< const GfQuath &, const GfQuath & >(
                 (arg("real"), arg("dual"))))
        .def(init< const GfQuath &, const GfVec3h & >(
                 (arg("rotation"), arg("translation"))))
        .def(init<const GfDualQuatd & >())
        .def(init<const GfDualQuatf & >())

        .def("GetZero", &GfDualQuath::GetZero)
        .staticmethod("GetZero")

        .def("GetIdentity", &GfDualQuath::GetIdentity)
        .staticmethod("GetIdentity")

        .def("GetReal", getReal)
        .def("SetReal", setReal)
        .add_property("real", getReal, setReal)

        .def("GetDual", getDual)
        .def("SetDual", setDual)
        .add_property("dual", getDual, setDual)

        .def("GetLength", &GfDualQuath::GetLength)

        .def("GetNormalized", &GfDualQuath::GetNormalized,
             (arg("eps")=GF_MIN_VECTOR_LENGTH))
        .def("Normalize", &GfDualQuath::Normalize,
             (arg("eps")=GF_MIN_VECTOR_LENGTH), return_self<>())

        .def("GetConjugate", &GfDualQuath::GetConjugate)
        .def("GetInverse", &GfDualQuath::GetInverse)
        .def("SetTranslation",
             (void (GfDualQuath::*)(const GfVec3h &))
             &GfDualQuath::SetTranslation)
        .def("GetTranslation", &GfDualQuath::GetTranslation)

        .def("Transform",
             (GfVec3h (GfDualQuath::*)(const GfVec3h &) const)
             &GfDualQuath::Transform)

        .def( str(self) )
        .def( self == self )
        .def( self != self )
        .def( self += self )
        .def( self -= self )
        .def( self *= self )
        .def( self *= GfHalf() )
        .def( self /= GfHalf() )
        .def( self + self )
        .def( self - self )
        .def( self * self )
        .def( self * GfHalf() )
        .def( GfHalf() * self )
        .def( self / GfHalf() )

        .def("__repr__", __repr__)
        .def("__hash__", __hash__)
        ;


    to_python_converter<std::vector<GfDualQuath>,
        TfPySequenceToPython<std::vector<GfDualQuath> > >();

    if (!PyObject_HasAttrString(cls.ptr(), "__truediv__")) {
        // __truediv__ not added by .def( self / GfHalf() ) above, which
        // happens when building with python 2, but we need it to support
        // "from __future__ import division"
        cls.def("__truediv__", __truediv__);
    }
    if (!PyObject_HasAttrString(cls.ptr(), "__itruediv__")) {
        // __itruediv__ not added by .def( self /= GfHalf() ) above, which
        // happens when building with python 2, but we need it to support
        // "from __future__ import division". This is also a workaround for a 
        // bug in the current version of boost::python that incorrectly wraps
        // in-place division with __idiv__ when building with python 3.
        cls.def("__itruediv__", __itruediv__, return_self<>());
    }
}
