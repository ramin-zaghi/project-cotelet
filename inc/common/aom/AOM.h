/******************************************************************************
 * Copyright (c) 2015 Ramin Zaghi <rzaghi@mosaic3dx.com>. All rights reserved.
 *
 * Developed by: Ramin Zaghi
 * Mosaic3DX.com
 * http://mosaic3dx.com
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal with the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 *   Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimers.
 *
 *   Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimers in the
 *   documentation and/or other materials provided with the distribution.
 *
 *   Neither the names of Ramin Zaghi, Mosaic3DX, Mosaic3dX.com, nor the names
 *   of its contributors may be used to endorse or promote products derived
 *   from this Software without specific prior written permission.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE CONTRIBUTORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
 * OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS WITH THE SOFTWARE.
 *
 *   Please see "The University of Illinois/NCSA Open Source License (NCSA)"
 *   at http://opensource.org/licenses/NCSA
 *
 *****************************************************************************/

#ifndef __AOM_H__
#define __AOM_H__

#include "base/BaseObject.h"

namespace cotelet {

  class AOMPropertyType : public BaseObject<AOMPropertyType> {
  }; // AOMPropertyType

  class AOMInstanceType : public BaseObject<AOMInstanceType> {
  }; // AOMInstanceType

  class AOMProperty : public BaseObject<AOMProperty> {
  }; // AOMProperty

  class AOMInstance : public BaseObject<AOMInstance> {
    public:
      // TODO: Delete this function.
      // This is just to setup the initial unit tests.
      void printhi() {
        std::cout << "Hello unit test..." << std::endl;
        properties.push_back(std::unique_ptr<AOMProperty>(new AOMProperty));
      }

    private:
      AOMProperty::TypeUniquePointerVector properties;

  }; // AOMInstance

} // cotelet

#endif

