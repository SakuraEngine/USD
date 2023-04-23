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
////////////////////////////////////////////////////////////////////////
// This file is generated by a script.  Do not edit directly.  Edit the
// wrapVec.template.cpp file to make changes.

#include "pxr/pxr.h"
#include "pxr/base/gf/vec4h.h"

#include "pxr/base/gf/pyBufferUtils.h"

#include "pxr/base/tf/hash.h"
#include "pxr/base/tf/pyContainerConversions.h"
#include "pxr/base/tf/pyUtils.h"
#include "pxr/base/tf/stringUtils.h"
#include "pxr/base/tf/wrapTypeHelpers.h"

// Include headers for other vec types to support wrapping conversions and
// operators.
#include "pxr/base/gf/vec4d.h"
#include "pxr/base/gf/vec4f.h"
#include "pxr/base/gf/vec4i.h"

#include <boost/python/class.hpp>
#include <boost/python/def.hpp>
#include <boost/python/make_constructor.hpp>
#include <boost/python/operators.hpp>
#include <boost/python/overloads.hpp>
#include <boost/python/return_arg.hpp>
#include <boost/python/tuple.hpp>
#include <boost/python/slice.hpp>

#include <string>

using namespace boost::python;

using std::string;

PXR_NAMESPACE_USING_DIRECTIVE

namespace {

////////////////////////////////////////////////////////////////////////
// Python buffer protocol support.

// Python's getbuffer interface function.
static int
getbuffer(PyObject *self, Py_buffer *view, int flags) {
    if (view == NULL) {
        PyErr_SetString(PyExc_ValueError, "NULL view in getbuffer");
        return -1;
    }

    // We don't support fortran order.
    if ((flags & PyBUF_F_CONTIGUOUS) == PyBUF_F_CONTIGUOUS) {
        PyErr_SetString(PyExc_ValueError, "Fortran contiguity unsupported");
        return -1;
    }

    GfVec4h &vec = extract<GfVec4h &>(self);

    view->obj = self;
    view->buf = static_cast<void *>(vec.data());
    view->len = sizeof(GfVec4h);
    view->readonly = 0;
    view->itemsize = sizeof(GfHalf);
    if ((flags & PyBUF_FORMAT) == PyBUF_FORMAT) {
        view->format = Gf_GetPyBufferFmtFor<GfHalf>();
    } else {
        view->format = NULL;
    }
    if ((flags & PyBUF_ND) == PyBUF_ND) {
        view->ndim = 1;
        static Py_ssize_t shape = 4;
        view->shape = &shape;
    } else {
        view->ndim = 0;
        view->shape = NULL;
    }
    if ((flags & PyBUF_STRIDES) == PyBUF_STRIDES) {
        static Py_ssize_t strides = sizeof(GfHalf);
        view->strides = &strides;
    } else {
        view->strides = NULL;
    }
    view->suboffsets = NULL;
    view->internal = NULL;

    Py_INCREF(self); // need to retain a reference to self.
    return 0;
}

// This structure serves to instantiate a PyBufferProcs instance with pointers
// to the right buffer protocol functions.
static PyBufferProcs bufferProcs = {
    (getbufferproc) getbuffer,
    (releasebufferproc) 0,
};

// End python buffer protocol support.
////////////////////////////////////////////////////////////////////////


static string __repr__(GfVec4h const &self) {
    string elems;
    for (size_t i = 0; i < self.dimension; ++i) 
        elems += (i ? ", " : "") + TfPyRepr(self[i]);

    return TF_PY_REPR_PREFIX + "Vec4h(" + elems + ")";
}

static size_t __hash__(GfVec4h const &self) {
    return TfHash{}(self);
}


BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(VecGetNormalized_overloads,
                                       GetNormalized, 0, 1);
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(VecNormalize_overloads, Normalize, 0, 1);
BOOST_PYTHON_FUNCTION_OVERLOADS(GetNormalized_overloads,
                                GfGetNormalized, 1, 2);

static GfHalf
NormalizeHelper(GfVec4h *vec, GfHalf eps = 0.001)
{
    return GfNormalize(vec, eps);
}

BOOST_PYTHON_FUNCTION_OVERLOADS(Normalize_overloads, NormalizeHelper, 1, 2);

 

 
static int
normalizeIndex(int index) {
    return TfPyNormalizeIndex(index, 4, true /*throw error*/);
}

static int __len__(const GfVec4h &self) { return 4; }

// Implements __getitem__ for a single index
static GfHalf __getitem__(const GfVec4h &self, int index) {
    return self[normalizeIndex(index)];
}

// Implements __getitem__ for a slice
static list __getslice__(const GfVec4h &self, slice indices) {
    list result;

    const GfHalf* begin = self.data();
    const GfHalf* end = begin + 4;

    slice::range<const GfHalf*> bounds;
    try {
        // This appears to be a typo in the boost headers.  The method
        // name should be "get_indices".
        //
        bounds = indices.get_indicies<>(begin, end);
    } catch (std::invalid_argument const &) {
        return result;
    }

    while (bounds.start != bounds.stop) {
        result.append(*bounds.start);
        bounds.start += bounds.step;
    }
    // Unlike STL ranges, bounds represents a *closed* interval.  This
    // means that we must append exactly one more item at the end of
    // the list.
    //
    result.append(*bounds.start);

    return result;
}

static void __setitem__(GfVec4h &self, int index, GfHalf value) {
    self[normalizeIndex(index)] = value;
}

// Handles refcounting & extraction for PySequence_GetItem.
static GfHalf _SequenceGetItem(PyObject *seq, Py_ssize_t i) {
    boost::python::handle<> h(PySequence_GetItem(seq, i));
    return extract<GfHalf>(boost::python::object(h));
}

static bool _SequenceCheckItem(PyObject *seq, Py_ssize_t i) {
    boost::python::handle<> h(PySequence_GetItem(seq, i));
    extract<GfHalf> e((boost::python::object(h)));
    return e.check();
}

static void __setslice__(GfVec4h &self, slice indices, object values) {
    // Verify our arguments
    //
    PyObject* valuesObj = values.ptr();

    if (!PySequence_Check(valuesObj)) {
        TfPyThrowTypeError("value must be a sequence");
    }

    GfHalf* begin = self.data();
    GfHalf* end = begin + 4;

    Py_ssize_t sliceLength = -1;

    slice::range<GfHalf*> bounds;

    // Convince g++ that we're not using uninitialized values.
    //
    bounds.start = 0;
    bounds.stop  = 0;
    bounds.step  = 0;

    try {
        // This appears to be a typo in the boost headers.  The method
        // name should be "get_indices".
        //
        bounds = indices.get_indicies<>(begin, end);
    } catch (std::invalid_argument const &) {
        sliceLength = 0;
    }

    // If sliceLength was not set in the exception handling code above,
    // figure out how long it really is.
    //
    if (sliceLength == -1) {
        sliceLength = ((bounds.stop - bounds.start) / bounds.step) + 1;
    }

    if (PySequence_Length(valuesObj) != sliceLength) {
        TfPyThrowValueError(
            TfStringPrintf(
                "attempt to assign sequence of size %zd to slice of size %zd",
                PySequence_Length(valuesObj), sliceLength));
    }

    // Short circuit for empty slices
    //
    if (sliceLength == 0) {
        return;
    }

    // Make sure that all items can be extracted before changing the GfVec4h.
    //
    for (Py_ssize_t i = 0; i < sliceLength; ++i) {
        // This will throw a TypeError if any of the items cannot be converted.
        _SequenceGetItem(valuesObj, i);
    }

    for (Py_ssize_t i = 0; i < sliceLength; ++i) {
        *bounds.start = _SequenceGetItem(valuesObj, i);
        bounds.start += bounds.step;
    }
}

static bool __contains__(const GfVec4h &self, GfHalf value) {
    for (size_t i = 0; i < 4; ++i) {
        if (self[i] == value)
            return true;
    }
    return false;
}

static GfVec4h __truediv__(const GfVec4h &self, GfHalf value)
{
    return self / value;
}

static GfVec4h& __itruediv__(GfVec4h &self, GfHalf value)
{
    return self /= value;
}

template <class V>
static V *__init__() {
    // Default contstructor zero-initializes from python.
    return new V(0);
}

struct FromPythonTuple {
    FromPythonTuple() {
        converter::registry::
            push_back(&_convertible, &_construct,
                      boost::python::type_id<GfVec4h>());
    }

