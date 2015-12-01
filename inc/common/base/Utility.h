/******************************************************************************
 * Copyright (c) 2015 Ramin Zaghi <rzaghi@mosaic3dx.com>.                     *
 * All rights reserved.                                                       *
 *                                                                            *
 * Developed by: Ramin Zaghi                                                  *
 * Mosaic3DX.com                                                              *
 * http://mosaic3dx.com                                                       *
 *                                                                            *
 * Permission is hereby granted, free of charge, to any person obtaining a    *
 * copy of this software and associated documentation files (the "Software"), *
 * to deal with the Software without restriction, including without           *
 * limitation the rights to use, copy, modify, merge, publish, distribute,    *
 * sublicense, and/or sell copies of the Software, and to permit persons      *
 * to whom the Software is furnished to do so, subject to the                 *
 * following conditions:                                                      *
 *                                                                            *
 *   Redistributions of source code must retain the above copyright notice,   *
 *   this list of conditions and the following disclaimers.                   *
 *                                                                            *
 *   Redistributions in binary form must reproduce the above copyright        *
 *   notice, this list of conditions and the following disclaimers in the     *
 *   documentation and/or other materials provided with the distribution.     *
 *                                                                            *
 *   Neither the names of Ramin Zaghi, Mosaic3DX, Mosaic3dX.com, nor the      *
 *   names of its contributors may be used to endorse or promote products     *
 *   derived from this Software without specific prior written permission.    *
 *                                                                            *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS    *
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF                 *
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.     *
 * IN NO EVENT SHALL THE CONTRIBUTORS OR COPYRIGHT HOLDERS BE LIABLE          *
 * FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF         *
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION         *
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS WITH THE SOFTWARE.          *
 *                                                                            *
 *   Please see "The University of Illinois/NCSA Open Source License (NCSA)"  *
 *   at http://opensource.org/licenses/NCSA                                   *
 *                                                                            *
 *****************************************************************************/

/**
 * @file Utility.h
 * @author Ramin Zaghi
 * @brief TODO: Fill this field.
 *
 * TODO: Fill this field.
 * @see http://www.stack.nl/~dimitri/doxygen/
 */

#ifndef __UTILITY_H__
#define __UTILITY_H__

#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <memory>


#define COTELET_CLASS(classname)                                               \
  class classname;                                                             \
                                                                               \
  template <class T>                                                           \
  class _BaseClass##classname : virtual public BaseObject<T> {                 \
    public:                                                                    \
      /** \brief Return classname in null-terminated character string. */      \
      static char const * const TypeName() noexcept {                          \
        return #classname;                                                     \
      }                                                                        \
                                                                               \
    private:                                                                   \
      /** \brief Register this class in the class registery. */                \
      static _ClassRegistery _registery;                                       \
                                                                               \
  };                                                                           \
                                                                               \
  class classname :                                                            \
      virtual public _BaseClass##classname<classname>


#define COTELET_CLASS_IMPLEMENT(classname)                                     \
  /** \brief Force the compiler to instantiate the static template member. */  \
  template<>                                                                   \
  _ClassRegistery _BaseClass##classname<classname>::_registery {               \
    #classname,                                                                \
    &_BaseClass##classname<classname>::createUninitialized };


#define COTELET_PROPERTY_STATIC_READONLY(Type, name)                           \
  /** \brief Avoid static member initialization fiasco and destroy it too. */  \
  static Type& get##name() {                                                   \
    static Type* static_object = new Type();                                   \
    static std::unique_ptr<Type> destroy_object(static_object);                \
    return *static_object; };


namespace cotelet {

  class Base; // Look at inc/common/base/Base.h

  /** \brief A type for a pointer to the factory method. */
  typedef Base* (*FunctionCreateUninitializedBaseObject)(void*);

  /**
   * @brief Keeps a record of each and every "cotelet" class.
   *
   * TODO: Fill this detailed field.
   */
  class _ClassRegistery {
    public:
      /**
       * @brief TODO: Fill this brief field.
       *
       * TODO: Fill this detailed field.
       */
       _ClassRegistery(char const * const classname, FunctionCreateUninitializedBaseObject factory)  {
         getMapClassNameToFactory()[classname] = factory;
       }

    private:
      /** \brief TODO: Fill this brief field. */
      typedef std::map<char const * const, FunctionCreateUninitializedBaseObject> MapType;

      /**
       * @brief TODO: Fill this brief field.
       *
       * TODO: Fill this detailed field.
       */
      COTELET_PROPERTY_STATIC_READONLY(MapType, MapClassNameToFactory);

  }; // _ClassRegistery

} // cotelet

#endif // __UTILITY_H__

