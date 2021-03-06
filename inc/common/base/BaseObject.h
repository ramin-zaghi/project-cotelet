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

namespace cotelet {

  /**
   * @brief TODO: Fill this brief field.
   *
   * TODO: Fill this detailed field.
   */
  class Base {
  }; // Base

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

    private:

  }; // BaseObject

} // cotelet

#endif // __BASEOBJECT_H__