  private:
    
    static void *_convertible(PyObject *obj_ptr) {
        // If this object is a GfVec already, disregard.
        if (PyObject_HasAttrString(obj_ptr, "__isGfVec"))
            return 0;

        typedef GfHalf Scalar;

        // XXX: Would like to allow general sequences, but currently clients
        // depend on this behavior.
        if ((PyTuple_Check(obj_ptr) || PyList_Check(obj_ptr)) &&
            PySequence_Size(obj_ptr) == 4 &&
            _SequenceCheckItem(obj_ptr, 0) &&
            _SequenceCheckItem(obj_ptr, 1) &&
            _SequenceCheckItem(obj_ptr, 2) &&
            _SequenceCheckItem(obj_ptr, 3)) {
            return obj_ptr;
        }
        return 0;
    }

    static void _construct(PyObject *obj_ptr, converter::
                           rvalue_from_python_stage1_data *data) {
        typedef GfHalf Scalar;
        void *storage = ((converter::rvalue_from_python_storage<GfVec4h>*)data)
	    ->storage.bytes;
        new (storage)
	    GfVec4h(
                _SequenceGetItem(obj_ptr, 0),
                _SequenceGetItem(obj_ptr, 1),
                _SequenceGetItem(obj_ptr, 2),
                _SequenceGetItem(obj_ptr, 3));
        data->convertible = storage;
    }
};

// This adds support for python's builtin pickling library
// This is used by our Shake plugins which need to pickle entire classes
// (including code), which we don't support in pxml.
struct PickleSuite : boost::python::pickle_suite
{
    static boost::python::tuple getinitargs(const GfVec4h &v) {
        return boost::python::make_tuple(v[0], v[1], v[2], v[3]);
    }
};

} // anonymous namespace 

