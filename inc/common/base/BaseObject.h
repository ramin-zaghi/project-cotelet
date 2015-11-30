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
 * @file BaseObject.h
 * @author Ramin Zaghi
 * @brief TODO: Fill this field.
 *
 * TODO: Fill this field.
 * @see http://www.stack.nl/~dimitri/doxygen/
 */

#ifndef __BASEOBJECT_H__
#define __BASEOBJECT_H__

#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <memory>

#define COTELET_CLASS(classname)                                               \
  class classname;                                                             \
  template <class T>                                                           \
  class ___COTELET_UTILITY_BASECLASS___##classname :                           \
      virtual public BaseObject<T> {                                           \
    public:                                                                    \
      /** \brief Return classname in null-terminated character string. */      \
      static char const * const TypeName() noexcept {                          \
        return #classname;                                                     \
      }                                                                        \
      /** \brief Register this class in the class registery. */                \
      static ___UTILITY_COTELET_CLASSREGISTRY___ ___classregistery___;   \
  };                                                                           \
  class classname :                                                            \
      virtual public ___COTELET_UTILITY_BASECLASS___##classname<classname>

#define COTELET_CLASS_IMPLEMENT(classname)                                     \
  /** \brief Force the compiler to instantiate the static template member. */  \
  template<>                                                                   \
  ___UTILITY_COTELET_CLASSREGISTRY___                                    \
    ___COTELET_UTILITY_BASECLASS___##classname<classname>::                    \
      ___classregistery___{                                                    \
        #classname,                                                            \
        &___COTELET_UTILITY_BASECLASS___##classname<classname>::               \
          createUninitialized};

namespace cotelet {

  /**
   * @brief TODO: Fill this brief field.
   *
   * TODO: Fill this detailed field.
   */
  class Base {
  }; // Base

  /**
   * @brief Keeps a record of each and every "cotelet" class.
   *
   * TODO: Fill this detailed field.
   */
  class ___UTILITY_COTELET_CLASSREGISTRY___ {
    public:
      /** \brief A type for a pointer to the factory method. */
      typedef Base* (*VFPToCreateUninitialized)(void*);
      typedef std::map<char const * const, VFPToCreateUninitialized> MapType;

      /**
       * @brief TODO: Fill this brief field.
       *
       * TODO: Fill this detailed field.
       */
       ___UTILITY_COTELET_CLASSREGISTRY___(char const * const classname,
         VFPToCreateUninitialized factory)  {
 std::cout << map_class_to_factory().size() << " - CLASS = " << classname << std::endl;
//         map_class_to_factory.insert(
//           std::pair<char const * const,
//             const VirtualFunctionPointerToCreateUninitialized>(classname, factory));
map_class_to_factory()[classname] = factory;
       }

    private:
      /** \brief TODO: Fill this brief field. */
      static MapType& map_class_to_factory() {
        static MapType* _local_map = new MapType();
        static std::unique_ptr<MapType> _destroy_it(_local_map);
        return *_local_map;
      }

  }; // ___UTILITY_COTELET_CLASSREGISTRY___

  /**
   * @brief TODO: Fill this brief field.
   *
   * TODO: Fill this detailed field.
   */
  template<class T>
  class BaseObject : public Base {

    public:
      /** \brief TODO: Fill in this briefe field. */
      typedef T Type;

      /** \brief TODO: Fill in this briefe field. */
      typedef std::vector<Type> TypeVector;

      /** \brief TODO: Fill in this briefe field. */
      typedef std::vector<std::unique_ptr<Type>> TypeUniquePointerVector;

      static Base* createUninitialized(void* data) {
        return new T();
      }

    private:
   }; // BaseObject

} // cotelet

#endif // __BASEOBJECT_H__