void wrapVec4h()
{
    typedef GfVec4h Vec;
    typedef GfHalf Scalar;

    static const size_t _dimension = 4;
    static const bool _true = true;
    
    def("Dot", (Scalar (*)( const Vec &, const Vec &))GfDot);
    
    def("CompDiv", (Vec (*)(const Vec &v1, const Vec&v2))GfCompDiv);
    def("CompMult", (Vec (*)(const Vec &v1, const Vec&v2))GfCompMult);
    def("GetLength", (Scalar (*)(const Vec &v))GfGetLength);
    def("GetNormalized", (Vec (*)(const Vec &v, Scalar eps))
        GfGetNormalized, GetNormalized_overloads());
    def("GetProjection", (Vec (*)(const Vec &a, const Vec &b))
        GfGetProjection);
    def("GetComplement", (Vec (*)(const Vec &a, const Vec &b))
        GfGetComplement);
    def("IsClose", (bool (*)(const Vec &v1, const Vec &v2, double))
        GfIsClose);
    def("Normalize", NormalizeHelper, Normalize_overloads());
        

 
    class_<GfVec4h> cls("Vec4h", no_init);
    cls
        .def("__init__", make_constructor(__init__<Vec>))

        // A tag indicating that this is a GfVec class, for internal use.
        .def_readonly("__isGfVec", _true)

        .def_pickle(PickleSuite())

        // Conversion from other vec types.
        .def(init<GfVec4d>())
        .def(init<GfVec4f>())
        .def(init<GfVec4i>())
        
        .def(init<Vec>())
        .def(init<Scalar>())
        .def(init<Scalar, Scalar, Scalar, Scalar>())

        .def(TfTypePythonClass())

        .def("__len__", __len__ )
        .def("__getitem__", __getitem__ )
        .def("__getitem__", __getslice__ )
        .def("__setitem__", __setitem__ )
        .def("__setitem__", __setslice__ )
        .def("__contains__", __contains__ )

        .def_readonly("dimension", _dimension)
        
        // Comparison to other vec types.
        .def( self == GfVec4i() )
        .def( self != GfVec4i() )

        .def(self == self)
        .def(self != self)
        .def(self += self)
        .def(self -= self)
        .def(self *= double())
        .def(self * double())
        .def(double() * self)
        .def(self /= GfHalf())
        .def(self / GfHalf())
        .def(-self)
        .def(self + self)
        .def(self - self)
        .def(self * self)
        .def(str(self))

        .def("Axis", &Vec::Axis).staticmethod("Axis")

        .def("XAxis", &Vec::XAxis).staticmethod("XAxis")
        .def("YAxis", &Vec::YAxis).staticmethod("YAxis")
        .def("ZAxis", &Vec::ZAxis).staticmethod("ZAxis")
        .def("WAxis", &Vec::WAxis).staticmethod("WAxis")

        .def("GetDot", (Scalar (*)(const Vec &, const Vec &))GfDot)
        
        .def("GetComplement", &Vec::GetComplement)
        .def("GetLength", &Vec::GetLength)
        .def("GetNormalized", &Vec::GetNormalized, VecGetNormalized_overloads())
        .def("GetProjection", &Vec::GetProjection)
        .def("Normalize", &Vec::Normalize, VecNormalize_overloads())

        .def("__repr__", __repr__)
        .def("__hash__", __hash__)
        ;
    to_python_converter<std::vector<GfVec4h>,
        TfPySequenceToPython<std::vector<GfVec4h> > >();

    // Install buffer protocol: set the tp_as_buffer slot to point to a
    // structure of function pointers that implement the buffer protocol for
    // this type.
    auto *typeObj = reinterpret_cast<PyTypeObject *>(cls.ptr());
    typeObj->tp_as_buffer = &bufferProcs;

    // Allow appropriate tuples to be passed where Vecs are expected.
    FromPythonTuple();

    // Allow conversion of lists of GfVec4h to std::vector<GfVec4h>
    TfPyContainerConversions::from_python_sequence<
        std::vector<GfVec4h>,
        TfPyContainerConversions::variable_capacity_policy >();

    if (!PyObject_HasAttrString(cls.ptr(), "__truediv__")) {
        // __truediv__ not added by .def( self / double() ) above, which
        // happens when building with python 2, but we need it to support
        // "from __future__ import division"
        cls.def("__truediv__", __truediv__);
    }
    if (!PyObject_HasAttrString(cls.ptr(), "__itruediv__")) {
        // __itruediv__ not added by .def( self /= double() ) above, which
        // happens when building with python 2, but we need it to support
        // "from __future__ import division". This is also a workaround for a 
        // bug in the current version of boost::python that incorrectly wraps
        // in-place division with __idiv__ when building with python 3.
        cls.def("__itruediv__", __itruediv__, return_self<>{});
    }
}
